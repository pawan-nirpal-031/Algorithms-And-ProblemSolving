// Problem Link : https://codeforces.com/contest/1547/problem/A
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

There are three cells on an infinite 2-dimensional grid, labeled A, B, and F. Find the length of the shortest path from A to B if:

in one move you can go to any of the four adjacent cells sharing a side;
visiting the cell F is forbidden (it is an obstacle).
Input
The first line contains an integer t (1≤t≤104) — the number of test cases in the input. Then t test cases follow. Before each test case, there is an empty line.

Each test case contains three lines. The first one contains two integers xA,yA (1≤xA,yA≤1000) — coordinates of the start cell A. The second one contains two integers xB,yB (1≤xB,yB≤1000) — coordinates of the finish cell B. The third one contains two integers xF,yF (1≤xF,yF≤1000) — coordinates of the forbidden cell F. All cells are distinct.

Coordinate x corresponds to the column number and coordinate y corresponds to the row number (see the pictures below).

Output
Output t lines. The i-th line should contain the answer for the i-th test case: the length of the shortest path from the cell A to the cell B if the cell F is not allowed to be visited.

*/


/*
Author's solution : 



*/

void solve(){
    int ax,ay,bx,by,fx,fy;
    cin>>ax>>ay>>bx>>by>>fx>>fy;
    if((ax==bx and bx==fx) or (ay==by and by==fy)){
        if(ax==bx and bx==fx)  cout<<abs(ay-by)+((fy>min(ay,by) and fy<max(ay,by))?2:0)<<'\n';
        else cout<<abs(ax-bx)+((fx>min(ax,bx) and fx<max(ax,bx))?2:0)<<'\n';
    }else cout<<abs(ax-bx)+abs(ay-by)<<'\n';
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      solve();
   }
  return 0;
} 
// If Solved Mark (0/1) here => [1]