#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Pair(a,b) make_pair(a,b)
#define Point(x) std::fixed<<setprecision(6)<<x
#define SetBits(x) __builtin_popcount(x);
#define Case(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Status(b) (cout<<(b?"YES\n":"NO\n"));


void solve(){
    int n;  
    cin>>n;
    int t[n-1];  
    for(int &x : t) cin>>x;
    ll pa[n-1],pb[n-1]; 
    pa[0] = t[0];
    for(int i =1;i<n-1;i++) pa[i] = pa[i-1]+t[i]; 
    pb[0] = 2*pa[0]; 
    for(int i =1;i<n-1;i++) pb[i] = pa[i]+t[i]; 
    cout<<pb[n-2]<<'\n';
}


int main(){
  FastIO;
  int t = 1;
  cin>>t; 
  while(t--) solve();
  return 0;
} 
