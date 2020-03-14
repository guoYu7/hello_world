//
// Created by Zhangjun on 2020/3/14.
//
//1. 我们在字节跳动大街的N个建筑中选定3个埋伏地点。
//2. 为了相互照应，我们决定相距最远的两名特工间的距离不超过D。
//请听题：给定N（可选作为埋伏点的建筑物数）、D（相距最远的两名特工间的距离的最大值）以及可选建筑的坐标，计算在这次行动中，大锤的小队有多少种埋伏选择。
//注意：
//1. 两个特工不能埋伏在同一地点
//2. 三个特工是等价的：即同样的位置组合(A, B, C) 只算一种埋伏方法，不能因“特工之间互换位置”而重复使用
//
//第一行包含空格分隔的两个数字 N和D(1 ≤ N ≤ 1000000; 1 ≤ D ≤ 1000000)
//第二行包含N个建筑物的的位置，每个位置用一个整数（取值区间为[0, 1000000]）表示，从小到大排列（将字节跳动大街看做一条数轴）
//输出描述:
//一个数字，表示不同埋伏方案的数量。结果可能溢出，请对 99997867 取模
//输入例子1:
//4 3
//1 2 3 4
//输出例子1:
//4
//例子说明1:
//可选方案 (1, 2, 3), (1, 2, 4), (1, 3, 4), (2, 3, 4)
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <stdlib.h>
#include <iterator>
using namespace std;

bool check(vector<int> v,int D){
    if(abs(v[0]-v[1])<=D && abs(v[1]-v[2])<=D && abs(v[0]-v[2])<=D )
        return true;
    else
        return false;
}

vector<vector<int> > res2;
void backtrack2(vector<int>& nums,int k,int start, vector<int>& track,int D){
    if(track.size() == k ){
        if(check(track,D))
            res2.push_back(track);
        return;
    }
    for(int i = start; i < nums.size(); i++){
        track.push_back(nums[i]);
        backtrack2(nums,k,i+1,track,D);
        track.pop_back();
    }
}

vector<vector<int> > combine(vector<int> nums,int k,int D){
    if(nums.size() <= 0 || k <= 0)
        return {{}};
    vector<int> track;
    backtrack2(nums,k,0,track, D);
    return res2;
}

int main(){
    string line;
    getline(cin,line);
    stringstream ss(line);
    int N,D;
    ss>>N>>D;
    getline(cin,line);
    stringstream ss0(line);
    int temp;
    vector<int> v;

    for(int i=0;i<N;i++){
        ss0>>temp;
        v.push_back(temp);
    }
    vector<vector<int> > track;
    track = combine(v,3,D);
    cout<<track.size()<<endl;

    for(int i = 0; i < res2.size(); i++ ){
        cout <<"[";
        copy(res2[i].begin(),res2[i].end(),ostream_iterator<int>(cout," "));
        cout <<"]";
    }

}



