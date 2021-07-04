// Problem Link : https://codeforces.com/contest/1005/problem/C
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

A sequence a1,a2,…,an is called good if, for each element ai, there exists an element aj (i≠j) such that ai+aj is a power of two (that is, 2d for some non-negative integer d).

For example, the following sequences are good:

[5,3,11] (for example, for a1=5 we can choose a2=3. Note that their sum is a power of two. Similarly, such an element can be found for a2 and a3),
[1,1,1,1023],
[7,39,89,25,89],
[].
Note that, by definition, an empty sequence (with a length of 0) is good.

For example, the following sequences are not good:

[16] (for a1=16, it is impossible to find another element aj such that their sum is a power of two),
[4,16] (for a1=4, it is impossible to find another element aj such that their sum is a power of two),
[1,3,2,8,8,8] (for a3=2, it is impossible to find another element aj such that their sum is a power of two).
You are given a sequence a1,a2,…,an. What is the minimum number of elements you need to remove to make it good? You can delete an arbitrary set of elements.


*/


/*
Author's solution : 



*/

int Lookup(ll a[],int n,ll x,ll y){
    int l = 0;
    int r = n-1;
    int ret_val = -1;
    while(r>l+1){
        int mid = ((l+r)>>1);
        if(a[mid]==x) r = mid;
        else if(a[mid]<x) l = mid;
        else r = mid;
    }
    if(a[r]==x) ret_val = r;
    if(a[l]==x) ret_val = l;
    if(x!=y) return ret_val;
    int low = ret_val;
    int high = n-1;
    while(high>low+1){
        ll mid = ((low+high)>>1);
        if(a[mid]==x) low = mid;
        else if(a[mid]>x) high = mid;
        else low = mid;
    }
    int upper = low;
    if(a[high]==x) upper = high;
    return upper-ret_val+1;
}

int main(){
  FastIO;
  int n;
  cin>>n;
  ll a[n];
  for(ll &x : a) cin>>x;
  sort(a,a+n);
  int cnt =0;
  for(int i =0;i<n;i++){
      bool flg =0;
      for(int k = 0;k<=32;k++){
          ll x = (1LL<<k) - a[i];
          int status = Lookup(a,n,x,a[i]);
          if(x>-1){
           if((a[i]==x and status>1) or (a[i]!=x and status>=0)){
              flg = 1;
              break;
            }
          }
      }
      if(flg==0) cnt+=1; 
  }
  cout<<cnt;
  return 0;
} 
// If Solved Mark (0/1) here => [1]