//
// Created by Zhangjun on 2020/6/6.
//
二叉树序列化可以基于先序/中序/后序/按层等遍历方式进行。

现输入二叉树层次遍历序列，请输出其前序遍历序列。

如有二叉树如下：
0
/ \
1   2
/     \
3       4
\     /
5   6
其层次遍历序列为：0, 1, 2, 3, #, #, 4, #, 5, 6, #
其先序遍历序列为：0, 1, 3, #, 5, #, #, #, 2, #, 4, 6, #, #, #
（其中空用"#"代替）

输入描述:
第一行输入数字N为层次遍历结点个数
        接下来以层次遍历顺序输入N行节点的值（空用"#"代替）
输出描述:
先序遍历结果（空打印为"#"）
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
输出
0
1
3
#
5
#
#
#
2
#
4
6
#
#
#

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct treenode{
    string val;
    treenode *left,*right;
    treenode(string x):val(x),left(NULL),right(NULL){};
};

void preOrder(treenode* root){
    if(root){
        cout<<root->val<<endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}


int main(){
    int n;
    cin>>n;
    string value[n];
    for(int i=0;i<n;i++)
        cin>>value[i];

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

    stack<treenode*> st;

    st.push(root);
    while (st.size()){
        treenode* node = st.top();
        st.pop();
        if (!node)
            cout << "#" << endl;
        else{
            cout << node->val << endl;
            st.push(node->right);
            st.push(node->left);
        }
    }

    // preOrder(root);
    return 0;
}



/*
const int N = 1e5 + 10;
int root = 1, idx = 1;
struct node
{
    int l, r;
    string val;
};
node tr[N];
queue< node* > q;
string tree[N];
stack<node*> st;

void addnode(node* root, string val, int opt){
    //着重解释  opt 的含义   如果是  1   代表将她插入到   root 的左树中，2  代表插入到右树中
    int u = ++idx;
    if (opt == 1){
        root->l = u;
    }
    else{
        root->r = u;
    }
    tr[u].l = tr[u].r = 0;    //作为一个新的节点  左右两树应该置位空
    tr[u].val = val;
}

void output()
{
    st.push(&tr[1]);
    while (st.size())
    {
        node* t = st.top();
        st.pop();
        if (t->val.size() == 0)
            cout << "#" << endl;
        else
        {
            cout << t->val << endl;
            st.push(&tr[t->r]);
            st.push(&tr[t->l]);
        }

    }
}
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    tr[root].l = tr[root].r = 0;
    tr[root].val = s;

    q.push(&tr[root]);

    for (int i = 2; i <= n; i++)
        cin >> tree[i];    //规定  1是根节点，所以从2 开始
    int cur = 2;

    while (q.size()){  //如果写成   while(true)   会发生段错误
        node* t = q.front();
        q.pop();

        string l = tree[cur++];
        if (l != "#"){
            addnode(t, l, 1);
            q.push(&tr[t->l]);
        }
        if (cur > n)
            break;   //坑 ：注意如果  这个下标已经超过 n  那么已经说明所有节点遍历完了，不要继续了

        string r = tree[cur++];
        if (r != "#"){
            addnode(t, r, 2);
            q.push(&tr[t->r]);
        }
        if (cur > n)
            break;
    }
    output();
    return 0;
}
 */
