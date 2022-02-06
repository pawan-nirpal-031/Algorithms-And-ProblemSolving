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

You are given two arrays a and b, sorted in non-decreasing order. Find the number of pairs (i,j) for which ai=bj.

Input
The first line contains integers n and m, the sizes of the arrays (1≤n,m≤105). The second line contains n integers ai, elements of the first array, the third line contains m integers bi, elements of the second array (−109≤ai,bi≤109).


*/


/*
Author's solution : 



*/

int main(){
  FastIO;
  int n,m;
  cin>>n>>m;
  ll a[n],b[m];
  vector<int>pair_cnt(m,0);
  for(ll &x : a) cin>>x;
  for(ll &x : b) cin>>x;
  int ptr_a =0;
  for(int ptr_b=0;ptr_b<m;ptr_b++){
      if(pair_cnt[ptr_b]==0){
          while(ptr_a<n and a[ptr_a]<=b[ptr_b]){
              if(ptr_a<n and a[ptr_a]==b[ptr_b]){
                  pair_cnt[ptr_b]+=1;
              }
              ptr_a+=1;
          }
      }
  }
  ll ans = pair_cnt[0];
  for(int i =1;i<m;i++){
      if(b[i]==b[i-1]) pair_cnt[i] = pair_cnt[i-1];
      ans+=pair_cnt[i];
  }
  cout<<ans;

  return 0;
} 
// If Solved Mark (0/1) here => []