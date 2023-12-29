#include <iostream>
#include <vector>
#include <stack>
#include <queue>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if (!root)
            return result;

        std::stack<TreeNode*> nodeStack;
        nodeStack.push(root);

        while (!nodeStack.empty()) {
            TreeNode* node = nodeStack.top();
            nodeStack.pop();

            result.push_back(node->val);
            if (node->right)
                nodeStack.push(node->right);
            if (node->left)
                nodeStack.push(node->left);
        }
        return result;
    }
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> nodeStack;
        TreeNode* current = root;
        while (current != nullptr || !nodeStack.empty())
        {
            while (current != nullptr)
            {
                nodeStack.push(current);
                current = current->left;
            }
            current = nodeStack.top();
            nodeStack.pop();
            result.push_back(current->val);

            current = current->right;
        }
        return result;
    }
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if (root == nullptr)
            return result;
        std::stack<TreeNode*> stack1;
        std::stack<TreeNode*> stack2;
        TreeNode* current = root;
        stack1.push(root);
        while (!stack1.empty())
        {
            current = stack1.top();
            stack1.pop();
            stack2.push(current);
            if (current->left) {
                stack1.push(current->left);
            }
            if (current->right) {
                stack1.push(current->right);
            }
        }
        while (!stack2.empty())
        {
            result.push_back(stack2.top()->val);
            stack2.pop();
        }
        return result;
    }
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        std::vector<int> levelTree;
        if(!root){
            return result;
        }
        std::queue<TreeNode*> queue;
        queue.push(root);
        queue.push(nullptr); // маркер
        while (!queue.empty())
        {
            TreeNode* current = queue.front();
            queue.pop();

            if(current){
                levelTree.push_back(current->val);
                if(current->left) queue.push(current->left);
                if(current->right) queue.push(current->right);
            }
            else {
                result.push_back(levelTree);
                levelTree.clear();
                if(!queue.empty()) queue.push(nullptr);
            }
        }
        return result;     
    }
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int depthLeft = 1;
        int depthRight = 1;
        if(root->left) depthLeft += maxDepth(root->left); 
        if(root->right) depthRight += maxDepth(root->right);
        return depthLeft > depthRight ? depthLeft : depthRight;
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isSymmetricUnderTree(root->left, root->right);
    }
    bool isSymmetricUnderTree(TreeNode* left, TreeNode* right) {
        if (!left && !right) {
            return true;
        }
        if (!left || !right) {
            return false;
        }
        return (left->val == right->val) && isSymmetricUnderTree(left->left, right->right) && isSymmetricUnderTree(left->right, right->left);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        if(!root->left && !root->right && targetSum == root->val){
            return true;
        }
        if(hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val)){
            return true;
        }
        return false;
    }
};

int main(){
    TreeNode* symmetricTree = new TreeNode(1);
    symmetricTree->left = new TreeNode(2);
    symmetricTree->right = new TreeNode(2);
    symmetricTree->left->left = new TreeNode(3);
    symmetricTree->left->right = new TreeNode(4);
    symmetricTree->right->left = new TreeNode(4);
    symmetricTree->right->right = new TreeNode(3);

    Solution s;
    std::vector<std::vector<int>> result = s.levelOrder(symmetricTree);
    for(std::vector<int> j : result){
        for(int i : j){
            std::cout << i << '\n';
        }
    }
    std::cout << s.maxDepth(symmetricTree)<<'\n';
    std::cout << s.isSymmetric(symmetricTree)<<'\n';
    std::cout << s.hasPathSum(symmetricTree, 6) << '\n'; 
    delete symmetricTree->left->left;
    delete symmetricTree->left->right;
    delete symmetricTree->right->left;
    delete symmetricTree->right->right;
    delete symmetricTree->left;
    delete symmetricTree->right;
    delete symmetricTree;
    return 0;
}