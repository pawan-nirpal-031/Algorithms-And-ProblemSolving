#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Infinity (ll)1e18
#define Append(a) push_back(a)
#define Pair(a,b) make_pair(a,b)
#define Clear(a) for(ll &x : a){x=0;}
#define Point(x) std::fixed<<setprecision(15)<<x
#define SetBits(x) __builtin_popcount(x);
#define DebugCase(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Status(b) (cout<<(b?"YES\n":"NO\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x


class node{
    public:
     int val;
     node *left;
     node *right;
     
     node(int val){
         this->val = val;
         left = right = NULL;
     }

     node* GetNode(int v){
         node *n = new node(v);
         return n;
     }
};


class CommonUtility{
  public:
   int daimeter;
   int max_path_sum;

  void LevelOrderTraversal(node *root){
    queue<node*>process;
    process.push(root);
    while(not process.empty()){
      node *curr = process.front();
      process.pop();
      cout<<curr->val<<' ';
      if(curr->left) process.push(curr->left);
      if(curr->right) process.push(curr->right);
    }
  }

};

class BinaryTree : public CommonUtility{
    public:
        node *root;
        BinaryTree(){
            root=NULL;
            daimeter =0;
            max_path_sum =0;
        }

        node *GetExampleTree(){
            root = new node(1);
            root->left = new node(2);
            root->right = new node(3);
            root->left->left = new node(4);
            root->left->right = new node(5);
            root->right->right = new node(6);
            root->left->left->left = new node(7);
            root->left->right->left = new node(8);
            return root;
        }

       node* GetExampleTree2(){
            root = new node(1);
            root->left = new node(2);
            root->right = new node(3);
            root->left->left = new node(4);
            root->left->right = new node(9);
            root->left->left->right = new node(5);
            root->left->left->right->right = new node(6);
            root->right->left = new node(7);
            root->right->right = new node(8);
            // node*n1 = root->left->left->right->right;
            // node *n2 =root->left->right;
            // return {root,n1,n2};
            return root;
        }

        node* ExampleTree3(){
            root = new node(1);
            root->left = new node(2);
            root->right = new node(2);
            root->left->left = new node(3);
            root->right->right = new node(3);
            root->left->right = new node(4);
            root->right->left = new node(4);
            root->left->left->left = new node(5);
            root->right->right->right = new node(5);
            return root;
        }

};

int main(){
  FastIO;
  
  return 0;
} 
