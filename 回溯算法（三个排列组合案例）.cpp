//
// Created by Zhangjun on 2020/2/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator> // for ostream_iterator<>
#include <ctime>
#include <algorithm>
using namespace std;
template <class T>
void show(const T& x){cout << x << " ";}

//问题很简单，输入一个不包含重复数字的数组，要求算法输出这些数字的所有子集。
//vector<vector<int>> subsets(vector<int>& nums);
//比如输入 nums = [1,2,3]，你的算法应输出 8 个子集，包含空集和本身，顺序可以不同：
//[ [],[1],[2],[3],[1,3],[2,3],[1,2],[1,2,3] ]

//  方法1 回溯算法
//  回溯算法模板
//  result = []
//  def backtrack(路径, 选择列表):
//  if 满足结束条件:
//  result.add(路径)
//  return
//  for 选择 in 选择列表:
//  做选择
//        backtrack(路径, 选择列表)
//  撤销选择

vector<vector<int>> res;

void backtrack(vector<int>& nums, int start, vector<int>& track) {
    res.push_back(track);
    // 注意 i 从 start 开始递增
    for (int i = start; i < nums.size(); i++) {
        // 做选择
        track.push_back(nums[i]);
        // 回溯
        backtrack(nums, i + 1, track);
        // 撤销选择
        track.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> track;// 记录走过的路径
    backtrack(nums, 0, track);
    return res;
}

//方法2 递归算法
vector<vector<int> > dfs(vector<int>& nums){
    if(nums.empty())
        return {{}};
    int n = nums.back();
    nums.pop_back();
    vector<vector<int> > res = dfs(nums);
    int size = res.size();
    for(int i=0;i<size;i++){
        res.push_back(res[i]);
        res.back().push_back(n);
    }
    return res;
}

// ----------------------------------------------------
// 组合问题
// 输入一个不包含重复数字的数组 nums,，算法输出 nums 中 k 个数字的所有组合。
//vector<vector<int>> combine(vector<int> nums, int k);
//比如输入 nums = {1,2,3,4}, k = 2，输出如下结果，顺序无所谓，
//但是不能包含重复（按照组合的定义，[1,2] 和 [2,1] 也算重复）：
//        [
//        [1,2],
//        [1,3],
//        [1,4],
//        [2,3],
//        [2,4],
//        [3,4]
//        ]
//这就是典型的回溯算法，k 限制了树的高度，n 限制了树的宽度，直接套我们以前讲过的回溯算法模板框架就行了：

vector<vector<int> > res2;
void backtrack2(vector<int>& nums,int k,int start, vector<int>& track){
    if(track.size() == k){
        res2.push_back(track);
        return;
    }
    for(int i = start; i < nums.size(); i++){
        track.push_back(nums[i]);
        backtrack2(nums,k,i+1,track);
        track.pop_back();
    }
}

vector<vector<int> > combine(vector<int> nums,int k){
    if(nums.size() <= 0 || k <= 0)
        return {{}};
    vector<int> track;
    backtrack2(nums,k,0,track);
    return res2;
}

// ----------------------------------------------------
//    排列问题
//    输入一个不包含重复数字的数组 nums，返回这些数字的全部排列。
//    vector<vector<int>> permute(vector<int>& nums);
//    比如说输入数组 [1,2,3]，输出结果应该如下，顺序无所谓，不能有重复：
//    [
//    [1,2,3],
//    [1,3,2],
//    [2,1,3],
//    [2,3,1],
//    [3,1,2],
//    [3,2,1]
//    ]


vector<vector<int> > res3;
void backtrack3(vector<int>& nums, vector<int>& track){
    if(track.size() == nums.size()){
        res3.push_back(track);
        return;
    }
    for(int i = 0; i < nums.size(); i++){
        if(find(track.begin(),track.end(),nums[i])!=track.end())
            continue;
        track.push_back(nums[i]);
        backtrack3(nums,track);
        track.pop_back();
    }
}

vector<vector<int> > permute(vector<int> nums){
    if(nums.empty())
        return {{}};
    vector<int> track;
    backtrack3(nums,track);
    return res3;
}


int main() {
    // 第一个问题测试
    vector<int> v{1,2,3};
    vector<vector<int> > res;
    res = subsets(v);
//    res = dfs(v);

    for(int i = 0; i < res.size(); i++ ){
        cout <<"[";
        copy(res[i].begin(),res[i].end(),ostream_iterator<int>(cout," "));
        //for_each(res[i].begin(),res[i].end(),show<int>);
        cout <<"]";
    }


    // 组合问题测试
    cout<<endl<<"combine:"<<endl;
    vector<int> v2{1,2,3};
    vector<vector<int> > res2;

    res2 = combine(v2,2);
    for(int i = 0; i < res2.size(); i++ ){
        cout <<"[";
        copy(res2[i].begin(),res2[i].end(),ostream_iterator<int>(cout," "));
        cout <<"]";
    }

    // 排列问题测试
    cout<<endl<<"permute"<<endl;
    vector<int> v3{1,2,3};
    vector<vector<int> > res3;
    res3 = permute(v3);
    for(int i = 0; i < res3.size(); i++ ){
        cout <<"[";
        copy(res3[i].begin(),res3[i].end(),ostream_iterator<int>(cout," "));
        cout <<"]";
    }

    return 0;
}


//    clock_t t0;
//    t0 = clock();
//    res = subsets(v);
//    //res = dfs(v);
//    cout<<"time is "<<double(clock()-t0)/CLOCKS_PER_SEC<<" s"<<endl;