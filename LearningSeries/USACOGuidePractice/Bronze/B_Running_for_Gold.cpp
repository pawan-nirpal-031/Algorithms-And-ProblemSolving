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

The Olympic Games have just started and Federico is eager to watch the marathon race.

There will be n athletes, numbered from 1 to n, competing in the marathon, and all of them have taken part in 5 important marathons, numbered from 1 to 5, in the past. For each 1≤i≤n and 1≤j≤5, Federico remembers that athlete i ranked ri,j-th in marathon j (e.g., r2,4=3 means that athlete 2 was third in marathon 4).

Federico considers athlete x superior to athlete y if athlete x ranked better than athlete y in at least 3 past marathons, i.e., rx,j<ry,j for at least 3 distinct values of j.

Federico believes that an athlete is likely to get the gold medal at the Olympics if he is superior to all other athletes.

Find any athlete who is likely to get the gold medal (that is, an athlete who is superior to all other athletes), or determine that there is no such athlete.

Input
The first line contains a single integer t (1≤t≤1000) — the number of test cases. Then t test cases follow.

The first line of each test case contains a single integer n (1≤n≤50000) — the number of athletes.

Then n lines follow, each describing the ranking positions of one athlete.

The i-th of these lines contains the 5 integers ri,1,ri,2,ri,3,ri,4,ri,5 (1≤ri,j≤50000) — the ranking positions of athlete i in the past 5 marathons. It is guaranteed that, in each of the 5 past marathons, the n athletes have distinct ranking positions, i.e., for each 1≤j≤5, the n values r1,j,r2,j,…,rn,j are distinct.

It is guaranteed that the sum of n over all test cases does not exceed 50000.

Output
For each test case, print a single integer — the number of an athlete who is likely to get the gold medal (that is, an athlete who is superior to all other athletes). If there are no such athletes, print −1. If there is more than such one athlete, print any of them.

*/


/*
Author's solution : 



*/

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      int n;
      cin>>n;
      vector<vector<int>>ranks(n,vector<int>(5,0));
      vector<int>win_scores(5,INT_MAX);
      int winner = -1;
      for(int i =0;i<n;i++) for(int j =0;j<5;j++) cin>>ranks[i][j]; 
      for(int i =0;i<n;i++){
         if(i==0){
             for(int j =0;j<5;j++) win_scores[j] = ranks[i][j];
         }else{
             int c =0;
             for(int j =0;j<5;j++){
                if(ranks[i][j]<win_scores[j]) c+=1;
             }
             if(c>=3){
                for(int j =0;j<5;j++){
                    winner = i;
                    win_scores[j] = ranks[i][j];
                }
             }
         }
      }
      for(int j =0;j<5;j++) cout<<win_scores[j]<<' ';
      cout<<'\n';
    //   int c =0;
    //   for(int i =0;i<n;i++){
    //       int nf =0;    
    //       for(int j =0;j<5;j++) {
    //           if(ranks[i][j]<win_scores[j]) nf+=1;
    //       }
    //       if(nf>=3) c+=1;
    //   }  
      //cout<<(winner>-1 and c==n-1?winner+1:-1)<<'\n';   
  }
  return 0;
} 
// If Solved Mark (0/1) here => []