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

inline int Merge(vector<int>&tree,int left,int right){
    return min(tree[left],tree[right]);
}

void BuildTree(int tree_indx,int seg_left,int seg_right,vector<int>&a,vector<int>&tree){
    if(seg_left==seg_right){
        tree[tree_indx] = a[seg_left];
        return;
    }
    int mid = ((seg_left + seg_right)>>1);
    BuildTree(2*tree_indx,seg_left,mid,a,tree);
    BuildTree(2*tree_indx+1,mid+1,seg_right,a,tree);
    tree[tree_indx] = min(tree[2*tree_indx],tree[2*tree_indx+1]);
}

void PointUpdate(int tree_indx,int seg_left,int seg_right,vector<int>&tree,int updt_indx,int updt_val){
    if(seg_left==seg_right and seg_left==updt_indx){
        tree[tree_indx] = updt_val;
        return;
    }
    int mid = ((seg_left + seg_right)>>1);
    if(updt_indx<=mid){
        PointUpdate(2*tree_indx,seg_left,mid,tree,updt_indx,updt_val);
    }else{
        PointUpdate(2*tree_indx+1,mid+1,seg_right,tree,updt_indx,updt_val);
    }
    tree[tree_indx] = min(tree[2*tree_indx],tree[2*tree_indx+1]);
}


int QueryRange(int tree_indx,int seg_left,int seg_right,vector<int>&tree,int query_left,int query_right){
    if(seg_left>=query_left and seg_right<=query_right) return tree[tree_indx];
    if(query_right<seg_left or query_left>seg_right) return INT_MAX;
    int mid = ((seg_left + seg_right)>>1);
    int left = QueryRange(2*tree_indx,seg_left,mid,tree,query_left,query_right);
    int right = QueryRange(2*tree_indx+1,mid+1,seg_right,tree,query_left,query_right);
    return min(left,right);
}


int main(){
  FastIO;
  int n,q;
  cin>>n>>q;
  vector<int>a(n+1,0);
  for(int i =1;i<=n;i++) cin>>a[i];
  vector<int>tree(4*n+5,0);
  BuildTree(1,1,n,a,tree);
  while(q--){
      char c;
      cin>>c;
      if(c=='q'){
          int l,r;
          cin>>l>>r;
          cout<<QueryRange(1,1,n,tree,l,r)<<'\n';
      }else{
          int indx,val;
          cin>>indx>>val;
          PointUpdate(1,1,n,tree,indx,val);
      }
  }
  return 0;
} 
