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
    tree[tree_indx] = tree[2*tree_indx]+tree[2*tree_indx+1];
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
    tree[tree_indx] = tree[2*tree_indx]+tree[2*tree_indx+1];
}

void RangeUpdateLazy(int tree_indx,int seg_left,int seg_right,vector<int>&tree,vector<int>&lazy,int updt_left,int updt_right,int val){
    if(lazy[tree_indx]!=0){
        tree[tree_indx]+=((seg_right-seg_left+1)*(lazy[tree_indx]));
        if(seg_left!=seg_right){
            lazy[2*tree_indx]+=lazy[tree_indx];
            lazy[2*tree_indx+1]+=lazy[tree_indx];
        }
        lazy[tree_indx] =0;
    }
    if(updt_left>seg_right or updt_right<seg_left) return;
    if(seg_left>=updt_left and seg_right<=updt_right){
        tree[tree_indx]+=((seg_right-seg_left+1)*(val));
        if(seg_left!=seg_right){
            lazy[2*tree_indx]+=val;
            lazy[2*tree_indx+1]+=val;
        }
        return;
    }
    int mid = ((seg_left + seg_right)>>1);
    RangeUpdateLazy(2*tree_indx,seg_left,mid,tree,lazy,updt_left,updt_right,val);
    RangeUpdateLazy(2*tree_indx+1,mid+1,seg_right,tree,lazy,updt_left,updt_right,val);
    tree[tree_indx] = tree[2*tree_indx]+tree[2*tree_indx+1];
}

int RangeQuery(int tree_indx,int seg_left,int seg_right,vector<int>&tree,vector<int>&lazy,int query_left,int query_right){
    if(lazy[tree_indx]!=0){
        tree[tree_indx]+=((seg_right-seg_left+1)*(lazy[tree_indx]));
        if(seg_left!=seg_right){
            lazy[2*tree_indx]+=lazy[tree_indx];
            lazy[2*tree_indx+1]+=lazy[tree_indx];
        }
        lazy[tree_indx] =0;
    }
    if(seg_left>=query_left and seg_right<=query_right) return tree[tree_indx];
    if(query_right<seg_left or query_left>seg_right) return 0;
    int mid = ((seg_left + seg_right)>>1);
    int left = RangeQuery(2*tree_indx,seg_left,mid,tree,lazy,query_left,query_right);
    int right = RangeQuery(2*tree_indx+1,mid+1,seg_right,tree,lazy,query_left,query_right);
    return left+right;
}


void LazyPropDemo(){
    int n,q;
    cin>>n>>q;
    vector<int>a(n+1,0);
    for(int i =1;i<=n;i++) cin>>a[i];
    vector<int>tree(4*n+5,0),lazy(4*n+5,0);
    BuildTree(1,1,n,a,tree);
    while(q--){
        char c;
        cin>>c;
        if(c=='q'){//'query'
            int l,r;
            cin>>l>>r;
            cout<<RangeQuery(1,1,n,tree,lazy,l,r)<<endl;
        }else{//'update'
            int l,r,val; // add val to all elemnts in range [l,r]
            cin>>l>>r>>val;
            RangeUpdateLazy(1,1,n,tree,lazy,l,r,val);
        }
    }
  
}

int main(){
  FastIO;
  LazyPropDemo();
  return 0;
} 
