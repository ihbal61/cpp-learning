#include "TreeNode.h"

using namespace tree_algo;

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
    nums = tree_node_helper.preorder(root, false);

    std::cout << "Preorder vector contains value below: " << std::endl;

    for (auto& num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


    return 0;
}