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

Given an array  of  integers. Find out the minimum value of the following expression for all valid .

, where .

Video approach to solve this question: here

Input format

First line: A single integer  denoting the number of test cases
For each test case:
First line contains a single integer , denoting the size of the array.
Second line contains  space separated integers 
Output format

For each test case, print a single line containing one integer that represents the minimum value of the given expression

Constraints


Note: Sum of  overall test cases does not exceed 



*/


/*
Author's solution : 



*/


void binary(ll n){
    if(n>0){
        binary(n>>1);
        cout<<n%2;
    }
}


void Solve(){
    int n;
    cin>>n;
    ll a[n];
    for(ll &x : a) cin>>x;
    ll ans = 10000;
    for(int i =0;i<n;i++){
       for(int j =i+1;j<n;j++){
           if(i==j) continue;
           binary(a[i]);
           cout<<'\n';
           binary(a[j]);
           ans = min(ans,(ll)((a[i] & a[j]) xor (a[i] | a[j])));
           cout<<"\n----\n";
       }
    }
    cout<<ans;
}

int main(){
  FastIO;
  int t=1;
  //cin>>t;
  while(t--){
    Solve();
  }
  return 0;
} 
// If Solved Mark (0/1) here => []