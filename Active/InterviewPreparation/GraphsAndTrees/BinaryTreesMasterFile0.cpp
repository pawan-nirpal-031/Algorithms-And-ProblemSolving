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

    int MaximumPathSum(const node *tmp){
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

    vector<vector<int>> ZigZagLevelOrder(node *root){
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<node*>que;
        que.push(root);
        bool flg = 1;
        while(not que.empty()){
            int level_size = que.size();
            vector<int>local(level_size);
            for(int i=0;i<level_size;i++){
                node *newnode = que.front();
                que.pop();
                int indx = (flg?i:(level_size-i-1));
                local[indx] = newnode->val;
                if(newnode->left) que.push(newnode->left);
                if(newnode->right)  que.push(newnode->right);
            }
            flg = (!flg);
            ans.push_back(local);
        }
        return ans;
    }

    bool IsLeaf(node *tmp){
        return (tmp->left==NULL and tmp->right==NULL);
    }

    void GetLeaves(node *tmp,vector<int>&ans){
        if(IsLeaf(tmp)){
            ans.push_back(tmp->val);
            return;
        }
        if(tmp->left) GetLeaves(tmp->left,ans);
        if(tmp->right) GetLeaves(tmp->right,ans);
    }

    vector<int>BoundryTraversal(node *root){
        vector<int>ans;
        node *curr = root;
        while(curr){
            if(not IsLeaf(curr)) ans.push_back(curr->val);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
        GetLeaves(root,ans);
        stack<int>right;
        curr = root;
        while(curr){
            if(not IsLeaf(curr)) right.push(curr->val);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        while(not right.empty()){
            ans.push_back(right.top());
            right.pop();
        }
        return ans;
    }


    vector<vector<int>> VerticalOrderTraversal(node *root){
        if(root==NULL) return {{}};
        queue<pair<node*,pair<int,int>>>process;
        map<int,map<int,multiset<int>>>cache;
        process.push({root,{0,0}});
        while(not process.empty()){
            auto item = process.front();
            process.pop();
            node*curr = item.first;
            auto coordinates = item.second;
            cache[coordinates.first][coordinates.second].insert(curr->val);
            if(curr->left) process.push({curr->left,{coordinates.first-1,coordinates.second+1}});
            if(curr->right) process.push({curr->right,{coordinates.first+1,coordinates.second+1}});
        }
        vector<vector<int>>order;
        for(auto tuple : cache){
            vector<int>vertical;
            for(auto ver : tuple.second){
                for(int x : ver.second) vertical.push_back(x);
            }
            order.push_back(vertical);
        }
        return order;
    }

    vector<int> TopView(node *root){
        queue<pair<node*,pair<int,int>>>process;
        map<int,node*>cache;
        process.push({root,{0,0}});
        while(not process.empty()){
            auto tuple = process.front();
            process.pop();
            node *curr = tuple.first;
            auto cordinates = tuple.second;
            if(cache.find(cordinates.first)==cache.end()) cache[cordinates.first] = curr;
            if(curr->left) process.push({curr->left,{cordinates.first-1,cordinates.second+1}});
            if(curr->right) process.push({curr->right,{cordinates.first+1,cordinates.second+1}});
        }
        vector<int>ans;
        for(auto p : cache) ans.push_back(p.second->val);
        return ans;
    }

    vector<int> BottomView(node *root){
        if(root==NULL) return {};
        queue<pair<node*,pair<int,int>>>process;
        map<int,int>cache;
        process.push({root,{0,0}});
        while(not process.empty()){
            auto tuple = process.front();
            process.pop();
            node *curr = tuple.first;
            auto cordinates = tuple.second;
            cache[cordinates.first] = curr->val;
            if(curr->left) process.push({curr->left,{cordinates.first-1,cordinates.second+1}});
            if(curr->right) process.push({curr->right,{cordinates.first+1,cordinates.second+1}});
        }
        vector<int>ans;
        for(auto x : cache) ans.push_back(x.second);
        return ans;
    }

    void RightOrLeftViewRecursiveUtil(node *root,vector<int>&rview,int lvl){
        if(root==NULL) return;
        if(lvl==rview.size()) rview.push_back(root->val);
        RightOrLeftViewRecursiveUtil(root->left,rview,lvl+1); // for left view use root->left and right view root->right
        RightOrLeftViewRecursiveUtil(root->right,rview,lvl+1);// for left view use root->right and right view root->left
    }

    vector<int> RightOrLeftViewRecursive(node *root){
        vector<int>rview;
        RightOrLeftViewRecursiveUtil(root,rview,0);
        return rview;
    }

    bool LeftTraversal(node *left,node *right){
        if(left==NULL) return right==NULL;
        if(right==NULL) return left==NULL;
        if(left->val!=right->val) return 0;
        bool c1 =  LeftTraversal(left->left,right->right);
        bool c2 =  LeftTraversal(left->right,right->left);
        return c1 and c2;
    }
    
    
    bool IsSymmertic(node *root){
        return LeftTraversal(root,root);
    }
    
    bool PrintRootToNodeUtil(node *tmp,int target,vector<int>&path){
        if(not tmp) return 0;
        path.push_back(tmp->val);
        if(tmp->val==target) return 1;
        if(PrintRootToNodeUtil(tmp->left,target,path) or PrintRootToNodeUtil(tmp->right,target,path)) return 1;
        path.pop_back();
        return 0;
    }

    vector<int> PrintRootToNode(node *root,int target){
        vector<int>path;
        PrintRootToNodeUtil(root,target,path);
        return path;
    }

    node* LeastCommonAncestor(node *tmp,node* node1,node* node2){
        if(tmp==NULL or tmp==node1 or tmp==node2) return tmp;
        node *left = LeastCommonAncestor(tmp->left,node1,node2);
        node *right = LeastCommonAncestor(tmp->right,node1,node2);
        if(left and right==NULL) return left;
        else if(right and left==NULL) return right;
        else if(right and left) return tmp;
        return NULL;
    }

    string Serialize(node *root){
        if(root==NULL) return "";
        string s="";
        queue<node*>que;
        que.push(root);
        while(not que.empty()){
            node *curr = que.front();
            que.pop();
            if(curr==NULL) s+="#,";
            else s+=(to_string(curr->val)+',');
            if(curr){
                que.push(curr->left);
                que.push(curr->right);
            }
        }
        return s;
    }

    node *DeSerialize(string data){
        if(data.size()==0) return NULL;
        stringstream stream(data);
        string buffr;
        getline(stream,buffr,',');
        node *tmp = new node(stoi(buffr));
        queue<node*>que;
        que.push(tmp);
        while(not que.empty()){
            node *curr = que.front();
            que.pop();
            getline(stream,buffr,',');
            if(buffr=="#") curr->left = NULL;
            else{
                node *curr_l = new node(stoi(buffr));
                curr->left = curr_l;
                que.push(curr_l);
            }
            getline(stream,buffr,',');
            if(buffr=="#") curr->right = NULL;
            else{
                node *curr_r = new node(stoi(buffr));
                curr->right = curr_r;
                que.push(curr_r);
            }
        }
        return tmp;
    }

    int MinimumTimeToBurnTheTree(node *root,int start){
        unordered_map<int,node*>par_ptrs;
        queue<node*>process;
        process.push(root);
        node *strt = NULL;
        while(not process.empty()){
            node *curr = process.front();
            if(curr->val==start) strt = curr;
            process.pop();
            if(curr->left){
                 par_ptrs[curr->left->val] = curr;
                 process.push(curr->left);
            }
            if(curr->right){
                 par_ptrs[curr->right->val] = curr;
                 process.push(curr->right);
            }
        }
        
        queue<pair<node*,int>>burn;
        burn.push({strt,0});
        int max_time = 0;
        int c =0;
        unordered_map<int,bool>vis;
        while(not burn.empty()){
            auto p = burn.front();
            burn.pop();
            if(vis[p.first->val]) continue;
            node *curr = p.first;
            vis[p.first->val] = 1;
            int timer = p.second;
            max_time = max(max_time,timer);
            auto it  = par_ptrs.find(curr->val);
            if(it!=par_ptrs.end()) burn.push({it->second,timer+1});
            if(curr->left) burn.push({curr->left,timer+1});
            if(curr->right) burn.push({curr->right,timer+1});
        }
        return max_time;
    }

    int MaximumWidthOfBinaryTree(node *root){
        queue<pair<node*,int>>process;
        process.push({root,0});
        while(not process.empty()){
            
        }
        
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

        vector<node*> GetExampleTree4(){
            root = new node(1);
            root->left = new node(2);
            root->right = new node(3);
            root->left->left = new node(4);
            root->left->right = new node(10);
            root->left->left->right = new node(5);
            root->left->left->right->right = new node(6);
            root->right->left = new node(9);
            root->right->right = new node(10);
            return {root,root->left->left->right->right,root};
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
   BinaryTree b;
   
   return 0;
} 
