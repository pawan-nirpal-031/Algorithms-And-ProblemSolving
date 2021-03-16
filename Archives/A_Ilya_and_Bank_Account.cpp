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


int main(){
  FastIO;
  ll n;
  cin>>n;
  if(n>0){
    cout<<n;
  }else{
    // ll last = n/10;
    // int last_dig = n%10;
    // ll second_last = n/100;

    // if(last_dig==0 and n>-100){
    //     cout<<0;
    // }else{
    //     cout<<last<<' '<<second_last;
    //    // cout<<max(last,second_last);
    // }
    string num = to_string(n); 
    int dig = n%10;
    string last = num.substr(num.length()-1);
    string sec = num.substr(num.length()-2) + to_string(dig);
    cout<<last<<' '<<sec;

  }
  return 0;
} 