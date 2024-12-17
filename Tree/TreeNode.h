/*
 * Date: 2024-12-18 01:07
 * Author: yikebaer·aizezi
 * Content: TreeNode related algorithm
*/
 // Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <stack>

namespace tree_algo {

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class TreeNodeHelper {
    public:
        std::vector<int> preorder(TreeNode* root, bool method);
        std::vector<int> inorder(TreeNode* root, bool method);
        std::vector<int> postorder(TreeNode* root, bool method);
        std::vector<int> levelorder(TreeNode* root, bool method);

        
    private:
        /*前序*/
        void _preorder_recursive(TreeNode* _root);
        void _preorder_non_recursive(TreeNode* _root);
        /*中序*/
        void _inorder_recursive(TreeNode* _root);
        void _inorder_non_recursive(TreeNode* _root);
        /*后序*/
        void _postorder_recursive(TreeNode* _root);
        void _postorder_non_recursive(TreeNode* _root);
        
    
        
    private:
        std::vector<int> _order_vec;
        std::stack<TreeNode*> _stk;
        TreeNode* _node = nullptr;
        TreeNode* _prev = nullptr;
};

}; // namespace tree_algo