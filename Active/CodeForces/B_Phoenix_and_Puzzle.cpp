// Problem Link : https://codeforces.com/problemset/problem/1515/B
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

Phoenix is playing with a new puzzle, which consists of n identical puzzle pieces. Each puzzle piece is a right isosceles triangle as shown below.

A puzzle piece
The goal of the puzzle is to create a square using the n pieces. He is allowed to rotate and move the pieces around, but none of them can overlap and all n pieces must be used (of course, the square shouldn't contain any holes as well). Can he do it?

*/

/*

if n can be written as 2x or 4x, where x is a square number, then the answer is YES. Otherwise it is NO.

To visualize this construction, we start by first building a smaller square using exactly 2 or 4 pieces (the drawings are in the sample test explanation). We can just use x of those smaller squares to build a larger square.

Let's prove that there are no other answers (although this isn't necessary to solve the problem). Let's define each triangle piece to have a short side of length 1 and a longer side of length 2–√. Consider one side of the square, and suppose that it has a triangles on the short side and b triangles on the longer side. The side length will be a+2–√b. The area of the square is a rational number because the area of each triangle piece is rational. So, (a+2–√b)2 has to be rational, which means either a is 0, or b is 0. If either is 0, we can use the construction in the previous paragraph.

Time complexity for each test case: O(n−−√) or O(logn) (depends on how you check for square numbers)

*/

ll IsSquare(ll x){
    ll p = (ll)sqrt(x);
    return p*p==x;
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      ll n;
      cin>>n;
      Status((IsSquare(n/2) and (n%2==0)) or (IsSquare(n/4) and (n%4==0)));
  }
  return 0;
} 
// If Solved Mark (0/1) here => []