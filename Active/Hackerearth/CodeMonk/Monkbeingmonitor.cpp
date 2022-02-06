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

Monk being monitor
Monk being the monitor of the class needs to have all the information about the class students. He is very busy with many tasks related to the same, so he asked his friend Mishki for her help in one task. She will be given heights of all the students present in the class and she needs to choose 2 students having heights  and  respectively, such that  and difference between the number of students having height  and number of students having height  is maximum.

Note: The difference should be greater than 0.

Video approach to solve this question: here

As Mishki has never been a monitor of the class, help her in the same. If there exists such students, then print the required difference else print "1" (without quotes).

Input:
The first line will consists of one integer T, which denotes the number of test cases.
For each test case:
One line consists of a integer N, denotes the number of students in the class.
Second line contains N space separated integers, where  integer denotes the height of the  student in the class.

Output:

For each test case, if the required difference exists then print its value, otherwise print 1. Print the answer for each test case in a new line.

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
      int MAX_N = 1000006;
      vector<ll>freq(MAX_N,0);
      int minh = MAX_N;
      int maxh = 0;
      for(int i =0;i<n;i++){
        int h;
        cin>>h;
        freq[h]++;
        minh = min(minh,h);
        maxh = max(maxh,h);
      }
      vector<ll>suff(MAX_N,0);
      suff[maxh] = freq[maxh];
      for(int i = maxh-1;i>=minh;i--) suff[i] = max(suff[i+1],freq[i]);
      ll diff = -MAX_N;
      ll mn = freq[minh];
      for(int i = minh;i<maxh-1;i++){
        if(freq[i]==0) continue;
        mn = min(mn,freq[i]);
        diff = max(diff,suff[i+1]-mn);
      }
      cout<<((diff<0)?-1:diff)<<"\n";
  }
  return 0;
} 
// If Solved Mark (0/1) here => [1]