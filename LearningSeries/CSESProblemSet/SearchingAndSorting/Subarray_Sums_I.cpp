// Problem Link : https://cses.fi/problemset/task/1660
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

Given an array of n positive integers, your task is to count the number of subarrays having sum x.

Input

The first input line has two integers n and x: the size of the array and the target sum x.

The next line has n integers a1,a2,…,an: the contents of the array.

Output

Print one integer: the required number of subarrays.

*/


/*
Author's solution : 



*/

int main(){
  FastIO;
  int n;
  ll k;
  cin>>n>>k;
  ll a[n];
  ull prefix[n];
  for(int i =0;i<n;i++){
    cin>>a[i];
    prefix[i] = a[i];
    if(i>0) prefix[i]+=prefix[i-1];
  }
  map<ll,ll>cache;
  ll cnt =0;
  cache[0] =1;
  for(int i =0;i<n;i++){
    cnt+=cache[prefix[i]-k];
    cache[prefix[i]]+=1;
  }
  cout<<cnt;
  return 0;
} 
// If Solved Mark (0/1) here => [1]