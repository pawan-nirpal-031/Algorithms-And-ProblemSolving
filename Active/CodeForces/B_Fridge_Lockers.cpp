// Problem Link : https://codeforces.com/problemset/problem/1255/B
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
Problem Statement : Hanh lives in a shared apartment. There are n people (including Hanh) living there, each has a private fridge.

n fridges are secured by several steel chains. Each steel chain connects two different fridges and is protected by a digital lock. The owner of a fridge knows passcodes of all chains connected to it. A fridge can be open only if all chains connected to it are unlocked. For example, if a fridge has no chains connected to it at all, then any of n people can open it For exampe, in the picture there are n=4 people and 5 chains. The first person knows passcodes of two chains: 1−4 and 1−2. The fridge 1 can be open by its owner (the person 1), also two people 2 and 4 (acting together) can open it.
The weights of these fridges are a1,a2,…,an. To make a steel chain connecting fridges u and v, you have to pay au+av dollars. Note that the landlord allows you to create multiple chains connecting the same pair of fridges.

Hanh's apartment landlord asks you to create exactly m steel chains so that all fridges are private. A fridge is private if and only if, among n people living in the apartment, only the owner can open it (i.e. no other person acting alone can do it). In other words, the fridge i is not private if there exists the person j (i≠j) that the person j can open the fridge i.

For example, in the picture all the fridges are private. On the other hand, if there are n=2 fridges and only one chain (which connects them) then both fridges are not private (both fridges can be open not only by its owner but also by another person).

Of course, the landlord wants to minimize the total cost of all steel chains to fulfill his request. Determine whether there exists any way to make exactly m chains, and if yes, output any solution that minimizes the total cost.

*/

/*
 Given a graph with n vertexes, each vertex has a value ai≥0. We have to add m edges to the graph such that each vertex is connected to at least two different vertexes and the total cost of edges added is minimum. The cost of an edge is the sum of value of its two end-points.

Observe some basic properties of graph
Now, each edge added will increase the sum of degree of all vertexes by 2. So adding m edges will make the sum of degree equal to 2×m. Since each vertexes must be connected to at least 2 other vertexes, the minimum sum of degree is 2×n.

Case 1: 2×m<2×n⇔m<n
In this case, it is obvious that the answer is −1.

Case 2: 2×m=2×n⇔m=n
In this case, it is easy to see that the degree of each vertex will be exactly 2. As a result, no matter what edges we add, the result is still 2×(a1+a2+...+an). But please take note that if n=2, then the answer will be −1 since for each vertex we have at most 1 different vertex to connect to.

Case 3(Of the original, pre-modified version of the problem): 2×m>2×n⇔m>n

Remarks : Overthinking or not thinking clearly in this problem it was so simple.

*/



void SolveCase(){
    int n,m;
    cin>>n>>m;
    int w[n];
    int s =0;
    for(int i=0;i<n;i++){
        cin>>w[i];
        s+=w[i];
    }
    if(n==2 or m<n){
        cout<<"-1\n";
        return;
    }
    cout<<2*s<<'\n';
    int u = 1,v = 2;
    for(int i =0;i<n-1;i++){
        cout<<u<<' '<<v<<'\n';
        u+=1;
        v+=1;
    }
    cout<<n<<' '<<1<<'\n';
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) SolveCase();
  return 0;
} 
// If Solved Mark (0/1) here => [1]