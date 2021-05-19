// Problem Link : https://codeforces.com/problemset/problem/474/D
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

We saw the little game Marmot made for Mole's lunch. Now it's Marmot's dinner time and, as we all know, Marmot eats flowers. At every dinner he eats some red and white flowers. Therefore a dinner can be represented as a sequence of several flowers, some of them white and some of them red.

But, for a dinner to be tasty, there is a rule: Marmot wants to eat white flowers only in groups of size k.

Now Marmot wonders in how many ways he can eat between a and b flowers. As the number of ways could be very large, print it modulo 1000000007 (109 + 7).

For K = 2 and length 1 Marmot can eat (R).
For K = 2 and length 2 Marmot can eat (RR) and (WW).
For K = 2 and length 3 Marmot can eat (RRR), (RWW) and (WWR).
For K = 2 and length 4 Marmot can eat, for example, (WWWW) or (RWWR), but for example he can't eat (WWWR).


*/

int main(){
  FastIO;
  int t,k;
  cin>>t>>k;
  vector<ll>dp(100005,0);
  for(int i =0;i<100005;i++) dp[i] = ((i<k)?1:(dp[i-1]%Mod + dp[i-k]%Mod)%Mod);
  for(int i = 1;i<100005;i++) dp[i] = (dp[i]+dp[i-1])%Mod;
  while(t--){
      int a,b;
      cin>>a>>b;
      ll ans = (dp[b]- dp[a-1]);
      if(ans<0) ans+=Mod;
      cout<<ans<<'\n';
  }
  return 0;
} 
// If Solved Mark (0/1) here => [1]