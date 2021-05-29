// Problem Link : https://codeforces.com/contest/999/problem/C
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
#define letters 26


/*
Problem Statement : 

You are given a string s consisting of n lowercase Latin letters. Polycarp wants to remove exactly k characters (k≤n) from the string s. Polycarp uses the following algorithm k times:

if there is at least one letter 'a', remove the leftmost occurrence and stop the algorithm, otherwise go to next item;
if there is at least one letter 'b', remove the leftmost occurrence and stop the algorithm, otherwise go to next item;
...
remove the leftmost occurrence of the letter 'z' and stop the algorithm.
This algorithm removes a single letter from the string. Polycarp performs this algorithm exactly k times, thus removing exactly k characters.

Help Polycarp find the resulting string.

*/

int main(){
  FastIO;
  int n,k;
  cin>>n>>k;
  vector<int>freq(letters,0);
  string s;
  cin>>s;
  for(char c : s) freq[c-'a']+=1;
  int first = 0;
  for(int i =0;i<letters;i++) {
    if(freq[i]>0){
        first = i;
        break;
    }
  }
  vector<int>Kval(letters,0);
  for(int i =0;i<letters;i++){
      if(i>=first){
          if(k<=0) break;
          Kval[i] = min(k,freq[i]);
          k-=Kval[i];
      }
  }
  for(int i =0;i<n;i++){
      if(Kval[s[i]-'a']>0){
           Kval[s[i]-'a']-=1;
           s[i]='.';
      }
  }
  for(char c : s) if(c!='.')cout<<c;
  return 0;
} 
// If Solved Mark (0/1) here => [1]