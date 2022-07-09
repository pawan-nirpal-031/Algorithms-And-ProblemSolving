// Problem Link : https://www.codechef.com/submit/XORMUL
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


ll brute(int n,int a,int b){
  ll ans = 0; 
  ll up = (1<<n); 
  ll x =0;
  for(ll i = 0;i<(up);i++){
    ll val = ((a ^ i)*(b ^ i)); 
    cout<<i<<" : "<<val<<'\n';
    if(val>ans){
        ans = val;
        x = i;
    }
  }
  for(ll i =0;i<up;i++){
    ll val = ((a ^ i)*(b ^ i));
    if(val==ans){
        cout<<i<<'\n';
    }
  }
  cout<<ans; 
  return x;
}


int main(){
  FastIO;
  int n,a,b; 
  cin>>n>>a>>b; 
  brute(n,a,b);

  return 0;
} 
// If Solved Mark (0/1) here => []