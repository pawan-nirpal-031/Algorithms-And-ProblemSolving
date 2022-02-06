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

For educational purposes, in the problems of this block, the time limit is large enough for the solution to pass in O(nlogn) time, but try to write the solution in linear time, which we discussed in the lecture.

You are given two arrays, sorted in non-decreasing order. Merge them into one sorted array.

Input
The first line contains integers n and m, the sizes of the arrays (1≤n,m≤105). The second line contains n integers ai, elements of the first array, the third line contains m integers bi, elements of the second array (−109≤ai,bi≤109).

Output
Print n+m integers, the merged array.

*/


/*
Author's solution : 



*/

int main(){
  FastIO;
  int n,m;
  cin>>n>>m;
  int a[n],b[m];
  for(int &x : a) cin>>x;
  for(int &x : b) cin>>x;
  int c[n+m];
  int ptr_a =0; // first non deleted element indx in a
  int ptr_b = 0; // first non deleted element indx in b
  while(ptr_a<n and ptr_b<m){
      c[ptr_a+ptr_b] = min(a[ptr_a],b[ptr_b]);
      (a[ptr_a]<b[ptr_b])?ptr_a+=1:ptr_b+=1;
  }
  if(ptr_b!=m) while(ptr_b<m) c[ptr_a+ptr_b] = b[ptr_b],ptr_b+=1;
  if(ptr_a!=n) while(ptr_a<n) c[ptr_a+ptr_b] = a[ptr_a],ptr_a+=1; 
  for(int v : c) cout<<v<<' ';
  return 0;
} 
// If Solved Mark (0/1) here => []