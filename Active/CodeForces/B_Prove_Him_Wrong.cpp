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


ull Power(ll a,int n){
    ll res = 1;
    while(n){
        if(n&1) res = res*a;
        n>>=1;
        a = a*a;
    }
    return res;
}


int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      int n;
      cin>>n;
      ull high = Power(3,n-1);
      if(high<=(1e9)){
          Status(1);
          ll res = 1;
          for(int i =0;i<n;i++){
              cout<<res<<' ';
              res = res*3;
          }
          cout<<'\n';
      }else Status(0);
  }
  return 0;
} 
// If Solved Mark (0/1) here => []