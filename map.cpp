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
