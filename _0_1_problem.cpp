#include<algorithm>
#include <iostream>
#include <vector>
#include<sstream>

using namespace std;
//    int MAXN = 10005;

int _0_1_bag(int n,int all_weight, vector<int> weight,vector<int> value)
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


int absolute_bag(int n,int all_weight, vector<int> weight,vector<int> value)
{
//    完全背包
//    一般版本
//    vector<vector<int>> dp0(n + 1, vector<int>(all_weight + 1, 0));
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= all_weight; j++) {
//            for (int k = 0; k * weight[i] <= j; k++) {
//                dp0[i][j] = max(dp0[i - 1][j], dp0[i - 1][j - k * weight[i]] + k * value[i]);
//            }
//        }
//    }
//    return dp0[n][all_weight];


    //优化版本
    vector<int> dp(all_weight + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = weight[i]; j <= all_weight; j++)
        {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    return dp[all_weight];



}

int main()
{

    string line;
    getline(cin, line);
    stringstream ss0(line);
    int n,temp, all_weight;
    ss0>>n>>all_weight;

    vector<int> value(n+1,0),weight(n+1,0);

    getline(cin, line);
    stringstream ss(line);
    for(int i=1;i<=n;i++)
    {
        ss>>temp;

        value[i] = temp;
    }

    getline(cin, line);
    stringstream ss1(line);
    for(int i=1;i<=n;i++)
    {
        ss1>>temp;
        weight[i] = temp;
    }

    int res;
    res = _0_1_bag(n,all_weight,weight,value);
    cout<<"0-1: "<<res<<endl;

    res = absolute_bag(n,all_weight,weight,value);
    cout<<"完全: "<<res<<endl;

    return 0;

}


// https://github.com/skyerhxx/Test-Data-of-01-knapsack-problem-/tree/master/%E6%B5%8B%E8%AF%95%E6%95%B0%E6%8D%AE
//0-1test case:
//input:
//    5 10
//    1 2 3 4 5
//    5 4 3 2 1
//output:
//    14


//0-1test case:
//input:
//    5 100
//    92 22 87 46 90
//    77 22 29 50 99
//output:
//    133


//0-1test case:
//input:
//    8 200
//    83 14 54 79 72 52 48 62
//    79 58 86 11 28 62 15 68
//output:
//    334


//完全背包test case:
//input:
//    5 100
//    92 22 87 46 90
//    77 22 29 50 99
//output:
//    261




