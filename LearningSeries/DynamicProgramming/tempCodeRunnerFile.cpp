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
    map<ll,ll>a;
    for(int i =0;i<n;i++){
        ll x;
        cin>>x;
        a[x]+=1;
    }
    if(k==0){
        cout<<-1;
        return;
    }
    int cnt = 0;
    for(auto x : a){
        cnt+=x.second;
        if(cnt==k){
            if(x.first<=limit){
                cout<<x.first;
                return;
            }
        }else if(cnt>k) break;
    }
    cout<<-1;
}


int main(){
  FastIO;
  SolveCase();
  return 0;
} 
