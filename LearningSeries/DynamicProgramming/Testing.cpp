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


void UnitTests(){
    
}


bool cases =1;

void RandomGenrator(){

}

void SolveCase(){
    ll limit = 1e9;
    ll n,k;
    cin>>n>>k;
    vector<ll>seq(n,0);
    for(ll &x : seq) cin>>x;
    sort(seq.begin(),seq.end());
    int cnt = 0;
    ll num = 0;
    for(int i =0;i<n;i++){
        if(cnt==k and (seq[i]<=limit)){
            cout<<seq[i]<<' ';
            return;
        }else{
            cnt+=1;
        }
    }
    cout<<-1;
}


int main(){
  FastIO;
  SolveCase();
  return 0;
} 
