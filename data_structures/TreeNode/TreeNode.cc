/*
 * Copyright (c) 2024 yikebaer·aizezi
 * @date: 2024-12-19 11:07
 * @author: yikebaer·aizezi
 * @file: TreeNode.cc
 * @brief: TreeNode related algorithm
*/

#include "TreeNode.h"

namespace tree_algo{

std::vector<int> TreeNodeHelper::preorder(TreeNode* root, bool method) {
    if (method) {
        preorder_recursive(root);
    } else {
        preorder_non_recursive(root);
    }
    return order_vec_;
}

std::vector<int> TreeNodeHelper::inorder(TreeNode* root, bool method) {
    if (method) {
        inorder_recursive(root);
    } else {
        inorder_non_recursive(root);
    }
    return order_vec_;
}

std::vector<int> TreeNodeHelper::postorder(TreeNode* root, bool method) {
    if (method) {
        postorder_recursive(root);
    } else {
        postorder_non_recursive(root);
    }
    
    return order_vec_;
}

std::vector<int> TreeNodeHelper::levelorder(TreeNode* root) {
    levelorder_helper(root);
    return order_vec_;
}

int TreeNodeHelper::max_depth(TreeNode* root, bool method) {
    if (method) {
        return max_depth_recursive(root);
    } else {
        return levelorder_helper(root);
    }
}

bool TreeNodeHelper::is_complete_binary_tree(TreeNode* root) {
    bool flag_ = true;
    flag_ = is_complete_binary_tree_helper(root);
    return flag_;
}

void TreeNodeHelper::preorder_recursive(TreeNode* root_) {
    /*递归前序遍历*/
    if (!root_) {
        return;
    }
    order_vec_.push_back(root_ -> val);
    preorder_recursive(root_ -> left);
    preorder_recursive(root_ -> right);
}

void TreeNodeHelper::preorder_non_recursive(TreeNode* root_) {
    /*非递归前序遍历*/
    if (!root_) {
        return;
    }
    while (!stk_.empty() || root_) {
        while (root_) {
            order_vec_.push_back(root_ -> val);
            stk_.push(root_);
            root_ = root_ -> left;
        }

        root_ = stk_.top();
        stk_.pop();
        root_ = root_ -> right;
    }
}

/*
 * Algorithm complexity: O(n)
 * Space complexity: O(n)
 * leetcode 94
 */
void TreeNodeHelper::inorder_recursive(TreeNode* root_) {
    /*递归中序遍历*/
    if (!root_) {
        return;
    }
    inorder_recursive(root_ -> left);
    order_vec_.push_back(root_ -> val);
    inorder_recursive(root_ -> right);
}

/*
 * Algorithm complexity: O(n)
 * Space complexity: O(n)
 * leetcode 94
 */
void TreeNodeHelper::inorder_non_recursive(TreeNode* root_) {
    /*非递归中序遍历*/
    if (!root_) {
        return;
    }
    while (!stk_.empty() || root_) {
        while (root_) {
            stk_.push(root_);
            root_ = root_ -> left;
        }

        root_ = stk_.top();
        stk_.pop();

        order_vec_.push_back(root_ -> val);
        root_ = root_ -> right;
    }
}

/*
 * Algorithm complexity: O(n)
 * Space complexity: O(n)
 * leetcode 145
 */
void TreeNodeHelper::postorder_recursive(TreeNode* root_) {
    /*递归后序遍历*/
    if (!root_) {
        return;
    }
    postorder_recursive(root_ -> left);
    postorder_recursive(root_ -> right);
    order_vec_.push_back(root_ -> val);
}

/*
 * Algorithm complexity: O(n)
 * Space complexity: O(n)
 * leetcode 145
 */
void TreeNodeHelper::postorder_non_recursive(TreeNode* root_) {
    /*非递归后序遍历*/
    if (!root_) {
        return;
    }
    while (!stk_.empty() || root_) {
        while (root_) {
            stk_.push(root_);
            root_ = root_ -> left;
        }

        root_ = stk_.top();
        stk_.pop();

        if (!root_ -> right || root_ -> right == prev_) {
            order_vec_.push_back(root_ -> val);
            prev_ = root_;
            root_ = nullptr;
        } else {
            stk_.push(root_);
            root_ = root_ -> right;
        }
    }
}

/*
 * Algorithm complexity: O(n)
 * Space complexity: O(n)
 * leetcode 102
 */
int TreeNodeHelper::levelorder_helper(TreeNode* root_) {
    if (!root_) {
        return 0;
    }
    que_.push(root_);
    while (!que_.empty()) {

        int n = que_.size();
        for (int i = 0; i < n; i++) {
            node_ = que_.front();
            que_.pop();
            order_vec_.push_back(node_ -> val);

            if (node_ -> left) {
                que_.push(node_ -> left);
            }
            if (node_ -> right) {
                que_.push(node_ -> right);
            }
        }
        max_depth_++;
    }
    return max_depth_;
}

/*
 * Algorithm complexity: O(n)
 * Space complexity: O(n)
 * leetcode 104
 */
int TreeNodeHelper::max_depth_recursive(TreeNode* root_) {
    if (!root_) {
        return max_depth_;
    }
    return std::max(max_depth_recursive(root_ -> left),
                max_depth_recursive(root_ -> right)) + 1;
}

/*
 * Algorithm complexity: O(n)
 * Space complexity: O(n)
 * leetcode 958
 */
bool TreeNodeHelper::is_complete_binary_tree_helper(TreeNode* root_) {
    if (!root_) {
        return true;
    }
    que_.push(root_);
    while (!que_.empty()) {
        node_ = que_.front();
        que_.pop();
        if (!node_) {
            flag_ = true;
        } else {
            if (flag_) {
                return false;
            }
            que_.push(node_ -> left);
            que_.push(node_ -> right);
        }

    }
    return flag_;
}

/*
 * Algorithm complexity: O(n)
 * Space complexity: O(n)
 * leetcode 230
 */
int TreeNodeHelper::kth_node(TreeNode* root, int k) {
    if (!root) {
        return -1;
    }
    std::stack<TreeNode*> stk;
    TreeNode* node = root;
    while (node || !stk.empty()) {
        while (node) {
            stk.push(node);
            node = node -> left;
        }
        node = stk.top();
        stk.pop();
        if (--k == 0) {
            return node -> val;
        }
        node = node -> right;
    }
    return -1;
}

/*
 * Algorithm complexity: O(n)
 * Space complexity: O(n)
 * leetcode 226
 */
TreeNode* TreeNodeHelper::mirror_recursive(TreeNode* root) {
    if (!root) {
        return nullptr;
    }
    TreeNode* left = mirror_recursive(root -> left);
    TreeNode* right = mirror_recursive(root -> right);
    root -> left = right;
    root -> right = left;
    return root;
}

/*
 * Algorithm complexity: O(n)
 * Space complexity: O(n)
 * leetcode 226
 */
TreeNode* TreeNodeHelper::mirror_non_recursive(TreeNode* root) {
    if (!root) {
        return nullptr;
    }
    std::stack<TreeNode*> stk;
    stk.push(root);
    while (!stk.empty()) {
        TreeNode* node = stk.top();
        stk.pop();
        if (node -> left) {
            stk.push(node -> left);
        }
        if (node -> right) {
            stk.push(node -> right);
        }
        TreeNode* tmp = node -> left;
        node -> left = node -> right;
        node -> right = tmp;
    }
    return root;
}

/*
 * Algorithm complexity: O(n)
 * Space complexity: O(n)
 * leetcode 113
 */
std::vector<std::vector<int>> TreeNodeHelper::path_sum_list(TreeNode* root, int target) {
    if (!root) {
        return res_vec_;
    }
    std::vector<int> path;
    dfs(root, target, path);
    return res_vec_;
}


void TreeNodeHelper::dfs(TreeNode* node, int target, std::vector<int>& path) {
    if (!node) {
        return;
    }
    path.push_back(node -> val);
    target -= node -> val;
    if (!node -> left && !node -> right && target == 0) {
        res_vec_.push_back(path);
    }
    dfs(node -> left, target, path);
    dfs(node -> right, target, path);
    path.pop_back();
}

/*
 * Algorithm complexity: O(n)
 * Space complexity: O(n)
 * leetcode 110
 */
bool TreeNodeHelper::is_balanced(TreeNode* root) {
    return height(root) >= 0;
}

int TreeNodeHelper::height(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);
    if (left_height == -1 || right_height == -1 || std::abs(right_height - left_height) > 1) {
        return -1;
    }
    return std::max(left_height, right_height) + 1;
}

};// namespace tree_algo