// Problem Link : https://codeforces.com/problemset/problem/1462/B
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

Polycarp has a string s[1…n] of length n consisting of decimal digits. Polycarp performs the following operation with the string s no more than once (i.e. he can perform operation 0 or 1 time):

Polycarp selects two numbers i and j (1≤i≤j≤n) and removes characters from the s string at the positions i,i+1,i+2,…,j (i.e. removes substring s[i…j]). More formally, Polycarp turns the string s into the string s1s2…si−1sj+1sj+2…sn.
For example, the string s="20192020" Polycarp can turn into strings:

"2020" (in this case (i,j)=(3,6) or (i,j)=(1,4));
"2019220" (in this case (i,j)=(6,6));
"020" (in this case (i,j)=(1,5));
other operations are also possible, only a few of them are listed above.
Polycarp likes the string "2020" very much, so he is wondering if it is possible to turn the string s into a string "2020" in no more than one operation? Note that you can perform zero operations.

*/

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool yes =0;
    for(int i =0;i<=4;i++){
      if(s.substr(0,i)+s.substr(i+n-4,4-i)=="2020"){
        yes = 1;
      }
    }
    Status(yes);
  }
  return 0;
} 
// If Solved Mark (0/1) here => [1]