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

ll GetCeil(ll x,ll k){
  return ceil((x*1.0)/k);
}

void Que1(){
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n,0);
    for(ll &x : a) cin>>x;
    vector<ll>suffx(n,0);
    suffx[n-1] = a[n-1];
    vector<ll>dp(n,0);
    vector<ll>dp2(n,0);
    for(ll i = n-2;i>=0;i--){
      suffx[i] = a[i]+suffx[i+1];
    } 
    dp[n-1] = dp2[n-1] = GetCeil(a[n-1],k);
    for(ll i = n-2;i>=0;i--){
        dp[i] = min( GetCeil(suffx[i+1]+a[i],k), dp[i+1]+GetCeil(a[i],k) );
        dp2[i] = max(GetCeil(suffx[i+1]+a[i],k), dp2[i+1]+GetCeil(a[i],k) );
    }
    cout<<dp[0]<<' '<<dp2[0]<<'\n';
    
}

int  f(int q,int x){

}

void CountBits(int n ){
  int c =0;
  while(n>0){
    n = n*(n-1);
    c++;
  }
  cout<<c;
}

int main(){
  FastIO;
   CountBits(15);
  return 0;
} 