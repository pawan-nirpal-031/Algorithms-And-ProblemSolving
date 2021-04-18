// Problem Link : https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/social-networking-graph/
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
In a social networking site, people are connected with other people. The whole system appears as a giant 
connected graph. In this question, you are required to answer the total number of people connected at t nodes 
away from each other (t distance connectivity). For example: Two persons directly connected are at 1 distance 
connectivity. While the two persons having a common contact without having direct connectivity, are at 2 distance 
connectivity. First line of input line contains, two integers n and e, where n is the nodes and e are the edges. 
Next e line will contain two integers u and v meaning that node u and node v are connected to each other in 
undirected fashion. Next line contains single integer, m, which is number of queries. Next m lines, each have 
two inputs, one as source node and other as a required t distance connectivity which should be used to process 
query.
*/


vector<int> SingleSourceShortestPathBFSUtil(vector<int>g[],vector<bool>&vis,int root,int n){
  queue<int>que;
  que.push(root);
  vector<int>dist(n,0);
  dist[root] = 0;
  while(not que.empty()){
    int curr = que.front();
    que.pop();
    vis[curr] = 1;
    for(int v : g[curr]){
      if(not vis[v]){
        vis[v] = 1;
        que.push(v);
        dist[v] = 1 + dist[curr];
      }
    }
  }
  return dist;
}

int main(){
  FastIO;
  int n,m;
  cin>>n>>m;
  vector<int>g[n];
  while(m--){
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int q;
  cin>>q;
  while(q--){
    int v,d;
    cin>>v>>d;
    vector<bool>vis(n,0);
    vector<int>dist = SingleSourceShortestPathBFSUtil(g,vis,v,n);
    int cnt =0;
    for(int i =0;i<n;i++) if(dist[i]==d) cnt+=1;
    cout<<cnt<<'\n';
  }
  return 0;
} 
// If Solved Mark (0/1) here => [1]