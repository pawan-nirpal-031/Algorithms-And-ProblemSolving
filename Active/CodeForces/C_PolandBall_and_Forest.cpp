// Problem Link : https://codeforces.com/problemset/problem/755/C
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

PolandBall lives in a forest with his family. There are some trees in the forest. Trees are undirected acyclic graphs with k vertices and k - 1 edges, where k is some integer. Note that one vertex is a valid tree.

There is exactly one relative living in each vertex of each tree, they have unique ids from 1 to n. For each Ball i we know the id of its most distant relative living on the same tree. If there are several such vertices, we only know the value of the one with smallest id among those.

How many trees are there in the forest?

Input
The first line contains single integer n (1 ≤ n ≤ 104) — the number of Balls living in the forest.

The second line contains a sequence p1, p2, ..., pn of length n, where (1 ≤ pi ≤ n) holds and pi denotes the most distant from Ball i relative living on the same tree. If there are several most distant relatives living on the same tree, pi is the id of one with the smallest id.

It's guaranteed that the sequence p corresponds to some valid forest.

Hacking: To hack someone, you should provide a correct forest as a test. The sequence p will be calculated according to the forest and given to the solution you try to hack as input. Use the following format:

In the first line, output the integer n (1 ≤ n ≤ 104) — the number of Balls and the integer m (0 ≤ m < n) — the total number of edges in the forest. Then m lines should follow. The i-th of them should contain two integers ai and bi and represent an edge between vertices in which relatives ai and bi live. For example, the first sample is written as follows:


5 3
1 2
3 4
4 5
Output
You should output the number of trees in the forest where PolandBall lives.

Interaction
From the technical side, this problem is interactive. However, it should not affect you (except hacking) since there is no interaction.

*/


/*
Author's solution : 



*/

int main(){
  FastIO;
  int n;
  cin>>n;
  int g[n+1];
  for(int i = 1;i<=n;i++) cin>>g[i];
  vector<bool>vis(n+1,0);
  int ans = 0;
  for(int i =1;i<=n;i++){
      if(i==g[g[i]] and ((not vis[i]) and (not vis[g[i]]))){ 
          vis[i] = vis[g[i]] = 1;
          ans+=1;
      }
  }
  /*
    logic is fairly simple, in a tree most distant reletives will be always ends of daimeter 
    ie. if most distant rel of 2 is say 5 and most dist rel of 5 is 2 then they will lie in same 
    component and so i = g[g[i]] will give us pair (i, g[i]) ends of daimeter of some tree in a forrest 
    to ensure count does not incr on (g[i],i) we use visited list, so now the problem comes down to just counting the number of these pairs, it will give us the no of trees in a forrest.
  */
  cout<<ans;
  return 0;
} 
// If Solved Mark (0/1) here => [1]