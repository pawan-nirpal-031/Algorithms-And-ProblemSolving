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

mplement disjont sets union data structure. You have to perform queries of two types:

union u v — unite two sets that contain u and v, respectively;
get u v — check that two elements u and v belong to the same set.
Input
The first line of the input contains two integers n and m (1≤n,m≤105) — the number of elements and the number of queries. Next m lines contain queries, one per line. For a query union the line looks like union u v (1≤u,v≤n). For a query get the line looks like get u v (1≤u,v≤n).

Output
Output the result of each query get one per line in the respected order: "YES", if the elements belong to the same set, and "NO", otherwise.

*/


/*
Author's solution : 



*/

int Find(int parent[],int u){
  return (parent[u]==u?u:parent[u] = Find(parent,parent[u]));
}

void Union(int parent[],int u,int v,vector<int>&Size){
  u = Find(parent,u);
  v = Find(parent,v);
  if(Size[v]>Size[u]) swap(u,v);
  parent[v] = u;
  Size[u]+=Size[v];
}

int main(){
  FastIO;
  int n,q;
  cin>>n>>q;
  int parent[n+1];
  for(int i =0;i<=n;i++) parent[i] = i;
  vector<int>Size(n+1,1);
  while(q--){
    string cmd;
    int u,v;
    cin>>cmd>>u>>v;
    if(cmd=="union") Union(parent,u,v,Size);
    else Status(Find(parent,u)==Find(parent,v));
  }
  return 0;
} 

// If Solved Mark (0/1) here => [1]