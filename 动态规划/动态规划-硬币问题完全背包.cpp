//
// Created by Zhangjun on 2020/3/14.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


//数组版
int absolute_bag(int n,int all_weight, int weight[],int value[])
{
//完全背包
    int* dp = new int[all_weight+1]();//注意整体赋值为0，其他值不行，c++不支持其他值
    for(int i=0;i<=all_weight+1;i++)
        dp[i] = all_weight;
    dp[0] = 0;//注意！！！！！！！！！！！！！
    for (int i = 1; i <=n; i++)
        for (int j = weight[i]; j <=all_weight ;j++)
            dp[j] = min(dp[j],dp[j - weight[i]] + value[i]);

    int res = dp[all_weight];
    delete [] dp;
    return res;
}

//vector版本
int absolute_bag1(int n,int all_weight, vector<int> &weight,vector<int> &value)
{
//完全背包
    vector<int> dp(all_weight + 1, all_weight);
    dp[0] = 0;//注意！！！！！！！！！！！！！
    for (int i = 1; i <=n; i++)
        for (int j = weight[i]; j <=all_weight ;j++)
            dp[j] = min(dp[j],dp[j - weight[i]] + value[i]);

    int res = dp[all_weight];
    return res;
}


int absolute_bag1_1(int n,int all_weight, vector<int> &weight,vector<int> &value)
{
//完全背包
    vector<int> dp(all_weight + 1, all_weight);
    dp[0] = 0;//注意！！！！！！！！！！！！！
    for (int i = 1; i <=n; i++)
        for (int j = weight[i]; j <=all_weight ;j++)
            dp[j] = min(dp[j],dp[j - weight[i]] + value[i]);

    int res = dp[all_weight];
    return res;
}


int func(int N);//测试验证函数

int main(){
    int N,res;
    cin>>N;
    res = func(N);
    cout<<res<<endl;

    int weight[5]{0,1,4,16,64};//第0个不要赋值
    int value[5]{0,1,1,1,1};//第0个不要赋值

    vector<int> weight1{0,1,4,16,64};//第0个不要赋值
    vector<int> value1{0,1,1,1,1};//第0个不要赋值

    int res2,res3;
    res2 = absolute_bag(4,1024-N,weight,value);
    cout<<res2<<endl;
    res3 = absolute_bag1(4,1024-N,weight1,value1);
    cout<<res3<<endl;

    return 0;
}
int func(int N) {
    int num=0;
    if (N == 1024) {
        return 0;
    } else {
        N = 1024 - N;
        int a = 0;
        if (N % 64 == 0) {
            num += N / 64;
            cout << num << endl;
            return num;
        } else {
            num += N / 64;
            N = N - (N / 64) * 64;
        }

        if (N % 16 == 0) {
            num += N / 16;
            cout << num << endl;
            return num;
        } else {
            num += N / 16;
            N = N - (N / 16) * 16;
        }
        if (N % 4 == 0) {
            num += N / 4;
            return num;
        } else {
            num += N / 4;
            N = N - (N / 4) * 4;
        }
        num += N;
        return num;
    }
}