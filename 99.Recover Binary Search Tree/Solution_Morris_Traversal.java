void inorderMorrisTraversal(TreeNode *root) {
    TreeNode *cur = root, *prev = NULL;
    while (cur != NULL)
    {
        if (cur->left == NULL)          // 1.
        {
            printf("%d ", cur->val);
            cur = cur->right;
        }
        else
        {
            // find predecessor
            prev = cur->left;
            while (prev->right != NULL && prev->right != cur)
                prev = prev->right;

            if (prev->right == NULL)   // 2.a)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else                       // 2.b)
            {
                prev->right = NULL;
                printf("%d ", cur->val);
                cur = cur->right;
            }
        }
    }
}

public void recoverTree(TreeNode root) {
    TreeNode pre = null;
    TreeNode first = null, second = null;
    // Morris Traversal
    TreeNode temp = null;
    while(root!=null){
        if(root.left!=null){
            // connect threading for root
            temp = root.left;
            while(temp.right!=null && temp.right != root)
                temp = temp.right;
            // the threading already exists
            if(temp.right!=null){
                if(pre!=null && pre.val > root.val){
                    if(first==null){first = pre;second = root;}
                    else{second = root;}
                }
                pre = root;
                
                temp.right = null;
                root = root.right;
            }else{
                // construct the threading
                temp.right = root;
                root = root.left;
            }
        }else{
            if(pre!=null && pre.val > root.val){
                if(first==null){first = pre;second = root;}
                else{second = root;}
            }
            pre = root;
            root = root.right;
        }
    }
    // swap two node values;
    if(first!= null && second != null){
        int t = first.val;
        first.val = second.val;
        second.val = t;
    }
}