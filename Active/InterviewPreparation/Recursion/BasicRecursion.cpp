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




void PrintNameNtimes(int n,string name){
  if(n--){
    cout<<name<<"\n";
    PrintNameNtimes(n,name);
  }
}


void Reverse(int a[],int i,int n){
   if(i<n){
       Reverse(a,i+1,n);
       cout<<a[i]<<' ';
   }
}


void PrintBinary(int n){
  if(n==0) cout<<0;
  if(n>0){
    PrintBinary(n>>1);
    cout<<n%2;
  }
}


bool LinearSearch(int a[],int i,int n,int x){
  if(i<n){
    if(a[i]==x) return 1;
    return LinearSearch(a,i+1,n,x);
  }
  return 0;
}



bool BinarySearch(int a[],int l,int r,int n,int x){
  if(l+1<r){  
    int m = (l+r)/2;
    if(a[m]==x) return 1;
    return (x<a[m]?BinarySearch(a,l,m,n,x):BinarySearch(a,m,r,n,x));
  }else return (a[l]==x or a[r]==x);
}


void PrintToN(int n){
  if(n>0){
    cout<<n<<'\n';
    PrintToN(--n);
  }
}

int sum =0;
void SumOfFirstN(int i,int n){
  if(i>n) return;
  sum+=i;
  SumOfFirstN(i+1,n);
}

int SumOfFirstNFunctional(int n){
  return (n==0?0:n+SumOfFirstNFunctional(n-1));
}

ll Factorial(int n){
  return (n==0?1:n*Factorial(n-1));
}

int main(){
  FastIO;

  return 0;
} 
