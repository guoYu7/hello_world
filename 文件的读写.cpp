#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("/home/zj/Desktop/file/data.txt");

    char ch[20];
    float a,b,c,d;


    ofstream o("/home/zj/Desktop/file/data_d.txt");

    if(!f || !o)
        return -1;

    while(f)
    {
        f>>ch>>a>>b>>c;
        if(f)//最后一次操作时，虽然f无法<<，但是a,b,c仍然有值，所以还是会计算一次，造成多一行
        {
            d = (a+b+c)/3.0f;
            o<<ch<<'\t'<<a<<'\t'<<b<<'\t'<<c<<'\t'<<d<<endl;
        }



    }
    f.close();
    o.close();

    return 0;




}
