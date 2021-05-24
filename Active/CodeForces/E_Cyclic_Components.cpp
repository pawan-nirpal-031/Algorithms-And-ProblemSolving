// Problem Link : https://codeforces.com/contest/977/problem/E
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

You are given an undirected graph consisting of n vertices and m edges. Your task is to find the number of connected components which are cycles.

Here are some definitions of graph theory.

An undirected graph consists of two sets: set of nodes (called vertices) and set of edges. Each edge connects a pair of vertices. All edges are bidirectional (i.e. if a vertex a is connected with a vertex b, a vertex b is also connected with a vertex a). An edge can't connect vertex with itself, there is at most one edge between a pair of vertices.

Two vertices u and v belong to the same connected component if and only if there is at least one path along edges connecting u and v.

A connected component is a cycle if and only if its vertices can be reordered in such a way that:

the first vertex is connected with the second vertex by an edge,
the second vertex is connected with the third vertex by an edge,
...
the last vertex is connected with the first vertex by an edge,
all the described edges of a cycle are distinct.
A cycle doesn't contain any other edges except described above. By definition any cycle contains three or more vertices.

*/

int NofNodes = 0;
int SumOfDegrees = 0;

bool CanbeCycleutil(vector<int>g[],int u,vector<bool>&vis){
    if(g[u].size()!=2) return 0;
    vis[u] = 1;
    SumOfDegrees+=g[u].size();
    NofNodes+=1;
    for(int v : g[u]) if(not vis[v]) return CanbeCycleutil(g,v,vis);
    return 1;
}

void IsCycle(){
    int n,m;
    cin>>n>>m;
    vector<int>g[n+1];
    for(int i =0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<bool>vis(n+1,0);
    int ans = 0;
    for(int i =1;i<=n;i++){
       if(not vis[i]){
           SumOfDegrees = 0;
           NofNodes = 0;
           bool b = CanbeCycleutil(g,i,vis);
           if(SumOfDegrees==2*NofNodes and b) ans+=1;
       }
    }
    cout<<ans;
}

int main(){
  FastIO;
  IsCycle();
  return 0;
} 
// If Solved Mark (0/1) here => [0]