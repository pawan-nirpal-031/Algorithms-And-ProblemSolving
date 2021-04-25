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

*/

bool CanProvideNewtork(ll cities[],ll towers[],int n,int m,int dist){
   for(int i = 0;i<n;i++){
     bool covered = 0;
     if(i<m){
       ll tow_i = towers[i];
       ll city_i = cities[i];
       if(city_i>=tow_i-dist or city_i<=tow_i+dist) covered = 1;
     }
     if(i+1<m){
       ll tow_x = towers[i+1];
       ll city_x = cities[i+1];
       if(city_x>=tow_x-dist or city_x<=tow_x+dist) covered = 1;
     }
     if(not covered) return 0;
   }
   return 1;
}

int main(){
  FastIO;
  int n,m;
  cin>>n>>m;
  ll cities[n];
  ll towers[m];
  for(ll &x : cities) cin>>x;
  for(ll &x : towers) cin>>x;
  ll r_high = 1e18;// distance such that network can be surely provided
  ll r_low = 0; // distance such that network can't be provided
  // while(r_high-r_low>1){
  //   ll mid = (r_low + ((r_high-r_low)>>1));
  //   if(CanProvideNewtork(cities,towers,n,m,mid)) r_high = mid;
  //   else r_low = mid;
  // }
  // if(CanProvideNewtork(cities,towers,n,m,r_low)) cout<<r_low;
  // else cout<<r_high;
  cout<<CanProvideNewtork(cities,towers,n,m,100);
  return 0;
} 
// If Solved Mark (0/1) here => []