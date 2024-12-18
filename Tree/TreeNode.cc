/*
 * Date: 2024-12-18 01:07
 * Author: yikebaer·aizezi
 * Content: TreeNode related algorithm
*/
 // Online C++ compiler to run C++ program online
#include "TreeNode.h"

namespace tree_algo{

std::vector<int> TreeNodeHelper::preorder(TreeNode* root, bool method) {
    if (method) {
        _preorder_recursive(root);
    } else {
        _preorder_non_recursive(root);
    }
    return _order_vec;
}

std::vector<int> TreeNodeHelper::inorder(TreeNode* root, bool method) {
    if (method) {
        _inorder_recursive(root);
    } else {
        _inorder_non_recursive(root);
    }
    return _order_vec;
}

std::vector<int> TreeNodeHelper::postorder(TreeNode* root, bool method) {
    if (method) {
        _postorder_recursive(root);
    } else {
        _postorder_non_recursive(root);
    }
    
    return _order_vec;
}

std::vector<int> TreeNodeHelper::levelorder(TreeNode* root) {
    _levelorder(root);
    return _order_vec;
}

int TreeNodeHelper::max_depth(TreeNode* root, bool method) {
    if (method) {
        return _max_depth_recursive(root);
    } else {
        return _levelorder(root);
    }
}

bool TreeNodeHelper::is_complete_binary_tree(TreeNode* root) {
    bool flag = true;
    flag = _is_complete_binary_tree(root);
    return flag;
}

void TreeNodeHelper::_preorder_recursive(TreeNode* _root) {
    /*递归前序遍历*/
    if (!_root) {
        return;
    }
    _order_vec.push_back(_root -> val);
    _preorder_recursive(_root -> left);
    _preorder_recursive(_root -> right);
}

void TreeNodeHelper::_preorder_non_recursive(TreeNode* _root) {
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

void TreeNodeHelper::_inorder_recursive(TreeNode* _root) {
    /*递归中序遍历*/
    if (!_root) {
        return;
    }
    _inorder_recursive(_root -> left);
    _order_vec.push_back(_root -> val);
    _inorder_recursive(_root -> right);
}

void TreeNodeHelper::_inorder_non_recursive(TreeNode* _root) {
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

void TreeNodeHelper::_postorder_recursive(TreeNode* _root) {
    /*递归后序遍历*/
    if (!_root) {
        return;
    }
    _postorder_recursive(_root -> left);
    _postorder_recursive(_root -> right);
    _order_vec.push_back(_root -> val);
}

void TreeNodeHelper::_postorder_non_recursive(TreeNode* _root) {
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

int TreeNodeHelper::_levelorder(TreeNode* _root) {
    if (!_root) {
        return 0;
    }
    _que.push(_root);
    while (!_que.empty()) {

        int n = _que.size();
        for (int i = 0; i < n; i++) {
            _node = _que.front();
            _que.pop();
            _order_vec.push_back(_node -> val);

            if (_node -> left) {
                _que.push(_node -> left);
            }
            if (_node -> right) {
                _que.push(_node -> right);
            }
        }
        _max_depth++;
    }
    return _max_depth;
}

int TreeNodeHelper::_max_depth_recursive(TreeNode* _root) {
    if (!_root) {
        return _max_depth;
    }
    return std::max(_max_depth_recursive(_root -> left),
                _max_depth_recursive(_root -> right)) + 1;
}

bool TreeNodeHelper::_is_complete_binary_tree(TreeNode* _root) {
    if (!_root) {
        return true;
    }
    _que.push(_root);
    while (!_que.empty()) {
        _node = _que.front();
        _que.pop();
        if (!_node) {
            _flag = true;
        } else {
            if (_flag) {
                return false;
            }
            _que.push(_node -> left);
            _que.push(_node -> right);
        }

    }
    return _flag;
}

};// namespace tree_algo