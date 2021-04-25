// Problem Link : https://codeforces.com/contest/1466/problem/C
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

/*

The main observation is that if there exists a palindrome of length larger than 3, then there exists a palindrome of length 2 or 3. This observation allows us to simplify the task to erasing all palindromes of length 2 or 3. We can also notice that each character will be replaced at most once.

From now on, there are a few possible solutions. The easiest one is to iterate over a word from left to right. When we encounter a palindrome (of length 2 or 3) ending on the current position, consisting of unmarked elements, we greedily mark this character as the one we want to replace. The number of marked characters is the answer, as it turns out that we can obtain a valid palindrome-less sequence by replacing only the letters on the marked positions. The complexity is O(n).

The sketch of proof is as follows: it is sufficient to ensure that each marked character does not coincide with 4 neighboring characters, so we are still left with 22 remaining possibilities.

We can try different approaches too. One of these is a dp-based solution, where the state dp[i][ca][cb] denotes the minimal result after analyzing first i elements, where characters si and si−1 are equal to ca and cb respectively. This dp can be implemented in O(n⋅262), which should pass, but is pretty messy to implement, so we want to improve it.

We can notice that we are not interested in the last 2 characters' exact values, but only if these were changed or not (the same observation as in the greedy solution). Thanks to this, our state changes to dp[i][ci][ci−1], where ci encodes whether i-th character was changed. This dp can be cleanly implemented in linear time.

*/

void Solve(){
    string s;
    cin>>s;
    int n = s.length();
    vector<bool>used(n+1,0);
    int ans =0;
    for(int i = 2;i<=n;i++){
      bool need = 0;
      if((s[i]==s[i-1]) and (not used[i-1])) need = 1;
      if(i>2 and (s[i]==s[i-2]) and  (not used[i-2])) need = 1;
      used[i] = need;
      ans+=used[i];
    }
    cout<<ans<<'\n';
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) Solve();
  return 0;
} 
// If Solved Mark (0/1) here => []