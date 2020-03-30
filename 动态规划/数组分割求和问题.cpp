//
// Created by Zhangjun on 2020/3/30.
//
//给定一个整型数组，判断能否分割成两部分，使得两部分的和相等

bool dp_func(vector<int> &v){
    int sum = 0;
    for(auto v_:v){
        sum+=v_;
    }
    if(sum%2 != 0)
        return false;
    sum/=2;
    vector<vector<bool>> dp(v.size()+1,vector<bool>(sum+1,false));
    for(int i=0;i<=v.size();i++)
        dp[i][0] = true;

    for(int i=1;i<=v.size();i++){
        for(int j=1;j<=sum;j++){
            if(j-v[i-1] < 0){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j] | dp[i-1][j-v[i-1]];
            }
        }
    }
    return dp[v.size()][sum];
}

bool dp_func_1(vector<int> &v){
    int sum = 0;
    for(auto v_:v){
        sum+=v_;
    }
    if(sum%2 != 0)
        return false;
    sum/=2;
    vector<bool> dp(sum+1,false);
    dp[0] = true;

    for(int i=1;i<=v.size();i++){
        for(int j=sum;j>=0;j--){
            if(j-v[i-1] >= 0)
                dp[j] = dp[j] | dp[j-v[i-1]];
        }
    }
    return dp[sum];
}
