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



int MaximumRunsScored(pair<int,int>player_data[],int n,int balls){ 
  // 0-1 Knapsack varient max_runs[i][j] denotes maximum runs scored by i players wheh we have exactly j balls to play
  int max_runs[n+1][balls+1];
  for(int i=0;i<=balls;i++) max_runs[0][i] =0;
  for(int i =0;i<=n;i++) max_runs[i][0] = 0; 
  for(int player = 1;player<=n;player++){
    for(int ball =1;ball<=balls;ball++){
      int plays_balls = player_data[player-1].first;
      int runs_scored = player_data[player-1].second;
      if(ball>=plays_balls){
        max_runs[player][ball] = max(max_runs[player-1][ball],runs_scored+max_runs[player-1][ball-plays_balls]);
      }else{
        max_runs[player][ball] = max_runs[player-1][ball];
      }
    }
  }
  return max_runs[n][balls];
}


int UnBoundedKnapSack(pair<int,int> costs[],int n,int max_weight){
  vector<int>MaximumCost(max_weight+1,0);
  MaximumCost[0] = 0;
  for(int curr_weight = 1;curr_weight<=max_weight;curr_weight++){
    for(int item =0;item<n;item++){
      if(curr_weight>=costs[item].first) MaximumCost[curr_weight] = max(MaximumCost[curr_weight],costs[item].second+MaximumCost[curr_weight-costs[item].first]);
    }
  }
  for(int wt =0;wt<=max_weight;wt++) cout<<MaximumCost[wt]<<' ';
  return MaximumCost[max_weight];
}

int NumberOfBinaryStringsWithNoConsecutiveZeros(int n){
  vector<pair<int,int>>ValidCount(n+1,{0,0});
  ValidCount[1].first = ValidCount[1].second = 1;
  for(int i=2;i<=n;i++){
     ValidCount[i].first = ValidCount[i-1].second;
     ValidCount[i].second = ValidCount[i-1].first+ValidCount[i-1].second;
  }
  for(int i =0;i<=n;i++) cout<<ValidCount[i].first<<" "<<ValidCount[i].second<<endl;
}

int main(){
  FastIO;
  int n;
  cin>>n;
  NumberOfBinaryStringsWithNoConsecutiveZeros(n);
  return 0;
} 
