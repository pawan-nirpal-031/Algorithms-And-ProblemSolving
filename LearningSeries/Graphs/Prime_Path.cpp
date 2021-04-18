// Problem Link : 
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

bool OneDigitChange(int a,int b){
    int d = 0;
    while(a>0){
      if(a%10!=b%10) d+=1;
      a/=10;
      b/=10;
    }
    return d==1;
}


int main(){
  FastIO;
  int n = 10000;
  vector<bool>primes(10000,1);
  primes[0] = primes[1] = 0;
  for(int i =2;i*i<=n;i++){
      if(primes[i]){
        for(int j = i*i;j<=n;j+=i) primes[j] =0;
      }
  }
  vector<int>candidates;
  for(int i = 1000;i<=n;i++) if(primes[i]) candidates.push_back(i);
  int s = candidates.size();
  vector<int>g[10000];
  for(int i =0;i<s;i++){
    for(int j =i+1;j<s;j++){
      if(OneDigitChange(candidates[i],candidates[j])){
        int u = candidates[i];
        int v = candidates[j];
        g[u].push_back(v);
        g[v].push_back(u);
      }
    }
  }
  int q;
  cin>>q;
  while(q--){
    int a,b;
    cin>>a>>b;
    queue<int>que;
    vector<int>dist(n,0);
    que.push(a);
    dist[a] = 0;
    vector<int>vis(n,0);
    while(not que.empty()){
      int curr = que.front();
      que.pop();
      vis[curr] = 1;
      if(curr==b) break;
      for(int v : g[curr]){
        if(not vis[v]){
          que.push(v);
          vis[v] = 1;
          dist[v]= 1 + dist[curr];
        }
      } 
    }
    cout<<dist[b]<<"\n";
  }

  return 0;
} 
// If Solved Mark (0/1) here => [1]