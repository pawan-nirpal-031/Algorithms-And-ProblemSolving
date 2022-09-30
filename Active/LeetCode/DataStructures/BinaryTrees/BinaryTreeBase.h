class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(){
        val =0; 
        left = right = nullptr;
    }

    TreeNode(int val){
        this->val = val; 
        left = right = nullptr;
    }
};

TreeNode * ExampleTree1(){
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    return root;
    /* 
            5 
          4   8 
        11   13 4 
       7  2       1

    */
}