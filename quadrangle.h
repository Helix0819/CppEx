#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;


class quadrangle
{
protected:
    string ids;
    size_t edge;
    double area;
    double tmp;
    // static size_t Accuracy;
public:
    
    static int Accuracy;
    quadrangle(string ids,size_t e = 0,double area = 0) : ids(ids),edge(e),area(area){}
    ~quadrangle(){}

    string who_am_I()
    {
        return ids;
    }

    virtual int info_cin()
    {
        cout<<"I'm a(an) "<<who_am_I()<<endl;
        cout<<"I have "<<edge<<"edges"<<endl;
        return 1;
    }

    bool judge()
    {
        if(tmp == area)
        {
            cout<<"Your answer is correct"<<endl;
            Accuracy++;
            return true;
        }
        else
        {
            cout<<"Your answer is incorrect"<<endl;
            return false;
        }
    }
    double get_area()
    {
        return area;
    }

    virtual void review()
    {
        std::cout<<"Reviewing..."<<std::endl;
    }
};

class trapezoid : public quadrangle
{
private:
    size_t width1;
    size_t width2;
    size_t height;
public:
    
    trapezoid(size_t _width1,size_t _width2,size_t _height,string ids) : quadrangle(ids),width1(_width1),width2(_width2),height(_height)
    {
        area = 0.5*(_width1+_width2)*_height;
    }
    ~trapezoid(){}

    int info_cin() override
    {
        cout<<"trapezoid: width1="<<width1<<", width2="<<width2<<", height="<<height<<", area=?";
        cin>>tmp;
        if(tmp == -1)
            return -1;
        judge();
        return 1;
        
    }

    void review() override
    {
        
        std::cout<<ids<<": "<<"width1= "<<width1<<", width2="<<width2<<", height="<<height<<", area="<<area<<", answer="<<tmp;
        if(tmp==area)
            std::cout<<" V"<<std::endl;
        else
            std::cout<<" X"<<std::endl;
    }
};

class para : public quadrangle
{
protected:
   size_t width;
   size_t height;
public:
    
    para(size_t _width,size_t _height,string ids) : quadrangle(ids), width(_width),height(_height)
    {
        if(ids == "diamond")
            area = 0.5*_width*_height;
        else
            area = _width * _height;
    }
    
    
    ~para(){}

    int info_cin() override
    {
        cout<<"parallelogram: width="<<width<<", height="<<height<<", area=?";
        cin>>tmp;
        if(tmp == -1)
            return -1;
        judge();
        return 1;
        
    }

    void review() override
    {
        
        std::cout<<ids<<": "<<"width= "<<width<<", height="<<height<<", area="<<area<<", answer="<<tmp;
        if(tmp==area)
            std::cout<<" V"<<std::endl;
        else
            std::cout<<" X"<<std::endl;
    }
};

class rect : public para
{
public:
    
    rect(size_t _width,size_t _height,string ids) : para(_width,_height,ids){}
    
    ~rect(){}
    

    int info_cin() override
    {
        cout<<"rectangle: width="<<width<<", height="<<height<<", area=?";
        cin>>tmp;
        if(tmp == -1)
            return -1;
        judge();
        return 1;
        
    }

    void review() override
    {
        
        std::cout<<ids<<": "<<"width= "<<width<<", height="<<height<<", area="<<area<<", answer="<<tmp;
        if(tmp==area)
            std::cout<<" V"<<std::endl;
        else
            std::cout<<" X"<<std::endl;
    }
};

class diamond : public para
{
private:
    size_t diagnal1;
    size_t diagnal2;
public:
    
    
    diamond(size_t _diagnal1,size_t _diagnal2,string ids) : para(_diagnal1,_diagnal2,ids) ,diagnal1(_diagnal1),diagnal2(_diagnal2){}
    ~diamond(){}


    int info_cin() override
    {
        cout<<"diamond: diagnal1="<<diagnal1<<", diagnal2="<<diagnal2<<", area=?";
        cin>>tmp;
        if(tmp == -1)
            return -1;
        judge();
        return 1;
        

    } 
    
    void review() override
    {
       
        std::cout<<ids<<": "<<"diagnal1= "<<diagnal1<<", diagnal2="<<diagnal2<<", area="<<area<<", answer="<<tmp;
        if(tmp==area)
            std::cout<<" V"<<std::endl;
        else
            std::cout<<" X"<<std::endl;
    }
};

class square : public rect
{
public:
    int ret = 0;
    square(size_t _width,string ids = "square") : rect(_width,_width,ids){}
    
    ~square(){}

    int info_cin() override
    {
        cout<<"square: width="<<width<<", area=?";
        cin>>tmp;
        if(tmp == -1)
            return -1;
        judge();
        return 1;
        
    }

    void review() override
    {
        
        std::cout<<ids<<": "<<"width= "<<width<<", area="<<area<<", answer="<<tmp;
        if(tmp==area)
            std::cout<<" V"<<std::endl;
        else
            std::cout<<" X"<<std::endl;
    }
};