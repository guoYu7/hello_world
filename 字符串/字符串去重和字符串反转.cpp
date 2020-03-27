//
// Created by Zhangjun on 2020/3/14.
//
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>

//1. 三个同样的字母连在一起，一定是拼写错误，去掉一个的就好啦：比如 helllo -> hello
//2. 两对一样的字母（AABB型）连在一起，一定是拼写错误，去掉第二对的一个字母就好啦：比如 helloo -> hello
//3. 上面的规则优先“从左到右”匹配，即如果是AABBCC，虽然AABB和BBCC都是错误拼写，
//应该优先考虑修复AABB，结果为AABCC

using namespace std;

void func(string &l1){
    for(int i=2;i<l1.size();i++){
        if(l1[i] == l1[i-1] && l1[i-1] == l1[i-2]){
            l1.erase(i,1);
            i--;
            if(l1.size()<3)
                break;
        }
    }
    for(int i=3;i<l1.size();i++){
        if(l1[i] == l1[i-1] && l1[i-2] == l1[i-3]){
            l1.erase(i,1);
            i--;
            if(l1.size()<4)
                break;
        }
    }
}


#include<iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
//字符串去重
string func(string &line){
    string res;
    bool b[50] = { 0 };

    for (int j = 0; j < line.size(); j++){
        if (b[line[j] - 'a'] == 0){
            res = res + line[j];
            b[line[j] - 'a'] = 1;//重复字符-'a'总是等于相同值，故重复字符对应的布尔值都为1；
        }
    }
    return res;
}









int main(){
    int num;

    vector<string> v;
    string line;
    getline(cin,line);
    stringstream ss(line);
    ss>>num;

    for(int i=0;i<num;i++){
        getline(cin,line);
        func(line);
        v.push_back(line);
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }

    //字符串其他测试(字符串反转)
    char str[] = "hellooooohe";
    char *str1 = new char[strlen(str)+1];//'\0'
    char *p = str;
    int i = strlen(str)-1;
    str1[i+1] = '\0';
    while(*p!='\0'){
        cout<<*p<<" ";
        str1[i--] = *p;
        p++;
    }
    cout<<endl;

    p = str1;
    while(*p!='\0'){
        cout<<*p<<" ";
        p++;
    }
    return 0;
}


