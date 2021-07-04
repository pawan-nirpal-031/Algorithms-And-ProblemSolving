// Problem Link : https://codeforces.com/contest/1006/problem/C
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

  You are given an array d1,d2,…,dn consisting of n integer numbers.

  Your task is to split this array into three parts (some of which may be empty) in such a way that each element of the array belongs to exactly one of the three parts, and each of the parts forms a consecutive contiguous subsegment (possibly, empty) of the original array.

  Let the sum of elements of the first part be sum1, the sum of elements of the second part be sum2 and the sum of elements of the third part be sum3. Among all possible ways to split the array you have to choose a way such that sum1=sum3 and sum1 is maximum possible.

  More formally, if the first part of the array contains a elements, the second part of the array contains b elements and the third part contains c elements, then:

  sum1=∑1≤i≤adi,
  sum2=∑a+1≤i≤a+bdi,
  sum3=∑a+b+1≤i≤a+b+cdi.
  The sum of an empty array is 0.

  Your task is to find a way to split the array such that sum1=sum3 and sum1 is maximum possible.

  Input
  The first line of the input contains one integer n (1≤n≤2⋅105) — the number of elements in the array d.

  The second line of the input contains n integers d1,d2,…,dn (1≤di≤109) — the elements of the array d.

  Output
  Print a single integer — the maximum possible value of sum1, considering that the condition sum1=sum3 must be met.

  Obviously, at least one valid way to split the array exists (use a=c=0 and b=n).


*/


/*
Author's solution : 



*/

bool Lookup(ll suffix[],ll prefix_sum,int n,int curr_indx){
  int left = curr_indx+1;
  int right = n-1;
  while(right>left+1){
    int mid = ((left+right)>>1);
    if(suffix[mid]==prefix_sum) return 1;
    if(suffix[mid]>prefix_sum) left = mid;
    else right = mid;
  }
  return (suffix[left]==prefix_sum or suffix[right]==prefix_sum);
}

int main(){
  FastIO;
  int n;
  cin>>n;
  ll a[n];
  ll suffix[n];
  for(ll &x : a) cin>>x;
  suffix[n-1] = a[n-1];
  for(int i = n-2;i>=0;i--) suffix[i] = a[i]+suffix[i+1];
  ll max_val = 0;
  ll prefix_sum = 0;
  for(int i = 0;i<n-1;i++){
    prefix_sum+=a[i];
    max_val = max(max_val,prefix_sum*Lookup(suffix,prefix_sum,n,i));
  }
  cout<<max_val;
  return 0;
} 
// If Solved Mark (0/1) here => [1]