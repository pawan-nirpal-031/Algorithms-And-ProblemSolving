// Problem Link : https://cses.fi/problemset/task/2217
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


struct Tuple{
    int x,y;
    bool z;
};


/*
Problem Statement : 

You are given an array that contains each number between 1…n exactly once. Your task is to collect the numbers from 1 to n in increasing order.

On each round, you go through the array from left to right and collect as many numbers as possible.

Given m operations that swap two numbers in the array, your task is to report the number of rounds after each operation.

Input

The first line has two integers n and m: the array size and the number of operations.

The next line has n integers x1,x2,…,xn: the numbers in the array.

Finally, there are m lines that describe the operations. Each line has two integers a and b: the numbers at positions a and b are swapped.

Output

Print m integers: the number of rounds after each swap.

Constraints
1≤n,m≤2⋅105
1≤a,b≤n


*/


/*
Author's solution : 

int ans = 0;
  for(int i =1;i<n;i++) ans+=(a[i].second=(a[i+1].first<a[i].first));
  while(q--){
      int x,y;
      cin>>x>>y;
      int past = 0;
      for(int v : {2,1}) for(int i = -1;i<=1;i++) if(v+i>=1 and v+i<=n) {
          past+=a[v+i].second;
          a[v+i].second = 0;
      }
      swap(a[x].first,a[y].first);
      map<int,bool>cache;
      for(int v : {x,y}) for(int i = -1;i<=1;i++) if(v+i>=1 and v+i<=n) {
          int u = v+i;
          if(u!=n) cache[u] = a[u].second = (a[u+1].first<a[u].first);
      }
      int curr = 0;
      for(auto u : cache) curr+=cache[u.first];
      ans = ans - past + curr;
      //cout<<ans<<'\n';

*/

int main(){
  FastIO;
  int n,q;
  cin>>n>>q;
  Tuple a[n+1];
  for(int i =1;i<=n;i++){
      cin>>a[i].x;
      a[i].y = i;
      a[i].z =0;
  }
  for(int i =1;i<n;i++){
      a[i].z = (a[i].y>a[i+1].y);
  }
  for(int i =1;i<=n;i++) cout<<a[i].z<<' ';
 // cout<<ans;

  return 0;
} 
// If Solved Mark (0/1) here => []