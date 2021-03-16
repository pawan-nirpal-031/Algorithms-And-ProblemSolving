#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define append(a) push_back(a)
#define pair(a,b) make_pair(a,b)
#define clear(a) for(ll &x : a){x=0;}
#define point(x) std::fixed<<setprecision(10)<<x;
#define setbits(x) __builtin_popcount(x);
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


ll NoOFSetBits(ll n){
  /*
     Brian Kernighan’s Algorithm:
    Subtracting 1 from a decimal number flips all the bits after the rightmost 
    set bit(which is 1) including the rightmost set bit.
    for example :
    10 in binary is 00001010
    9 in binary is 00001001
    8 in binary is 00001000
    7 in binary is 00000111
    So if we subtract a number by 1 and do bitwise & with itself (n & (n-1)), 
    we unset the rightmost set bit. If we do n & (n-1) in a loop and count the no of times loop executes 
    we get the set bit count.
    The beauty of this solution is the number of times it loops is equal
    to the number of set bits in a given integer.
  */

  if(n==0){
      return 0;
  }
  ll c=0;
  while(n>0){
      n = (n&(n-1));
      c++;
  }
  return c;
}


int main(){
  FastIO;
  
  return 0;
} 
