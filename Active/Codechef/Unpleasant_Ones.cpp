// Problem Link : https://www.codechef.com/LTIME97B/problems/UNONE
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

The ugliness of a string is defined as the count of two consecutive ones i.e. "11" in the given string. For example, the ugliness of string "10111" is 2.

You are given an array A of N integers and you have to find any ordering of the array such that the ugliness of the concatenated string of the binary representations of the integers (without leading zeros) is minimum.

*/


/*
Author's solution : 



*/

void Solve(){
    int n;
    cin>>n;
    vector<ll>even_nos,odd_nos;
    while(n--){
        ll v;
        cin>>v;
        if(v%2==0) even_nos.push_back(v);
        else odd_nos.push_back(v);
    }
    for(ll v : even_nos) cout<<v<<' ';
    for(ll v : odd_nos) cout<<v<<' ';
    cout<<'\n';
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      cout<<Point((2*1.0)/3);
  }
  
  
  return 0;
} 
// If Solved Mark (0/1) here => []