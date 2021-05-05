#pragma once

#include <iostream>
#include <functional>
#include <exception>

//double linked list, has head and tail node
template <typename value_t>
class list {
public:
    //define inner type
    using value_type = value_t;
    using pointer = value_type*;
    using reference = value_type&;

protected:
    //node structure
    struct node {
        value_type data;
        node *next = nullptr, *prior = nullptr;
        node() {}

        template <typename ...types>
        node(types ...args) : data(args...) {}
    };
    using nodeptr = node*;

    node head, tail;
    size_t len = 0;

    void _init() {
        head.next = &tail;
        tail.prior = &head;
        len = 0;
    }

    //link node p after pre
    void _link_after(nodeptr pre, nodeptr p) {
        p->prior = pre;
        p->next = pre->next;
        pre->next->prior = p;
        pre->next = p;

        ++len;
    }

    //remove node p
    void _remove_at(nodeptr p) {
        auto pre = p->prior;
        pre->next = p->next;
        p->next->prior = pre;
        delete p;

        --len;
    }

    //swap key values of list
    void _swap(list &&l) {
        std::swap(head, l.head);
        std::swap(tail, l.tail);
        std::swap(len, l.len);
    }

    //locate an element by position (from 0)
    nodeptr _locate(size_t pos, size_t limit) try {
        if (pos > limit)
            throw std::out_of_range("inserting position out of range");

        auto p = head.next;
        for (size_t i = 0; i < pos; ++i, p = p->next);
        return p;
    } catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
        exit(-1);
    }

public:
    //default constructor
    list() noexcept {
        _init();
    }

    //copy constructor
    list(const list &l) noexcept : list() {
        auto p = l.head.next;

        while (p != &l.tail) {
            push_back(p->data);
            p = p->next;
        }
    }

    //move copy constructor
    list(list &&l) noexcept : list() {
        _swap(std::move(l));
    }

    //destructor
    virtual ~list() noexcept {
        clear();
    }

    //append an element at tail
    void push_back(const value_type &v) {
        _link_after(tail.prior, new node{v});
    }

    //insert an element at top
    void push_front(const value_type &v) {
        _link_after(&head, new node{v});
    }

    //insert an element at top
    template <typename ...types>
    void emplace_front(types ...args) {
        _link_after(&head, new node(args...));
    }

    //get the first element
    value_type front() try {
        if (empty())
            throw std::out_of_range("list is empty");

        return head.next->data;
    } catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
        exit(-1);
    }

    //remove the first element at top
    void pop() {
        if (empty()) return;

        _remove_at(head.next);
    }

    //get the size(length) of list
    size_t size() const {
        return len;
    }

    //test if the list is empty
    bool empty() const {
        return len == 0;
    }

    void clear() {
        nodeptr p = head.next, q;

        while (p != &tail) {
            q = p;
            p = p->next;
            delete q;
        }

        _init();
    }

    //insert an emlement at position pos
    void insert(size_t pos, const value_type &v) {
        auto p = _locate(pos, len);
        _link_after(p->prior, new node{v});
    }

    //remove an emlement at position pos
    void remove(size_t pos) {
        auto p = _locate(pos, len - 1);
        _remove_at(p);
    }

    //define callback type
    using callback_t = std::function<void (value_type &)>;

    //traverse the list
    void traverse(callback_t f) {
        for (auto p = head.next; p != &tail; p = p->next)
            f(p->data);
    }
};