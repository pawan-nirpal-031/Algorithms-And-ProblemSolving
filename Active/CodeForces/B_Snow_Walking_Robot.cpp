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

Recently you have bought a snow walking robot and brought it home. Suppose your home is a cell (0,0) on an infinite grid.

You also have the sequence of instructions of this robot. It is written as the string s consisting of characters 'L', 'R', 'U' and 'D'. If the robot is in the cell (x,y) right now, he can move to one of the adjacent cells (depending on the current instruction).

If the current instruction is 'L', then the robot can move to the left to (x−1,y);
if the current instruction is 'R', then the robot can move to the right to (x+1,y);
if the current instruction is 'U', then the robot can move to the top to (x,y+1);
if the current instruction is 'D', then the robot can move to the bottom to (x,y−1).
You've noticed the warning on the last page of the manual: if the robot visits some cell (except (0,0)) twice then it breaks.

So the sequence of instructions is valid if the robot starts in the cell (0,0), performs the given instructions, visits no cell other than (0,0) two or more times and ends the path in the cell (0,0). Also cell (0,0) should be visited at most two times: at the beginning and at the end (if the path is empty then it is visited only once). For example, the following sequences of instructions are considered valid: "UD", "RL", "UUURULLDDDDLDDRRUU", and the following are considered invalid: "U" (the endpoint is not (0,0)) and "UUDD" (the cell (0,1) is visited twice).

The initial sequence of instructions, however, might be not valid. You don't want your robot to break so you decided to reprogram it in the following way: you will remove some (possibly, all or none) instructions from the initial sequence of instructions, then rearrange the remaining instructions as you wish and turn on your robot to move.

Your task is to remove as few instructions from the initial sequence as possible and rearrange the remaining ones so that the sequence is valid. Report the valid sequence of the maximum length you can obtain.

Note that you can choose any order of remaining instructions (you don't need to minimize the number of swaps or any other similar metric).

You have to answer q independent test cases.

Input
The first line of the input contains one integer q (1≤q≤2⋅104) — the number of test cases.

The next q lines contain test cases. The i-th test case is given as the string s consisting of at least 1 and no more than 105 characters 'L', 'R', 'U' and 'D' — the initial sequence of instructions.

It is guaranteed that the sum of |s| (where |s| is the length of s) does not exceed 105 over all test cases (∑|s|≤105).

Output
For each test case print the answer on it. In the first line print the maximum number of remaining instructions. In the second line print the valid sequence of remaining instructions t the robot has to perform. The moves are performed from left to right in the order of the printed sequence. If there are several answers, you can print any. If the answer is 0, you are allowed to print an empty line (but you can don't print it).

*/


/*
Author's solution : 



*/

int main(){
  FastIO;
  
  return 0;
} 
// If Solved Mark (0/1) here => []