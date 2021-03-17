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

Chang is a big fan of bitwise operations. As he was sitting in a boring lecture, he thought 
of a simple problem but had a tough time figuring out the solution. Help him to solve it. 
The problem is as follows. Given a list of N non-negative integers, you perform the following 
operation on this list. Select any subsequence of integers from the list and remove the 
elements of that subsequence. The cost incurred will be Bitwise OR of the elements.
Your task is to remove all the integers from the list by applying the above operation as 
many times as you want. You want to incur the minimum total cost at the end. Total cost 
is the sum of all the costs incurred while removing subsequences.


dp[i][b] : min cost incurred if element b : 1 kept or b : 0 removed in the current subsequence


*/


bool cases =1;

void SolveCase(){
  int n;
  cin>>n;
  ll ans =0;
  while(n--){
    ll x;
    cin>>x;
    ans |=x;
  }
  cout<<ans<<'\n';
}

int main(){
  FastIO;
  int t = 1;
  if(cases) cin>>t;
  while(t--){
     SolveCase();
  }
  return 0;
} 


/*

The problem can indeed be solved by simple observation.
It is first important to understand how the Bitwise OR operation actually works. 
A bitwise OR for two integers takes their corresponding bit patterns of equal length 
and performs the logical inclusive OR operation on each pair of corresponding bits. 
The result in each position is 00 if both bits are 00, while otherwise the result is 11.
In order to incur the minimum cost, it is necessary to select a complete array as a 
subsequence so that the total cost will be the Bitwise OR of all the integers in the array. 
But, why this will give you the minimum cost.
Consider a number that has some set bits in it’s binary representation. There may be another 
number in the array who might have set bits in the same position. In case, you do not take these 
numbers in a single operation, you will end up adding the value contributed by that common set 
bits twice. However, if you take them as a part of the same subsequence, you do a Bitwise OR 
and the value contribution for common set bit just get added up only once to the final cost.

*/