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

string Test(){
  string s = "abcdefghijklmnopqrstuvwxyz";
  int l = 2 + rand()%7;
  string gen;
  for(int i =0;i<l;i++){
    gen+=s[rand()%7];
  }
  return gen;
}


void Solve(){
  string s;
  cin>>s;
  vector<int>freq(26,0);
  for(char c : s) freq[c-'a']+=1;
  int even =0;
  int odd =0;
  int ones = 0;
  for(int i =0;i<26;i++){
    if(freq[i]==1){
      ones+=1;
      continue;
    }else{
      if(freq[i]%2==0 and freq[i]>0) even+=(freq[i]/2);
      else if(freq[i]&1) odd+=((freq[i]-3)/2);
    }
  }
  Status(even+odd>=ones or ones==0);
}



int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
    Solve();
  }
 
  return 0;
} 