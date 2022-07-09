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
    int n,k; 
    cin>>n>>k; 
    int a[n+1]; 
    for(int i =1;i<=n;i++) cin>>a[i]; 
    int count =0; 
    for(int i =1;i<=n;i++){
        int votes =0; 
        if(a[i]==i) continue;
        for(int j = 1;j<=n;j++){
            if(j!=i){
                votes+=(a[j]==i);
            }
        }
        count+=(votes>=k);
    }
    cout<<count<<'\n';
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
