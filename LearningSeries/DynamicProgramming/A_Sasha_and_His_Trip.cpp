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

Sasha is a very happy guy, that's why he is always on the move. There are n cities in the country where Sasha lives. They are all located on one straight line, and for convenience, they are numbered from 1 to n in increasing order. The distance between any two adjacent cities is equal to 1 kilometer. Since all roads in the country are directed, it's possible to reach the city y from the city x only if x<y.

Once Sasha decided to go on a trip around the country and to visit all n cities. He will move with the help of his car, Cheetah-2677. The tank capacity of this model is v liters, and it spends exactly 1 liter of fuel for 1 kilometer of the way. At the beginning of the journey, the tank is empty. Sasha is located in the city with the number 1 and wants to get to the city with the number n. There is a gas station in each city. In the i-th city, the price of 1 liter of fuel is i dollars. It is obvious that at any moment of time, the tank can contain at most v liters of fuel.

Sasha doesn't like to waste money, that's why he wants to know what is the minimum amount of money is needed to finish the trip if he can buy fuel in any city he wants. Help him to figure it out!


*/

int main(){
  FastIO;
  int n,v;
  cin>>n>>v;
  if(n-1<=v){
      Print(n-1);
      return 0;
  }
  int money = v-1;
  for(int i = 1;i<=n-v;i++){
      money+=i;
  }
  Print(money);
  return 0;
} 
// If Solved Mark (0/1) here => []