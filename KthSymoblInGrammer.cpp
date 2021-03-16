#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define pub(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define getl(s) getline(cin,s);

/*
    Problem is solely based on observational skills
*/

bool solve(int n,int k){
    if(n==1&&k==1){
        return 0;
    }else{
        int mid = (1<<(n-2));
        if(k<=mid){
            return solve(n-1,k);
        }else{
            return !(solve(n-1,k-mid));
        }
    }
}


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k;
  cin>>n>>k;
  cout<<solve(n,k);
  return 0;
}
