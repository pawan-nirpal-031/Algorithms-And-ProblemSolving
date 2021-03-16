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
#define BoolAnsCall(b) (cout<<(b?"Yes\n":"No\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x

void Solve(){
    int n;
    cin>>n;
    vector<ll>heights(n,0),iq(n,0);
    for(int i =0;i<n;i++) cin>>heights[i];
    for(int i = 0;i<n;i++) cin>>iq[i];
    vector<ll>dp(n,1);
    ll max_seq = 1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++){
            if(heights[i]>heights[j] and iq[i]<iq[j]){
                dp[i] = max(dp[i],1 + dp[j]);
                max_seq = max(max_seq,dp[i]);
            }
        }
    }
    cout<<max_seq<<'\n';
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