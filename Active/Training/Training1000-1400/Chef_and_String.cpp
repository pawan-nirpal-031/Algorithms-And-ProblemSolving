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
    string left; 
    int n = s.length();
    for(int i =1;i<n;i++) left+=s[i]; 
    left+=s[0]; 
    string right; 
    right+=s[n-1]; 
    for(int i =0;i<n-1;i++) right+=s[i]; 
    Status(left==right);
  }
  return 0;
} 
