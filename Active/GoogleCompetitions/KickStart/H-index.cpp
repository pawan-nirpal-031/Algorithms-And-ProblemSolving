// Problem Link : 
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
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#include <ext/pb_ds/assoc_container.hpp>


/*
Problem Statement : 



*/


/*
Author's solution : 



*/

class Math{
    public:
    int Floor(int x,int y){
        return floor(x*1.0/y);
    }
    int Ceil(int x,int y){
        return ceil(x*1.0/y);
    }
};

int GetNofElems(auto it1,auto it2){


}

void solve(){
    int n;
    cin>>n;
    multiset<int>set;
    int ans = 1;
    for(int i =1;i<=n;i++){
        int x;
        cin>>x;
        set.insert(x);
        if(i>1){
            if(GetNofElems(set.lower_bound(ans+1),set.end())>=ans+1){
                ans+=1;
            }
            ans = min(ans,i);
        }
        cout<<ans<<" ";
    }
    cout<<'\n';
}

int main(){
  FastIO;
  int t;
  cin>>t;
  for(int i =1;i<=t;i++){
      cout<<"Case #"<<i<<": ";
      solve();
  }
  return 0;
} 
// If Solved Mark (0/1) here => []