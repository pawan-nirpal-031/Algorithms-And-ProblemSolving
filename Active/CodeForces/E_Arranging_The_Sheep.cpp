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

You are playing the game "Arranging The Sheep". The goal of this game is to make the sheep line up. The level in the game is described by a string of length n, consisting of the characters '.' (empty space) and '*' (sheep). In one move, you can move any sheep one square to the left or one square to the right, if the corresponding square exists and is empty. The game ends as soon as the sheep are lined up, that is, there should be no empty cells between any sheep.

For example, if n=6 and the level is described by the string "**.*..", then the following game scenario is possible:

the sheep at the 4 position moves to the right, the state of the level: "**..*.";
the sheep at the 2 position moves to the right, the state of the level: "*.*.*.";
the sheep at the 1 position moves to the right, the state of the level: ".**.*.";
the sheep at the 3 position moves to the right, the state of the level: ".*.**.";
the sheep at the 2 position moves to the right, the state of the level: "..***.";
the sheep are lined up and the game ends.
For a given level, determine the minimum number of moves you need to make to complete the level.

*/

int main(){
  FastIO;
  
  return 0;
} 
// If Solved Mark (0/1) here => []