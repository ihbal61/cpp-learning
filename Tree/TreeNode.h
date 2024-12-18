/*
 * Copyright (c) 2024 yikebaer·aizezi
 * @date: 2024-12-18 01:07
 * @author: yikebaer·aizezi
 * @file: TreeNode.h
 * @brief: TreeNode related algorithm
*/

#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

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
        std::vector<int> levelorder(TreeNode* root);
        int max_depth(TreeNode* root, bool method);
        bool is_complete_binary_tree(TreeNode* root);

        
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
        /*层序*/
        int _levelorder(TreeNode* _root);
        int _max_depth_recursive(TreeNode* _root);
        /*判断是否为完全二叉树*/
        bool _is_complete_binary_tree(TreeNode* _root);
    
        
    private:
        std::vector<int> _order_vec;
        std::stack<TreeNode*> _stk;
        TreeNode* _node = nullptr;
        TreeNode* _prev = nullptr;
        std::queue<TreeNode*> _que;
        int _max_depth = 0;
        bool _flag = false;
};

}; // namespace tree_algo