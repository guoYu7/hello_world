#include<algorithm>
#include<cassert>
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <string>
using namespace std;

//template <typename T>;
typedef pair<int,int> T;

vector<T> twoSum(vector<int>& u,int target)
{
    unordered_map<int,int> m;
    vector<T> res;
    for(int i=0;i<u.size();i++)
    {
        m[u[i]] = i;
    }


    for(int i=0;i<u.size();i++)
    {
        int t = target - u[i];
        //count()返回要查找的key在map的所有key种
        //的出现次数。因为此容器不允许重复，故count()只可能返回 1 或 0，即可判断此key是否存在。

        if(m.count(t) && m[t]!=i)  //if(m.find(t) != m.end() && m[t]!=i)
        {
            res.push_back(make_pair(m[t],i));

        }
    }
    return res;

}

int main()
{
    string line;
    getline(cin,line);
    stringstream ss(line);

    vector<int> u;
    int temp;
    while (ss>>temp)
    {

        u.push_back(temp);
    }

    getline(cin ,line);
    stringstream ss1(line);
    int target;
    ss1>>target;
    vector<T> res;
    res = twoSum(u,target);

    for(int i=0;i<res.size();i++)
        cout<<res[i].first<<"-"<<res[i].second<<",";
    cout<<endl;
}

/*
给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。
示例 1:
输入: nums = [1,2,3,1], k = 3
输出: true
链接：https://leetcode-cn.com/problems/contains-duplicate-ii
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])!=m.end() && i-m[nums[i]]<=k)
                return true;
            else
                m[nums[i]] = i;
        }
        return false;
        
    }
};

