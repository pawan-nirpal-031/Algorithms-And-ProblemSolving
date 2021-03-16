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


int main(){
    FastIO;
    ll n,m,t;
    cin>>n>>m>>t;
    ll ch = n;
    ll maxcap = n;
    bool y =0;
    ll cfe[m][2];
    for(int i =0;i<m;i++){
       cin>>cfe[i][0]>>cfe[i][1];
    }
    ch-=cfe[0][0];
    for(int i =0;i<m;i++){
        if(ch==0){
            y =1;
            break;
        }else{
            if(ch!=maxcap){
                ch+=(cfe[i][1]-cfe[i][0]);
            }
            if(i+1<n){
                ch-=(cfe[i+1][0]-cfe[i][1]);
            }
        }
    }
    ch-=(t-cfe[m-1][1]);
    if(ch==0){
        y =1;
    }
    cout<<((y?"No":"Yes"));
    return 0;
} 