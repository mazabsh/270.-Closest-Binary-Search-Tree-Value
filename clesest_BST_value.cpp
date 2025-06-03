#include<iostream> 
#include<algorithm> 
#include<cmath> 

using namespace std; 

class TreeNode{
public: 
      int val; 
      TreeNode* left; 
      TreeNode* right; 
      TreeNode(): val(0), left(nullptr), right(nullptr){}
      TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
      TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right){}
};
class Solution{
public: 
       int closestValue(TreeNode* root, double target){
          int ans = root->val; 
          dfs(root, ans, target); 
          return ans; 
       }
       void dfs(TreeNode* root, int& ans, double target){
         if(abs(root->val-target)<abs(ans-target)) ans = root->val; 
         else if(abs(root->val-target)==abs(ans-target)) ans = min(ans, root->val); 
         if(root->left) dfs(root->left, ans, target); 
         if(root->right) dfs(root->right, ans, target); 
       }
};
int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    double target =3.5; 
    Solution sol; 
    cout << sol.closestValue(root, target) << endl; 
    return 0; 
}
