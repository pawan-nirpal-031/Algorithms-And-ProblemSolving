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


void UnitTests(){
    
}


bool cases =1;

void RandomGenrator(){

}

// int SmallestKworthy(vector<vector<int>>&g,int i,int j,ll k,int n){
  // int r = n-1;
  // int l = i;
  // while(r>=l){
  //   int mid = ((r-l)>>1);
  //   // if()
  // }
// }

void WorthyMatrix(){
  int n,m;
  cin>>n>>m;
  ll k;
  cin>>k;
  vector<vector<int>>g(n,vector<int>(m,0));
  for(int i =0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>g[i][j];
    }
  }
  for(int i=0;i<n;i++){      
    for(int j=0;j<m;j++) g[i][j]+=(j>0?g[i][j-1]:0);
  }
  for(int i =0;i<n;i++){
    for(int j =0;j<m;j++) g[i][j]+=(i>0?g[i-1][j]:0);
  }
  // for(int i =0;i<n;i++){
  //   for(int j =0;j<m;j++){
  //     int s =  SmallestKworthy(g,i,j,k,n);
  //   }
  // }
  

}

void CycleFinding(vector<int>g[],int u,int par,vector<int>&vis){
  if(not vis[u]){
    vis[u] = 1;
    for(int v : g[u]){
      if(not vis[v]) CycleFinding(g,v,u,vis);
      else if(vis[v]==1) return;
    }
    vis[u] = 2;
  }
}

int main(){
   FastIO;
  int n,m;
  cin>>n>>m;
  vector<int>g[n+1];
  while (m--){
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int>vis(n+1,0);
  for(int i =1;i<=n;i++){
    if(vis[i]==1){
      Status(1);
      return 0;
    }
  }
  Status(0);
  return 0;
} 
