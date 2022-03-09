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

vector<int>min_devs;
void MinimumNumberOfSoftwareDevelopers(int i,const vector<int>&skills,vector<int>&carry,int skill_map){
    if(i==skills.size()){
        if(skill_map==(1<<i)-1){
            if(min_devs.size()==0 or (carry.size()<min_devs.size())){
                min_devs = carry;
            }
        }
        return;
    }
    carry.push_back(i);
    MinimumNumberOfSoftwareDevelopers(i+1,skills,carry,(skill_map|skills[i]));
    carry.pop_back();
    MinimumNumberOfSoftwareDevelopers(i+1,skills,carry,skill_map);
}


int UniqueNumberOccuringOnlyOnceAllOtherTwice(int a[],int n){
    int ans =0;
    for(int i=0;i<n;i++) ans = ans xor a[i];
    return ans;
}

void AllNumbersOccuringTwiceTwoNumbersOccuringOnce(int a[],int n){
    int array_xor = 0;
    for(int i=0;i<n;i++) array_xor = a[i] xor array_xor;
    int rightmost_set_mask = (array_xor & (-array_xor));
    int one_of_the_numbers =0;
    for(int i=0;i<n;i++) if(rightmost_set_mask&a[i]) one_of_the_numbers = one_of_the_numbers xor a[i];
    cout<<one_of_the_numbers<<' '<<(array_xor xor one_of_the_numbers)<<endl;
}

int main(){
  FastIO;
  int n;
  cin>>n;
  int a[n];
  for(int &x : a) cin>>x;
  AllNumbersOccuringTwiceTwoNumbersOccuringOnce(a,n);
  return 0;
} 
