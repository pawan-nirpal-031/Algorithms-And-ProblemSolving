// Problem Link : https://atcoder.jp/contests/abc206/tasks/abc206_b 
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
  ll n;
  cin>>n;
  ll low = 0;
  ll high = (1e9);
  while(high>low+1){
      ll mid = ((low+high)>>1);
      if(((mid*(mid+1))>>1)>=n) high = mid;
      else low =mid;
  }
  cout<<(((low*(low+1))>>1)>=n?low:high);
  return 0;
} 
// If Solved Mark (0/1) here => [1]