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
    int a[n]; 
    set<int>cache; 
    int ans = 0; 
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    for(int i =0;i<n;i++){
        int v = a[i]; 
        if(v>=1 and v<=7 and cache.find(v)==cache.end()){
            ans = i+1; 
            cache.insert(v); 
            if(cache.size()==7) break;
        }
    }
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
