// Problem Link : https://codeforces.com/contest/1472/problem/A
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
For the New Year, Polycarp decided to send postcards to all his n friends. He wants to make postcards with his own hands. For this purpose, he has a sheet of paper of size w×h, which can be cut into pieces.

Polycarp can cut any sheet of paper w×h that he has in only two cases:

If w is even, then he can cut the sheet in half and get two sheets of size w2×h;
If h is even, then he can cut the sheet in half and get two sheets of size w×h2;
If w and h are even at the same time, then Polycarp can cut the sheet according to any of the rules above.

After cutting a sheet of paper, the total number of sheets of paper is increased by 1.

Help Polycarp to find out if he can cut his sheet of size w×h at into n or more pieces, using only the rules described above.

In the first test case, you can first cut the 2×2 sheet into two 2×1 sheets, and then cut each of them into two more sheets. As a result, we get four sheets 1×1. We can choose any three of them and send them to our friends.

In the second test case, a 3×3 sheet cannot be cut, so it is impossible to get two sheets.

In the third test case, you can cut a 5×10 sheet into two 5×5 sheets.

In the fourth test case, there is no need to cut the sheet, since we only need one sheet.

In the fifth test case, you can first cut the 1×4 sheet into two 1×2 sheets, and then cut each of them into two more sheets. As a result, we get four sheets 1×1.

*/

int main(){
  FastIO;
  
  return 0;
} 
// If Solved Mark (0/1) here => []