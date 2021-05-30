// Problem Link : https://www.codechef.com/COOK129C/problems/TLAPM
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


/*
Problem Statement : 

*/
void Solve(){
    vector<vector<ll>>dp(1001,vector<ll>(1001,0));
    dp[1][1] = 1;
    for(int i = 2;i<=1000;i++){
        dp[1][i] = i-1+dp[1][i-1];
    }
    dp[2][1000] = 1000+dp[1][1000];
    for(int i = 2;i<=1000;i++){
        for(int j =1;j<=1000;j++){
            if(j<1000) dp[i][j] = 1+dp[i-1][j+1];
            else dp[i][j] = (i<=2?dp[i][j]:dp[i-1][j]+1+(dp[i-1][j]-dp[i-2][j]));
        }
    }
    int t;
    cin>>t;
    while(t--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        ll ans = 0;
        for(int i = x1;i<x2;i++){
            ans+=dp[i][y1];
        }
        for(int j = y1;j<=y2;j++){
            ans+=dp[x2][j];
        }
        cout<<ans<<'\n';
    }
}

int main(){
  FastIO;
  Solve();
  return 0;
} 
// If Solved Mark (0/1) here => []