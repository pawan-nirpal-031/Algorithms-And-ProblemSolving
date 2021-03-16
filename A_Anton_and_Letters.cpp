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
  string s;
  getline(cin,s);

  vector<bool>f(26,0);
  int ans = 0;
  for(int i = 0;i<s.length();i++){
    char c = s[i];
    if(c>='a' and c<='z'){
      if(not f[c-'a']) ans+=1;
      f[c-'a'] = 1;
    }
  }
  
  cout<<ans<<endl;

  return 0;
} 