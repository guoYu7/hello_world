#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
//硬币分配问题，买了价值为N<1024的商品，用一张1024的纸币去找零，
// 硬币种类weight1{0,1,4,16,64}，请问最少找多少枚硬币


//vector版本-二维形式
int absolute_bag0(int n,int all_weight, vector<int> &weight,vector<int> &value)
{
//完全背包
    vector<vector<int>> dp(n + 1, vector<int>(all_weight + 1, all_weight));
    for(int i=0;i<weight.size();i++)
        dp[i][0] = 0;

    for (int i = 1; i <=n; i++)
        for (int j = 1; j <=all_weight ;j++){
            for(int k=0; k*weight[i] <= j; k++)
                dp[i][j] = min(dp[i-1][j],dp[i-1][j - k*weight[i]] + k*value[i]);
        }
    for(int i=1;i<=n;i++)
        cout<<dp[i][all_weight]<<" ";//含义表示，只考虑weight[1]到weight[i]时，
    cout<<endl;
    // 最少需要多少个硬币

    int res = dp[n][all_weight];
    return res;
}


//vector版本-优化
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

int main(){

    int N=399;

    int weight[5]{0,1,4,16,64};//第0个不要赋值
    int value[5]{0,1,1,1,1};//第0个不要赋值

    vector<int> weight1{0,1,4,16,64};//第0个不要赋值
    vector<int> value1{0,1,1,1,1};//第0个不要赋值

    int res1,res2,res3;
    res1 = absolute_bag0(4,1024-N,weight1,value1);
    cout<<res1<<endl;

    res2 = absolute_bag(4,1024-N,weight,value);
    cout<<res2<<endl;

    res3 = absolute_bag1(4,1024-N,weight1,value1);
    cout<<res3<<endl;

    return 0;
}