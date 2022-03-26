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




bool CheckBiPartite(vector<int>g[],int u,vector<bool>&vis,vector<bool>&colours,int col){
    vis[u] = 1;
    colours[u] = col;
    for(int v : g[u]){
        if(not vis[v]) return CheckBiPartite(g,v,vis,colours,(col xor 1));
        else if(colours[v]==colours[u]) return 0;
    }
    return 1;
}

vector<pair<int,int>>back_edges;
vector<int>parent;

bool CycleDetection(vector<int>g[],int u,int par,vector<bool>&vis){
    vis[u] =1; 
    parent[u] = par;
    for(int v : g[u]){
        if(v==par) continue;
        if(not vis[v]) return CycleDetection(g,v,u,vis);
        else{
          back_edges.push_back({u,v});
          return 1;
        }
    }
    return 0;
}

void Cycle(int n,vector<int>g[]){
  vector<bool>vis(n);
  parent.resize(n);
  bool has_cycle = 0;
  for(int i =1;i<=n;i++) if(not vis[i])  has_cycle = has_cycle or CycleDetection(g,i,0,vis);
  Status(has_cycle);
  if(has_cycle){
    pair<int,int>edge = back_edges.back();
    back_edges.pop_back();
    int s = edge.second;
    int e = edge.first;
    int i =0;
    while(parent[e]!=s){
      i++;
      cout<<e<<" ";
      e = parent[e];
    }
    cout<<e<<' '<<parent[e];
  }
}


void TopologicalSort(vector<int>&in,vector<int>&res,vector<int>g[],int n){
  queue<int>process;
  for(int i =1;i<=n;i++) if(in[i]==0) process.push(i);
  while(not process.empty()){
    int curr = process.front();
    process.pop();
    res.push_back(curr);
    for(int out : g[curr]){
      if(in[out]){
        in[out]--;
        if(in[out]==0) process.push(out);
      }
    }
  }
}


int timer =0;
vector<pair<int,int>>InOutTimes;
void InOutIimeComputaion(int u,vector<int>g[],vector<pair<int,int>>&Inout,vector<bool>&vis){
  vis[u] = 1;
  Inout[u].first = timer++;
  for(int v : g[u]){
    if(not vis[v]) InOutIimeComputaion(v,g,Inout,vis);
  }
  Inout[u].second = timer++;
}

vector<pair<int,int>>bridges;
void FindBridges(int u,int par,vector<int>g[],vector<bool>&vis,vector<int>&low,vector<int>&in){
  vis[u] =1;
  low[u] = in[u] = timer++;
  for(int v : g[u]){
    if(v==par) continue;
    if(not vis[v]){ // only forward edge can  be a bridge candidate
      FindBridges(v,u,g,vis,low,in);
      if(low[v]>low[u]) bridges.push_back({u,v});
      low[u] = min(low[u],low[v]); // if chinld can reach lower in time ancestor so can this node beacause there is a path btwn them which is via child,
    }else low[u] = min(low[u],in[v]); // minimizing low time for child
  }
}


vector<int>ArticulationPoints;
void FindingArticulationPoints(int u,int root,int par,vector<int>g[],vector<bool>&vis,vector<int>&low,vector<int>&in){
  vis[u] = 1; 
  low[u] = in[u] = timer++;
  int number_of_dfs_subtrees =0;
  for(int v : g[u]){
    if(v==par) continue;
    if(not vis[v]){
      FindingArticulationPoints(v,root,u,g,vis,low,in);
      low[u] = min(low[u],low[v]);
      if(low[v]>=in[u] and u!=root) ArticulationPoints.push_back(u);
      number_of_dfs_subtrees+=1;
    }else{
      low[u] = min(low[u],in[v]);
    }
  }
  if(u==root and number_of_dfs_subtrees>1) ArticulationPoints.push_back(u);
}

void StronglyConnectedComponents(int n,vector<int>g[]){
  
}


stack<int>toposort;
void TopologicalSortDFS(vector<int>g[],vector<int>&vis,int u){
    vis[u] =1;
    for(int v : g[u]) if(not vis[v]) TopologicalSortDFS(g,vis,v);
    toposort.push(u);
}

struct edge{
  int u,v,weight;
};

void BellmanFordShortestPath(vector<edge>graph,int n,int src){
  vector<int>dist(n,INT_MAX);
  dist[src] =0;
  for(int i =0;i<n-1;i++){
    for(edge ed : graph){
      if(dist[ed.u]+ed.weight<dist[ed.v]) dist[ed.v] = dist[ed.u]+ed.weight;
    }
  }
  for(edge ed : graph){
    if(dist[ed.u]+ed.weight<dist[ed.v]) {
      cout<<"Cycle exists";
      return;
    }
  }
  for(int i =0;i<n;i++) cout<<dist[i]<<" ";
}

int main(){
  FastIO;
  int n,m;
  cin>>n>>m;
  vector<edge>graph(m,{0,0,0});
  for(int i =0;i<m;i++){
    int x,y,w;
    cin>>x>>y>>w;
    graph[i].u = x;
    graph[i].v = y;
    graph[i].weight = w;
  }
  int s;
  cin>>s;
  BellmanFordShortestPath(graph,n,s);
  return 0;
} 
