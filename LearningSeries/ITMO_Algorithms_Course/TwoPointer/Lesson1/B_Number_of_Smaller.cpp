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

You are given two arrays, sorted in non-decreasing order. For each element of the second array, find the number of elements in the first array strictly less than it.

Input
The first line contains integers n and m, the sizes of the arrays (1≤n,m≤105). The second line contains n integers ai, elements of the first array, the third line contains m integers bi, elements of the second array (−109≤ai,bi≤109).

Output
Print m numbers, the number of elements of the first array less than each of the elements of the second array.

*/


/*
Author's solution : 



*/

int main(){
  FastIO;
  int n,m;
  cin>>n>>m;
  ll a[n],b[m];
  int ptr_a =0;
  int strictly_less[m];
  for(int i =0;i<n;i++) cin>>a[i];
  for(int i =0;i<m;i++){
      cin>>b[i];
      strictly_less[i] =0;
  }
  for(int ptr_b =0;ptr_b<m;ptr_b++){
      while(a[ptr_a]<b[ptr_b] and ptr_a<n) ptr_a+=1;
      strictly_less[ptr_b] = ptr_a;
  }
  for(int x : strictly_less) cout<<x<<" ";
  return 0;
} 
// If Solved Mark (0/1) here => []