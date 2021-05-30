// Problem Link : https://www.hackerrank.com/challenges/journey-to-the-moon/problem
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

The member states of the UN are planning to send  people to the moon. They want them to be from different countries. You will be given a list of pairs of astronaut ID's. Each pair is made of astronauts from the same country. Determine how many pairs of astronauts from different countries they can choose from.

Example



There are  astronauts numbered  through . Astronauts grouped by country are  and . There are  pairs to choose from:  and .



The question demands the concept of using disjoint sets. (find and union with rank and path compression).

However, this method below using DFS also works (which I think i pretty similar to the editorial) :

We need to find the distinct sets (i.e. if x and y are from same country, they belong to same set) to get the answer. Let's say set A has a elements,set B has b elements.

Answer = a x b. [Because actual formula is to select one from set A and another one from set B = aC1 x bC1 = a x b]

Similarly, let's calculate answer for 4 sets - A,B,C,D with a,b,c,d elements respectively.

Lets say somehow I find set A has a elements.

Answer = 0 (Since I don't have another country to pair with)

Now, I find set B with b elements.

Answer = axb; .................................................(1)

Then, I find set C with c elements.

Answer = (axb) + (axc) + (bxc) [because we can select a pair from A and B, or A and C or B and C]

But this can be written as

Answer = (axb) + (a+b)xc ......................................(2)

Now I find set D with d elements, and I've examined all people.

Answer = (axb) + (axc) + (axd) + (bxc) + (bxd) + (cxd)

Or

Answer = (axb) x (a+b)xc + (a+b+c)xd ..........................(3)

Do you see the pattern? That means when we find a new set, the new answer is the old answer + the sum of old values x new value.

*/

int Nof_nodes = 0;

void dfs(vector<int>g[],int u,vector<bool>&vis){
    vis[u] = 1;
    Nof_nodes+=1;
    for(int v : g[u]) if(not vis[v]) dfs(g,v,vis);
}

int main(){
  FastIO;
  int n,m;
  cin>>n>>m;
  vector<int>g[n];
  for(int i =0;i<m;i++){
      int x,y;
      cin>>x>>y;
      g[x].push_back(y);
      g[y].push_back(x);
  }
  vector<bool>vis(n,0);
  ll ans = 0;
  ll nodes_sum = 0;
  for(int i =0;i<n;i++){
      if(not vis[i]){
          Nof_nodes = 0;
          dfs(g,i,vis);
          ans = ans + nodes_sum*Nof_nodes;
          nodes_sum+=Nof_nodes;
      }
  }
  cout<<ans;
  return 0;
} 
// If Solved Mark (0/1) here => []