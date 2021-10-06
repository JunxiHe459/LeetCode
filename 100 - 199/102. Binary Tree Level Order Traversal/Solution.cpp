class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        Order(root, result, 0);
        return result;
        
    }
    
    void Order(TreeNode* root, vector<vector<int>> &result, int depth)
    {
        if(root == NULL)
        {
            return;
        }
        
        if(size(result) <= depth)
        {
            result.push_back(vector<int>());
        }
        
        result[depth].push_back(root->val);
        
        Order(root->left, result, depth + 1);
        Order(root->right, result, depth + 1);
    }
};}
};