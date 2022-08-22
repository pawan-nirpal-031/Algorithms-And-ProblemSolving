#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Pair(a,b) make_pair(a,b)
#define Point(x) std::fixed<<setprecision(6)<<x
#define SetBits(x) __builtin_popcount(x);
#define Case(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Status(b) (cout<<(b?"Yes\n":"No\n"));


void solve(){
    string s1,s2; 
    cin>>s1>>s2; 
    vector<bool>ex1(26,0),ex2(26,0); 
    for(char c : s1) ex1[c-'a'] = 1; 
    for(char c : s2) ex2[c-'a'] = 1; 
    bool yes = 0; 
    for(int i =0;i<26;i++){
        if(ex1[i] and ex2[i]){
            yes = 1; 
            break;
        }
    }
    Status(yes);
}


int main(){
  FastIO;
  int t = 1;
  cin>>t; 
  while(t--) solve();
  return 0;
} 
