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

There is an N by M grid. A thief is trying to escape from a policeman. The thief is currently in cell (x,y) in the grid, while the policeman is in cell (a,b). Cells are numbered from 1 to N, top to bottom, and 1 to M, left to right. Both of them are at different cells initially.

Both of them take turns alternatively. First it is the thief's turn, then the police's, and so on. The thief needs to reach the cell (N,M) to escape. In his turn, the thief can move either right, or down, from his current cell. In other words, if his current cell is (i,j), then in one turn, he can either go to cell (i,j+1) or the cell (i+1,j). He can't stop, i.e., he needs to move during each of his turns. The policeman can move right, down, or (right + down) in one turn. In other words, in one turn, if his current cell is (i,j), then he can go to the cell (i,j+1), the cell (i+1,j) or the cell (i+1,j+1). It is not compulsory for the policeman to move every turn, i.e., he can choose to stay in his current cell in a particular turn of his. Neither of them are in cell (N,M) at the start.

The policeman catches the thief if he's in the same cell as the thief at any point of time, and he had reached that cell before the thief. If the thief reaches the cell (N,M) before the policeman, then he shall escape. Find if the thief shall escape, or the policeman shall catch him, if both of them move optimally, and if both of them have perfect knowledge of the other person's location at all times. Print YES if the thief shall escape, else print NO if the policeman shall catch him.

*/


void SolveCase(){
    int n,m,x,y,a,b;
    cin>>n>>m>>x>>y>>a>>b;
    int thief_dist = abs(n-x) + abs(m-y);
    int police_dist = min(n-a,m-b);
    int left = police_dist;
    if(a+left!=n and b+left==m) police_dist = police_dist + (n - (a+left));
    if(a+left==n and b+left!=m) police_dist = police_dist + (m - (b+left));
    Status(thief_dist<=police_dist);
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) SolveCase();
  return 0;
} 
// If Solved Mark (0/1) here => []