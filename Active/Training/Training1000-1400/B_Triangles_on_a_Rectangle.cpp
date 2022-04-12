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


/*
Problem Statement : 



*/


/*
Author's solution : 



*/


ll getMaxDiff(){
    ll yl;
    cin>>yl;
    ll ylow[yl];
    ll ylow_min = Mod;
    ll ylow_max = 0;
    for(ll &x : ylow){
          cin>>x;
          ylow_max = max(ylow_max,x);
          ylow_min = min(ylow_min,x);
    }
    return (ll)ylow_max-ylow_min;  
}


int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      ll width,height;
      cin>>width>>height;
      ll ylow_base = getMaxDiff();
      ll yhigh_base = getMaxDiff();
      ll xlow_base = getMaxDiff();
      ll xhigh_base = getMaxDiff();
      ll ans = height*(max(ylow_base,yhigh_base));
      ans = max(ans,width*max(xlow_base,xhigh_base));
      cout<<ans<<'\n';
  }
  return 0;
} 
// If Solved Mark (0/1) here => []