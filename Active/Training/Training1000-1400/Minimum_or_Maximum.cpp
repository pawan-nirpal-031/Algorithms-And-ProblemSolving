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
    bool yes = 1;
    int prefix_min = Mod; 
    int prefix_max = 0;
    for(int i =1;i<=n;i++){
        int x; 
        cin>>x; 
        if(i==1){
            prefix_max = prefix_min = x;
            continue;
        }
        if(x<=prefix_min){
            prefix_min = x;
        }else if(x>=prefix_max){
            prefix_max = x;
        }else yes =0; 
    }
    Status(yes);
  }

  return 0;
} 
