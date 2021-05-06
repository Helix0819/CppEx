#include "quadrangle.h"
#include "linklist.h"
#include<ctime>


//display any kinds of quadrangles polymorphism
int dis(quadrangle& obj)
{
    int ret = 0;
    ret = obj.info_cin();
    if(ret == -1)
        return ret;
    return 1;
}

// review function polymorphism
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

//init static value to cal correct answers
int quadrangle::Accuracy = 0;

int main(int argc,char* argv[])
{

    std::cout<<"Practicing. Input negative value to halt"<<std::endl;
    
    //init linklist to save all the given quadrangles
    list<quadrangle*> l; 

    //a loop to give assignments
    while(true)
    {   
        int ret = 0;//get return value

        size_t choice = get_random_value(5);//randomly choose which kinds of quadrangles to display

        switch(choice)
        {
            case 1: //diamond
            {
                diamond *d1 = new diamond(get_random_value(10),get_random_value(10),"diamond");
                ret = dis(*d1);
                if(ret == -1)
                    break;
                l.push_back(d1);
                continue;
                
            }
            case 2: //square
            {
                square *s1 = new square(get_random_value(10),"square");
                ret = dis(*s1);
                if(ret == -1)
                    break;
                l.push_back(s1);
                continue;
            }
            case 3: //rectangle
            {
                rect *r1 = new rect(get_random_value(10),get_random_value(10),"rectangle");
                ret = dis(*r1);
                if(ret == -1)
                    break;
                l.push_back(r1);
                continue;
            }
            case 4: //parallelogram
            {
                para *p1 = new para(get_random_value(10),get_random_value(10),"parallelogram");
                ret = dis(*p1);
                if(ret == -1)
                    break;
                l.push_back(p1);
                continue;
            }
            case 5: //trapezoid
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
        
    auto review = [](auto &&v){re(*v);}; //review lambda func
   
    std::cout<<"Reviewing..."<<std::endl;
   
    l.traverse(review); //traverse the linklist and review
   
   //give total and correct ones
    std::cout<<"Total: "<<l.size()<<", Correct: "<<quadrangle::Accuracy<<std::endl;
   
   //clear the linklist
    l.clear();
    
    
    return 0;

}