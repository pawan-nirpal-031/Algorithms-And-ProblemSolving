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


int SumOfFirstN(int n){
  return (n==0?0:n+SumOfFirstN(n-1));
}

ll Factorial(int n){
  return (n==0?1:n*Factorial(n-1));
}

void Reverse(int a[],int l,int r){
   if(l<r){
       swap(a[l],a[r]);
       Reverse(a,++l,--r);
   }
}


bool IsPalindrome(string s,int i,int n){
    if(i<(n/2))  return (s[i]==s[n-(i+1)] and IsPalindrome(s,++i,n));
    return 1;
}

ll Fibonacci(int n){
    return ((n==0 or n==1)?n:Fibonacci(n-1)+Fibonacci(n-2));
}


void PrintSubsequences(int a[],int i,int n,vector<int>list){
    if(i>=n){
        for(int x : list) cout<<x<<' ';
        cout<<'\n';
        return;
    }
    list.push_back(a[i]);
    PrintSubsequences(a,i+1,n,list);
    list.pop_back();
    PrintSubsequences(a,i+1,n,list);
}


void SubsequncesWithSumK(int a[],int i,int n,vector<int>list,int k,int curr_sum){
  if(i>=n){
    int s =0;
    for(int x : list) s+=x;
    if(s!=k) return;
    for(int x : list) cout<<x<<' ';
    cout<<'\n';
    return;
  }
  list.push_back(a[i]);
  curr_sum+=a[i];
  SubsequncesWithSumK(a,i+1,n,list,k,curr_sum);
  list.pop_back();
  curr_sum-=a[i];
  SubsequncesWithSumK(a,i+1,n,list,k,curr_sum);
}

bool SubsequncesWithSumKOnlyOne(int a[],int i,int n,int k,int curr_sum){
  if(i>=n) return k==curr_sum;
  return SubsequncesWithSumKOnlyOne(a,i+1,n,k,curr_sum+a[i]) or SubsequncesWithSumKOnlyOne(a,i+1,n,k,curr_sum);
}

int NumberOfSubsequncesWithSumK(int a[],int i,int n,int k,int curr_sum){
  return (i==n?(k==curr_sum):NumberOfSubsequncesWithSumK(a,i+1,n,k,curr_sum+a[i]) + NumberOfSubsequncesWithSumK(a,i+1,n,k,curr_sum));
}



int main(){
  FastIO;
  int n,k;
  cin>>n>>k;
  int a[n];
  for(int &x : a) cin>>x;
  cout<<NumberOfSubsequncesWithSumK(a,0,n,k,0);
  return 0;
} 
