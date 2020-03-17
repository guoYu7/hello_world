//
// Created by Zhangjun on 2020/3/15.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

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

int fun0_1(int n,int all_weight, vector<int> weight,vector<int> value)
{
//0-1背包

//一般版本
//    vector<vector<int>> dp0(n + 1, vector<int>(all_weight + 1, 0));
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= all_weight; j++)
//        {
//            if(weight[i] <= j)
//                dp0[i][j] = max(dp0[i - 1][j], dp0[i - 1][j - weight[i]] + value[i]);
//            else
//                dp0[i][j] = dp0[i - 1][j];
//        }
//    }
//    return dp0[n][all_weight];

    //优化版本
    vector<int> dp(all_weight + 1, 0);
    for (int i = 1; i <=n; i++)
        for (int j = all_weight; j >= weight[i];j--)
            dp[j] = max(dp[j],dp[j - weight[i]] + value[i]);
    return dp[all_weight];
}

int main(){
    int D,W,temp;
    vector<int> position,supply;
    string line;
    getline(cin,line);
    stringstream ss(line);
    ss>>D,W;

    getline(cin,line);
    stringstream ss1(line);
    while(ss1>>temp){
        position.push_back(temp);
    }

    getline(cin,line);
    stringstream ss2(line);
    while(ss2>>temp){
        supply.push_back(temp);
    }
    position.push_back(position.front());
    supply.push_back(supply.front());

    vector<int> value(supply.size(),1);



    int res3;

    res3 = fun0_1(position.size(),D,weight1,value1);
    cout<<res3<<endl;

    return 0;
}
