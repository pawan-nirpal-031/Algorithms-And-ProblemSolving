#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Infinity (ll)1e18
#define Append(a) push_back(a)
#define Pair(a,b) make_pair(a,b)
#define Clear(a) for(ll &x : a){x=0;}
#define Point(x) std::fixed<<setprecision(15)<<x
#define SetBits(x) __builtin_popcount(x);
#define GoogleOutput(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define BoolAnsCall(b) (cout<<(b?"Yes\n":"No\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x


void Solve(){
    ll m,h;
    cin>>m>>h;
    ll bmi = (m/(h*h));
    if(bmi<=18){
        cout<<1<<'\n';
    }else if(bmi>=19 and bmi<25){
        cout<<2<<'\n';
    }else if(bmi>=25 and bmi<30){
        cout<<3<<'\n';
    }else{
        cout<<4<<'\n';
    }
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
    Solve();
  }
  return 0;
} 