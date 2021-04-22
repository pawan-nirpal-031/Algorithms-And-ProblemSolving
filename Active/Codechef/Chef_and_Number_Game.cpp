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


Recently, Chef hosted a strange competition at the Byteland annual fair. There were N participants in the
competition (numbered 1 through N); at the end of the competition, their scores were A1,A2,…,AN. Since it 
was a strange competition, negative scores were allowed too. The total score of the competition is calculated as 
follows: Divide the participants into one or more non-empty groups (subsets); if there are K groups, let's 
denote them by G1,G2,…,GK. Each participant should be a member of exactly one group.
Sum up the scores of participants in each individual group. For each valid i, let's denote the sum of scores 
of participants in group i by Xi. The total score of the competition is the sum of squares of these summed up scores,
i.e. X21+X22+…+X2K.Chef wants to choose the groups in such a way that the total score is maximum possible. 
Since there may be many ways to form the groups that lead to the maximum total score, Chef wants to know 
just the size of the largest group and the size of the smallest group which could be formed while still 
maximising the total score. These sizes are independent - formally, they are the maximum and minimum size s 
of a group such that there is a way to form groups which maximises the total score and contains a group with size s.


1≤T≤20
1≤N≤105
1≤|Ai|≤109 for each valid i
the sum of N over all test cases does not exceed 5⋅105

*/

bool cases =1;

void SolveCase(){

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
