// Problem Link : https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/E
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

Given an array of n integers ai. Let's say that a segment of this array a[l..r] (1≤l≤r≤n) is good if there are no more than k unique elements on this segment. Your task is to find the number of different good segments.

Input
The first line contains integers n and k (1≤n≤105, 0≤k≤n). The second line contains integers ai (1≤ai≤105).

Output
Print one integer, the number of good segments.

*/


/*
Author's solution : 


*/



int main(){
  FastIO;
  int n,k;
  cin>>n>>k;
  vector<ll>a(n,0);
  for(int i =0;i<n;i++) cin>>a[i];
  vector<int>frequency(100005,0);
  int seg_uniq = 0;
  int l =0,r =0;
  ull cnt =0;
  for(r =0;r<n;r++){
    if(seg_uniq<k or (seg_uniq==k and frequency[a[r]]!=0)){
      frequency[a[r]]+=1;
      if(frequency[a[r]]==1) seg_uniq+=1;
      continue;
    }
    r-=1;
    cnt+=(r-l+1);
    frequency[a[l]]-=1;
    if(frequency[a[l]]==0) seg_uniq-=1;
    l++;
  }
  r-=1;
  ll c = r-l+1;
  cnt+=((c*(c+1))>>1);
  cout<<cnt;
  return 0;
} 
// If Solved Mark (0/1) here => [1]