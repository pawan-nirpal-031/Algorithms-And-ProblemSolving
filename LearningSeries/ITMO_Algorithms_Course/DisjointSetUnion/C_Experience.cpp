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

In a novel online game, the players fight the monsters and get the experience, as usual. To fight monsters players join together in raid teams. After the destruction of the monster, all the players of the team get the same amount of experience points. The special feature of the game is that a team cannot be split up and no one can leave a team. The only supported operation is to join two teams together.

Since there are already a lot of people playing the game, you are asked to maintain the experience points of the players.

Input
The first line of the input contains two integers n and m (1 ≤ n, m ≤ 2·105) — the number of players and the number of queries.

Next m lines contain the description of queries, one per line. A query can be of three types:

join X Y — join two teams to which players X and Y belong to (if they are already in the same team, nothing changes).
add X V — add V (1 ≤ V ≤ 100) experience points to each player in a team to which player X belongs to.
get X — output the current number of experience points of player X.
Initially, each player has 0 experience points and each of the player is in its own team of size one.

Output
For each query get X output the current number of experience points of player X on a separate line.

*/


/*
Author's solution : 



*/

int main(){
  FastIO;
  int n,m;
  cin>>n>>m;
  
  return 0;
} 
// If Solved Mark (0/1) here => []