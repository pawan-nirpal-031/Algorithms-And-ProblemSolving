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


bool HasEdge(int u,int v,vector<int>g[]){
    for(int x : g[u]) if(x==v) return 1;
    return 0;
}

void HamiltionionPathsUtil(int curr,int start,vector<int>g[],vector<bool>&vis,vector<vector<int>>&hamiltionionpaths,int n,vector<int>&path,int vis_count){
    if(path.size()==n){
        if(HasEdge(curr,start,g)){
             cout<<"checking paths bwn "<<curr<<" and "<<start<<endl;
             hamiltionionpaths.push_back(path);
        }
        return;
    }
    vis[curr] = 1;
    for(int adj : g[curr]){
        if(not vis[adj]){
            path.push_back(adj);
            HamiltionionPathsUtil(adj,start,g,vis,hamiltionionpaths,n,path,vis_count+1);
            path.pop_back();
        }
    }
    vis[curr] =0;
}

void HamiltionionPaths(vector<int>g[],vector<bool>&vis,vector<vector<int>>&hamiltionionpaths,int n){
    vector<int>path;
    path.push_back(0);
    HamiltionionPathsUtil(0,0,g,vis,hamiltionionpaths,n,path,1);
    if(hamiltionionpaths.size()==0){
        cout<<"no cycles"<<endl;
    }else{
        for(auto v : hamiltionionpaths){
            for(int x : v) cout<<x<<' ';
            cout<<'\n';
        }
    }
}   




int main(){
  FastIO;
//   int n,m;
//   cin>>n>>m;
//   vector<int>g[n];
//   while(m--){
//       int x,y;
//       cin>>x>>y;
//       g[x].push_back(y);
//       g[y].push_back(x);
//   }
//   vector<bool>vis(n,0);
//   vector<vector<int>>hamiltionionpaths;
//   HamiltionionPaths(g,vis,hamiltionionpaths,n);
  return 0;
} 
