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
You are given a string s consisting of the characters '0', '1', and '?'. You need to replace all the characters with '?' in the string s by '0' or '1' so that the string becomes a palindrome and has exactly a characters '0' and exactly b characters '1'. Note that each of the characters '?' is replaced independently from the others.

A string t of length n is called a palindrome if the equality t[i]=t[n−i+1] is true for all i (1≤i≤n).

For example, if s="01?????0", a=4 and b=4, then you can replace the characters '?' in the following ways:

"01011010";
"01100110".
For the given string s and the numbers a and b, replace all the characters with '?' in the string s by '0' or '1' so that the string becomes a palindrome and has exactly a characters '0' and exactly b characters '1'.

Input
The first line contains a single integer t (1≤t≤104). Then t test cases follow.

The first line of each test case contains two integers a and b (0≤a,b≤2⋅105, a+b≥1).

The second line of each test case contains the string s of length a+b, consisting of the characters '0', '1', and '?'.

It is guaranteed that the sum of the string lengths of s over all test cases does not exceed 2⋅105.

*/

bool cases =1;


void SolveCase(){
  int a,b;
  cin>>a>>b;
  string s;
  cin>>s;
  int n = s.length();
  int c = a;
  int d = b;
  int blank =0;
  if(a+b>n){
    cout<<"-1\n";
    return;
  }
  for(char c : s){
      if(c=='?'){
          blank+=1;
          continue;
      }
      (c-'0'?b-=1:a-=1);      
  }
  for(int i =0;i<=(n>>1);i++){
      if(s[i]!='?' and s[n-1-i]!='?' and (i!=n-1-i)){
          if(s[i]!=s[n-1-i]){
              cout<<"-1\n";
              return;
          }else continue;
      }
      if(i==n-1-i){
          if(s[i]!='?') continue;
          if(a+b==1){
              if(a==1){
                  s[i] = '0';
                  a-=1;
              }else if(b==1){
                 s[i] = '1';
                 b-=1;
              }
          }else{
              cout<<"-1\n";
              return;
          }
      }else{
          if(s[i]=='?' and s[n-1-i]=='?'){
              if(a<2 and b<2){
                cout<<"-1\n";
                return; 
              }else{
                  if(a>=2){
                      s[i] = s[n-1-i] = '0';
                      a-=2;
                  }else if(b>=2){
                      s[i] = s[n-1-i] = '1';
                      b-=2;
                  }
              }
          }else if(s[i]!='?' and s[n-1-i]=='?'){
             if(s[i]=='1'){
                 if(b>=1){
                     s[n-1-i] = '1';
                     b-=1;
                 }else{
                    cout<<"-1\n";
                    return;
                 }
             }else{
                 if(a>=1){
                     s[n-1-i] = '0';
                     a-=1;
                 }else{
                    cout<<"-1\n";
                    return;
                 }
             }
          }else if(s[i]=='?' and s[n-1-i]!='?'){
              if(s[n-1-i]=='1'){
                  if(b>=1){
                     s[i] = '1';
                     b-=1;
                 }else{
                    cout<<"-1\n";
                    return;
                 }
              }else{
                  if(a>=1){
                     s[i] = '0';
                     a-=1;
                 }else{
                    cout<<"-1\n";
                    return;
                 }
              }
          }
      }
  }
  if(a+b!=0){
    cout<<"-1\n";
    return;
  }
  // c = a
  // d = b
  int _a = 0;
  int _b =0;
  for(int i =0;i<n;i++){
      if(s[i]=='1'){
          _b+=1;
      }
      if(s[i]=='0'){
          _a+=1;
      }
      if(s[i]=='?' or s[i]!=s[n-1-i]){
        cout<<"-1\n";
        return;
      }
  }
  if(_a!=c or _b!=d){
    cout<<"-1\n";
    return;
  }
  cout<<s<<'\n';

}

int main(){
  FastIO;
  int t = 1;
  if(cases) cin>>t;
  while(t--){
    SolveCase();
  }
  return 0;
} 
