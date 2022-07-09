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
#define Status(b) (cout<<(b?"Yes\n":"No\n"));



int main(){
  FastIO;
  int t;
  cin>>t; 
  while(t--){
    string s; 
    cin>>s; 
    int n = s.length();
    int zeros =0; 
    int ones = 0; 
    for(char c : s){
        if(c=='1') ones+=1;
        else zeros+=1;
    }
    Status((zeros==1 and ones==n-1) or (ones==1 and zeros==n-1));
  }
  return 0;
} 
