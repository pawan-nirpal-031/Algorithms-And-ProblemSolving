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

// https://www.codechef.com/submit/AVG


void solve(){
    int n,k,v; 
    cin>>n>>k>>v;  
    ll sum =0; 
    for(int i =0;i<n;i++){
        ll x; 
        cin>>x; 
        sum+=x; 
    }
    ll num = v*(n+k) - sum; 
    if(num<=0 or num%k!=0){
        cout<<-1;
    }else{
        cout<<num/k;
    }
    cout<<'\n';
}

int main(){
  FastIO;
  int t;
  cin>>t; 
  while(t--){
    solve();
  }
  return 0;
} 
