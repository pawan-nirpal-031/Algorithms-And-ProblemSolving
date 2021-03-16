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
#define DebugCase(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Status(b) (cout<<(b?"YES\n":"NO\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x

ll Sieve(ll n){
    ll small = 2;
    for(int i =2;i<=n;i++){
        if(n%i==0){
            small = i;
            while(n%i==0){
                n/=i;
            }
            return small;
        }
    }
    return small;
}

bool cases =0;
void GenrateRandom(){

}

void SolveCase(){
  ll n;
  cin>>n;
  ll sml = Sieve(n);
  ll t = n/sml;
  cout<<t<<'\n';
  for(int i =0;i<t;i++) cout<<sml<<' ';
}


int main(){
  FastIO;
  SolveCase();  
  return 0;
} 