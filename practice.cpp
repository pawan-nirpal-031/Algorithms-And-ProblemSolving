#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define pub(a) push_back(a)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<ll>dp(n+1,mod);
    dp[0] = dp[1] =0;
    vector<ll>path;
    for(ll i =2;i<=n;i++){
        ll x = dp[i];
        ll y = dp[i];
        if(i%2==0){
            x = min(1+dp[i/2],dp[i]);
        }else if(i%3==0){
            y = min(1+dp[i/3],dp[i]);
        }
        dp[i] = min(1+dp[i-1],min(x,y));
    }
    for(ll i = n;i>1;){
        path.emplace_back(i);
        if(dp[i-1]==dp[i]-1){
            i-=1;
        }else if(i%2==0 && (dp[i/2]==dp[i]-1)){
            i /=2;
        }else if(i%3==0 && (dp[i/3]==dp[i]-1)){
            i/=3;
        }
    }
    path.emplace_back(1);
    reverse(path.begin(),path.end());
    cout<<dp[n]<<'\n';
    for(ll x : path){
        cout<<x<<" ";
    }

    return 0;
}
