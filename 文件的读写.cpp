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
        if(f)//���һ�β���ʱ����Ȼf�޷�<<������a,b,c��Ȼ��ֵ�����Ի��ǻ����һ�Σ���ɶ�һ��
        {
            d = (a+b+c)/3.0f;
            o<<ch<<'\t'<<a<<'\t'<<b<<'\t'<<c<<'\t'<<d<<endl;
        }



    }
    f.close();
    o.close();

    return 0;




}
