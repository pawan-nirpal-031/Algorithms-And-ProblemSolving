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
#define Status(b) (cout<<(b?"Yes\n":"No\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x


/*
Problem Statement : 



*/


/*
Author's solution : 



*/





int main(){
  FastIO;
  int n,m;
  cin>>n>>m;
  unordered_multiset<ll>cache;
  bool yes = 1;
  for(int i=0;i<n;i++){
      ll x;
      cin>>x;
      cache.insert(x);
  }
  while(m--){
      ll x;
      cin>>x;
      auto it = cache.find(x);
      if(it==cache.end()){
          yes =0;
          continue;
      }
      cache.erase(it);
  }
  Status(yes);
  return 0;
} 
// If Solved Mark (0/1) here => []