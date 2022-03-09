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

void SetBit(int &x,int bit_no){
    x |=(1<<bit_no);
}

void ClearBit(int &x,int bit_no){
    x &=~(1<<bit_no); 
}

void ToggleBit(int &x,int bit_no){
    x^=(1<<bit_no);
}


bool IsThisBitSet(int x,int bit_no){
    return (x&(1<<bit_no));
}

int RightMostSetBitMask(int x){ // -x is the 2's comp of x or ~x+1 also works as ~x is 1's comp and adding 1 to it is 2's complement 
    return (x & (-x)); // verify by an example ie (x & (2's complement of x))
}

int KernighenSAlgorithmForCountingNumberOfSetbits(int x){ // uses RightMostSetBitMask to count
/*
    just keep subtracting rightmost set bit mask from given number this algortihm skips all zeros and does not count them it only counts number of 1's unlike brute force so number of subtractions is equal to number of set bits only 

    ex : x = 1100110010000
      rsbm = 0000000010000
      when you do x = x-rsbm 
      x becomes : 110011 and keep doing until x>0 
      in next step 
        x = 110011
     rsbm = 000001
     x = x-rsbm gives = 11001  
*/
    int count =0;
    while(x){
        count++;
        x -=(x&-x);
    }
    return count;
}


int JosephousProblemUsingBitManip(int n){
    
}

int main(){
  FastIO;
  int x;
  cin>>x;
  cout<<KernighenSAlgorithmForCountingNumberOfSetbits(x);
  return 0;
} 
