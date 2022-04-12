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
  int n;
  cin>>n;
  pair<string,string> a[n];
  for(auto &p : a) cin>>p.first>>p.second;
  bool yes = 1;
  for(int i = 0;i<n;i++){
      bool fnex = 0;
      bool snex = 0;
      for(int j = 0;j<n;j++){
         if(i==j) continue;
         if(a[i].first==a[j].first or a[i].first==a[j].second) fnex = 1; 
      }
      for(int j = 0;j<n;j++){
          if(i==j) continue;
          if(a[i].second==a[j].first or a[i].second==a[j].second) snex = 1;
      }
      if(fnex and snex){
          yes = 0;
          break;
      }
  }
  Status(yes);
  return 0;
} 
// If Solved Mark (0/1) here => []