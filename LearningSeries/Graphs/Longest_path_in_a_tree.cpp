// Problem Link : https://www.spoj.com/problems/PT07Z/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Infinity (ll)1e18
#define Append(a,x) a.push_back(x)
#define Pair(a,b) make_pair(a,b)
#define Clear(a) for(ll &x : a){x=0;}
#define Point(x) std::fixed<<setprecision(15)<<x
#define SetBits(x) __builtin_popcount(x);
#define DebugCase(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Status(b) (cout<<(b?"YES\n":"NO\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x

int max_dist,max_node;
void DaimeterOfATree(int u,int dist_u,vector<bool>&vis,vector<int>g[]){
    vis[u] = 1;
    if(dist_u>max_dist){
        max_dist = dist_u;
        max_node = u;
    }
    for(int v : g[u]) if(not vis[v]) DaimeterOfATree(v,dist_u+1,vis,g);
}

int main(){
  FastIO;
  int n;
  cin>>n;
  vector<int>g[n+1];
  vector<bool>vis(n+1,0);
  for(int i =0;i<n-1;i++){
      int x,y;
      cin>>x>>y;
      g[x].push_back(y);
      g[y].push_back(x);
  }
  max_dist =0;
  DaimeterOfATree(1,0,vis,g);
  for(int i=1;i<=n;i++) vis[i] =0;
  max_dist =0;
  int u = max_node;
  DaimeterOfATree(max_node,0,vis,g);
  int v = max_node;
  cout<<max_dist;
  return 0;
} 
// If Solved Mark (0/1) here => [1]