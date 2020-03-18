//
// Created by Zhangjun on 2020/3/18.
//

第三题
#include <iostream>
#include <stack>
#include <cstdio>

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
struct point{
    int i;
    int j;

};
point check(vector<vector<int>> &v,int a,int b){
    point p;
    p.i = -1;

    int s  = v[0].size()-1,k1,k2;
    int min_V = (s+1)*(s+1)+1;

    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            k1 = a+i;
            k2 = b+j;
            if(k1<0 || k1>s ||k2<0 || k2>s || v[k1][k2] == 0 || (abs(i) + abs(j) !=1))
                continue;
            if(v[k1][k2]!=1 && v[k1][k2] < min_V){
                p.i = k1;
                p.j = k2;
                min_V = v[k1][k2];
            }
        }
    }
    return p;
}


int f(vector<vector<int>> &v,int num){
    int res = 0,all=0;
    point pp;
    pp.i = 0;
    pp.j = 0;
    while(1){
        if(all == num){
//            cout<<"11111111111"<<endl;
            break;
        }
        pp = check(v,pp.i,pp.j);
        if(pp.i == -1){
            res = -1;
//            cout<<"2222222222"<<endl;
            break;
        }
        //cout<<"("<<pp.i<<","<<pp.j<<")"<<"->";
        if(v[pp.i][pp.j]>1){
            v[pp.i][pp.j] = 1;
            all++;
            //cout<<v[pp.i][pp.j]<<"->";
        }
        res++;
        if(res>v[0].size()*v[0].size() && all < num){
            res = -1;
//            cout<<"33333333333333"<<endl;
            break;
        }
    }
    return  res;
}

int main() {
    vector<vector<int>> v;
    vector<int> v_temp;
    int temp;

    string line;
    int num = 0;
    getline(cin,line);
    stringstream ss(line);
    while(ss>>temp){
        if(temp>1)
            num++;
        v_temp.push_back(temp);
    }
    v.push_back(v_temp);
    v_temp.clear();

    for(int i=0;i<v[0].size()-1;i++){
        getline(cin,line);
        stringstream ss1(line);
        while(ss1>>temp){
            if(temp>1)
                num++;
            v_temp.push_back(temp);
        }
        v.push_back(v_temp);
        v_temp.clear();
    }

    int res=0;
    res = f(v,num);
    cout<<res<<endl;

    return 0;
}

//    测试用例
//    1 2 3
//    0 0 4
//    0 6 0
//    输出-1
//
//    1 2 0
//    0 3 4
//    0 6 5
//    输出5


第二题
#include <iostream>
#include <stack>
#include <cstdio>

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.empty() || matrix[0].empty())
        return 0;

    int row = matrix.size();
    int col = matrix[0].size();
    int maxval=0;
    vector<vector<int>> dp(row+1,vector<int>(col+1));

    for(int i=0;i<=row;++i){
        for(int j=0;j<=col;++j){
            if(i==0||j==0)
                dp[i][j]=0;
            else{
                if(matrix[i-1][j-1]== '1'){
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                    if(dp[i][j]>maxval){
                        maxval=dp[i][j];
                    }
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
    }
    return maxval*maxval;
}
int main() {
    vector<vector<char>> v;
    vector<char> v_temp;
    int m;

    string line;
    char str;
    getline(cin,line);
    stringstream ss(line);
    ss >> m;

    for(int i=0;i<m;i++){
        getline(cin,line);
        for (int j = 0; j < line.size(); ++j) {
            v_temp.push_back(line[j]);
        }
        v.push_back(v_temp);
        v_temp.clear();
    }
    int res;
    res = maximalSquare(v);
    cout<<res<<endl;
    return 0;
}
