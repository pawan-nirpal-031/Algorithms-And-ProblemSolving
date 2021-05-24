// Problem Link : https://codeforces.com/contest/988/problem/B
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

You are given n strings. Each string consists of lowercase English letters. Rearrange (reorder) the given strings in such a way that for every string, all strings that are placed before it are its substrings.

String a is a substring of string b if it is possible to choose several consecutive letters in b in such a way that they form a. For example, string "for" is contained as a substring in strings "codeforces", "for" and "therefore", but is not contained as a substring in strings "four", "fofo" and "rof".

*/

bool IsSubString(string big,string small){
    int lb = big.size();
    int ls = small.size();
    for(int i = 0;i<=lb-ls;i++){
        if(big.substr(i,ls)==small){
            return 1;
        }
    }
    return 0;
}

int main(){
  FastIO;
  int n;
  cin>>n;
  multimap<int,string>data;
  while(n--){
      string s;
      cin>>s;
      int l = s.length();
      data.insert({l,s});
  }
  int i =0;
  string prv;
  for(auto p : data){
      if(i==0){
          prv = p.second;
      }else{
          string curr = p.second;
          if(IsSubString(curr,prv)){
               prv = curr;
          }
          else{
              Status(0);
              return 0;
          }
      }
      i+=1;
  }
  Status(1);
  for(auto p : data) cout<<p.second<<'\n';
 
  return 0;
} 
// If Solved Mark (0/1) here => [1]