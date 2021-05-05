#include "quadrangle.h"
#include "linklist.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;

//display any kinds of quadrangles 
int dis(quadrangle& obj)
{
    int ret = 0;
    ret = obj.info_cin();
    if(ret == -1)
        return ret;
    return 1;
}
// review function
void re(quadrangle& obj)
{
    obj.review();
}

//get a random value in a limit range 
size_t get_random_value(int edge)
{
    size_t ret = 0;
    unsigned seed = time(0);
    srand(seed);
    ret = rand()%edge + 1;
    return ret;
    
}

int main(int argc,char* argv[])
{
    // string s1 = "rectangle";
    // rect r1(get_random_value(10),get_random_value(10),s1);
    // dis(r1);
    // re(r1);
    
    list<quadrangle*> l; 
    while(true)
    {   
        int ret = 0;
        size_t choice = get_random_value(5);
        switch(choice)
        {
            case 1:
            {
                diamond *d1 = new diamond(get_random_value(10),get_random_value(10),"diamond");
                ret = dis(*d1);
                if(ret == -1)
                    break;
                l.push_back(d1);
                continue;
                
            }
            case 2:
            {
                square *s1 = new square(get_random_value(10),"square");
                ret = dis(*s1);
                if(ret == -1)
                    break;
                l.push_back(s1);
                continue;
            }
            case 3:
            {
                rect *r1 = new rect(get_random_value(10),get_random_value(10),"rectangle");
                ret = dis(*r1);
                if(ret == -1)
                    break;
                l.push_back(r1);
                continue;
            }
            case 4:
            {
                para *p1 = new para(get_random_value(10),get_random_value(10),"parallelogram");
                ret = dis(*p1);
                if(ret == -1)
                    break;
                l.push_back(p1);
                continue;
            }
            case 5:
            {            
                trapezoid *t1 = new trapezoid(get_random_value(10),get_random_value(10),get_random_value(10),"trapezoid");
                ret = dis(*t1);
                if(ret == -1)
                    break;
                l.push_back(t1);
                continue;
            }
        
        }
        break;
    }
        
    auto review = [](auto &&v){re(*v);};
    std::cout<<"Reviewing..."<<std::endl;
    l.traverse(review);
    l.clear();
    
    // }
    // auto af = [](auto&& v){dis(*v);};
    // rect *c1 = new rect(get_random_value(10),get_random_value(10),"rectangle");
    // list<quadrangle*> l;
    // //std::cout<<c1->who_am_I();
    // //dis(*c1);
    // l.push_back(c1);
    // l.traverse(af);
    // delete c1;
    
    return 0;

}