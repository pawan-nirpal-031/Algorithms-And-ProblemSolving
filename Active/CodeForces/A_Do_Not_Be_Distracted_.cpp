// Problem Link : https://codeforces.com/contest/1520/problem/A
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

Polycarp has 26 tasks. Each task is designated by a capital letter of the Latin alphabet.

The teacher asked Polycarp to solve tasks in the following way: if Polycarp began to solve some task, then he must solve it to the end, without being distracted by another task. After switching to another task, Polycarp cannot return to the previous task.

Polycarp can only solve one task during the day. Every day he wrote down what task he solved. Now the teacher wants to know if Polycarp followed his advice.

For example, if Polycarp solved tasks in the following order: "DDBBCCCBBEZ", then the teacher will see that on the third day Polycarp began to solve the task 'B', then on the fifth day he got distracted and began to solve the task 'C', on the eighth day Polycarp returned to the task 'B'. Other examples of when the teacher is suspicious: "BAB", "AABBCCDDEEBZZ" and "AAAAZAAAAA".

If Polycarp solved the tasks as follows: "FFGZZZY", then the teacher cannot have any suspicions. Please note that Polycarp is not obligated to solve all tasks. Other examples of when the teacher doesn't have any suspicious: "BA", "AFFFCC" and "YYYYY".

Help Polycarp find out if his teacher might be suspicious.

*/

void Solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>start(26,-1),end(26,-1);
    for(int i =0;i<n;i++){
      char c = s[i];
      if(start[c-'A']==-1) start[c-'A'] = i;
      end[c-'A'] = i;
    }
    for(int i =0;i<26;i++){
      if(start[i]==-1) continue;
      for(int j = 0;j<26;j++){
        if(start[j]==-1) continue;
        if(j!=i){
          if(start[i]<start[j] and start[j]<end[i]){
            Status(0);
            return;
          }
        }
      }
    }
    Status(1);
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) Solve();
  return 0;
} 
// If Solved Mark (0/1) here => []