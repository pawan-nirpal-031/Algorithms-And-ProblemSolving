// Problem Link : https://codeforces.com/contest/1055/problem/A
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

Alice has a birthday today, so she invited home her best friend Bob. Now Bob needs to find a way to commute to the Alice's home.

In the city in which Alice and Bob live, the first metro line is being built. This metro line contains n stations numbered from 1 to n. Bob lives near the station with number 1, while Alice lives near the station with number s. The metro line has two tracks. Trains on the first track go from the station 1 to the station n and trains on the second track go in reverse direction. Just after the train arrives to the end of its track, it goes to the depot immediately, so it is impossible to travel on it after that.

Some stations are not yet open at all and some are only partially open — for each station and for each track it is known whether the station is closed for that track or not. If a station is closed for some track, all trains going in this track's direction pass the station without stopping on it.

When the Bob got the information on opened and closed stations, he found that traveling by metro may be unexpectedly complicated. Help Bob determine whether he can travel to the Alice's home by metro or he should search for some other transport.

*/

/*
    Remarks : Clarity in understanding the problem was missing, the train on forw track will either go to station s directly which means "YES" else if it does not go directly to s, then BOB has to get out of forw train after s and say it was station x, x>s so he also has to check if s was reachable from x on that reverse train.

*/

int main(){
  FastIO;
  int n,s;
  cin>>n>>s;
  bool forw[n];
  bool revr[n];
  for(int i =0;i<n;i++) cin>>forw[i];
  for(int i =0;i<n;i++) cin>>revr[i];
  if(forw[0] and forw[s-1]){
      Status(1);
      return 0;
  }
  for(int i =1;i<n;i++) if(forw[0] and i>=s-1 and (forw[i] and revr[i] and revr[s-1])) {
      Status(1);
      return 0;
  }
  Status(0);
  return 0;
} 
// If Solved Mark (0/1) here => [1]