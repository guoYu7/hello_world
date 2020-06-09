//
// Created by Zhangjun on 2020/6/9.
//
#include<iostream>
#include<queue>
#include<stack>
#include <list>
//根据层序遍历结果，恢复二叉树，
// 然后，调用getNode函数，将目标点所在的路径找出来，并打印


using namespace std;

struct treenode{
    string val;
    treenode *left,*right;
    treenode(string x):val(x),left(NULL),right(NULL){};
};

bool getNode(treenode* root, string p,list<treenode*> &l){
    l.push_back(root);
    if(root->val == p)
        return true;
    bool flag = false;
    if(root->left)
        flag = getNode(root->left,p,l);
    if(root->right && !flag)
        flag = getNode(root->right,p,l);
    if(!flag)
        l.pop_back();
    return flag;
}

int main(){
//    int n;
//    cin>>n;
//    string value[n];
//    for(int i=0;i<n;i++)
//        cin>>value[i];

    string value[11] = {            "0",
                                    "1","2",
                                    "3","#","#","4",
                                    "#","5",     "6","#"};
    int n = 11;

    if(n == 0){
        cout<<"#"<<endl;
        return 0;
    }

    queue<treenode*> q;
    treenode *root = new treenode(value[0]);
    q.push(root);

    int cur = 1;//第0个已经取出来了
    string c_value;
    while(!q.empty()){
        treenode *temp = q.front();
        q.pop();

        c_value = value[cur++];
        if(c_value != "#"){
            treenode *node = new treenode(c_value);
            temp->left = node;
            q.push(node);
        }

        if( cur >= n)
            break;

        c_value = value[cur++];
        if(c_value != "#" ){
            treenode *node = new treenode(c_value);
            temp->right = node;
            q.push(node);
        }
        if( cur >= n)
            break;
    }

    list<treenode* > l;
    bool found;
    string s = "6";
    found = getNode(root,s,l);
    list<treenode*>::iterator it;
    for(it = l.begin();it!=l.end();it++ )
        cout<<(*it)->val<<endl;
    return 0;
}
/*
示例1
11
0
1
2
3
#
#
4
#
5
6
#
 */


