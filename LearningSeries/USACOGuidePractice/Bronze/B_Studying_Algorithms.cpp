// Problem Link : https://codeforces.com/gym/102951/problem/B
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

Steph wants to improve her knowledge of algorithms over winter break. She has a total of X (1≤X≤104) minutes to dedicate to learning algorithms. There are N (1≤N≤100) algorithms, and each one of them requires ai (1≤ai≤100) minutes to learn. Find the maximum number of algorithms she can learn.

Input
Line 1: Two space-separated integers N and X
Line 2: N space-separated integers a1,a2,…aN
Output
A single integer, the answer to the problem.

*/


/*
Author's solution : 



*/

int main(){
  FastIO;
  int n,k;
  cin>>n>>k;
  int a[n];
  for(int &x : a) cin>>x;
  sort(a,a+n);
  int t =0;
  int c =0;
  int i =0;
  while(i<n and t<k){
    c+=1;
    t+=a[i];
    i++;
  }
  cout<<c;
  return 0;
} 
// If Solved Mark (0/1) here => []