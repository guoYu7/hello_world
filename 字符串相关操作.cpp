//
// Created by Zhangjun on 2020/3/14.
//
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(){
//    C风格字符串：
//    C风格字符串初始化
    char greeting[]="Hello";  //字符串初始化用双引号，字符初始化用单引号
    cout<<greeting<<endl;     //打印Hello

//    strcpy(s1,s2); 复制到目标字符串
//    strcat(s1, s2); 连接两个字符串
//    strlen(s1); //返回s1的长度（不加’\0’）sizeof(s1)返回字符串数组大小
//    strcmp(s1, s2); //如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回值小于 0；如果 s1>s2 则返回值大于 0。
//    strchr(s1, ch); //返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。
//    strstr(s1, s2); //返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置。

    // 尾插一个字符
    s1.push_back('a');
    s1.push_back('b');
    s1.push_back('c');
    cout<<"s1:"<<s1<<endl; // s1 = abc
    // insert(pos,char):在制定的位置pos前插入字符char
    s1.insert(s1.begin(),'1');// s1 = 1abc

    //erase()
    string s1 = "123456789";
    // s1.erase(s1.begin()+1);              // 结果：13456789
    // s1.erase(s1.begin()+1,s1.end()-2);   // 结果：189
    s1.erase(1,6);     删除1位开始后面6个字符 // 结果：189

    //迭代器
    string::iterator iter = s1.begin();
    while( iter != s1.end() )
    {
        cout<<*iter;
        *iter++;
    }
    cout<<endl;

    //find()
    // string s1 = "abcdddecfgh";
    // 2. 从下标为3开始找字符'c'，返回找到的第一个i的下标
    cout << s.find('c',3) << endl;            // 结果是：7


    //sort排序
    string s = "cdefba";
    sort(s.begin(),s.end());
    cout<<"s:"<<s<<endl;     // 结果：abcdef


    string s="abcdefg";
    string s1=s.substr(1,3);   //bcd
    string s2=s.substr(4);     //efg

}
