#include <bits/stdc++.h>
#include "BinaryTreeBase.h"
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Pair(a,b) make_pair(a,b)
#define Point(x) std::fixed<<setprecision(6)<<x
#define SetBits(x) __builtin_popcount(x);
#define Case(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Status(b) (cout<<(b?"YES\n":"NO\n"));


bool IsLeaf(TreeNode *node){
    return (node->right==nullptr and node->left==nullptr);
}

bool hasPathSum(TreeNode* root, int targetSum) {
    if(root==nullptr) return 0;
    if(IsLeaf(root)) return root->val==targetSum;
    bool has_sub_tree_path_sum = 0; 
    if(root->left) has_sub_tree_path_sum = hasPathSum(root->left,targetSum-(root->val));
    if(root->right) has_sub_tree_path_sum = has_sub_tree_path_sum or hasPathSum(root->right,targetSum-(root->val));
    return has_sub_tree_path_sum;
}

int main(){
  FastIO;
  Status(hasPathSum(ExampleTree1(),26));
  return 0;
} 
