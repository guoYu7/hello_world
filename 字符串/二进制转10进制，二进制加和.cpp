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
// 网上找的，可以转任意进制
string str10to_n_good(int n,int radix){
    //n是待转数字，radix是指定的进制任意2~36进制数转化为10进制
    string ans="";
    do{
        int t=n%radix;
        if(t>=0&&t<=9)    ans+=t+'0';
        else ans+=t-10+'a';
        n/=radix;
    }while(n!=0);    //使用do{}while（）以防止输入为0的情况
    reverse(ans.begin(),ans.end());
    return ans;
}
// 自己实现的 10转9进制以内
string str10to_n(int R, int N){
    string str = "";
    int c;
    while (R!=0){   //数制转换，结果存入数组s[m]
        c = R % N;
        R = R / N;
        str = to_string(c) + str;   //将余数按顺序存入数组s[m]中
    }
    return str;
}

int main()
{
    cout << "input data(2) :"<<endl;
    string line;
    getline(cin,line);

    int res;
    res = str2to10(line);
    cout << "str 2 to 10 res = " << res << endl;

    string res1;
    res1 = str10to_n_good(75,16);
    cout << "str 10 to n res = " << res1 << endl;
//    char a = '0',b = '1',c;
//    int a1 = 5,b1 = 3,c1;
//    c1 = a1^b1;
//    cout<<"res2 = "<<c1<<endl;

    return 0;
}


//二进制加和
//#include<iostream>
//using namespace std;
//#define size 8
//int c, sig = 0,location = 8;
////c为存储当前位，sig为进位标志
//void binary_add(int a, int b,int arr[]){
//    //当有进位时：
//    if (sig == 1){
//        //确定当前位
//        c = a^b;
//        //当两位相加后，如果不同：0/1
//        if (c != 1){
//            //相加：或操作
//            c = c | sig;
//            //标志位清除
//            sig = 0;
//        }
//            //两位相加后与sig相同：
//        else{
//            //如果同为1
//            if (c == sig == 1){
//                //异或
//                c = c^sig;
//                //有进位
//                sig = 1;
//            }
//            else{
//                sig = 0;
//            }
//        }
//
//    }
//        //首次进入或者无进位直接异或得出当前位
//    else{
//        c = a^b;
//    }
//    //如果都为1进位
//    if (a == 1 && b == 1){
//        sig = 1;
//    }
//    //cout << c << endl;
//    //将结果存入另一个数组
//    arr[location--] = c;
//}
//int main(){
//    int arr1[size] = { 1, 0, 1, 1, 0, 0, 1, 1 };
//    int arr2[size] = { 0, 1, 0, 1, 1, 0, 1, 1 };
//    int arr[size + 1];
//    for (int i = size - 1; i >= 0; i--){
//        binary_add(arr1[i], arr2[i],arr);
//    }
//    arr[0] = sig;
//
//
////    打印
////    10110011
////    +01011011
////    ----------------
////    100001110
//    cout << " ";
//    for (int i = 0; i <size; i++){
//        cout << arr1[i];
//    }
//    cout << endl;
//    cout << "+";
//    for (int i = 0; i <size; i++){
//        cout << arr2[i];
//    }
//    cout << endl;
//    cout << "----------------"<<endl;
//    for (int i = 0; i <size+1; i++){
//        cout<<arr[i];
//    }
//    cout << endl;
//}


