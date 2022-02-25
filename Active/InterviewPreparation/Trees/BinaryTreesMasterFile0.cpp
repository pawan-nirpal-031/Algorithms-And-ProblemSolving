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

    void Preorder(node *root){
        if(root==NULL) return;
        cout<<root->val<<' ';
        Preorder(root->left);
        Preorder(root->right);
    }

    void PostOrder(node *root){
        if(root==NULL) return;
        PostOrder(root->left);
        PostOrder(root->right);
        cout<<root->val<<' ';
    }


    void InOrder(node *root){
        if(root==NULL) return;
        InOrder(root->left);
        cout<<root->val<<' ';
        InOrder(root->right);
    }

    void LevelOrder(node *root){
        queue<node*>level_order;
        level_order.push(root);
        while(not level_order.empty()){
            node *tmp = level_order.front();
            level_order.pop();
            cout<<tmp->val<<' ';
            if(tmp->left!=NULL) level_order.push(tmp->left);
            if(tmp->right!=NULL) level_order.push(tmp->right);
        }
    }

    int Height(node *tmp){
        if(tmp==NULL) return 0;
        return 1+max(Height(tmp->left),Height(tmp->right));
    }

    int CheckBalance(node *tmp){
        if(tmp==NULL) return 0;
        int left_h = CheckBalance(tmp->left);
        if(left_h==-1) return -1;
        int right_h = CheckBalance(tmp->right);
        if(right_h==-1) return -1;
        if(abs(left_h-right_h)>1) return -1;
        return 1+max(left_h,right_h);
    }

    int Daimeter(node *tmp){
        if(tmp==NULL) return 0;
        int left_h = Daimeter(tmp->left);
        int right_h = Daimeter(tmp->right);
        daimeter = max(daimeter,left_h+right_h);
        return max(left_h,right_h)+1;
    }

    int MaximumPathSum(node *tmp){
        if(tmp==NULL) return 0;
        int left_half = MaximumPathSum(tmp->left);
        int right_half = MaximumPathSum(tmp->right);
        max_path_sum = max(max_path_sum,left_half+right_half+tmp->val);
        return tmp->val+max(left_half,right_half);
    }

    bool CheckIfIdentical(node *tree1,node *tree2){
        if(tree1==NULL) return (tree2==NULL);
        bool lcheck = CheckIfIdentical(tree1->left,tree2->left);
        bool rcheck = CheckIfIdentical(tree1->right,tree2->right);
        return (lcheck and rcheck and (tree1->val==tree2->val));
    }


};



class BinarySearchtree : public CommonUtility{
    public:
    node *root;
    BinarySearchtree(){
        root = NULL;
        daimeter =0;
        max_path_sum =0;
    }

    node* Insert(node *trv,int v){
        if(trv==NULL)  return new node(v);
        else if(v<=trv->val) trv->left = Insert(trv->left,v);
        else trv->right = Insert(trv->right,v);
        return trv;
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


};


int main(){
  FastIO;
   BinaryTree b,c;
   b.root = new node(-10);
   b.root->left = new node(9);
   b.root->right = new node(20);
   b.root->right->left = new node(15);
   b.root->right->right = new node(7);
   return 0;
} 
