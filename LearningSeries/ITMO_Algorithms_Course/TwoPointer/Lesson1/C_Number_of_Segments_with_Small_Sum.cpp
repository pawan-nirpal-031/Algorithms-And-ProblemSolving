// Problem Link : https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/C
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
#define Scan(a) for(auto &x : a) cin>>x;
#define Write(a) for(auto x : a) cout<<x<<' ';
#define Print(x) cout<<x
#define Input(x) cin>>x


/*
Problem Statement : 

Given an array of n integers ai. Let's say that the segment of this array a[l..r] (1≤l≤r≤n) is good if the sum of elements on this segment is at most s. Your task is to find the number of good segments.

Input
The first line contains integers n and s (1≤n≤105, 1≤s≤1018). The second line contains integers ai (1≤ai≤109).

Output
Print one integer, the number of good segments.

*/


/*
Author's solution : 



*/

int main(){
  FastIO;
  int n;
  ull s;
  cin>>n>>s;
  ull a[n];
  Scan(a);
  ull seg_count = 0,l = 0;
  ull seg_sum = 0;
  for(int r = 0;r<n;r++){
      seg_sum+=a[r];
      while(seg_sum>s and l<=r){
          seg_sum-=a[l];
          l++;
      }
      seg_count +=(r-l+1); 
  }
  cout<<seg_count;
  return 0;
} 
// If Solved Mark (0/1) here => [1]