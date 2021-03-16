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
#define GoogleOutput(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


void Calheights(vector<ll>&heights,ll u,ll par,vector<ll>g[]){
  if(g[u].empty()){
     heights[u] = 1+ heights[par]; 
  }
  for(ll &v : g[u]){
    heights[v] = 1+heights[u];
    Calheights(heights,v,u,g);
  }
}

ll Subordinates(vector<ll>g[],ll u,vector<ll>&size){
  if(g[u].empty()){
    return size[u] =0;
  }
  size[u]=0;
  for(ll v : g[u]){
    size[u] += (1+ Subordinates(g,v,size));
  }
  return size[u];
}

ll MaximumMatching(vector<ll>g[],vector<vector<ll>>&dp,ll u,vector<ll>&SubtreeAns){
  if(g[u].empty()){
    return SubtreeAns[u] = 0;
  }

  


  return SubtreeAns[u] = max(dp[u][0],dp[u][1]);
}


ll IndependentSet(vector<ll>g[],vector<vector<ll>>&dp,ll u,bool colu,bool colpar){
  if(g[u].empty()){
    if(colu==0){
      
    }
  }
  dp[u][1] = 1;
  dp[u][0] = 0;
  for(auto &v : g[u]){
    dp[u][1]+=IndependentSet(g,dp,v,0,1);
    dp[u][0]+=(IndependentSet(g,dp,v,0,0)+IndependentSet(g,dp,v,1,0));
  }
  return dp[u][1]+dp[u][0];
}



void ExpectedPath(vector<ll>g[],ll u,ll par,vector<ll>&heights,vector<double>&prob){
  if(g[u].empty()){
    prob[u] = (prob[par]*1.0)/g[par].size();
  }
  if(g[u].size()>0){
    for(auto &v : g[u]){
      prob[v] = (prob[u]*1.0)/g[u].size();
      ExpectedPath(g,v,u,heights,prob);
    }
  }
}


int main(){
  FastIO;
  ll n;
  cin>>n;
  vector<ll>g[n+1];
  ll m = n-1;
  while(m--){
      ll x,y;
      cin>>x>>y;
      g[x].emplace_back(y);
  }
  vector<vector<ll>>dp(n+1,vector<ll>(n+1,0));
  cout<<IndependentSet(g,dp,1,0,0)+IndependentSet(g,dp,1,1,0);
  
  return 0;
} 
