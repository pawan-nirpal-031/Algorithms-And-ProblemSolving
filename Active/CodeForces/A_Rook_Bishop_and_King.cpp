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
Little Petya is learning to play chess. He has already learned how to move a king, a rook and a bishop. Let us remind you the rules of moving chess pieces. A chessboard is 64 square fields organized into an 8 × 8 table. A field is represented by a pair of integers (r, c) — the number of the row and the number of the column (in a classical game the columns are traditionally indexed by letters). Each chess piece takes up exactly one field. To make a move is to move a chess piece, the pieces move by the following rules:

A rook moves any number of fields horizontally or vertically.
A bishop moves any number of fields diagonally.
A king moves one field in any direction — horizontally, vertically or diagonally.

Petya is thinking about the following problem: what minimum number of moves is needed for each of these pieces to move from field (r1, c1) to field (r2, c2)? At that, we assume that there are no more pieces besides this one on the board. Help him solve this problem.

*/

int main(){
  FastIO;
  int r1,c1,r2,c2;
  cin>>r1>>c1>>r2>>c2;
  int rook = 2;
  int bishop = 0;
  if(r1==r2 or c1==c2) rook-=1;
  if(abs(c1-c2)!=0 and (abs(r1-r2)==abs(c1-c2))) bishop = 1;
  
  return 0;
} 
// If Solved Mark (0/1) here => []