// Problem Link : https://codeforces.com/problemset/problem/862/B
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

Mahmoud and Ehab continue their adventures! As everybody in the evil land knows, Dr. Evil likes bipartite graphs, especially trees.

A tree is a connected acyclic graph. A bipartite graph is a graph, whose vertices can be partitioned into 2 sets in such a way, that for each edge (u, v) that belongs to the graph, u and v belong to different sets. You can find more formal definitions of a tree and a bipartite graph in the notes section below.

Dr. Evil gave Mahmoud and Ehab a tree consisting of n nodes and asked them to add edges to it in such a way, that the graph is still bipartite. Besides, after adding these edges the graph should be simple (doesn't contain loops or multiple edges). What is the maximum number of edges they can add?

A loop is an edge, which connects a node with itself. Graph doesn't contain multiple edges when for each pair of nodes there is no more than one edge between them. A cycle and a loop aren't the same .

Input
The first line of input contains an integer n — the number of nodes in the tree (1 ≤ n ≤ 105).

The next n - 1 lines contain integers u and v (1 ≤ u, v ≤ n, u ≠ v) — the description of the edges of the tree.

It's guaranteed that the given graph is a tree.

Output
Output one integer — the maximum number of edges that Mahmoud and Ehab can add to the tree while fulfilling the conditions.

*/


/*
Author's solution : 



*/

void Color(vector<int>g[],int u,bool cu,vector<bool>&vis,vector<bool>&col){
    vis[u] = 1;
    col[u] = cu;
    for(int v : g[u])  if(not vis[v]) Color(g,v,cu xor 1,vis,col);
}

int main(){
  FastIO;
  int n;
  cin>>n;
  vector<int>g[n+1];
  vector<bool>vis(n+1,0),col(n+1,0);
  for(int i =0;i<n-1;i++){
      int x,t;
      cin>>x>>t;
      g[x].push_back(t);
      g[t].push_back(x);
  }
  Color(g,1,1,vis,col);
  ll ans = 0;
  int othr = 0;
  for(int i =1;i<=n;i++){
      if(col[i]==col[1]) continue;
      othr+=1;
  }
  for(int i =1;i<=n;i++){
      if(col[i]!=col[1]) continue;
      ans+=(othr-g[i].size());
  }
  cout<<ans;
  return 0;
} 
// If Solved Mark (0/1) here => []