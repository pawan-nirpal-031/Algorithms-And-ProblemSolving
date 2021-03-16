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





void testCase(){
  int n,m;
  cin>>n>>m;
  vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
  for(int i=1;i<=n;i++){
    for(int j =1;j<=m;j++){
      char c;
      cin>>c;
      if(c=='#'){
        dp[i][j] = -1;
      }else{
        dp[i][j] =0;
      }
    }
  }
  for(int i=1;i<=m;i++){
      if(dp[n][i]!=-1){
         dp[n][i] = 1;
      }
  }
  for(int i=1;i<=n;i++){
    if(dp[i][m]!=-1){
      dp[i][m] = 1;
    }
  }
   for(int i=n-1;i>=1;i--){
     for(int j = m-1;j>=1;j--){
       if(dp[i][j]!=-1){
         if(dp[i][j+1]!=-1){
           dp[i][j] = (dp[i][j+1]%Mod)%Mod;
         }
         if(dp[i+1][j]!=-1){
           dp[i][j] = (1+dp[i+1][j]%Mod)%Mod;
         }
         if(dp[i+1][j+1]!=-1){
           dp[i][j] = (1+dp[i+1][j+1]%Mod)%Mod;
         }
       }
     }
   }
   for(int i=1;i<=n;i++){
     for(int j = 1;j<=m;j++){
       cout<<dp[i][j]<<' ';
     }
     cout<<'\n';
   }
   //cout<<dp[1][1];
}

void Solve(){
  ll a,b;
  cin>>a>>b;
  cout<<(((a)<<1)+100)-b;
}


int main(){
  FastIO;
  int t=1;
  while(t--){
     Solve();
  }
  return 0;
} 

