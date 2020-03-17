/*
给定一个整数数组，判断是否存在重复元素。
如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
示例 1:

输入: [1,2,3,1]
输出: true

链接：https://leetcode-cn.com/problems/contains-duplicate
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]] +=1;
            
            if(m[nums[i]]>=2)
                return true;
        }
        
        return false;
    }
};


#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using  namespace std;

int main() {
    map<int, int> m;
    vector<int> u{2, 3, 4, 2, 2, 2, 2, 11, 1, 2, 3, 4, 5};
    for (int i = 0; i <= u.size(); i++) {
        m[u[i]]++;
    }
    m.insert(make_pair(2222,3));

    map<int, int>::iterator it = m.find(2);

    cout << it->first << " " << it->second << endl;
    cout << m.size() << endl;
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}

//字节跳动 颜色问题（最小间距限制）
#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using  namespace std;

int main() {
    map<int,vector<int>> mm;
    string line;
    getline(cin,line);
    stringstream ss(line);
    int n,m,c;
    ss>>n>>m>>c;

    for(int i=1;i<=n;i++){
        getline(cin,line);
        stringstream ss1(line);
        int num;
        ss1>>num;
        int temp;
        for(int j=0;j<num;j++){
            ss1>>temp;
            mm[temp].push_back(i);
        }
    }
    int res=0;

    for(int k = 1;k <= c; k++ ){
        //判断头尾是否相连
        if(mm[k][0]+n-mm[k][mm[k].size()-1] < m){
            res++;
            continue;
        }
        for(int s = 1;s<mm[k].size();s++){
            if(mm[k][s]-mm[k][s-1] < m){
                res++;
                break;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}