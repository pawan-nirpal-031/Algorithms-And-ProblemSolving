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

bool IsPlaindrome(string s){
    int n = s.length();
    int u = n/2; 
    for(int i = 0;i<u;i++) if(s[i]!=s[n-1-i]) return 0;
    return 1;
}

int main(){
  FastIO;
  int t;
  cin>>t; 
  vector<int>palindromes(100002,0);
  for(int i = 1;i<100002;i++){
    if(IsPlaindrome(to_string(i))){
        palindromes[i] = i;
    }
    palindromes[i]+=palindromes[i-1];
  }
  while(t--){
    int l,r; 
    cin>>l>>r; 
    if(l==1){
        cout<<palindromes[r]<<'\n';
    }else{
        cout<<palindromes[r]-palindromes[l-1]<<"\n";
    }
  } 
  return 0;
} 
