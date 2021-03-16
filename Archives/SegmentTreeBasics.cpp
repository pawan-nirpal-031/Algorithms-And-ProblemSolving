#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Infinity (ll)1e18
#define Append(a) push_back(a)
#define Pair(a,b) make_pair(a,b)
#define Clear(a) for(ll &x : a) x=0;
#define Point(x) std::fixed<<setprecision(15)<<x
#define SetBits(x) __builtin_popcount(x);
#define GoogleOutput(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define BoolAnsCall(b) (cout<<(b?"Yes\n":"No\n"));

/*

All associtive opretions can be implmented using segment tree
min,max, add, mul, xor, mul, or, gcd,lcm;

*/


int merge(int a,int b){
    return a+b;
}

void Build(int a[],vector<int>&tree,int seg_left,int seg_right,int tree_indx){
    if(seg_left==seg_right){
        tree[tree_indx] = a[seg_left];
        return;
    }
    int mid = (seg_left+seg_right)>>1;
    Build(a,tree,seg_left,mid,2*tree_indx);
    Build(a,tree,mid+1,seg_right,2*tree_indx+1);
    tree[tree_indx] = merge(tree[2*tree_indx],tree[2*tree_indx+1]);
}

void PointUpdate(int a[],vector<int>&tree,int seg_left,int seg_right,int tree_indx,int update_indx,int update_val){
    if(seg_left==seg_right and seg_left==update_indx){
        tree[tree_indx] = a[update_indx] = update_val;
        return;
    }
    int mid = (seg_left+seg_right)>>1;
    if(update_indx>mid){
        PointUpdate(a,tree,mid+1,seg_right,2*tree_indx+1,update_indx,update_val);
    }else{
        PointUpdate(a,tree,seg_left,mid,2*tree_indx,update_indx,update_val);
    }
    tree[tree_indx] = merge(tree[2*tree_indx],tree[2*tree_indx+1]);
}

void RangeUpdate(vector<int>&tree,vector<int>&lazy,int tree_indx,int seg_left,int seg_right,int update_left,int update_right,int update_val){
    if(lazy[tree_indx]>0){
        int update_val = lazy[tree_indx];
        tree[tree_indx]+=(seg_right-seg_left+1)*(update_val);
        lazy[tree_indx] =0;
        if(seg_left!=seg_right){
            lazy[2*tree_indx] +=update_val;
            lazy[2*tree_indx+1]+=update_val;
        }
    }
    if(seg_left>update_right or seg_right<update_left){
        return; 
    }
    if( update_left<=seg_left and seg_right<=update_right){
        int update = (seg_right-seg_left+1)*(update_val);
        tree[tree_indx]+=update;

        if(seg_left!=seg_right){
            lazy[2*tree_indx]+=update;
            lazy[2*tree_indx+1]+=update;
        }
        return;
    }
    int mid = (seg_left+seg_right)>>1;
    RangeUpdate(tree,lazy,2*tree_indx,seg_left,mid,update_left,update_right,update_val);
    RangeUpdate(tree,lazy,2*tree_indx+1,mid+1,seg_right,update_left,update_right,update_val);
    tree[tree_indx] = merge(tree[2*tree_indx],tree[2*tree_indx+1]);
}

int Query(vector<int>&tree,vector<int>&lazy,int seg_left,int seg_right,int tree_indx,int query_left,int query_right){
    if(lazy[tree_indx]>0){
        int update_val = lazy[tree_indx];
        tree[tree_indx]+=(seg_right-seg_left+1)*(update_val);
        lazy[tree_indx] =0;
        if(seg_left!=seg_right){
            lazy[2*tree_indx] +=update_val;
            lazy[2*tree_indx+1]+=update_val;
        }
    }
    if(query_left>=seg_left and query_right<=seg_right){
        return tree[tree_indx]; // Full overlap
    }
    if(query_left>seg_right or query_right<seg_left){
        return 0; // Return Identity elment as zero overlap
    }
    int mid = (seg_left+seg_right)>>1;
    return merge(Query(tree,lazy,seg_left,mid,2*tree_indx,query_left,query_right),Query(tree,lazy,mid+1,seg_right,2*tree_indx+1,query_left,query_right));
}



int main(int argc, const char** argv) {
    FastIO;
    int n,q;
    cin>>n>>q;
    int a[n+1];
    for(int i =0;i<=n;i++) a[i] =0;
    vector<int>tree(4*n+1,0),lazy(4*n,0);
   // for(int i =1;i<=n;i++) cin>>a[i];
    Build(a,tree,1,n,1);
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l,r;
            cin>>l>>r;
            cout<<Query(tree,lazy,1,n,1,l,r)<<endl;
        }else{
            int l,r,v;
            cin>>l>>r>>v;
            RangeUpdate(tree,lazy,1,1,n,l,r,v);
        }
        
    }
    return 0;
}