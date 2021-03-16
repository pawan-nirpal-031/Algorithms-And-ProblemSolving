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

class DpOnTreesproblems{
  public:
    int SubtreeSizes(vector<int>g[],vector<int>&dp,int u){
      if(g[u].empty()){
        return dp[u]= 1;
      }
      dp[u] = 1;
      for(int &v : g[u]){
        dp[u]+=SubtreeSizes(g,dp,v);
      }
      return dp[u];
    }

    int MaxCostToLeaf(vector<int>g[],vector<int>&cost,int u,vector<int>&dp){
      if(g[u].empty()){
        return dp[u] = cost[u];
      }
      dp[u] = cost[u];
      for(int &v : g[u]){
        dp[u] = max(dp[u],cost[u]+MaxCostToLeaf(g,cost,v,dp));
      }
      return dp[u];
    }

    int MaxCostSubset(vector<int>g[],vector<vector<int>>&dp,vector<int>&cost,int u){
      if(g[u].empty()){
        dp[u][0] =0;
        dp[u][1] = cost[u];
        return max(dp[u][0],dp[u][1]);
      }  

      dp[u][1] = cost[u];
      for(int &v : g[u]){
        dp[u][1] +=MaxCostSubset(g,dp,cost,v);
      }
      


      return max(dp[u][0],dp[u][1]);
    }





    // void IndependentSetUtil(vector<ll>g[],vector<ll>&white,vector<ll>&black,ll u,ll p){
    //   for(auto &v : g[u]){
    //     if(p!=v){
    //       IndependentSetUtil(g,white,black,v,u);
    //       white[u]*=(white[v]+black[v]);
    //       black[u]*=(white[v]);    
    //       white[u]%=Mod;
    //       black[u]%=Mod;
    //     }
    //   }
    // }

    void IndependentSet(){
      ll n;
      cin>>n;
      ll m = n-1;
      vector<ll>g[n+1];
      while(m--){
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
      }
      vector<ll>black(n+1,1);
      vector<ll>white(n+1,1);
      function <void(ll,ll)> IndependentSetUtil = [&](ll u,ll p){
          for(auto &v : g[u]){
            if(p!=v){
              IndependentSetUtil(v,u);
              white[u]*=(white[v]+black[v]);
              black[u]*=(white[v]);    
              white[u]%=Mod;
              black[u]%=Mod;
            }
          }
      };
      IndependentSetUtil(1,0);
      cout<<(black[1]+white[1])%Mod;
    }
};


int main(){
  FastIO;
  DpOnTreesproblems p;
  p.IndependentSet();
  return 0;
} 
