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





int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      int a,b;
      cin>>a>>b; 
      pair<int,int>ans = {-1,-1};
      int sum =INT_MAX;
      for(int i = a;i<=min(b,a+3);i++){
          for(int j = i+1;j<=min(b,a+3);j++){
              if(__gcd(i,j)>1){
                  if(i+j<sum){
                      sum = i+j;
                      ans = {i,j};
                  }
              }
          }
      }
      if(ans.first==-1) cout<<-1<<"\n";
      else cout<<ans.first<<' '<<ans.second<<"\n";
  }
  return 0;
} 
// If Solved Mark (0/1) here => []