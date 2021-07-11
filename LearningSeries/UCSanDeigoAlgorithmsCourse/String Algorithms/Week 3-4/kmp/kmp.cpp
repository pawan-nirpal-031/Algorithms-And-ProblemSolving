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

void ComputePrefixFun(string &text,vector<int>&prefix_fun){
  for(int i = 1;i<text.length();i++){
    int j = prefix_fun[i-1];
    while(j>0 and (text[i]!=text[j])) j = prefix_fun[j-1];
    if(text[i]==text[j]) j+=1;
    prefix_fun[i] = j;
  }
}

int main(){
  FastIO;
  string pattern,genome;
  cin>>pattern>>genome;
  string text = pattern+"#"+genome;
  vector<int>prefix_fun(text.length(),0);
  ComputePrefixFun(text,prefix_fun);
  int split_indx = pattern.length();
  for(int i =split_indx+1;i<text.length();i++) if(prefix_fun[i]==split_indx) cout<<(i - 2*(split_indx))<<' ';
  return 0;
} 
