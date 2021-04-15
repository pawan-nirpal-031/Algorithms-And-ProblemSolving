// Problem Link : https://www.codechef.com/problems/FIRESC
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

ll nn;
void FireEscape(int u, vector<bool>&vis,vector<int>g[]){
    if(vis[u]) return;
    vis[u] = 1;
    nn+=1;
    for(int v : g[u]) FireEscape(v,vis,g);
}

void Solve(){
    ll n,m;
    cin>>n>>m;
    vector<int>g[n+1];
    vector<bool>vis(n+1,0);
    while(m--){
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int k =0;
    ll cnt = 1;
    for(int i=1;i<=n;i++){
        if(not vis[i]){
            k+=1;
            nn = 0;
            FireEscape(i,vis,g);
            cnt = ((cnt%Mod)*(nn%Mod))%Mod;
        }
    }
    cout<<k<<' '<<cnt<<'\n';
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      Solve();
  }
  return 0;
} 
// If Solved Mark (0/1) here => [1]