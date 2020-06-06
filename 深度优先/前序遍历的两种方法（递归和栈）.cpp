//
// Created by Zhangjun on 2020/6/6.
//


void preOrder(treenode* root){
    if(root){
        cout<<root->val<<endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

void preOrder_stack(treenode* root){
    stack<treenode*> st;
    st.push(root);
    while (st.size()){
        treenode* node = st.top();
        st.pop();
        if (node){
            cout << node->val << endl;
            st.push(node->right);//特别注意下顺序，栈的后进先出原则
            st.push(node->left);
        }
    }
}