// Problem Link : https://codeforces.com/contest/1520/problem/D
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

You are given an array a of n integers. Count the number of pairs of indices (i,j) such that i<j and aj−ai=j−i.

Input
The first line contains one integer t (1≤t≤104). Then t test cases follow.

The first line of each test case contains one integer n (1≤n≤2⋅105).

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤n) — array a.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case output the number of pairs of indices (i,j) such that i<j and aj−ai=j−i.

*/

void Solve(){
    int n;
    cin>>n;
    unordered_map<ll,ll>frq;
    for(int i =0;i<n;i++){
        int x;
        cin>>x;
        frq[x-(i+1)]+=1;
    }
    ll ans =0;
    for(auto p : frq){
        ll n1 = p.second;
        ans+=((n1*(n1-1))>>1);
    }
    cout<<ans<<'\n';
}


int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      Solve();
  }
  return 0;
} 
// If Solved Mark (0/1) here => [1]