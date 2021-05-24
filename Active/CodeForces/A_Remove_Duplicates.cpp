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

Petya has an array a consisting of n integers. He wants to remove duplicate (equal) elements.

Petya wants to leave only the rightmost entry (occurrence) for each element of the array. The relative order of the remaining unique elements should not be changed.

*/

int main(){
  FastIO;
  int n;
  cin>>n;
  vector<int>Index(1005,0);
  vector<int>a(n+1,0);
  int mx = 0;
  for(int i =1;i<=n;i++){
      int x;
      cin>>x;
      a[i] = x;
      Index[x] = i;
      mx = max(mx,x);
  }
  set<int>dp;
  for(int i =1;i<=mx;i++){
      if(Index[i]>0) dp.insert(Index[i]);
  }
  cout<<dp.size()<<'\n';
  for(int i : dp) cout<<a[i]<<' ';
  return 0;
} 
// If Solved Mark (0/1) here => [1]