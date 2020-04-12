//
// Created by Zhangjun on 2020/4/12.
//
// 找出成对的括号，输出成对对数，单左括号数，单右括号数
#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;
int a=0,b=0,c=0;
bool Judge(string str) {  //使用栈判断括号匹配
    stack <char> s;
    for (int i = 0; i < str.length(); i++) {
        switch (str[i]) {
            case '(':
                s.push('(');
                break;
            case ')':
                if (!s.empty()) {
                    s.pop();
                    a++;
                }
                else {
                    c++;
                }
                break;
        }
    }
    if (!s.empty()) {
        b = s.size();
    }
}

int main() {
    string str;
    getline(cin,str);
    Judge(str);
    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
    return 0;
}
/*
输出 1*2+(3+3)))(((
输出 1 2 3
*/

// 输入一个整数R和N，将R分解为N进制，要求各次幂不重复（系数为1）
class Solution {
public:
    /**
     * 返回无重复幂因子的 N进制完美数之和的所有幂因子
     * @param R int整型
     * @param N int整型 N进制
     * @return int整型vector
     */
    vector<int> GetPowerFactor(int R, int N) {
        // write code here
        vector<int> v;
        int c,n;
        while (R!=0)//数制转换，结果存入数组s[m]
        {
            c=R%N;
            R=R/N;
            //m++;
            if(c<=1)
                v.push_back(c);   //将余数按顺序存入数组s[m]中
            else{
                v.clear();
                break;
            }
        }
        vector<int> res;
        for(int i=0;i<v.size();i++){
            if(v[i]==1)
                res.push_back(i);
        }
        return res;
    }
};


