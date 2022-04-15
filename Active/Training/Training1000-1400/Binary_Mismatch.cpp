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


/*
Problem Statement : 



*/


/*
Author's solution : 



*/



void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>zeroprefix(n,0),zerosuffix(n,0);
    vector<int>oneprefix(n,0),onesuffix(n,0);
    zeroprefix[0] = (s[0]=='0');
    oneprefix[0] = (s[0]=='1');
    for(int i=1;i<n;i++){
      oneprefix[i] = oneprefix[i-1]+(s[i]=='1');
      zeroprefix[i] = zeroprefix[i-1]+(s[i]=='0');
    }
    for(int i=n-2;i>=0;i--){
      onesuffix[i] = onesuffix[i+1]+(s[i]=='1');
      zerosuffix[i] = zerosuffix[i+1]+(s[i]=='0');
    }
    int last_pre = 0;
    for(int i =0;i<n;i++){
      if(oneprefix[i]==((i+1)>>1)) last_pre = i;
    }
    int last_suff = n-1;
    for(int i = n-1;i>last_pre;i--){
      if(onesuffix[i]==((n-i)>>1)) last_suff = i;
    }
    cout<<last_pre<<' '<<last_suff;
}


int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
} 
// If Solved Mark (0/1) here => []