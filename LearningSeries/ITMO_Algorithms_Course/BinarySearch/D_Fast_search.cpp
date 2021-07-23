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

You are given an array a of n integers a1,a2,…,an.

Your task is to response to the queries like "How many numbers' values are between l and r?".

Input
The first line of the input contains n — the length of the array (1≤n≤105).

The second line contains n integers a1,a2,…,an (−109≤ai≤109).

The third line contains integer k — the number of queries (1≤k≤105).

The following k lines contain a pair of integers l r — query, described above (−109≤l≤r≤109).

Output
The output must consist of k integers — responses for the queries.

*/


/*
Author's solution : 



*/

int ClosestFromLeft(ll a[],int n,ll x){
  int l = -1;
  int r = n;
  while(r>l+1){
      int mid = ((l+r)>>1);
      if(a[mid]<=x) l = mid;
      else r = mid;
  }
  return l+1;
}

int ClosestFromRight(ll a[],int n,ll x){
  int l =-1;
  int r = n;
  while(l+1<r){
    int mid = (l+r)>>1;
    if(a[mid]>=x) r = mid;
    else l = mid;
  }
  return r+1;
}


int main(){
  FastIO;
  int n;
  cin>>n;
  ll a[n];
  for(ll &x : a) cin>>x;
  sort(a,a+n);
  int q;
  cin>>q;
  while(q--){
    ll l,r;
    cin>>l>>r;
    ll cfl =  ClosestFromLeft(a,n,r);
    ll cfr =  ClosestFromRight(a,n,l);
    cout<<cfl-cfr+1<<' ';
  }
  return 0;
} 
// If Solved Mark (0/1) here => []