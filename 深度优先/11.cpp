//
// Created by Zhangjun on 2020/6/6.
//

//
// Created by Zhangjun on 2020/6/6.
//


/**
给定一个二叉树，判断它是否是高度平衡的二叉树 。
本题中，一棵高度平衡二叉树定义为：
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
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
给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
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
给定一个二叉树，检查它是否是镜像对称的。
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
    1
   / \
  2   2
 / \ / \
3  4 4  3
链接：https://leetcode-cn.com/problems/symmetric-tree
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
给定两个二叉树，编写一个函数来检验它们是否相同。
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
示例 1:
输入:       1         1
          / \       / \
         2   3     2   3
        [1,2,3],   [1,2,3]
输出: true
链接：https://leetcode-cn.com/problems/same-tree
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
给定一个二叉树，返回所有从根节点到叶子节点的路径。
说明: 叶子节点是指没有子节点的节点。
示例:
输入:
   1
 /   \
2     3
 \
  5
输出: ["1->2->5", "1->3"]
链接：https://leetcode-cn.com/problems/binary-tree-paths
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