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

int Get(char x, char y){
    return abs((x-'a')-(y-'a'));
}
bool Isfunny(string s){
    int n = s.length();
    int prefix[n-1];
    int m = n-1;
    prefix[0] = Get(s[0],s[1]);
    int suffix[m];
    suffix[m-1] = Get(s[n-1],s[n-2]);
    for(int i =1;i<=n-2;i++) prefix[i] = Get(s[i],s[i+1]);
    for(int i = n-3;i>=0;i--) suffix[i] = Get(s[i],s[i+1]);
    
    for(int x : suffix) cout<<x<<" ";

    return 0;
}

int main(){
  FastIO;
  string a,b,c,d;
  cin>>a>>b>>c>>d;
  int q;
  cin>>q;
  string x;
  getline(cin,x);
  while(q--){
      string p;
      cin>>p;
      cout<<(Isfunny(p)?"Funny\n":"Not Funny\n");
      string q;
      cin>>q;
  }

  return 0;
} 