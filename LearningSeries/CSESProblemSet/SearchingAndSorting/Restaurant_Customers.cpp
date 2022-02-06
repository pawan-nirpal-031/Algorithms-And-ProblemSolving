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
#define All(x) begin(x),end(x)


/*
Problem Statement : 

You are given the arrival and leaving times of n customers in a restaurant.

What was the maximum number of customers?

Input

The first input line has an integer n: the number of customers.

After this, there are n lines that describe the customers. Each line has two integers a and b: the arrival and leaving times of a customer.

You may assume that all arrival and leaving times are distinct.

Output

Print one integer: the maximum number of customers.

Constraints
1≤n≤2⋅105
1≤a<b≤109

*/


/*
Author's solution : 

We can use prefix sums to determine the number of intervals that cover any
particular point, and then find the maximum number in the sum.

A naïve approach is to create an array $\texttt{ctr}$, where $\texttt{ctr}[i]$
is the number of intervals that cover each point $i$. We can do this by looping
through each interval $[a,b]$ and increasing $\texttt{ctr}[i]$ by $1$ for each
index in $a \leq i \leq b$.

This results in a $\mathcal{O}(nV)$ time complexity (where
$0 \leq a \leq b \leq V$), which easily times out (think what happens when the
interval $[0, V]$ is queried $n$ times).

We can do better. It's easy to see that an increment of $x$ (before computation)
in $\texttt{arr}[i]$ causes all subsequent $\texttt{prefix}[i...V]$ (after
computation) to increase by $x$. We can also "undo" this operation by adding
$-x$ to $\texttt{arr}[i]$. This concept can be conceptualized through increment
and decrement points. An increment point increases (and decrement decreases) all
subsequent cells. Note that our decrement point is located at $B+1$ because the
interval is inclusive - decrementing at point $B$ turns the interval to
$[A, B)$.

Example 1: Add two to each point in the interval $[2, 4]$

Our array after adding 2 at our increment (start) point (before computation)

0
0
2
0
0
0

Our prefix sum after adding 2 at our increment (start) point (and computing).

0
0
2
2
2
2

Our prefix sum after subtracting 2 at our decrement point (and computing).

0
0
2
2
2
0

Observe that this works for multiple intervals.

Example 2: Add two to each point in $[2, 4]$ and one to each point in
$[1, 3]$

Adding interval $[2, 4]$ with increment point at $2$ and decrement at $4+1=5$

0
0
2
0
0
-2

Adding interval $[1, 3]$ with increment point at $1$ and decrement at $3+1=4$

0
1
2
0
-1
-2

After computation

0
1
3
3
2
0

In this problem, our $x$ is fixed at $1$. As a result, when we encounter a
starting point, we can increment by $1$, and for an endpoint, decrement by $1$.
We actually cannot compute the prefix sum array directly since $V \leq 10^9$,
and we will run out of memory when creating an array of size $V$.

Instead, we can either coordinate compress and compute the prefix sum over
interesting intervals or sweep over the intervals while maintaining a running
prefix sum.

*/



int main(){
  FastIO;
  int q;
  cin>>q;
  vector<pair<int,int>>intervals;
  while(q--){
    int x,y;
    cin>>x>>y;
    intervals.push_back(Pair(x,1));
    intervals.push_back(Pair(y,-1));
  }
  sort(All(intervals));
  int c =0;
  int sum = 0;
  for(auto p : intervals){
    sum+=p.second;
    c = max(c,sum);
  }
  
  cout<<c;
  return 0;
} 
// If Solved Mark (0/1) here => []