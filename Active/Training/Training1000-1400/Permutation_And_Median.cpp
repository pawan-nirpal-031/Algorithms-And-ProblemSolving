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

// https://www.codechef.com/submit/PER_MED



int main(){
  FastIO;
  int t; 
  cin>>t;
  while(t--){
    int n;
    cin>>n; 
    int odd = n; 
    int even = 1; 
    for(int i =1;i<=n;i++){
      if(i&1){
        cout<<odd<<' '; 
        odd--;
      }else{
        cout<<even<<' ';
        even++;
      }
    }
    cout<<'\n';
  }
  return 0;
} 
