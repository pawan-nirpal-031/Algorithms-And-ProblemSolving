// Problem Link : https://www.codechef.com/LTIME95C/problems/BENCHP
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


/*
Problem Statement : 

In the gym, Chef prefers to lift at least W grams during a bench press and if that's impossible, Chef considers his workout to be incomplete and feels bad.

The rod weighs Wr grams and there are N other weights lying on the floor that weigh w1,w2,...,wN grams. To maintain balance and to ensure that there is no unnecessary load due to torque, it's important that the weights added to the left side are symmetric to the weights added to the right side. It is not required to use all of the weights. It is also not required to use any weights at all, if Chef feels satisfied lifting only the rod.

For example:

1 2 2 1 |Rod Center| 1 1 1 3 is a wrong configuration, but

1 2 3 1 |Rod Center| 1 3 2 1 is a right configuration.

Find whether Chef will be able to collect the required weights to feel satisfied.

*/



void SolveCase(){
    ll n,w,wr;
    cin>>n>>w>>wr;
    vector<ll>count(100003,0);
    ll max_weight =0;
    for(ll i=0;i<n;i++){
        ll wt;
        cin>>wt;
        count[wt]+=1;
        max_weight = max(max_weight,wt);
    }
    if(wr>=w){
        Status(1);
        return;
    }
    ll required =0;
    for(ll i =1;i<=max_weight;i++) required+=(i*(count[i]&1?count[i]-1:count[i]));
    Status(required+wr>=w);
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      SolveCase();
  }
  return 0;
} 
// If Solved Mark (0/1) here => []