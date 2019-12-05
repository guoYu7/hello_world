#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include<sstream>
#include <string>
#include <map>

using namespace std;

struct point
{
    float x;
    float y;
};

float cal_s_1(vector<point> &u)//s = sqrt(p*(p-a)(p-b)(p-c))
{
    float a,b,c,p;
    float temp_x,temp_y;
    temp_x = pow(u[0].x-u[1].x,2);
    temp_y = pow(u[0].y-u[1].y,2);
    a = sqrt(temp_x+temp_y);

    temp_x = pow(u[0].x-u[2].x,2);
    temp_y = pow(u[0].y-u[2].y,2);
    b = sqrt(temp_x+temp_y);

    temp_x = pow(u[2].x-u[1].x,2);
    temp_y = pow(u[2].y-u[1].y,2);
    c = sqrt(temp_x+temp_y);

    p = (a+b+c)/2.0f;

    float res;
    res = sqrt(p*(p-a)*(p-b)*(p-c));
    return res;

}

float cal_s_2(vector<point> &u)
{
    point ab,bc;
    ab.x = u[0].x-u[1].x;
    ab.y = u[0].y-u[1].y;
    bc.x = u[2].x-u[1].x;
    bc.y = u[2].y-u[1].y;

    return fabs(ab.x*bc.y-ab.y*bc.x)/2.0f;

}






int main()
{
    string line;
    vector<point> p;
    for(int i=0;i<3;i++)
    {
        point temp;
        getline(cin, line);
        stringstream ss(line);
        ss>>temp.x;
        ss>>temp.y;
        p.push_back(temp);
    }

//    for(int i=0;i<3;i++)
//    {
//        cout<<p[i].x<<"-"<<p[i].y<<endl;
//    }
    float res_1,res_2;
    res_1 = cal_s_1(p);
    res_2 = cal_s_2(p);
    cout<<res_1<<" -- "<<res_2<<endl;


    return 0;


}
