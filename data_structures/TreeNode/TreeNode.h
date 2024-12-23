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
        void preorder_recursive(TreeNode* root_);
        void preorder_non_recursive(TreeNode* root_);
        /*中序*/
        void inorder_recursive(TreeNode* root_);
        void inorder_non_recursive(TreeNode* root_);
        /*后序*/
        void postorder_recursive(TreeNode* root_);
        void postorder_non_recursive(TreeNode* root_);
        /*层序*/
        int levelorder_helper(TreeNode* root_);
        int max_depth_recursive(TreeNode* root_);
        /*判断是否为完全二叉树*/
        bool is_complete_binary_tree_helper(TreeNode* root_);
    
        
    private:
        std::vector<int> order_vec_;
        std::stack<TreeNode*> stk_;
        TreeNode* node_ = nullptr;
        TreeNode* prev_ = nullptr;
        std::queue<TreeNode*> que_;
        int max_depth_ = 0;
        bool flag_ = false;
};

}; // namespace tree_algo