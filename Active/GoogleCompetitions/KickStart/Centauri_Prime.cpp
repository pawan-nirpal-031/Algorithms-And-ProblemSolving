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


/*
Problem Statement : 



*/


/*
Author's solution : 



*/

class Math{
    public:
    int Floor(int x,int y){
        return floor(x*1.0/y);
    }
    int Ceil(int x,int y){
        return ceil(x*1.0/y);
    }
};


bool IsVowel(char c){
    char s[] = {'a','e','i','o','u','A','E','I','O','U'};
    for(char x : s) if(c==x) return 1;
    return 0;
}

int main(){
  FastIO;
  int t;
  cin>>t;
  int bob =0;
  int alice =0;
  for(int i =1;i<=t;i++){
    string s;
    cin>>s;
    char l = s[s.length()-1];
    if(l=='y' or l=='Y') DebugCase(i,s+" is ruled by nobody.");
    else DebugCase(i,(IsVowel(l)?(s+" is ruled by Alice."):(s+" is ruled by Bob.")));
  }

  
  return 0;
} 
// If Solved Mark (0/1) here => []