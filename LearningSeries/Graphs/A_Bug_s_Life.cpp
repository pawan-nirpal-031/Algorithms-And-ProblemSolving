// Problem Link : https://www.spoj.com/problems/BUGLIFE/
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
#define Status(b) (cout<<(b?"No suspicious bugs found!\n":"Suspicious bugs found!\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x

bool BipartiteTestUtil(int u,bool col_u,vector<bool>&vis,vector<bool>&col,vector<int>g[]){
  vis[u] = 1;
  col[u] = col_u;
  for(int v : g[u]){
    if(not vis[v]){
       if(not BipartiteTestUtil(v,col_u^1,vis,col,g)) return 0;
    }
    else {
      if(col[v]==col[u]) return 0;
    }
  }
  return 1; 
}

void BugLife(int x){
  int n,m;
  cin>>n>>m;
  vector<int>g[n+1];
  while(m--){
      int x,y;
      cin>>x>>y;
      g[x].push_back(y);
      g[y].push_back(x);
  }
  vector<bool>vis(n+1,0),col(n+1,0);
  cout<<"Scenario #"<<x<<":\n";
  bool log = 1;
  for(int i =1;i<=n;i++){ // be sure to check for all the components
      if(not vis[i]){
        log = BipartiteTestUtil(i,1,vis,col,g);
        if(log==0){
            Status(0);
            return;
        }else continue;
      }
  }
  Status(1);
}

int main(){
  FastIO;
  int t;
  cin>>t;
  for(int x =1;x<=t;x++) BugLife(x);
  return 0;
} 
// If Solved Mark (0/1) here => [1]