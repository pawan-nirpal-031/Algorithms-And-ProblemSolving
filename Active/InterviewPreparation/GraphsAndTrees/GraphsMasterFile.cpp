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

void Test(){
  int n,m;
  cin>>n>>m;
  vector<int>g[n+1];
  vector<bool>vis(n+1,0);
  vector<int>low(n+1,0);
  vector<int>in(n+1,0);
  for(int i =0;i<m;i++){
      int x,y;
      cin>>x>>y;
      g[x].push_back(y);
      g[y].push_back(x);
  }
  FindingArticulationPoints(1,1,0,g,vis,low,in);
  for(int p : ArticulationPoints) cout<<p<<' ';
}


struct edge{
  int a,b,w;
};

bool comp(edge a,edge b){
  return a.w<b.w;
}


int Find(int u,int parent[]){
  return (parent[u]==u?u:(parent[u]=Find(parent[u],parent)));
}

void Union(int x,int y,int parent[],int sizes[]){
  int par_x = Find(x,parent);
  int par_y = Find(y,parent);
  if(par_x==par_y) return;
  if(sizes[par_x]>sizes[par_y]){
    parent[y] = par_x;
    sizes[par_x]+=sizes[par_y];
  }
}


void KruskalsMstAlgorithm(){
  int n,m;
  cin>>n>>m;
  int parent[n+1];
  int sizes[n+1];
  for(int i =1;i<=n;i++){
    parent[i] = i;
    sizes[i] = 1;
  }
  edge graph[m+1];
  for(int i =1;i<=m;i++) cin>>graph[i].a>>graph[i].b>>graph[i].w;
  sort(graph,graph+m,comp);
  int min_wt =0;
  for(int i =1;i<=m;i++){
    int para = Find(graph[i].a,parent);
    int parb = Find(graph[i].b,parent);
    if(para!=parb){
      min_wt+=graph[i].w;
      Union(para,parb,parent,sizes);
    }
  }
  cout<<min_wt;
}



void DijkstraSAlgorithm(){
  int n,m,src;
  cin>>n>>m>>src;
  vector<pair<int,int>>g[n+1];
  vector<bool>vis(n+1,0);
  vector<int>distance(n+1,INT_MAX);
  for(int i =0;i<m;i++){
      int x,y,w;
      cin>>x>>y>>w;
      g[x].push_back({y,w});
      g[y].push_back({x,w});
  }
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>process;
  process.push({0,src});
  distance[src] = 0;
  while(not process.empty()){
    int curr_d = process.top().first;
    int curr_node = process.top().second;
    process.pop();
    for(auto edge : g[curr_node]){
      if(curr_d+edge.second<distance[edge.first]){
        distance[edge.first] = curr_d+edge.second;
        process.push({distance[edge.first],edge.first});
      }
    }
  }
  for(int i =1;i<=n;i++) cout<<distance[i]<<" ";
}






int main(){
  FastIO;
  DijkstraSAlgorithm();
  return 0;
} 
