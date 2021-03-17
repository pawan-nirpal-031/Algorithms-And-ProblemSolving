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

There's an array A consisting of N non-zero integers A1..N. A subarray of A is 
called alternating if any two adjacent elements in it have different signs (i.e. 
one of them should be negative and the other should be positive).
For each x from 1 to N, compute the length of the longest alternating subarray that starts 
at x - that is, a subarray Ax..y for the maximum possible y ≥ x. The length of such a subarray
is y-x+1


Solution : 
dp[i] length of max alternating-subarray-suffix starting at i 
if ai*ai<0 then dp[i] = 1 + dp[i+1];
else dp[i] =1; 

*/



bool cases =1;

void SolveCase(){
    int n;
    cin>>n;
    ll a[n];
    ll dp[n];
    for(int u=0;u<n;u++){
        cin>>a[u];
        dp[u] =0;
    }
    dp[n-1] = 1;
    for(int i = n-2;i>=0;i--) (a[i]*a[i+1]<0?dp[i] = 1 + dp[i+1]:dp[i]=1);
    for(int i =0;i<n;i++) cout<<dp[i]<<' ';
    cout<<'\n';
}

int main(){
  FastIO;
  int t = 1;
  if(cases) cin>>t;
  while(t--){
     SolveCase();
  }
  return 0;
} 
