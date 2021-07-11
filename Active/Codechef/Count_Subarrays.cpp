// Problem Link : https://www.codechef.com/problems/SUBINC
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

Given an array A1,A2,...,AN, count the number of subarrays of array A which are non-decreasing.
A subarray A[i,j], where 1≤i≤j≤N is a sequence of integers Ai,Ai+1,...,Aj.

A subarray A[i,j] is non-decreasing if Ai≤Ai+1≤Ai+2≤...≤Aj. You have to count the total number of such subarrays.

*/



void solve(){
    int n;
    cin>>n;
    ll a[n];
    vector<ll>num_of_subarrys_end(n,0);
    for(ll &x : a) cin>>x;
    ll ans = num_of_subarrys_end[0] = 1;
    for(int i =1;i<n;i++){
     num_of_subarrys_end[i] = 1 + (a[i]>=a[i-1]?num_of_subarrys_end[i-1]:0);
     ans+=num_of_subarrys_end[i];
    }
    cout<<ans<<'\n';
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
} 
// If Solved Mark (0/1) here => [1]