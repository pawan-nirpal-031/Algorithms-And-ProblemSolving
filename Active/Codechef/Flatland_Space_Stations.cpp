// Problem Link : https://www.hackerrank.com/challenges/flatland-space-stations/problem
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
Flatland is a country with a number of cities, some of which have space stations. Cities are numbered consecutively and each has a road of  length connecting it to the next city. It is not a circular route, so the first city doesn't connect with the last city. Determine the maximum distance from any city to its nearest space station.

Example


There are  cities and city  has a space station. They occur consecutively along a route. City  is  unit away and city  is  units away. City  is  units from its nearest space station as one is located there. The maximum distance is .

*/

int main(){
  FastIO;
  int n,m;
  cin>>n>>m;
  vector<pair<int,int>>dp(n,{INT_MAX,INT_MAX});
  int u_limt = 0;
  int l_limt = n-1;
  for(int i =0;i<m;i++){
      int x;
      cin>>x;
      dp[x].first =  dp[x].second = 0;
      u_limt = max(u_limt,x);
      l_limt = min(l_limt,x);
  }
  for(int i = u_limt-1;i>=0;i--) dp[i].second = min(dp[i].second,dp[i+1].second+1);
  for(int i = l_limt+1;i<n;i++) dp[i].first = min(dp[i].first,((i>0)?dp[i-1].first+1:INT_MAX));
  int ans = 0;
  for(int i =0;i<n;i++) ans = max(ans,min(dp[i].first,dp[i].second));
  cout<<ans;
  return 0;
} 
// If Solved Mark (0/1) here => [1]