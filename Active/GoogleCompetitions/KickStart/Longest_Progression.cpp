// Problem Link : https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435a5b/000000000077a3a5
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

In Kick Start 2020 Round E (you do not need to know anything about the previous problem to solve this one) Sarasvati learned about arithmetic arrays. An arithmetic array is an array that contains at least two integers and the differences between consecutive integers are equal. For example, [9,10], [3,3,3], and [9,7,5,3] are arithmetic arrays, while [1,3,3,7], [2,1,2], and [1,2,4] are not.

Sarasvati again has an array of N non-negative integers. The i-th integer of the array is Ai. She can replace at most one element in the array with any (possibly negative) integer she wants.

For an array A, Sarasvati defines a subarray as any contiguous part of A. Please help Sarasvati determine the length of the longest possible arithmetic subarray she can create by replacing at most one element in the original array.

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing the integer N. The second line contains N integers. The i-th integer is Ai.

*/

/*

Test Set 1
For any test case, if N=2, we can return 2 as the answer immediately, as any two numbers are trivially an arithmetic progression by themselves. For N≥3, we can attempt a strategy that tries to improve it by considering every element of A as a possible starting point. For instance, let us try to start a longest progression beginning at A0. Let us call the first difference we encounter, A1−A0, d. d could be the common difference of a longest progression that starts from A0, or it could not be. We attempt both possibilities:
If it is, we just need to continue trying to extend our possible progression with A2, A3 and so on, checking that A2−A1=d, A3−A2=d, etc. Because we can change at most one number, the first time we find some k for which Ak−Ak−1≠d, we fix Ak so that this expression does equal to d. We continue along the array afterwards until we reach the end or we find a second instance of k where Ak−Ak−1≠d; at that point, we cannot go any further.
If it is not, the only possibility for a progression with length >=3 starting from A0 is if the common difference is (A2−A0)/2. In this case, we must set A1 such that (A1−A0)=(A2−A1). Hence, note that this is only possible if A2−A0 is an even number - if it is not, we can determine the longest progression starting at A0 under this scenario to simply be 2 (as we cannot extend it past the first two values of the array). Once we have done so, our common difference is set, and we continue trying to extend our progression starting from A3, A4, and so on, stopping at the first Ak where (A1−A0)≠(Ak−Ak−1). At that point, the length of the longest progression starting at A0 under this scenario will be k.

Both possibilities 1 and 2 take O(N) for a given starting point. Because we will try sequentially all possible starting points from A0,A1,…,AN−2, finding the max value amongst all N−1 possible starting points with 2 possible scenarios each, our overall time complexity with this strategy will be O(N2).
Test Set 2
Let's simplify the problem a little. The only thing that really matters in this situation is the common difference between two adjacent numbers, not the numbers themselves. That is, the length of the longest progression of [a,b,c,d,e,f] is always going to be the same as that of [a+k,b+k,c+k,d+k,e+k,f+k]. So, we can create an array D where Di=Ai+1−Ai. D0 is hence A1−A0, and so on, until DN−2 which is AN−1−AN−2. For instance, given A=[1,3,4,7,9,11], we find that D=[2,1,3,2,2].

Now, we can break D into chunks. Each chunk is a contiguous portion of the array with identical values. For a given chunk, let us call this value its common value. For instance, for D=[2,1,3,2,2], we can break this down as [2],[1],[3],[2,2], so 2 is the common value of the first chunk, and so on. Each chunk has a starting index within D. That index should be associated with the length and common value of that chunk, and this information stored for lookup. Then, we iterate through the chunks in ascending starting index order. For each chunk beginning at index i, with length k, and having common value d, we greedily try to fix the element in D right after the chunk, if it exists. Then, we also need a separate attempt to try fixing the element right before the chunk, if it exists. That means we will need to attempt merging for each chunk up to two times. The following analysis is for what happens when we merge with the element after our current chunk, but the same applies for the corresponding situation when we merge backwards too.

The last element in our current chunk has index (i+k−1). If we greedily use our ability to change a number by adding some amount to Di+k so it is equal to d, we must also reduce Di+k+1 by the same amount. The opposite case applies. At this point:

if Di+k+Di+k+1≠2×d, then we have only been able to merge our current chunk with the element right after. The length of our extended chunk is now k+1.
if Di+k+Di+k+1=2×d, but Di+k+2≠d, then changing Di+k has allowed us to also merge with Di+k+1. The length of our extended chunk is now k+2.
if Di+k+Di+k+1=2×d, and Di+k+2=d, then we have been able to merge even further with a chunk that starts 3 elements after our current one ends. The length of the whole merge becomes k+2+ the length of the next chunk with common value d.
For instance, with D=[1,1],[2],[0,0], if we try to merge forward from the first chunk which begins at index i=0, has length k=2 and common value d=1,D2+D3=2+0=2×d, but D4≠d. This is the second scenario above, and the length of our extended chunk is now 4, so the overall progression length in A is 5. Another example: with D=[2],[1],[3],[2,2], if we try to merge forward from the first chunk which begins at index i=0, has length k=1 and common value d=2,D1+D2=1+3=4=2×d, and D3=d. This is the third scenario above, and the length of our extended chunk is now 1+2+2=5, so the overall progression length in A is 6.

Our overall solution to the problem is then just the max of all the possible chunks made by considering each chunk in turn, and trying to merge it backwards and forwards. (As a result, if the test case in question falls into the third scenario listed above, the "longest progression" will actually be discovered twice, but this doesn't change its correctness.)

In summary, we run through the initial array once to create D, and then run through D to create map(s) of chunks tagged with the appropriate information, and then run through D again with our map of chunks to finally get our result. Assuming we have access to constant-time lookup for the lengths and common values of chunks, the overall time complexity is O(N).

*/

int main(){
  FastIO;
  
  return 0;
} 
// If Solved Mark (0/1) here => []