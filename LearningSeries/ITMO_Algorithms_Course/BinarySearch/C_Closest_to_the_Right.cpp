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

Given an array of n numbers, sorted in non-decreasing order, and k queries. For each query, print the minimum index of an array element not less than the given one.

Input
The first line of the input contains integers n and k (0<n,k≤105), the length of the array and the number of queries. The second line contains n elements of the array, sorted in non-decreasing order. The third line contains k queries. All array elements and queries are integers, each of which does not exceed 2⋅109 in absolute value.

Output
For each of the k queries, print the minimum index of an array element not less than the given one. If there are none, print n+1.


*/


/*
Author's solution : 



*/


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
  int n,q;
  cin>>n>>q;
  ll a[n];
  for(ll &x : a) cin>>x;
  while(q--){
    ll x;
    cin>>x;
    cout<<ClosestFromRight(a,n,x)<<'\n';
  }
  return 0;
} 
// If Solved Mark (0/1) here => [1]