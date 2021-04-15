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

void SingleSourceShortestPathDFSUtilOnTrees(int u,vector<ll>&info,vector<int>g[],int par){
  if(info[u]!=Mod){
    info[u] = min(info[u],1+info[par]);
    return;
  }else{
    info[u] = 1+info[par];
    for(int v : g[u]) SingleSourceShortestPathDFSUtilOnTrees(v,info,g,u);
  }
}

void SingleSourceShortestPathDFSOnTrees(){ // works on on trees 
  int n,m;
  cin>>n>>m;
  int src;
  cin>>src;
  vector<int>g[n+1];
  while(m--){
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<ll>info(n+1,Mod);
  info[0] = -1;
  SingleSourceShortestPathDFSUtilOnTrees(src,info,g,0);
  for(int i =1;i<=n;i++){
    cout<<i<<" "<<info[i]<<'\n';
  }
}

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



bool CycleDetectionUtil(int u,int par,vector<bool>&vis,vector<int>g[]){
  vis[u] =1;
  for(int v : g[u]){
    if(not vis[v]) return CycleDetectionUtil(v,u,vis,g);
    else {
      if(v!=par) return 1;
    }
  }
  return 0;
}

void CycleDetection(){
  int n,m;
  cin>>n>>m;
  vector<int>g[n+1];
  while(m--){
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<bool>vis(n+1,0);
  Status(CycleDetectionUtil(1,0,vis,g));
}


int Timer;
void InOutTimeForQueryProcessingUtil(int u,vector<bool>&vis,vector<int>g[],vector<pair<int,int>>&InOut){
  vis[u] = 1;
  InOut[u].first = ++Timer;
  for(int v : g[u]) if(not vis[v]) InOutTimeForQueryProcessingUtil(v,vis,g,InOut);
  InOut[u].second = ++Timer;
}

void InOutTimeForQueryProcessing(){
  int n,m;
  cin>>n>>m;
  Timer =0;
  vector<int>g[n+1];
  vector<bool>vis(n+1,0);
  while(m--){
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<pair<int,int>>InOutData(n+1,{0,0});// InOutData = (Intime,Outime)
  InOutTimeForQueryProcessingUtil(1,vis,g,InOutData);
  for(int i =1;i<=n;i++) cout<<i<<", In : "<<InOutData[i].first<<" Out : "<<InOutData[i].second<<'\n';
}

int main(){
  FastIO;
  InOutTimeForQueryProcessing();
  return 0;
} 
