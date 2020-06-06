//
// Created by Zhangjun on 2020/4/19.
//
#include<iostream>
#include<vector>
#include<math.h>
#include <string>
#include <sstream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

void insert(TreeNode* node,vector<int> &arr,int i){
    int len=(int)arr.size();
    if(i>=len)					//访问到数组末尾时跳出
        return;
    node->val=arr[i];			//赋值给该节点

    if(2*(i+1)-1 <= len-1){		//如果该节点的左子节点可以赋值，即数组长度足够给左子节点赋值
        TreeNode* l=new TreeNode(NULL);	//创建左子节点
        node->left=l;				//将该节点指向新创建的左子节点
        insert(l,arr,2*(i+1)-1);	//递归赋值
    }

    if(2*(i+1) <= len-1){		//如果该节点的右子节点可以赋值，即数组长度足够给右子节点赋值
        TreeNode* r=new TreeNode(NULL);	//创建右子节点
        node->right=r;				//将该节点指向新创建的右子节点
        insert(r,arr,2*(i+1));		//递归赋值
    }
}

//创建树的根节点，调用insert()为根节点添加子节点
TreeNode* ConTree(vector<int> arr){
    TreeNode* node=new TreeNode(NULL);
    insert(node,arr,0);
    return node;
}

void inOrder(TreeNode* node){
    if(node==NULL)				//若节点为空，跳出
        return;
    //cout<<node->val<<" ";
    inOrder(node->left);		//查看是否有左子节点，若有，递归查看
    cout<<node->val<<" ";		//无左子节点，打印该节点
    inOrder(node->right);		//查看是否有右子节点，若有，递归查看
}

int main(){
    vector<int> arr;
    int n;  //层数

    //输入该完全二叉树的层数
    string line0;
    getline(cin,line0);
    stringstream ss0(line0);
    ss0>>n;
    //输入二叉树的节点（按层次遍历顺序输入）
    string line;
    getline(cin,line);
    stringstream ss(line);
    int temp;
    while(ss>>temp)
        arr.push_back(temp);

    int index0,index1;
    index0 = pow(2,n)-1;	 //完全二叉树的节点数等于层次数的n次方-1
    index1 = pow(2,n-1)-1;
    if(!(n > index0 && n <= index1))
        return -1;

    TreeNode* root=ConTree(arr);
    inOrder(root);//中序遍历
    cout<<endl;
    return 0;
}

