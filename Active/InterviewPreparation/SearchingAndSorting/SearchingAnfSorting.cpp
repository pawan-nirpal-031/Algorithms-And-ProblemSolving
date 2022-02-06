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


void BuyAndSell(vector<int>&stocks){
    int n = stocks.size();
    int max_profit = -INT_MAX;
    vector<int>suff(n,0);
    suff[n-1] = stocks[n-1];
    for(int i =n-2;i>=0;i--) suff[i] = max(stocks[i+1],suff[i+1]);
    for(int i=0;i<n-1;i++){
        max_profit = max(max_profit,suff[i+1]-stocks[i]);
        cout<<max_profit<<' ';
    }
}


void TwoSum(vector<int>& nums, int target){
    
}


void ReversePairs(){

}

void GridUniquePaths(){

}


void Solve(){
    int n;
    cin>>n;
    vector<int>v(n,0);
    for(int i=0;i<n;i++) cin>>v[i];
    BuyAndSell(v);
}


int main(){
  FastIO;
  int t = 1;
  Solve();
  return 0;
} 
