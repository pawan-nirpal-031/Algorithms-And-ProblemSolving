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



bool cases =0;

void CheckATree(vector<int>g[],int u,vector<int>&vis){
  if(vis[u]) return;
  vis[u] = 1;
  for(int v : g[u]) CheckATree(g,v,vis);
}


void SolveCase(){
  int n,m;
  cin>>n>>m;
  if(m!=n-1){
    Status(0);
    return;
  }
  int m_ = m;
  vector<int>g[n+1];
  vector<int>vis(n+1,0);
  while(m--){
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  CheckATree(g,1,vis);
  bool yes =1;
  for(int i =1;i<=n;i++) if(not vis[i]) yes =0;
  Status(m_==n-1 and yes);
}

int main(){
  FastIO;
  int t = 1;
  if(cases) cin>>t;
  while(t--){
     SolveCase();
  }
  return 0;
} 
// If Solved Mark (0/1) here => [1]