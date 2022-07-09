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
    ll b[n];
    ll acc_b =0;
    for(int i =0;i<n;i++) {
        cin>>b[i]; 
        acc_b+=b[i];
    }
    ll val = acc_b/(n+1); 
    for(int i=0;i<n;i++) cout<<b[i]-val<<' '; 
    cout<<'\n';
  }
  return 0;
} 
