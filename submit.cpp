#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007


void bfs(vector<ll>g[],vector<bool>&vis,vector<ll>&dis,ll s){
  queue<ll>q;
  q.push(s);
  vis[s]=1;
  while(!q.empty()){
    int curr = q.front();
    q.pop();
    for(ll v : g[curr]){
     if(!vis[v]){
        vis[v]=1;
        dis[v] = 1+dis[curr];
        q.push(v);
     }
    }
  }
}



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll f[11];
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    for(ll &x : f){
      x =0;
    }
    ll fmax =0;
    for(ll i=0;i<n;i++){
      ll x;
      cin>>x;
      f[x]++;
      fmax = max(fmax,f[x]);
    }
    ll ffmax =0;
    unordered_map<ll,ll>dict;
    for(ll fi=1;fi<=fmax;fi++){
      for(ll i=1;i<=10;i++){
        if(fi==f[i]){
          dict[fi]++;
        }
        ffmax = max(ffmax,dict[fi]);
      }
    }
    ll hmax = mod;
    for(auto p : dict){
      if(p.second == ffmax){
        hmax = min(hmax,p.first);
      }
    }
    cout<<hmax<<'\n';
  }
  return 0;
} 

