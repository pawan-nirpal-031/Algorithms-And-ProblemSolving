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
    int a[11];
    int count[102] = {0}; 
    for(int &x : a){
        cin>>x; 
        count[x]+=1;
    }
    int k; 
    cin>>k; 
    sort(a,a+11); 
    int element = a[11-k]; 
    int freq = count[element];
    ll factorial[12]; 
    factorial[1] = factorial[0] = 1; 
    for(ll i = 2;i<=11;i++) factorial[i] = i*factorial[i-1]; 
    int fixed = 0;
    set<int>remains;  
    for(int i = 11-k+1;i<11;i++){
      if(a[i]==element) continue;
      remains.insert(a[i]);
    }
    for(const int &x : remains) fixed+=count[x];
    int var = k - fixed; 
    ll ans = (factorial[freq])/(factorial[freq-var]*factorial[var]); 
    cout<<ans<<'\n';
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
