// Problem Link : https://codeforces.com/problemset/problem/702/B
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

You are given n integers a1, a2, ..., an. Find the number of pairs of indexes i, j (i < j) that ai + aj is a power of 2 (i. e. some integer x exists so that ai + aj = 2x).

*/

pair<ll,ll> Lookup(ll a[],int n,ll x,ll y){
    ll l = 0;
    ll r = n-1;
    ll ret_val = -1;
    while(r>l+1){
        ll mid = ((l+r)>>1);
        if(a[mid]==x) r = mid;
        else if(a[mid]<x) l = mid;
        else r = mid;
    }
    if(a[r]==x) ret_val = r;
    if(a[l]==x) ret_val = l;
    if(ret_val==-1) return {-1,-1};
    ll low = ret_val;
    ll high = n-1;
    while(high>low+1){
        ll mid = ((low+high)>>1);
        if(a[mid]==x) low = mid;
        else if(a[mid]>x) high = mid;
        else low = mid;
    }
    ll upper = low;
    if(a[high]==x) upper = high;
    return {ret_val,upper};
}

int main(){
  FastIO;
  ll n;
  cin>>n;
  ll a[n];
  for(ll &x : a) cin>>x;
  sort(a,a+n);
  ll cnt =0;
  for(ll i =0;i<n;i++){
      for(ll k = 0;k<=32;k++){
          ll x = (1LL<<k) - a[i];
          auto p = Lookup(a,n,x,a[i]);
          ll low = p.first;
          ll up = p.second;
          if((low==-1 and up==-1) or (up>-1 and up<=i)) continue;
          cnt+=((low>i)?up-low+1:up-i);
      }
  }
  cout<<cnt;
  return 0;
} 
// If Solved Mark (0/1) here => [1]