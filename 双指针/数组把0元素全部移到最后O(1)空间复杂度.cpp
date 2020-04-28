//
// Created by Zhangjun on 2020/4/28.
//
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int a[] = {1,0,2,3,0,4,0,4};

    int flag = 0,temp;
    for(int i=0;i<8;i++){
        if(a[i] != 0){
            temp = a[i];
            a[i] = a[flag];
            a[flag++] = temp;
        }
    }

    for(int i=0;i<8;i++)
        cout << a[i] << " ";
    cout<<endl;
}


