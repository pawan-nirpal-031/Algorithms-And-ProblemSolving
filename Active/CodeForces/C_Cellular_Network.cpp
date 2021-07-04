// Problem Link : https://codeforces.com/contest/702/problem/C
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

You are given n points on the straight line — the positions (x-coordinates) of the cities and m points on the same line — the positions (x-coordinates) of the cellular towers. All towers work in the same way — they provide cellular network for all cities, which are located at the distance which is no more than r from this tower.

Your task is to find minimal r that each city has been provided by cellular network, i.e. for each city there is at least one cellular tower at the distance which is no more than r.

If r = 0 then a tower provides cellular network only for the point where it is located. One tower can provide cellular network for any number of cities, but all these cities must be at the distance which is no more than r from this tower.

Input
The first line contains two positive integers n and m (1 ≤ n, m ≤ 105) — the number of cities and the number of cellular towers.

The second line contains a sequence of n integers a1, a2, ..., an ( - 109 ≤ ai ≤ 109) — the coordinates of cities. It is allowed that there are any number of cities in the same point. All coordinates ai are given in non-decreasing order.

The third line contains a sequence of m integers b1, b2, ..., bm ( - 109 ≤ bj ≤ 109) — the coordinates of cellular towers. It is allowed that there are any number of towers in the same point. All coordinates bj are given in non-decreasing order.

Output
Print minimal r so that each city will be covered by cellular network.

*/


/*
Author's solution : 



*/

bool Fits(ll cities[],ll towers[],ll n,ll m,ll radius){
  int t = 0;
  int reach = 0;
  for(int c = 0;c<n;){
    if(t>=m) break;
    if(cities[c]<=towers[t]+radius){
      reach+=(cities[c]>=towers[t]-radius);
      c+=1;
    }else{
      t+=1;
    }
  }
  return reach==n;
}

int main(){
  FastIO;
  ll n,m;
  cin>>n>>m;
  ll cities[n],towers[m];
  for(ll &x : cities) cin>>x;
  for(ll &x : towers) cin>>x;
  ll low = 0;
  ll high = Infinity;
  while(high>low+1){
    ll mid = (low + ((high-low)>>1));
    (Fits(cities,towers,n,m,mid)?high=mid:low=mid);
  }
  cout<<(Fits(cities,towers,n,m,low)?low:high);
  return 0;
} 
// If Solved Mark (0/1) here => [1]