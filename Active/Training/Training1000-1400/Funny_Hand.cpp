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


void solve(){
  int n;
  cin>>n;
  int a[2];
  cin>>a[0]>>a[1];
  sort(a,a+2);
  if(a[1]==a[0]+1){
    if(a[1]==n or a[0]==1){
      cout<<1<<'\n';
    }else{
      cout<<2<<'\n';
    }
  }else{// 4 2 
    if(a[1]-a[0]==2){
      cout<<1<<'\n';
    }else{
      cout<<0<<'\n';
    }
  }
}


int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
} 
// If Solved Mark (0/1) here => []