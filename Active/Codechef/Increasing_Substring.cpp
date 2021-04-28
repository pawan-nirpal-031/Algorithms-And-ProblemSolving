// Problem Link : https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435a5b/000000000077a882
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

Your friend John just came back from vacation, and he would like to share with you a new property that he learned about strings.

John learned that a string C of length L consisting of uppercase English characters is strictly increasing if, for every pair of indices i and j such that 1≤i<j≤L (1-based), the character at position i is smaller than the character at position j.

For example, the strings ABC and ADF are strictly increasing, however the strings ACC and FDA are not.

Now that he taught you this new exciting property, John decided to challenge you: given a string S of length N, you have to find out, for every position 1≤i≤N, what is the length of the longest strictly increasing substring that ends at position i.

*/

void Solve(int x){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>dp(n,1);
    for(int i =1;i<n;i++){
        if(s[i]>s[i-1]) dp[i] = 1+dp[i-1];
    }
    cout<<"Case #"<<x<<": ";
    for(int i =0;i<n;i++) cout<<dp[i]<<' ';
    cout<<"\n";
}

int main(){
  FastIO;
  int t;
  cin>>t;
  for(int x=1;x<=t;x++) Solve(x);
  return 0;
} 
// If Solved Mark (0/1) here => [1]