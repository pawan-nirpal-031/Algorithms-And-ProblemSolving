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

void C(){
    ll n,k;
  cin>>n>>k;
  ll a[n];
  vector<pair<ll,int>>cache(n,{0,0});
  ll f = k/n;
  for(int i =0;i<n;i++){
      cin>>a[i];
      cache[i].first = a[i]+f;
      cache[i].second = i;
  }
  sort(a,a+n);
  k-=(f*n);
  for(int i =0;i<k;i++){
      cache[i].first+=1;
  }
  for(int i =0;i<n;i++){
      cout<<(cache[i].first - a[cache[i].second])<<'\n';
  }
}


int main(){
  FastIO;
  C();
  return 0;
} 
// If Solved Mark (0/1) here => []