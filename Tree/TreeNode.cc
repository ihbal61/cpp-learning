/*
 * Date: 2024-12-18 01:07
 * Author: yikebaer·aizezi
 * Content: TreeNode related algorithm
*/
 // Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class TreeNodeHelper {
    public:
        std::vector<int> preorder(TreeNode* root, bool method) {
            if (method) {
                _preorder_recursive(root);
            } else {
                _preorder_non_recursive(root);
            }
            return _order_vec;
        }

        std::vector<int> inorder(TreeNode* root, bool method) {
            if (method) {
                _inorder_recursive(root);
            } else {
                _inorder_non_recursive(root);
            }
            return _order_vec;
        }
        
        std::vector<int> postorder(TreeNode* root, bool method) {
            if (method) {
                _postorder_recursive(root);
            } else {
                _postorder_non_recursive(root);
            }
            
            return _order_vec;
        }
    private:
        void _preorder_recursive(TreeNode* _root) {
            /*递归前序遍历*/
            if (!_root) {
                return;
            }
            _order_vec.push_back(_root -> val);
            _preorder_recursive(_root -> left);
            _preorder_recursive(_root -> right);
        }

        void _preorder_non_recursive(TreeNode* _root) {
            /*非递归前序遍历*/
            if (!_root) {
                return;
            }
            while (!_stk.empty() || _root) {
                while (_root) {
                    _order_vec.push_back(_root -> val);
                    _stk.push(_root);
                    _root = _root -> left;
                }
    
                _root = _stk.top();
                _stk.pop();
                _root = _root -> right;
            }
        }

        void _inorder_recursive(TreeNode* _root) {
            /*递归中序遍历*/
            if (!_root) {
                return;
            }
            _inorder_recursive(_root -> left);
            _order_vec.push_back(_root -> val);
            _inorder_recursive(_root -> right);
        }

        void _inorder_non_recursive(TreeNode* _root) {
            /*非递归中序遍历*/
            if (!_root) {
                return;
            }
            while (!_stk.empty() || _root) {
                while (_root) {
                    _stk.push(_root);
                    _root = _root -> left;
                }
    
                _root = _stk.top();
                _stk.pop();

                _order_vec.push_back(_root -> val);

                _root = _root -> right;
            }
        }
        
        void _postorder_recursive(TreeNode* _root) {
            /*递归后序遍历*/
            if (!_root) {
                return;
            }
            _postorder_recursive(_root -> left);
            _postorder_recursive(_root -> right);
            _order_vec.push_back(_root -> val);
        }

        void _postorder_non_recursive(TreeNode* _root) {
            /*非递归后序遍历*/
            if (!_root) {
                return;
            }
            while (!_stk.empty() || _root) {
                while (_root) {
                    _stk.push(_root);
                    _root = _root -> left;
                }
    
                _root = _stk.top();
                _stk.pop();

                if (!_root -> right || _root -> right == _prev) {
                    _order_vec.push_back(_root -> val);
                    _prev = _root;
                    _root = nullptr;
                } else {
                    _stk.push(_root);
                    _root = _root -> right;
                }
            }
        }
        
    private:
        std::vector<int> _order_vec;
        std::stack<TreeNode*> _stk;
        TreeNode* _node = nullptr;
        TreeNode* _prev = nullptr;
};

int main() {
    // Write C++ code here
    TreeNodeHelper tree_node_helper;
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);
    root -> right -> left = new TreeNode(7);
    root -> right -> right = new TreeNode(6);

    std::vector<int> nums;
    nums = tree_node_helper.inorder(root, false);
    
    std::cout << "Preorder vector contains value below: " << std::endl;

    for (auto& num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


    return 0;
}
