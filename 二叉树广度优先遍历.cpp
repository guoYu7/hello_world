/**
����һ���������������䰴��α����Ľڵ�ֵ�� �������أ������ҷ������нڵ㣩��
����:
����������:�0�2[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

https://leetcode-cn.com/problems/binary-tree-level-order-traversal/

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int> > u;
        if(!root)
            return u;
        
        queue<TreeNode*> q;
        
        q.push(root);  
        
        while(!q.empty())
        {
            vector<int> v;
            for(int i=q.size();i>0;i--)
            {
                TreeNode *temp = q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                
            }            
            u.push_back(v);            
        }
        return u;        
    }
};
