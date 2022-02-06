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

You are given N (3≤N≤5000) integer points on the coordinate plane. Find the square of the maximum Euclidean distance (aka length of the straight line) between any two of the points.

Input
The first line contains an integer N. The second line contains N integers, the x-coordinates of the points: x1,x2,…,xN (−1000≤xi≤1000). The third line contains N integers, the y-coordinates of the points: y1,y2,…,yN (−1000≤yi≤1000).

Output
Print one integer, the square of the maximum Euclidean distance between any two of the points.

*/


/*
Author's solution : 



*/

int main(){
  FastIO;
  int n;
  cin>>n;
  ll max_dist = -Mod;
  pair<int,int> points[n];
  for(int i =0;i<n;i++) cin>>points[i].first;
  for(int i =0;i<n;i++) cin>>points[i].second;
  
  for(int i =0;i<n;i++){
      for(int j = i+1;j<n;j++){
          ll x = points[i].first-points[j].first;
          ll y = points[i].second -points[j].second;
          max_dist = max(max_dist,(ll)sqrt((x*x)+(y*y)));
      }
  }
  cout<<max_dist;
  return 0;
} 
// If Solved Mark (0/1) here => []