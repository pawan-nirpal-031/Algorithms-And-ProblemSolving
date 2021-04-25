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

After his wife's tragic death, Eurydice, Orpheus descended to the realm of death to see her. Reaching its gates was uneasy, but passing through them proved to be even more challenging. Mostly because of Cerberus, the three-headed hound of Hades.

Orpheus, a famous poet, and musician plans to calm Cerberus with his poetry and safely walk past him. He created a very peculiar poem for Cerberus. It consists only of lowercase English letters.

We call a poem's substring a palindrome if and only if it reads the same backwards and forwards. A string a is a substring of a string b if a can be obtained from b by deleting several (possibly zero or all) characters from the beginning and several (possibly zero or all) characters from the end.

Unfortunately, Cerberus dislikes palindromes of length greater than 1. For example in the poem abaa the hound of Hades wouldn't like substrings aba and aa.

Orpheus can only calm Cerberus if the hound likes his poetry. That's why he wants to change his poem so that it does not contain any palindrome substrings of length greater than 1.

Orpheus can modify the poem by replacing a letter at any position with any lowercase English letter. He can use this operation arbitrarily many times (possibly zero). Since there can be many palindromes in his poem, he may have to make some corrections. But how many, exactly? Given the poem, determine the minimal number of letters that have to be changed so that the poem does not contain any palindromes of length greater than 1.

In the first test case, we can replace the third character with c and obtain a palindrome-less poem bacba.

In the second test case, we can replace the third character with d and obtain a palindrome-less poem abdac.

In the third test case, the initial poem already doesn't contain any palindromes, so Orpheus doesn't need to change anything there.

*/

void Solve(){
    
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) Solve();
  return 0;
} 
// If Solved Mark (0/1) here => []