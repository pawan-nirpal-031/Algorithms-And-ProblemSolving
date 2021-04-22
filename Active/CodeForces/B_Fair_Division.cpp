// Problem Link : https://codeforces.com/contest/1472/problem/B
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

Alice and Bob received n candies from their parents. Each candy weighs either 1 gram or 2 grams. Now they want to divide all candies among themselves fairly so that the total weight of Alice's candies is equal to the total weight of Bob's candies.
Check if they can do that.

Note that candies are not allowed to be cut in half.

*/

/*
    Remarks :   This was a really good question, it was subtle most including me would have gotten wrong in a hurry
    
    If the sum of all the weights is not divisible by two, then it is impossible to divide the candies between two people. If the sum is divisible, then let's count the number of candies with a weight of 1 and 2. Now, if we can find a way to collect half the sum with some candies, then these candies can be given to Alice, and all the rest can be given to Bob.
    Simple solution — let's iterate through how many candies of weight 2 we will give to Alice, then the remaining weight should be filled by candies of weight 1. If there are enough of them, then we have found a way of division.
    In fact, if the sum is even and there are at least two candies with weight 1 (there can't be one candy), then the answer is always "YES" (we can collect the weight as close to half as possible with weight 2 and then add weight 1). If there are no candies with weight 1, then you need to check whether n is even (since all the candies have the same weight, you just need to divide them in half)

    My Approach : count(1) = x, count(2) = y, leaving the trivial cases say we spilt sum into Alice(x1,y1) Bob(x2,y2)
    x1+x2 = x and y1+y2 = y, x1+2*y1 = x2+2*y2 since Sum(Alice) = Sum(Bob) solve and get x1 = x/2 + y - 2*y1, now y1 can range from [0,y] so just iterate on y1 [0,y] and see if x1>=0 if yes then set a flag to true
*/

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      int n;
      cin>>n;
      int a[n];
      int x =0,y =0;
      for(int i =0;i<n;i++){
          cin>>a[i];
          if(a[i]==1) x+=1;
          else y+=1;
      }
      if(x&1){
          Status(0);
      }else{
          if(x==0){
              Status(y%2==0);
          }else{
              bool yes = 0;
              for(int y1 =0;y1<=y;y1++){
                  int x1 = (x>>1) + (y - 2*y1);
                  if(x1>=0){
                      yes = 1;
                      break;
                  }
              }
              Status(yes);
          }
      }
  }
  return 0;
} 
// If Solved Mark (0/1) here => [1]

