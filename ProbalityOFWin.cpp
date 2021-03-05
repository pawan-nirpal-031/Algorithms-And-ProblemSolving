#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod  200003//1000000007
#define pub(a) push_back(a)
#define mp(a,b) make_pair(a,b)



int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--){
      ll n,m;
      cin>>n>>m;
      double dp[n+2][m+2];
      for(ll i=0;i<=n;i++){
        for(ll j =0;j<=m;j++){
          dp[i][j] =0;
        }
      }
      for(ll i=0;i<=n;i++){
         for(ll j = 0;j<=m;j++){
            if(i==0|| j==0){
               dp[i][j] =1;
               continue;
            }
            dp[i][j] = (((i*1.0)/(i+j)) + ( ((j*1.0)/(i+j))*(((j-1)*(1.0))/(i+j-1)*(dp[i][j-2]))));
         }
      }
      cout<<fixed<<setprecision(6)<<dp[n][m]<<'\n';
   }
   return 0;
}