//
// Created by Zhangjun on 2020/3/14.
//

//首先区分三种二叉树，第一种普通二叉树，第二种完全二叉树（所有节点全靠左，满足紧凑），
//                第三种满二叉树
//
//
//
//
//普通二叉树
public int countNodes(TreeNode root) {
    if (root == null) return 0;
    return 1 + countNodes(root.left) + countNodes(root.right);
}

//满二叉树 2^h - 1，设法求深度即可
public int countNodes(TreeNode root) {
    int h = 0;
    // 计算树的高度
    while (root != null) {
        root = root.left;
        h++;
    }
    // 节点总数就是 2^h - 1
    return (int)Math.pow(2, h) - 1;
}
//完全二叉树最特殊
public int countNodes(TreeNode root) {
    TreeNode l = root, r = root;
    // 记录左、右子树的高度
    int hl = 0, hr = 0;
    while (l != NULL) {
        l = l.left;
        hl++;
    }
    while (r != NULL) {
        r = r.right;
        hr++;
    }
    // 如果左右子树的高度相同，则是一棵满二叉树
    if (hl == hr) {
        return (int)Math.pow(2, hl) - 1;
    }
    // 如果左右高度不同，则按照普通二叉树的逻辑计算
    return 1 + countNodes(root.left) + countNodes(root.right);
}

