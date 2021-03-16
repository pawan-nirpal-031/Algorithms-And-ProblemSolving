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



bool cases =1;

ll Solve(ll items,ll eggs,ll chocklates,ll omlette_price,ll milk_price,ll cake_price){
    ll ans = 1e18;
    for(int cakes =0;cakes<=items;cakes++){
        if(eggs<cakes or chocklates<cakes) break;
        ll maximum_omlettes = (items - cakes)/2;
        ll maximum_milk = (items - cakes)/3;
        if(cakes + maximum_milk + maximum_omlettes < items) continue;
        ll required_omlettes,required_milk;
        if(omlette_price<milk_price){
            required_omlettes = min(maximum_omlettes,items - cakes);
            required_milk = items - cakes - required_omlettes;
        }else{
            required_milk = min(maximum_milk,items - cakes);
            required_omlettes = items - cakes - required_milk;
        }
        ans = min(ans,(required_milk*milk_price + required_omlettes*omlette_price + cakes*cake_price));
    }
    return (ans==1e18?-1:ans);
}

int main(){
  FastIO;
  cout<<(40%15);
  return 0;
} 
