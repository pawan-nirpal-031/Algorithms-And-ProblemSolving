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

Chef is a big fan of Coldplay. Every Sunday, he will drive to a park taking M minutes to reach there, and during the ride he will play a single song on a loop. Today, he has got the latest song which is in total S minutes long. He is interested to know how many times will he be able to play the song completely.

*/

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      ll m,s;
      cin>>m>>s;
      cout<<(m/s)<<'\n';
  }
  return 0;
} 
// If Solved Mark (0/1) here => []