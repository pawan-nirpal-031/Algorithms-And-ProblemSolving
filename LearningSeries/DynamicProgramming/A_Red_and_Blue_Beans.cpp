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

You have r red and b blue beans. You'd like to distribute them among several (maybe, one) packets in such a way that each packet:

has at least one red bean (or the number of red beans ri≥1);
has at least one blue bean (or the number of blue beans bi≥1);
the number of red and blue beans should differ in no more than d (or |ri−bi|≤d)
Can you distribute all beans?

*/

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      ll r,b,d;
      cin>>r>>b>>d;
      Status(min(r,b)*(d+1)>=max(r,b));
  }
  return 0;
} 
// If Solved Mark (0/1) here => []