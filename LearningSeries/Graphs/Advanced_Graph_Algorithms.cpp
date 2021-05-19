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


int bridge_time =0;

void FindingBridesUtil(int u,int par,vector<int>g[],vector<bool>&vis,vector<int>&Intime,vector<int>&lowTime, vector<pair<int,int>>&bridges){
    vis[u] = 1;
    Intime[u] = lowTime[u] = bridge_time++;
    for(int v : g[u]){
        if(v==par) continue;
        if(vis[v]) lowTime[u] = min(lowTime[u],Intime[v]); // this edge u-v is a back-edge 
        else{ 
            FindingBridesUtil(v,u,g,vis,Intime,lowTime,bridges); // this one is a forw-edge
            if(lowTime[v]>Intime[u]){
                bridges.push_back({u,v});
            }
            lowTime[u] = min(lowTime[u],lowTime[v]); // the current node tries to reduce it's low time ie. if it's child node can reach a lower ancestor other than this par node, then this curr node can also reach the same ancestor vis that child so effectively we are just updating the reach of current node 
        }
    }
}


void FindingBrides(){
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
    vector<int>InTime(n+1,0),lowTime(n+1,0);
    vector<pair<int,int>>bridges;
    FindingBridesUtil(1,-1,g,vis,InTime,lowTime,bridges);
    cout<<'\n';
    for(auto b : bridges){
        cout<<b.first<<" "<<b.second<<'\n';
    }
}




void ArticulationPoints(){

}


int main(){
  FastIO;
  
  return 0;
} 
