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
#define GoogleOutput(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);



class SegmentTree{
    
    private: 

        int n;
        vector<int>arr;
        vector<int>tree;

        void UpdateHelper(int ss,int se,int ti,int val,int aindx){
            if(ss==se && ss==aindx){
                tree[ti] = arr[aindx] = val;
                return;
            }
            int mid = (ss+se)/2;
            if(aindx>=ss && aindx<=mid){
                UpdateHelper(ss,mid,2*ti,val,aindx);
            }else if(aindx>=mid+1&&aindx<=se) {
                UpdateHelper(mid+1,se,2*ti+1,val,aindx);
            }
            tree[ti] = Merge(tree[2*ti],tree[2*ti+1]);
        }

        int QueryHelper(int ss,int se,int ti,int qs,int qe){
            if(qs==ss&&qe==se){
                return tree[ti];
            }
            else if(qs>se||qe<ss){
                return INT_MAX; // return identity
            }
            int mid = (ss+se)/2;
            return Merge(QueryHelper(ss,mid,2*ti,qs,min(mid,qe)),QueryHelper(mid+1,se,2*ti+1,max(qs,mid+1),qe));
        }

        void Build(int ss,int se,int ti){
            if(ss==se){
                tree[ti] = arr[se];
                return;
            }
            int mid = (ss+se)/2;
            Build(ss,mid,2*ti);
            Build(mid+1,se,2*ti+1);
            tree[ti] = Merge(tree[2*ti],tree[2*ti+1]);
        }


        int FindPrefixSumHelper(int prfx,int ss,int se,int ti){
            if(prfx>tree[ti]){
                return -1;
            }
            if(ss==se){
                return ss;
            }
            int mid = (ss+se)/2;
            if(tree[2*ti]>=prfx){
                return FindPrefixSumHelper(prfx,ss,mid,2*ti);
            }else{
                return FindPrefixSumHelper(prfx-tree[2*ti],mid+1,se,2*ti+1);
            }
        }
    
    public:

        SegmentTree(int size,vector<int>&array){
            n = size;
            arr.resize(n+1);
            arr = array;
            tree.resize(4*n);
            Build(1,n,1);         
        }

        void ShowTree(){
            for(int i = 1;i<=tree.size(); i++ ){
                cout<<tree[i]<<" ";
            }
        }
        
        int Merge(int a,int b){
            return min(a,b);
        } 

        void Update(int val,int indx){
            UpdateHelper(1,n,1,val,indx);
        }

        int Query(int qs,int qe){
           return QueryHelper(1,n,1,qs,qe);
        }

        int FindPrefixSum(int PrfxSm){
            /*
                This function is only valid for RangeSum based segment tree
                it finds least index in input array for which the given PrefixSum
                is greater or equal.
                
                This exact same function also solves one more problem, which is The index of kth zero in
                the array, at each node in Segtree you will have to store number of zeros in that segment
                
            */
            return FindPrefixSumHelper(PrfxSm,1,n,1);
        }
        
};



void QuickTest(){
   int n;
   cin>>n;
   vector<int>a(n+1,0);
   for(int i=1;i<=n;i++){
       cin>>a[i];
   }
   SegmentTree s(n,a);
   int ans = 0;
   for(int i=1;i<=n;i++){
       for(int j =i;j<=n;j++){
           ans = max(ans,(j-i+1)*s.Query(i,j));
       }
   }
   cout<<ans;
}



int main(){
  FastIO;
  
  return 0;
} 
