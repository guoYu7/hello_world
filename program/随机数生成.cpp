//
// Created by Zhangjun on 2020/3/14.
//
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<iostream>
#define N 10
#define M 1010
using namespace std;
int main()
{
    double num,i;
    srand((unsigned int)time(NULL));//产生随机数的种子
    cout<<RAND_MAX<<endl;
    for(i=1;i<=N;i++)
    {
        num= (double)(rand()%10000)/10000;//产生随机数
        cout<<num<<endl;
    }

}
