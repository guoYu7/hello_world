/**
???????????????????????
?????????????????
????????? ??????????????????1?
https://leetcode-cn.com/problems/balanced-binary-tree/
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
    bool isBalanced(TreeNode* root)
    {
        if(!root)
            return true;
        int l_depth = getdepth(root->left);
        int r_depth = getdepth(root->right);

        if(abs(l_depth-r_depth)>1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int getdepth(TreeNode* node)
    {
        if(!node)
            return 0;

        return 1+max(getdepth(node->left),getdepth(node->right));
    }
};



/**
????????????????
????????????????????????????
https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
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
    int maxDepth(TreeNode* root)
    {
        if(!root)
            return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};

/**
https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/submissions/
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
    int minDepth(TreeNode* root)
    {
        if(!root)
            return 0;
        if(!root->left)
            return 1+minDepth(root->right);
        if(!root->right)
            return 1+minDepth(root->left);
        return 1+min(minDepth(root->left),minDepth(root->right));
    }
};


/**
????????????????????
?????? [1,2,2,3,4,4,3] ?????
    1
   / \
  2   2
 / \ / \
3  4 4  3
???https://leetcode-cn.com/problems/symmetric-tree
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
    bool isSymmetric(TreeNode* root) {
        return ismirror(root,root);

    }

    bool ismirror(TreeNode *p,TreeNode *q)
    {
        if(!p && !q)
            return true;
        if(!p || !q)
            return false;
        if(p->val == q->val)
            return ismirror(p->left,q->right) && ismirror(p->right,q->left);
        return false;
    }
};

/**
????????????????????????
?????????????????????????????????
?? 1:
??:       1         1
          / \       / \
         2   3     2   3
        [1,2,3],   [1,2,3]
??: true
???https://leetcode-cn.com/problems/same-tree
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
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if(!p &&!q)
            return true;
        if(!p || !q)
            return false;

        if(p->val == q->val)
            return isSameTree(p->left,q->left) &&isSameTree(p->right,q->right);

        return false;
    }
};


/**
?????????????????????????
??: ???????????????
??:
??:
   1
 /   \
2     3
 \
  5
??: ["1->2->5", "1->3"]
???https://leetcode-cn.com/problems/binary-tree-paths
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root)
            return {};
        if (!root->left && !root->right)
            return {to_string(root->val)};

        vector<string> left = binaryTreePaths(root->left);
        vector<string> right = binaryTreePaths(root->right);
        left.insert(left.end(), right.begin(), right.end());

        for (auto &a : left)
        {
            a = to_string(root->val) + "->" + a;
        }
        return left;
    }
};