// Problem link : 
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
#define All(x) begin(x),end(x)

/*
Problem Statement : 



*/


/*
Author's solution : 



*/
  

void SetIO(string s){
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}



void solve(){
  int n; 
  cin>>n; 
  string a,b; 
  cin>>a>>b; 
  vector<bool>uniq(26,0); 
  for(int i=0;i<n;i++){
    if(a[i]==b[i]) continue; 
    uniq[b[i]-'a'] = 1;
  } 
  int ans =0; 
  for(int i=0;i<26;i++) ans+=uniq[i]; 
  cout<<ans<<"\n";
}

int main(){
  FastIO; 
  int t=1;
  cin>>t; 
  while(t--) solve();
  return 0; 
}
// If Solved Mark (0/1) here => []