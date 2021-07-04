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
  int n;
  cin>>n;
  ll a[n];
  ll cnt =0;
  vector<int>step_len;
  for(ll &x : a){
      cin>>x;
      if(x==1) cnt+=1;
  }
  for(int i =0;i<n;i++){
      if(i==0){
          if(n==1 or (n>1 and a[1]==1)) step_len.push_back(1);
      }else if(i==n-1){
          step_len.push_back(a[i]);
      }else{
          if(a[i+1]==1) step_len.push_back(a[i]);
      }
  }
  cout<<cnt<<'\n';
  for(int x : step_len) cout<<x<<' ';
  return 0;
} 
// If Solved Mark (0/1) here => [1]