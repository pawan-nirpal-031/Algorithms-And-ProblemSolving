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

int CoinCombination(int coins[],int n,int amount){
  vector<int>nofways(amount+1,0);
  nofways[0] =1;
  for(int c =0;c<n;c++){
    for(int i =1;i<=amount;i++){
      if(coins[c]<=i){
        nofways[i]+=nofways[i-coins[c]];
      }
    }
  }
  return nofways[amount];
}

int CoinPermutation(int coins[],int n,int amount){
  vector<int>nofways(amount+1,0);
  nofways[0] =1;
  for(int i =1;i<=amount;i++){
    for(int c = 0;c<n;c++){
      if(coins[c]<=i){
        nofways[i]+=nofways[i-coins[c]];
      }
    }
  }
  return nofways[amount];
}

bool IsSumPossibleWithASubset(int a[],int sum,int n){
  bool IsPossible[n+1][sum+1];
  IsPossible[0][0] = 1;
  for(int i =1;i<=sum;i++) IsPossible[0][i] = 0;
  for(int i =1;i<=n;i++) IsPossible[i][0] = 1;
  for(int element_indx = 1;element_indx<=n;element_indx++){
    for(int possible_sum = 1;possible_sum<=sum;possible_sum++){
      int val = a[element_indx-1];
      if(possible_sum>=val){
        IsPossible[element_indx][possible_sum] = (IsPossible[element_indx-1][possible_sum] or IsPossible[element_indx-1][possible_sum-val]);
      }else{
        IsPossible[element_indx][possible_sum] = IsPossible[element_indx-1][possible_sum];
      }
    }
  }
  return IsPossible[n][sum];
}


int main(){
  FastIO;
  int n,amt;
  cin>>n>>amt;
  int a[n];
  for(int i =0;i<n;i++) cin>>a[i];
  IsSumPossibleWithASubset(a,amt,n);
  return 0;
} 
