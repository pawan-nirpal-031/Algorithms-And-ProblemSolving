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



int main(){
  FastIO;
  int n,t;
  cin>>n>>t;
  string s;
  cin>>s;
  int len = s.length();
  for(int i =1;i<=t;i++){
      for(int j =0;j<len-1;){
          if(s[j]=='B' and s[j+1]=='G'){
              s[j] = 'G';
              s[j+1] = 'B';
              j+=2;
          }else j+=1;
      }
  }
  cout<<s;
  return 0;
} 
// If Solved Mark (0/1) here => [1]