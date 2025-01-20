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

};// namespace tree_algo