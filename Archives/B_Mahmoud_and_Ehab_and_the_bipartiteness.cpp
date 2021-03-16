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



bool cases =1;

void dfs(vector<ll>g[],vector<ll>&vis,ll u,int cu){
    if(vis[u]==-1){
        vis[u] = cu;
        for(ll &v : g[u]){
            if(vis[v]==-1){
                dfs(g,vis,v,(cu xor 1));
            }
        }
    }
}

int main(){
  FastIO;
  ll n;
  cin>>n;
  vector<ll>g[n+1];
  vector<ll>vis(n+1,-1);
  ll m = n-1;
  while(m--){
    ll x,y;
    cin>>x>>y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  dfs(g,vis,1,0);
  ll c0=0;
  ll c1 =0;
  for(ll i =1;i<=n;i++) (vis[i]==0?c0+=1:c1+=1);
  ll ans =0;
  if(c0>c1){
      for(ll i=1;i<=n;i++){
          if(vis[i]==0){
              ans+=(c1-g[i].size());
          }
      }
  }else{
      for(ll i =1;i<=n;i++){
          if(vis[i]==1){
              ans+=(c0-g[i].size());
          }
      }
  }
  cout<<ans;
  return 0;
} 
