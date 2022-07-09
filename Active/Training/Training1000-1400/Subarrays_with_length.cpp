// Problem Link : https://www.codechef.com/MAY222D/problems/SUBARRAYLEN
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

You are given an array A of length N.

Determine the count of subarrays of A which contain their length as an element.

Formally, count the number of pairs (L,R) (1≤L≤R≤N) such that: (R−L+1)∈{AL,AL+1,…,AR}.


*/


/*
Author's solution : 



*/





int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
    int n; 
    cin>>n; 
    ll count =0; 
    ll a[n];
    for(int i =0;i<n;i++) cin>>a[i];
    for(int i =0;i<n;i++){
      ll x = a[i];
      ll suffix = i+x-1;
      ll prefix = i-(x-1); 
      cout<<i<<": ";
      if(prefix>=0 and suffix<=n-1){
        count+=x;
        cout<<x<<'\n';
      }else if(prefix<0 and suffix<=n-1){
        count+=(x-abs(i-x+1));
        cout<<(x-abs(i-x+1))<<'\n';
      }else if(prefix>=0 and suffix>=n){
        count+=n-i;
        cout<<n-i<<'\n';
      }else{
        count+=1;
        cout<<1<<'\n';
      }
    }
    //cout<<count<<'\n';
  }  
  return 0;
} 
// If Solved Mark (0/1) here => []