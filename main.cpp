#include "Ex.cpp"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;

void dis(quadrangle& obj)
{
    obj.info_cin();
}
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
    string s1 = "rectangle";
    rect r1(get_random_value(10),get_random_value(10),s1);
    dis(r1);
    string s2 = "diamond";
    diamond d1(get_random_value(10),get_random_value(10),s2);
    //cout<<d1.get_area();
    dis(d1);
    string s3 = "square";
    square sq1(get_random_value(10),s3);
    dis(sq1);
    string s4 = "parallelogram";
    para p1(get_random_value(10),get_random_value(10),s4);
    dis(p1);
    string s5 ="trapezoid";
    trapezoid t1(get_random_value(10),get_random_value(10),get_random_value(10),s5);
    dis(t1);
    return 0;

}