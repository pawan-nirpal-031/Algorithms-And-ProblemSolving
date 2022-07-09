// Problem Link : https://www.codechef.com/MAY222D/problems/MAKEZERO
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



void filltable(vector<int>&t,int v){
  for(int i =0;i<32;i++){
    t[i]+=(v&(1<<i)?1:0);
  }
}

int main(){
  FastIO;
  int t;
  cin>>t; 
  while(t--){
    int n; 
    cin>>n; 
    vector<int> bit_table(32,0); 
    for(int i =0;i<n;i++){
      int x; 
      cin>>x; 
      filltable(bit_table,x);
    }
    int ans =0;
    for(int i =0;i<32;i++){
      ans+=(bit_table[i]>0);
    }
    cout<<ans<<'\n';
  } 
  return 0;
} 
// If Solved Mark (0/1) here => []