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

};// namespace tree_algo