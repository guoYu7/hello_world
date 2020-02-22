//
// Created by Zhangjun on 2020/2/22.
//

//---------------------------------------------
// 题目四
// 给定一个无重复元素的数组 candidates 和一个目标数 target ，
// 找出 candidates 中所有可以使数字和为 target 的组合。
// candidates 中的数字可以无限制重复被选取。

vector<vector<int> > res4;
void combine(int remain,int k,vector<int>& track,vector<int>& candidates){
    if(remain == 0){
        res4.push_back(track);
        return;
    }
    int i;
    for(i=k;i<candidates.size();i++)
    {
        if(remain<0)
            break;
        track.push_back(candidates[i]);
        combine(remain-candidates[i],i,track,candidates);
        track.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    if(candidates.empty())
        return {{}};
    sort(candidates.begin(),candidates.end());
    vector<int> track;
    combine(target,0,track,candidates);
    return res4;
}

//---------------------------------------------
// 题目五
// 给定一个无重复元素的数组 candidates 和一个目标数 target ，
// 找出 candidates 中所有可以使数字和为 target 的组合。
// candidates 中的数字不能重复被选取。

vector<vector<int> > res5;
void combine5(int remain,int k,vector<int>& track,vector<int>& candidates){
    if(remain == 0){
        res5.push_back(track);
        return;
    }
    int i;
    for(i=k;i<candidates.size();i++)
    {
        if(remain<0)
            break;
        if(i>k && candidates[i] == candidates[i-1])
            continue;
        track.push_back(candidates[i]);
        combine5(remain-candidates[i],i+1,track,candidates);
        track.pop_back();
    }
}
vector<vector<int>> combinationSum5(vector<int>& candidates, int target) {
    if(candidates.empty())
        return {{}};
    sort(candidates.begin(),candidates.end());
    vector<int> track;
    combine5(target,0,track,candidates);
    return res5;
}