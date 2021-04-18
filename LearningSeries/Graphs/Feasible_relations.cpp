// Problem Link : https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/feasible-relations/
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


void AssignComponents(vector<int>g[],int u,vector<bool>&vis,int comp_no,vector<int>&compontent_no){
    if(vis[u]) return;
    vis[u]= 1;
    compontent_no[u] = comp_no;
    for(int v : g[u]) AssignComponents(g,v,vis,comp_no,compontent_no);
}

void Solve(){
  int n,m;
  cin>>n>>m;
  vector<int>equal[n+1];
  vector<int>comp_no(n+1,0);
  vector<pair<int,int>>unequal;
  while(m--){
      int x,y;
      string s;
      cin>>x>>s>>y;
      if(s=="="){
          equal[x].push_back(y);
          equal[y].push_back(x);
      }else{
          unequal.push_back({x,y});
      }
  }
  int k =0;
  vector<bool>vis(n+1,0);
  for(int i =1;i<=n;i++){
      if(not vis[i]){
          k+=1;
          AssignComponents(equal,i,vis,k,comp_no);
      }
  }
  for(auto p : unequal){
      int u = p.first;
      int v = p.second;
      if(comp_no[u]==comp_no[v]){
          Status(0);
          return;
      }
  }
  Status(1);
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--)
  Solve();
  return 0;
} 
// If Solved Mark (0/1) here => [1]