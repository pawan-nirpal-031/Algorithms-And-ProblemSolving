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

This is a simplified version of the problem B2. Perhaps you should read the problem B2 before you start solving B1.

Paul and Mary have a favorite string s which consists of lowercase letters of the Latin alphabet. They want to paint it using pieces of chalk of two colors: red and green. Let's call a coloring of a string wonderful if the following conditions are met:

each letter of the string is either painted in exactly one color (red or green) or isn't painted;
each two letters which are painted in the same color are different;
the number of letters painted in red is equal to the number of letters painted in green;
the number of painted letters of this coloring is maximum among all colorings of the string which meet the first three conditions.
E. g. consider a string s equal to "kzaaa". One of the wonderful colorings of the string is shown in the figure.

The example of a wonderful coloring of the string "kzaaa".
Paul and Mary want to learn by themselves how to find a wonderful coloring of the string. But they are very young, so they need a hint. Help them find k — the number of red (or green, these numbers are equal) letters in a wonderful coloring.

Input
The first line contains one integer t (1≤t≤1000) — the number of test cases. Then t test cases follow.

Each test case consists of one non-empty string s which consists of lowercase letters of the Latin alphabet. The number of characters in the string doesn't exceed 50.

Output
For each test case, output a separate line containing one non-negative integer k — the number of letters which will be painted in red in a wonderful coloring.

*/


/*
Author's solution : 



*/

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    vector<int>f(26,0);
    for(char c : s) f[c-'a']+=1;
    int ans =0;
    int ones =0;
    for(int i=0;i<26;i++){
      if(f[i]==0) continue;
      if(f[i]>=2) ans+=1;
      if(f[i]==1) ones+=1;
    }
    cout<<ans+(ones>>1)<<'\n';
  }
  return 0;
} 
// If Solved Mark (0/1) here => [1]