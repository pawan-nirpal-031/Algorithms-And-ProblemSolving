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

Implement disjoint sets union data structure. You have to perform queries of two types:

union u v — unite two sets that contain u and v, respectively;
get v — find the set to which v belongs to, find the minimal and the maximal element of the set, and the total number of elements in it.
Input
The first line of the input contains two integers n and m (1≤n,m≤3⋅105) — the number of elements and the number of queries. Next m lines contain queries, one per line. For a query union the line looks like union u v (1≤u,v≤n). For a query get the line looks like get v (1≤v≤n).

Output
For each operation get you should output the result on a separate line in the respected order. Each result should consist of three integers: the minimal element, the maximal element and the number of elements in the set.

*/


/*
Author's solution : 



*/




int Find(vector<pair<int,pair<int,int>>>&g,int u){
  return (g[u].first==u?u:g[u].first = Find(g,g[u].first)); 
}

void Union(vector<pair<int,pair<int,int>>>&g,int u,int v,vector<int>&Size){
  u = Find(g,u);
  v = Find(g,v);
  if(u==v) return;
  if(Size[v]>Size[u]) swap(v,u);
  g[v].first = u;
  g[u].second.first = max(g[u].second.first,g[v].second.first);
  g[u].second.second = min(g[u].second.second,g[v].second.second);
  Size[u]+=Size[v];
}

int main(){
  FastIO;
  int n,q;
  cin>>n>>q;
  vector<pair<int,pair<int,int>>>g(n+1,{0,{0,0}});
  vector<int>Size(n+1,1);
  for(int i =0;i<=n;i++) g[i].first =  g[i].second.first = g[i].second.second = i;
  while(q--){
    string cmd;
    cin>>cmd;
    if(cmd=="union"){
      int u,v;
      cin>>u>>v;
      Union(g,u,v,Size);
    }else{
      int x;
      cin>>x;
      int u = Find(g,x);
      cout<<g[u].second.second<<" "<<g[u].second.first<<' '<<Size[u]<<'\n';
    }
  }
  return 0;
} 
// If Solved Mark (0/1) here => [1]