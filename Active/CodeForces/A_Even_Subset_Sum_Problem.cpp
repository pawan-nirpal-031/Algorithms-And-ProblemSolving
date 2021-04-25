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

You are given an array a consisting of n positive integers. Find a non-empty subset of its elements such that their sum is even (i.e. divisible by 2) or determine that there is no such subset.

Both the given array and required subset may contain equal values.

For each test case output −1 if there is no such subset of elements. Otherwise output positive integer k, number of elements in the required subset. Then output k distinct integers (1≤pi≤n), indexes of the chosen elements. If there are multiple solutions output any of them

*/

void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i =0;i<n;i++){
        cin>>a[i];
        if(a[i]%2==0){
            cout<<1<<'\n'<<i+1<<'\n';
            return;
        }
    }
    
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
} 
// If Solved Mark (0/1) here => []