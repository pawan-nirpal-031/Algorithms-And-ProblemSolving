// Problem Link : https://cses.fi/problemset/task/1645
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

Given an array of n integers, your task is to find for each array position the nearest position to its left having a smaller value.

Input

The first input line has an integer n: the size of the array.

The second line has n integers x1,x2,…,xn: the array values.

Output

Print n integers: for each array position the nearest position with a smaller value. If there is no such position, print 0.

*/


/*
Author's solution : 

There can be an Efficient Solution that works in O(n) time. The idea is to use a stack. Stack is used to maintain a subsequence of the values that have been processed so far and are smaller than any later value that has already been processed.
Below is stack based algorithm 

Let input sequence be 'arr[]' and size of array be 'n'

1) Create a new empty stack S

2) For every element 'arr[i]' in the input sequence 'arr[]',
   where 'i' goes from 0 to n-1.
    a) while S is nonempty and the top element of 
       S is greater than or equal to 'arr[i]':
           pop S
    
    b) if S is empty:
           'arr[i]' has no preceding smaller value
    c) else:
           the nearest smaller value to 'arr[i]' is 
           the top element of S

    d) push 'arr[i]' onto S

*/

int main(){
  FastIO;
  int n;
  cin>>n;
  ll a[n];
  for(ll &x : a) cin>>x;
  stack<pair<int,int>>cache;
  for(int i =0;i<n;i++){
    while(not cache.empty() and cache.top().first>=a[i]) cache.pop();
    if(cache.empty()) cout<<0<<' ';
    else cout<<cache.top().second<<' ';
    cache.push({a[i],i+1});
  }
  return 0;
} 
// If Solved Mark (0/1) here => [1]