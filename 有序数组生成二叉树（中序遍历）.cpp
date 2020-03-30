//
// Created by Zhangjun on 2020/3/30.
//
//有序数组，按中序遍历，生成一个二叉搜索树
treeNode* helper(vector<int> v,int l,int r){
    if(l>r)
        return nullptr;
    int mid = l+(r-l)/2;
    treeNode *cur = new treeNode(v[mid]);
    cur->left = helper(v,l,mid-1);
    cur->right = helper(v,mid+1,r);
    return cur;
}

