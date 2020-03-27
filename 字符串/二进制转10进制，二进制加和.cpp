//
// Created by Zhangjun on 2020/3/27.
//

#include<iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int str2to10(string line){
    int value = 0;
    for (int i = line.size()-1; i >= 0;i --)
    {
        int j = line.size()-i-1;

        if(line[i] != '0' && line[i] != '1'){
            cout<<" error input!!"<<endl;
            return 0;
        }

        if (line[i] == '1')
            value += static_cast<int>(pow(2,j)); //强制把double 类型数据 转化为int  类型。
    }
    return value;
}


string func(string str1, string str2){
    char sig = '0',temp,a,b,c;
    string res = "";
    for(int i=str1.size()-1;i>=0;i--){
        a = str1[i];
        b = str2[i];

        res = c + res;
        if(sig == '1'){
            temp = a^b;//看看是不是相同
            if(temp == '1')//不相同
            {
                res = '0'+ res;
                sig = '1';
            }
            else{//相同
                if(a == b == '1'){
                    res = '1'+ res;
                    sig = '1';
                }
                else{
                    res = '1'+ res;
                    sig = '0';
                }
            }
        }
        else{//sig == '0'
            if(a == b == '1'){
                res = '0'+ res;
                sig = '1';
            }
            else{
                c = a|b;
                res = c + res;
                sig = '0';
            }
        }
    }
}



int main()
{


    cout << "input data:"<<endl;

    string line;
    getline(cin,line);

    int res;
    res = str2to10(line);
    cout << "res = " << res << endl;

    string l1 = "101";
    string l2 = "011";

    l1 = func(l1,l2);
    //cout<<"l1 = "<<l1<<endl;
    char a = '0',b = '1',c;
    int a1 = 5,b1 = 3,c1;
    c1 = a1^b1;

    cout<<"res2 = "<<c1<<endl;

    return 0;
}


//二进制加和
#include<iostream>
using namespace std;
#define size 8
int c, sig = 0,location = 8;
//c为存储当前位，sig为进位标志
void binary_add(int a, int b,int arr[]){
    //当有进位时：
    if (sig == 1){
        //确定当前位
        c = a^b;
        //当两位相加后，如果不同：0/1
        if (c != 1){
            //相加：或操作
            c = c | sig;
            //标志位清除
            sig = 0;
        }
            //两位相加后与sig相同：
        else{
            //如果同为1
            if (c == sig == 1){
                //异或
                c = c^sig;
                //有进位
                sig = 1;
            }
            else{
                sig = 0;
            }
        }

    }
        //首次进入或者无进位直接异或得出当前位
    else{
        c = a^b;
    }
    //如果都为1进位
    if (a == 1 && b == 1){
        sig = 1;
    }
    //cout << c << endl;
    //将结果存入另一个数组
    arr[location--] = c;
}
int main(){
    int arr1[size] = { 1, 0, 1, 1, 0, 0, 1, 1 };
    int arr2[size] = { 0, 1, 0, 1, 1, 0, 1, 1 };
    int arr[size + 1];
    for (int i = size - 1; i >= 0; i--){
        binary_add(arr1[i], arr2[i],arr);
    }
    arr[0] = sig;
    cout << " ";
    for (int i = 0; i <size; i++){
        cout << arr1[i];
    }
    cout << endl;
    cout << "+";
    for (int i = 0; i <size; i++){
        cout << arr2[i];
    }
    cout << endl;
    cout << "----------------"<<endl;
    for (int i = 0; i <size+1; i++){
        cout<<arr[i];
    }
    cout << endl;
}


