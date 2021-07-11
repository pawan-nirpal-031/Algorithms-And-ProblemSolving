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

A string s of length n (1≤n≤26) is called alphabetical if it can be obtained using the following algorithm:

first, write an empty string to s (i.e. perform the assignment s := "");
then perform the next step n times;
at the i-th step take i-th lowercase letter of the Latin alphabet and write it either to the left of the string s or to the right of the string s (i.e. perform the assignment s := c+s or s := s+c, where c is the i-th letter of the Latin alphabet).
In other words, iterate over the n first letters of the Latin alphabet starting from 'a' and etc. Each time we prepend a letter to the left of the string s or append a letter to the right of the string s. Strings that can be obtained in that way are alphabetical.

For example, the following strings are alphabetical: "a", "ba", "ab", "bac" and "ihfcbadeg". The following strings are not alphabetical: "z", "aa", "ca", "acb", "xyz" and "ddcba".

From the given string, determine if it is alphabetical.

Input
The first line contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow.

Each test case is written on a separate line that contains one string s. String s consists of lowercase letters of the Latin alphabet and has a length between 1 and 26, inclusive.

Output
Output t lines, each of them must contain the answer to the corresponding test case. Output YES if the given string s is alphabetical and NO otherwise.

You can output YES and NO in any case (for example, strings yEs, yes, Yes and YES will be recognized as a positive answer).

*/


/*
Author's solution : 



*/

void Solve(){
    string s;
    cin>>s;
    vector<int>freq(26,0);
    vector<int>indx(26,-1);
    int max_char =0;
    bool yes =1;
    for(int i =0;i<s.length();i++){
        freq[s[i]-'a']+=1;
        max_char = max(max_char,s[i]-'a');
        if(freq[s[i]-'a']>1){
            yes = 0;
            break;
        }
        indx[s[i]-'a'] = i;
    }
    if(yes==0){
        Status(0);
        return;
    }
    for(int i =0;i<=max_char;i++){
        if(freq[i]!=1){
            yes =0;
            break;
        }
        for(int j =0;j<i;j++){
            if(abs(indx[i]-indx[j])>i){
                yes =0;
                break;
            }
        }
    }
    Status(yes);
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
// If Solved Mark (0/1) here => [1]