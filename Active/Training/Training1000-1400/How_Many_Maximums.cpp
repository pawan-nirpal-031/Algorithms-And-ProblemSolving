#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Pair(a,b) make_pair(a,b)
#define Point(x) std::fixed<<setprecision(15)<<x
#define SetBits(x) __builtin_popcount(x);
#define Case(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Status(b) (cout<<(b?"YES\n":"NO\n"));


void solve(){
  int n; 
  cin>>n; 
  string s; 
  cin>>s; 
  n--; 
  int count = (s[0]=='1'); 
  for(int i =1;i<n;i++){
    if(s[i-1]=='0' and s[i]=='1') count+=1;
  }
  if(s[n-1]=='0') count+=1; 
  cout<<count<<'\n';
}

int main(){
  FastIO;
  int t;
  cin>>t; 
  while(t--) solve();
  return 0;
} 
