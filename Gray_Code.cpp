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

bool DiffersBy1bit(ll x,ll y){
    int p =  SetBits(x^y);
    return p==1;
}

void GenrateGrayCodes(int n,vector<ll>&gray,int &num){
    if(n==0){
        gray.emplace_back(num);
        return;
    }
    GenrateGrayCodes(n-1,gray,num);
    num^=(1<<(n-1));
    GenrateGrayCodes(n-1,gray,num);
}

void Bin(ll x,vector<bool>&b){
    if(x>1){
        Bin(x>>1,b);
    }
    b.push_back(x%2);
}


int main(){
  FastIO;
  int n;
  cin>>n;
  vector<ll>gray_codes;
  int num = 0;
  GenrateGrayCodes(n,gray_codes,num);
  for(ll x : gray_codes){
      vector<bool>b;
      Bin(x,b);
      int stuff = n - b.size();
      for(int i =0;i<stuff;i++) cout<<0;
      for(bool t : b) cout<<t;
      cout<<'\n';
  }
  return 0;
} 