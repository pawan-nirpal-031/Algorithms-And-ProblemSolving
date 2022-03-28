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
  // MaximumCost[i] deontes what is maximum cost be generated with weight as i, we can use diffrent ways of getting to i weight and those costs can be used again so since we can use a same weight again this problem is similar to Coincombinations.
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

int BuyAndSellStockSingleTransaction(int stocks[],int n){
  // what will be the max_profit if I sell today so I must buy minimum somewhere early.
  int max_profit =INT_MIN;
  int min_prefix = stocks[0];
  for(int i=0;i<n;i++){
    max_profit = max(max_profit,(stocks[i]-min_prefix));
    min_prefix = min(min_prefix,stocks[i]);
  }
  return max_profit;
}

int BuyAndSellStockInfinteTransactions(int stocks[],int n){
  int max_profit = 0;
  int buy_date = 0;
  int sell_date =0;
  for(int i =1;i<n;i++){
    if(stocks[i]>=stocks[i-1]) sell_date++;
    else{
      max_profit+=(stocks[sell_date]-stocks[buy_date]);
      buy_date = sell_date = i;
    }
  }
  max_profit+=(stocks[sell_date]-stocks[buy_date]);
  return max_profit;
}


int BuyAndSellStockInfinteTransactionsWithFees(int stocks[],int n,int fees){
  int BuySellStates[n][2];
  BuySellStates[0][0] = stocks[0];
  BuySellStates[0][1] = 0;
  for(int i=1;i<n;i++){
    BuySellStates[i][0] = max(BuySellStates[i-1][0],BuySellStates[i-1][1]-stocks[i]);
    BuySellStates[i][1] = max(BuySellStates[i-1][1],stocks[i]+BuySellStates[i-1][0]-fees);
  }
  for(int i=0;i<n;i++){
    cout<<BuySellStates[i][0]<<' '<<BuySellStates[i][1]<<endl;
  }
  return BuySellStates[n-1][1];
}



int NumberOfBinaryStringsWithNoConsecutiveZeros(int n){ // do space optimization we don't need ValidCount array do it in O(1);
  vector<pair<int,int>>ValidCount(n+1,{0,0});
  ValidCount[1].first = ValidCount[1].second = 1;
  for(int i=2;i<=n;i++){
     ValidCount[i].first = ValidCount[i-1].second;
     ValidCount[i].second = ValidCount[i-1].first+ValidCount[i-1].second;
  }
  return ValidCount[n].first+ValidCount[n].second;
}



int DecodeWays(string s){
  int n = s.length();
  vector<int>NumberOfWaysToDecode(n,0);
  NumberOfWaysToDecode[0] = (s[0]=='0'?0:1);
  for(int i =1;i<n;i++){
    if(s[i-1]=='0' and s[i]=='0'){
      NumberOfWaysToDecode[i] =0;
    }else if(s[i-1]!='0' and s[i]=='0'){
      if(s[i-1]=='1' or s[i-1]=='2'){ 
        NumberOfWaysToDecode[i] = (i>=2?NumberOfWaysToDecode[i-2]:1);
      }else NumberOfWaysToDecode[i] =0;
    }else if(s[i-1]=='0' and s[i]!='0'){
      NumberOfWaysToDecode[i] = NumberOfWaysToDecode[i-1];
    }else{
      NumberOfWaysToDecode[i] = NumberOfWaysToDecode[i-1];
      if(stoi(s.substr(i-1,2))<=26){
        NumberOfWaysToDecode[i] += (i>=2?NumberOfWaysToDecode[i-2]:1);
      }
    }
  }
  return NumberOfWaysToDecode[n-1];
}


int MaximumSizeOfZerosSquare(vector<vector<int>>&g){
  int n = g.size();
  int m = g[0].size();
  vector<vector<int>>MaximumSquareStartingAt(n,vector<int>(m,0));
  bool allzeros =0;
  for(int i =0;i<n;i++){
    for(int j =0;j<m;j++){
      if(g[i][j]==0) continue;
      if(i==n-1 or j ==m-1) g[i][j] = 1;
      allzeros =1;
    }
  }
  if(allzeros==0) return 0;
  int ans =1;
  for(int i =0;i<m;i++) MaximumSquareStartingAt[n-1][i] = g[n-1][i];
  for(int i =0;i<n;i++) MaximumSquareStartingAt[i][m-1] = g[i][m-1];
  for(int i =n-2;i>=0;i--){
    for(int j =m-2;j>=0;j--){
      if(g[i][j]==0) continue;
      MaximumSquareStartingAt[i][j] = min(MaximumSquareStartingAt[i+1][j],min(MaximumSquareStartingAt[i+1][j+1],MaximumSquareStartingAt[i][j+1]))+1;
      ans = max(ans,MaximumSquareStartingAt[i][j]);
    }
  }
  return ans;
}

int LongestCommonSubsequnece(string s1,string s2){
  int n = s1.length();
  int m = s2.length();
  int dp[n+1][m+1];
  for(int i=0;i<=n;i++){
    for(int j =0;j<=m;j++) dp[i][j] =0;
  }

  for(int i = n-1;i>=0;i--){
    for(int j = m-1;j>=0;j--){
      char c1 = s1[i];
      char c2 = s2[j];
      if(c1==c2) dp[i][j] = 1 + dp[i+1][j+1];
      else{
        dp[i][j] = max(dp[i][j+1],dp[i+1][j]);
      }
    }
  }
  return dp[0][0];
}


int MinCostHousePaint(vector<vector<int>>&cost){
  int n = cost.size();
  if(n==0) return 0;
  vector<vector<int>>MinCostToPaintThisHouse(n,vector<int>(3,0));
  MinCostToPaintThisHouse[0][0] = cost[0][0];
  MinCostToPaintThisHouse[0][1] = cost[0][1];
  MinCostToPaintThisHouse[0][2] = cost[0][2];
  for(int i=1;i<n;i++){
    MinCostToPaintThisHouse[i][0] =cost[i][0]+min(MinCostToPaintThisHouse[i-1][1],MinCostToPaintThisHouse[i-1][2]);
    MinCostToPaintThisHouse[i][1] =cost[i][1]+min(MinCostToPaintThisHouse[i-1][0],MinCostToPaintThisHouse[i-1][2]);
    MinCostToPaintThisHouse[i][2] =cost[i][2]+min(MinCostToPaintThisHouse[i-1][0],MinCostToPaintThisHouse[i-1][1]);
  }
  return min(MinCostToPaintThisHouse[n-1][0],min(MinCostToPaintThisHouse[n-1][1],MinCostToPaintThisHouse[n-1][2]));
}



int MinJumps(vector<int>&cost,int n){
  vector<pair<int,int>>min_jumps_to_dest(n,{2*n,n+1});
  min_jumps_to_dest[n-1].first=0;
  min_jumps_to_dest[n-1].second = -1;
  for(int i = n-2;i>=0;i--){
    if(cost[i]==0) continue;
    int min_jump = 2*n;
    int indx = -1;
    for(int j =1;j<=cost[i];j++){
      if(i+j>=n) continue;
      if(min_jumps_to_dest[i+j].first<min_jump){
        min_jump = min_jumps_to_dest[i+j].first;
        indx = i+j;
      }
      if(indx>0){
        min_jumps_to_dest[i].first = min_jump+1;
        min_jumps_to_dest[i].second = indx;
      }
    }
  }
  int curr = 0;
  vector<int>path;
  while(min_jumps_to_dest[curr].first!=0){
    if(min_jumps_to_dest[curr].first==2*n) break;
    path.push_back(curr);
    curr = min_jumps_to_dest[curr].second;
  }
  for(int v : path) cout<<v<<' ';
  return min_jumps_to_dest[0].first;
}


void PrintAllMinimumCostPaths(const vector<vector<int>>&cost,int n){
   vector<vector<int>>MinCostToDest(n,vector<int>(n,0)); 
   // MinCostToDest[i][j] denotes min cost to reach dest from (i,j)
   MinCostToDest[n-1][n-1] = cost[n-1][n-1];
   for(int i = n-2;i>=0;i--) MinCostToDest[n-1][i] = cost[n-1][i]+MinCostToDest[n-1][i+1];
   for(int i = n-2;i>=0;i--) MinCostToDest[i][n-1] = cost[i][n-1]+MinCostToDest[i+1][n-1];
    for(int i = n-2;i>=0;i--){
      for(int j =n-2;j>=0;j--) MinCostToDest[i][j] = cost[i][j]+min(MinCostToDest[i+1][j],MinCostToDest[i][j+1]);
    }
    queue<pair<string,pair<int,int>>>process;
    process.push({"",{0,0}});
    while(not process.empty()){
      auto tuple = process.front();
      int i = tuple.second.first;
      int j = tuple.second.second;
      string sofar = tuple.first;
      process.pop();
      if(i==n-1 and j==n-1){
        cout<<sofar<<endl;
      }else if(i==n-1 and  j<n-1){
        process.push({sofar+'R',{i,j+1}});
      }else if(i<n-1 and j==n-1){
        process.push({sofar+'D',{i+1,j}});
      }else{
        if(MinCostToDest[i+1][j]<MinCostToDest[i][j+1]) process.push({sofar+'D',{i+1,j}});
        else if(MinCostToDest[i][j+1]<MinCostToDest[i+1][j]) process.push({sofar+'R',{i,j+1}});
        else{
          process.push({sofar+'D',{i+1,j}});
          process.push({sofar+'R',{i,j+1}});
        }
      }
    }
}


void PrintAllMaxGoldPaths(const vector<vector<int>>&gold,int n){
  vector<vector<int>>MaxGoldToDest(n,vector<int>(n,0));
  for(int i =0;i<n;i++) MaxGoldToDest[i][n-1] = gold[i][n-1];
  int max_gold = 0;
  for(int col = n-2;col>=0;col--){
    for(int row = 0;row<n;row++){
      MaxGoldToDest[row][col] = gold[row][col];
      int max_content = MaxGoldToDest[row][col+1];
      if(row-1>=0) max_content = max(max_content,MaxGoldToDest[row-1][col+1]);
      if(row+1<n) max_content = max(max_content,MaxGoldToDest[row+1][col+1]);
      MaxGoldToDest[row][col]+=max_content;
      if(col==0) max_gold = max(max_gold,MaxGoldToDest[row][0]);
    }
  }
  queue<pair<string,pair<int,int>>>process;
  for(int i =0;i<n;i++) if(MaxGoldToDest[i][0]==max_gold) process.push({"",{i,0}});
  while(process.size()){
    auto tuple = process.front();
    process.pop();
    string path_so_far = tuple.first;
    int i = tuple.second.first;
    int j = tuple.second.second;
    if(j==n-1){
      cout<<path_so_far<<endl;
      
    }else{
      int max_next = MaxGoldToDest[i][j+1];
      if(i-1>=0) max_next = max(max_next,MaxGoldToDest[i-1][j+1]);
      if(i+1<n) max_next = max(max_next,MaxGoldToDest[i+1][j+1]);
      if(i-1>=0 and MaxGoldToDest[i-1][j+1]==max_next) process.push({path_so_far+'U',{i-1,j+1}});
      if(i+1<n and MaxGoldToDest[i+1][j+1]==max_next) process.push({path_so_far+'D',{i+1,j+1}});
      if(MaxGoldToDest[i][j+1]==max_next) process.push({path_so_far+'F',{i,j+1}});
    }
  }
}





void PrintAllTargetSumSubsets(const vector<int>&runscored,int n,int target){
  /*
    Scored[members][can_score] means Is it possible that 'members' number of people can score 'can_score' number of runs 
    a batsman is either able to score or he is unable beacuse of score must be large enough for youu to be able to bat, if he is able to score we see if should or should not bat we check both options and see if his batting can make runs or it is not necessacry for him to bat
  */
  vector<vector<int>> Scored(n+1,vector<int>(target+1,0)); 
  for(int i = 1;i<=target;i++) Scored[0][i] =0;
  for(int i = 0;i<=n;i++) Scored[i][0] = 1;
  for(int members =  1;members<=n;members++){
    for(int can_score = 1;can_score<=target;can_score++){
      if(can_score>=runscored[members-1]){
        Scored[members][can_score] = (Scored[members-1][can_score-runscored[members-1]]) or (Scored[members-1][can_score]);
      }else Scored[members][can_score] = Scored[members-1][can_score];
    }
  }
  queue<pair<string,pair<int,int>>>process;
  process.push({"",{n,target}});
  while(process.size()){
    auto tuple = process.front();
    string path_so_far = tuple.first;
    int people = tuple.second.first;
    int scores = tuple.second.second;
    process.pop();
    if(people==0 and scores==0){
      cout<<path_so_far<<'\n';
    }else{
      bool exc = Scored[people-1][scores];
      bool inc = 0;
      if(scores>=runscored[people-1]) inc = Scored[people-1][scores-runscored[people-1]];
      if(exc) process.push({path_so_far,{people-1,scores}});
      if(inc) process.push({path_so_far+to_string(runscored[people-1])+" ",{people-1,scores-runscored[people-1]}});
    } 
  }
}



int LongestBitoncSubsequence(const vector<int>&a,int n){
  /*
    the idea is simple we find the max LIS+LDS at any i
    longestIncreasingSubsequnce[i] denotes the longest increasing subsequnce that ends at i or includes ith value
    longestDecreasingSubsequnce[i] denotes the longest decreasing subsequnce in suffix starting at i 
  */
  vector<int>longestIncreasingSubsequnce(n,0); 
  for(int i =0;i<n;i++){
    longestIncreasingSubsequnce[i] = 1;
    int max_prefix = 0;
    for(int j =0;j<i;j++) if(a[i]>a[j]) max_prefix = max(max_prefix,longestIncreasingSubsequnce[j]);
    longestIncreasingSubsequnce[i]+=max_prefix;
  }
  vector<int>longestDecreasingSubsequnce(n,0); 
  for(int i = n-1;i>=0;i--){
    longestDecreasingSubsequnce[i] = 1;
    int max_suffix = 0;
    for(int j = i+1;j<n;j++) if(a[i]>a[j]) max_suffix = max(max_suffix,longestDecreasingSubsequnce[j]);
    longestDecreasingSubsequnce[i]+=max_suffix;
  }
  int longest_bitonic_len =0;
  for(int i =0;i<n;i++) longest_bitonic_len = max(longest_bitonic_len,longestIncreasingSubsequnce[i]+longestDecreasingSubsequnce[i]-1);
  return longest_bitonic_len;
}


int PerfectSquares(int n){
  // Count[i] denotes minimum number of perfect sqaures that sum to i 
  vector<int>Count(n+1,0);
  Count[0] =0;
  for(int i =1;i<=n;i++){
    int min_reach = INT_MAX;
    for(int j = 1;j*j<=i;j++) min_reach = min(min_reach,Count[i-j*j]);
    Count[i] = 1+min_reach;
  }
  return Count[n];
}

int CatalanNumber(int n){
  vector<ll>catlan(n+1,0);
  catlan[0] = catlan[1] = 1;
  for(int i = 2;i<=n;i++){
    for(int j = 0;j<i;j++) catlan[i]+=catlan[j]*catlan[i-1-j];
  }
  for(int i =0;i<=n;i++) cout<<catlan[i]<<' ';
  return catlan[n];
}

int LongestCommonSubstring(string a,string b){
  int n = a.length();
  int m = b.length();
  vector<vector<int>>longest_common_suffix(n+1,vector<int>(m+1,0));
  // longest_common_suffix[i][j] stores length of longest common suffix of substring upto i of a and substring upto j of b.
  for(int i =0;i<=m;i++) longest_common_suffix[0][i] = 0;
  for(int i =0;i<=n;i++) longest_common_suffix[i][0] = 0;
  int ans =0;
  for(int i = 1;i<=n;i++){
    for(int j =1;j<=m;j++){
      longest_common_suffix[i][j] = (a[i]==b[j])+longest_common_suffix[i-1][j-1];
      ans = max(ans,longest_common_suffix[i][j]);
    }
  }
  return ans;
} 

int MinimumNumberOfOpreationsToMakeStringsEqual(string a,string b,int i,int j){ // Edit distance
    int n = a.length();
    int m = b.length();
    vector<vector<int>>min_ops_to_convert(n+1,vector<int>(m+1,0));
    // min_ops_to_convert[i][j] stores min number of ops to convert string substring [0,i-1] to the substring [0,j-1] 
    for(int i =0;i<=m;i++) min_ops_to_convert[0][i] = i;
    for(int i =0;i<=n;i++) min_ops_to_convert[i][0] = i;
    for(int i =1;i<=n;i++){
      for(int j =1;j<=m;j++){
        if(a[i-1]==b[j-1]) min_ops_to_convert[i][j] = min_ops_to_convert[i-1][j-1];
        else{
          min_ops_to_convert[i][j] = 1+min(min_ops_to_convert[i-1][j-1],min(min_ops_to_convert[i-1][j],min_ops_to_convert[i][j-1]));
        }
      }
    }
    return min_ops_to_convert[n][m];
}



int main(){
  FastIO;
  string a,b; 
  cin>>a>>b; 
  cout<<MinimumNumberOfOpreationsToMakeStringsEqual(a,b,0,0);
  return 0;
} 
