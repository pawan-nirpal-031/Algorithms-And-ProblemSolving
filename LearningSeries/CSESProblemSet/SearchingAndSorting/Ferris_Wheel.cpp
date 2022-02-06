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

Time limit: 1.00 s Memory limit: 512 MB
There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.

Each gondola may have one or two children in it, and in addition, the total weight in a gondola may not exceed x. You know the weight of every child.

What is the minimum number of gondolas needed for the children?

Input

The first input line contains two integers n and x: the number of children and the maximum allowed weight.

The next line contains n integers p1,p2,…,pn: the weight of each child.

Output

Print one integer: the minimum number of gondolas.

Constraints
1≤n≤2⋅105
1≤x≤109
1≤pi≤x

*/


/*
Author's solution : 

Since each gondola can contain either 1 or 2 children, for each gondola, we can
do one of two things:

Pair the lightest child with the heaviest child possible without exceeding
the weight limit.
If the pairing isn't possible, we only include the lightest child.


Those left unpaired each get their own gondola. The implementation below uses
the above method.

Alternatively, for each gondola, we can also

Pair the heaviest child with the lightest child if possible.
Otherwise, only include the heaviest child.


Both pairing methods can be achieved in $\mathcal{O}(n)$ time using two
pointers, and sorting brings the overall time complexity to
$\mathcal{O}(n\log n)$.


*/

int main(){
  FastIO;
  int n,k;
  cin>>n>>k;
  vector<bool>have_cart(n+3,0);
  vector<int>wt(n,0);
  for(int &x : wt) cin>>x;
  sort(All(wt));
  int smaller =0,big = n-1;
  int ans =0;
  while(smaller<big){
    if(wt[smaller]+wt[big]>k) big-=1;
    else{
      ans+=1;
      have_cart[big] = have_cart[smaller] = 1;
      smaller+=1;
      big-=1;
    }
  }
  for(int i =0;i<n;i++) if(not have_cart[i]) ans++;
  cout<<ans;
  return 0;
} 
// If Solved Mark (0/1) here => [1]