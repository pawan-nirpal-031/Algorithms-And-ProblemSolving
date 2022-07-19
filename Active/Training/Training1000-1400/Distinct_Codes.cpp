#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Pair(a,b) make_pair(a,b)
#define Point(x) std::fixed<<setprecision(15)<<x
#define SetBits(x) __builtin_popcount(x);
#define Case(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Status(b) (cout<<(b?"YES\n":"NO\n"));



int main(){
  FastIO;
  int t;
  cin>>t; 
  while(t--){
    string s; 
    cin>>s; 
    set<string>cache;  
    int n = s.length();
    for(int i =1;i<n;i++){ 
        string code; 
        for(int j = 0;j<=1;j++) code+=s[i+j-1];
        if(cache.find(code)==cache.end()) cache.insert(code);
    }
    cout<<cache.size()<<'\n';
  }
  return 0;
} 
