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
#define Status(b) (cout<<(b?"Yes\n":"No\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x


/*
Given an array AA containing NN integers, find the maximum value of a*b+a-ba∗b+a−b where a, ba,b are distinct elements of array.

QUICK EXPLANATION
Rewriting a*b+a-b = (a-1)*(b+1) +1a∗b+a−b=(a−1)∗(b+1)+1, we can fix aa and see that for bb, we only need to consider either minimum or maximum of all elements of array excluding element aa.
It can be done by computing the minimum, second minimum, maximum and second maximum element of array, or just by simply sorting the array.
EXPLANATION
As mentioned in quick explanation, we can rewrite the expression.
a*b+a-b = a*(b+1) - (b+1)+1 = (a-1)*(b+1)a∗b+a−b=a∗(b+1)−(b+1)+1=(a−1)∗(b+1)

Hence, we need to maximise (a-1)*(b+1)(a−1)∗(b+1) where aa and bb are two distinct elements of array.

Now, a naive way to do this would be to try all pairs of numbers, and taking maximum of value resulted by any pair.

Here, if the elements of array were positive, Just taking the last two elements would have been sufficient. But there are negative elements too, and the product of two negative element can also lead to a higher positive product.

So we try to fix aa. We can see that once aa is fixed, it is optimal to choose bb which would maximise value of (a-1)*(b+1)+1(a−1)∗(b+1)+1. So

if (a-1) > 0(a−1)>0, we’d aim to select the largest element in array, so that the value of b+1b+1 can be maximised, therefore (a-1)*(b+1)+1(a−1)∗(b+1)+1 is maximised.
if (a-1) < 0(a−1)<0, we’d aim to select the smallest element in array, so that the value of b+1b+1 can be minimised, therefore (a-1)*(b+1)+1(a−1)∗(b+1)+1 is maximised.
if (a-1) < 0(a−1)<0, then answer is atleast zero.
Hence, all we need to do is to sort the array, fix aa to be each element one by one, and choose most optimum bb. Taking maximum over all these candidates gives the maximum value of a*b+a-ba∗b+a−b

Bonus
Write a solution for above problem which checks minimum number of pairs.

TIME COMPLEXITY
The time complexity can be O(N)O(N) or O(N*log(N))O(N∗log(N)) depending upon implementation, per test case.
The memory complexity is O(N)O(N) per test case, can be reduced to O(1)O(1).

*/


void SolveCaseWithoutSorting(){// O(n) time and O(1) memory this took 0.08 secs
  int n;
  cin>>n;
  ll ans = LLONG_MIN;
  ll first,second;
  first = second = LLONG_MIN;
  ll smallfir, smallsec;
  smallfir = smallsec = LLONG_MAX;
  for(int i=0;i<n;i++){
     ll x;
      cin>>x;
     if(x>first){
         second = first;
         first = x;
     }  
     else if(x>second and x<first){
         second = x;
     }
     if(x<smallfir){
         smallsec = smallfir;
         smallfir = x;
     }
     else if( x<smallsec){
         smallsec = x;
     }
  }
  ans  = max(ans,max((smallfir+1)*(smallsec-1)+1,(first-1)*(second+1)+1));
  cout<<ans<<'\n';
}

void SolveCaseWithSorting(){ // takes 0.12 secs with vector, sorting and 0.11 sec with naitve array, O(n) memory and O(nlogn) time  
  int n;
  cin>>n;
  ll v[n];
  for(int i =0;i<n;i++) cin>>v[i];
  sort(v,v+n);
  ll ans = LLONG_MIN;
  ans = max(ans,max(((v[n-1]-1)*(v[n-2]+1) + 1),((v[1]-1)*(v[0]+1)+1)));
  cout<<ans<<'\n';
}


int main(){
  FastIO;
  int t = 1;
  cin>>t;
  while(t--){
    SolveCaseWithoutSorting();
  }
  return 0;
} 


/*

Max and second max in O(n) in single travrsl 

Approach: Find the second largest element in a single traversal. 
Below is the complete algorithm for doing this:  

1) Initialize two variables first and second to INT_MIN as
   first = second = INT_MIN
2) Start traversing the array,
   a) If the current element in array say arr[i] is greater
      than first. Then update first and second as,
      second = first
      first = arr[i]
   b) If the current element is in between first and second,
      then update second to store the value of current variable as
      second = arr[i]
3) Return the value stored in second.


*/