// Problem Link : https://www.codechef.com/START39D/problems/MINBLOCK
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

Given a network of N cities (numbered from 1 to N) and (N−1) roads arranged in a tree format with the root at city 1.
Each of the (N−1) roads is assigned a value of either 0 or 1.

If the value of a road is 0, it cannot be blocked by the government.
If the value of a road is 1, it may or may not be blocked depending on the decision of the government.
Initially, city numbered 1 is infected by a virus. The infection spreads from an infected to an uninfected city only if all the roads present on the shortest path between the cities are unblocked.

The government wants to control the number of infected cities and has asked you to devise a plan. Determine the minimum number of roads (with value 1) you need to block such that at most K cities are infected at the end.
If it is not possible that at most K cities are infected, print −1.


The first line contains an integer T denoting the number of test cases. The T test cases then follow.
The first line of each test case contains two space-separated integers N and K, as given in the statement.
Each of the next (N−1) lines consists of 3 space-separated integers U, V, and X denoting that there exists a road between cities U and V with a value X (0 or 1).

For each test case, output a single integer representing the minimum number of roads that need to be blocked such that at most K cities are infected at the end.
If it is not possible that at most K cities are infected, print −1


Test Case 1: The road between city 1 and city 3 is blockable. By blocking that road the total number of infected cities, in the end, will be 3 (namely city 1,2 and 6) which is less than K=4.

Test Case 2: Even if all the blockable roads are blocked, the total number of cities that will get infected in the end will be 4 (namely city 1,2,3, and 4) which is greater than K=3. Thus, answer is −1.

*/


/*
Author's solution : 



*/





int main(){
  FastIO;
  
  return 0;
} 
// If Solved Mark (0/1) here => []