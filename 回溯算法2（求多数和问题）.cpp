// 题目四
// 给定一个无重复元素的数组 candidates 和一个目标数 target ，
// 找出 candidates 中所有可以使数字和为 target 的组合。
// candidates 中的数字可以无限制重复被选取。

vector<vector<int> > res4;
void combine(int remain,int k,vector<int>& track,vector<int>& nums){
    if(remain == 0){
        res4.push_back(track);
        return;
    }
    int i;
    for(i=k;i<nums.size();i++)
    {
        if(remain<0)
            break;
        track.push_back(nums[i]);
        combine(remain-nums[i],i,track,nums);
        track.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    if(nums.empty())
        return {{}};
    sort(nums.begin(),nums.end());
    vector<int> track;
    combine(target,0,track,nums);
    return res4;
}

//---------------------------------------------
// 题目五
// 给定一个无重复元素的数组 candidates 和一个目标数 target ，
// 找出 candidates 中所有可以使数字和为 target 的组合。
// candidates 中的数字不能重复被选取。

vector<vector<int> > res5;
void combine5(int remain,int k,vector<int>& track,vector<int>& nums){
    if(remain == 0){
        res5.push_back(track);
        return;
    }
    int i;
    for(i=k;i<nums.size();i++)
    {
        if(remain<0)
            break;
        if(i>k && nums[i] == nums[i-1])
            continue;
        track.push_back(nums[i]);
        combine5(remain-nums[i],i+1,track,nums);
        track.pop_back();
    }
}
vector<vector<int>> combinationSum5(vector<int>& nums, int target) {
    if(nums.empty())
        return {{}};
    sort(nums.begin(),nums.end());
    vector<int> track;
    combine5(target,0,track,nums);
    return res5;
}