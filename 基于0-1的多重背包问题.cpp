//
// Created by Zhangjun on 2020/3/1.
//

#include<algorithm>
#include <iostream>
#include <vector>
#include<sstream>
using namespace std;

int _0_1_bag(int n,int all_weight, vector<int> &weight,vector<int> &value)
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

// 多重背包问题，转换成0-1背包问题
int main()
{
    string line;
    getline(cin, line);
    stringstream ss0(line);
    int n, all_weight;
    ss0>>n>>all_weight;
    vector<int> weight,value;
    int all_n = 0;
    for(int i=0;i<n;i++){
        getline(cin, line);
        stringstream ss(line);
        int temp_n,temp_value,temp_weight;
        ss>>temp_n;
        all_n+=temp_n;
        ss>>temp_weight>>temp_value;
        for(int j=0;j<temp_n;j++){
            value.push_back(temp_value);
            weight.push_back(temp_weight);
        }
    }
    value.push_back(value.front());
    weight.push_back(weight.front());
    value[0] = 0;
    weight[0] = 0;

    int res;
    res = _0_1_bag(all_n,all_weight,weight,value);
    cout<<res<<endl;
    return 0;
}
// 测试用例
// 2 10
// 3 4 3
// 2 2 5
// 输出 13



//以下代码没有经过测试 部分可解 网上荡的
//#include <iostream>
//using namespace std;
//struct E{
//    int w;  //体积
//    int v;  //重量
//}lis[20005];
//int dp[20005];
//int Max(int a,int b){
//    return a>b?a:b;
//}
//int main(){
//    int n,m;
//    int k,p,value;
//    cin>>m>>n;
//    int index = 0;             //拆分后物品总数
//    for(int i=1;i<=m;i++){
//        cin>>k>>p>>value;          //数量\重量\价值
//        int c = 1;
//        while(k-c>0){                //拆分
//            k -= c;
//            lis[++index].w = c*p;
//            lis[index].v = c*value;
//            c*= 2;
//        }
//        lis[++index].w = p*k;     //补充不足指数的差值
//        lis[index].v = value*k;
//    }
//    for(int i=1;i<=index;i++){   //0-1背包
//        for(int j=n;j>=lis[i].w;j--)
//            dp[j]=Max(dp[j],dp[j-lis[i].w]+lis[i].v);
//    }
//    cout<<dp[n]<<endl;
//    return 0;
//}