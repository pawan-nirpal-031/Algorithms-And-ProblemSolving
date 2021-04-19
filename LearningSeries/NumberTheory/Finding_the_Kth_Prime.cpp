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
The problem statement is really simple. There are some queries. You are to give the answers.

Input
An integer stating the number of queries Q(equal to 50000), and Q lines follow, each containing one integer K between 1 and 5000000 inclusive.

Output
Q lines with the answer of each query: the Kth prime number.

*/

int main(){
  FastIO;
  ll max_limit = 90000000;
  vector<bool>primes(max_limit,1);// i is prime if primes[i]==true
  primes[0] = primes[1] = 0;
  for(int i = 2;i*i<=max_limit;i++){
      if(primes[i]) for(int j = i*i;j<=max_limit;j+=i) primes[j] =0;
  }
  vector<ll>cache;
  for(int i =2;i<=max_limit;i++) if(primes[i]) cache.push_back(i);
  int t;
  cin>>t;
  while(t--){
      int x;
      cin>>x;
      cout<<cache[x-1]<<'\n';
  }
  return 0;
} 
// If Solved Mark (0/1) here => [1]