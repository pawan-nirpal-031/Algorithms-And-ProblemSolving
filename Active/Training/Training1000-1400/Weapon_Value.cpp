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



int main(){
  FastIO;
  int t;
  cin>>t; 
  while(t--){
    int n; 
    cin>>n; 
    int count[10] = {0}; 
    for(int i =0;i<n;i++){
        string s;
        cin>>s; 
        for(int j =0;j<10;j++) count[j]+=(s[j]-'0');
    }
    int ans =0; 
    for(int i =0;i<10;i++) ans+=(count[i]&1); 
    cout<<ans<<'\n';
  }
  return 0;
} 
