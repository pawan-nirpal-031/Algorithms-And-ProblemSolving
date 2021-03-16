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
#define GoogleOutput(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define BoolAnsCall(b) (cout<<(b?"Yes\n":"No\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x

ll MinCost(ll n,ll m,ll a,ll b,vector<ll>&dp){
    if(n<=0){
        return 0;
    }
    if(dp[n]!=-1) return dp[n];
    ll not_use = a+ MinCost(n-1,m,a,b,dp);
    ll use = b + MinCost(n-m,m,a,b,dp);
    return dp[n] =  min(not_use,use);
}

int main(){
  FastIO;
  ll n,m,a,b;
  cin>>n>>m>>a>>b;
  vector<ll>dp(10005,-1);
  cout<<MinCost(n,m,a,b,dp);
  return 0;
} 