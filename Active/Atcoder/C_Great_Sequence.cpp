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





int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      ll n,x;
      cin>>n>>x;
      multiset<ll>data;
      vector<int>a(n,0);
      for(int i =0;i<n;i++){
          cin>>a[i];
          data.insert(a[i]);
      }
      int ans =0;
      for(int i =0;i<n;i++){
          auto self = data.find(a[i]);
          auto other = data.find(x*a[i]);
          if(self!=data.end() and other!=data.end()){
              data.erase(self);
              data.erase(other);
          }
      }
      cout<<data.size()<<"\n";
  }
    
  return 0;
} 
// If Solved Mark (0/1) here => []

/*

https://codeforces.com/contest/1642/problem/C
https://atcoder.jp/contests/abc243/tasks/abc243_d
https://www.codechef.com/START30D/problems/MINCOLOR

*/