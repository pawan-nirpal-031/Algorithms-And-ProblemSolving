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

Given an array A of length N, we can define rotation as follows. If we rotate A to the right, all elements move to the right one unit, and the last element moves to the beginning. That is, it becomes [AN,A1,A2,…,AN−1]. Similarly if we rotate A to the left, it becomes [A2,A3,…,AN,A1].

Given an array A and an integer x, define f(A,x) to be the array A rotated by the amount x. If x≥0, this means we rotate it right x times. If x<0, this means we rotate it left |x| times.

You are given an array A of length N. Then Q queries follow. In each query, an integer x is given. To answer the query, you should replace A with A+f(A,x) where + denotes concatenation. After this operation, you must output the sum of all elements of A. Since this number can be large, output it modulo 109+7.

Note that the queries are cumulative. When you modify A to answer one query, it starts that way for the next query.

*/


void Solve(){
    ll n;
    cin>>n;
    ll a[n];
    ll sum =0;
    for(int i =0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    ll q;
    cin>>q;
    while(q--){
        ll x;
        cin>>x;
        sum = (2*sum)%Mod;
        if(sum<0) sum+=Mod;
        cout<<sum<<'\n';
    }
}

int main(){
  FastIO;
  Solve();
  return 0;
} 
// If Solved Mark (0/1) here => []