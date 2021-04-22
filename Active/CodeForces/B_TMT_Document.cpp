// Problem Link : 
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


void TMTDocx(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  int tc = 0;
  int mc = 0;
  for(char c : s) (c=='T'?tc+=1:mc+=1);
  if(mc!=(n/3)){
    Status(0);
    return;
  }
  vector<int>prefix_t(n,0),prefix_m(n,0),suffix_t(n,0),suffix_m(n,0);
  prefix_t[0] = (s[0]=='T');
  prefix_m[0] = (s[0]=='M');
  suffix_m[n-1] = (s[n-1]=='M');
  suffix_t[n-1] = (s[n-1]=='T');
  for(int i =1;i<n;i++){
    prefix_m[i] = prefix_m[i-1]+(s[i]=='M');
    prefix_t[i] = prefix_t[i-1] + (s[i]=='T');
  }
  for(int i =n-2;i>=0;i--){
    suffix_m[i] = suffix_m[i+1] + (s[i]=='M');
    suffix_t[i] = suffix_t[i+1] + (s[i]=='T');
  }
  for(int i =0;i<n;i++){
    if(prefix_t[i]>=prefix_m[i] and suffix_t[i]>=suffix_m[i]) continue;
    else{
      Status(0);
      return;
    }
  }
  Status(1);
}


int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) TMTDocx();
  return 0;
} 
// If Solved Mark (0/1) here => [1]