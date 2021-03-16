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
#define Status(b) (cout<<(b?"Yes\n":"No\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x

 bool cases =1;
void SolveCase(){
  int s;
  cin>>s;
  ll song[s];
  ll total = 0;
  for(int i =0;i<s;i++) cin>>song[i];
  for(int i = 0;i<s;i++){
    ll e;
    cin>>e;
    for(int j = 0;j<e;j++){
      ll le=0;
      cin>>le;
      total+=((j==0)?le:le-song[i]);
    }
  }
  cout<<total<<'\n';
}

ll CollegeLife4Util(int n,int e,int h,ll a,ll b,ll c){
  if(n==0){
    return 0;
  }
  if((e==0 and h==0) or (e==0 and h<3) or (e<2 and h==0)) return Mod;
  // if(dp[n][e][h]!=-1) return dp[n][e][h];
  ll omlette = Mod;
  ll cokmilk = Mod;
  ll cockcke = Mod;
  if(e>=2) omlette = a + CollegeLife4Util(n-1,e-2,h,a,b,c);
  if(h>=3)  cokmilk = b + CollegeLife4Util(n-1,e,h-3,a,b,c);
  if(e>=1 and h>=1) cockcke = c + CollegeLife4Util(n-1,e-1,h-1,a,b,c);
  return  min(omlette,min(cokmilk,cockcke));
}

void CollegeLife4(){
  ll n,e,h,a,b,c;
  cin>>n>>e>>h>>a>>b>>c;
 // vector<vector<vector<ll>>>dp(n,vector<vector<ll> >(e,vector <ll>(h,-1)));
  ll ans = CollegeLife4Util(n,e,h,a,b,c);
  cout<<(ans>=Mod?-1:ans);
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--)
  SolveCase();
  return 0;
} 