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

ll Gcd(ll a,ll b){
    return ((a==0)?b:Gcd(b%a,a));
}

ll Lcm(ll a,ll b){
    return (a*b)/Gcd(a,b);
}

void DiffrentDivisors(){
    ll d;
    cin>>d;
   // cout<<((1+d)*(1+2*d))<<' '<<((1+2*d)*(1+3*d))<<' '<<((1+d)*(1+3*d));
    int n = 3;
    int times = (n*(n-1))>>1;
    int dx[4] = {1,2,3,4};
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            cout<<((1+dx[i]*d)*(1+dx[j]*d))<<' ';
        }
    } 

    

    // for(int x = 1;x<=100;x++){
    //     cout<<x<<" : "<<(x*x + 3*d*x + 2*d*d)<<'\n';
    // }
}


int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) DiffrentDivisors();
  return 0;
} 
