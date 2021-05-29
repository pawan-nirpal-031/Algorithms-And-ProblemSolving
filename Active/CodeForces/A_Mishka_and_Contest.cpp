// Problem Link : https://codeforces.com/contest/999/problem/A
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

int main(){
  FastIO;
  int n,k;
  cin>>n>>k;
  int a[n];
  for(int &x : a) cin>>x;
  int l = 0;
  int ans = 0;
  for(int i =0;i<n;i++){
      if(a[i]>k) break;
      l = i;
      ans+=1;
  }
  int r = n-1;
  for(int i = n-1;i>=0;i--){
      if(a[i]>k) break;
      if(i>l) ans+=1;
  }
  cout<<ans;
  return 0;
} 
// If Solved Mark (0/1) here => [1]