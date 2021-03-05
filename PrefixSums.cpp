#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod  200003//1000000007
#define pub(a) push_back(a)
#define mp(a,b) make_pair(a,b)

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll n,q;
   cin>>n>>q;
   ll a[n];
   ll b[n];
   for(ll i=0;i<n;i++){
      cin>>a[i];
   }
   for(ll i=0;i<n;i++){
      cin>>b[i];
   }
   for(ll i=0;i<n;i++){
      if(i%2==1){
         swap(a[i],b[i]);
      }
   }
   ll prfxa[n+1];
   prfxa[0]=0;
   prfxa[1]= a[0];
   for(ll i=2;i<=n;i++){
      prfxa[i] = prfxa[i-1]+a[i-1];
   }

   ll prfxb[n+1];
   prfxb[0] =0;
   prfxb[1] = b[0];
   for(ll i=0;i<=n;i++){
      prfxb[i] = prfxb[i-1]+b[i-1];
   }
   while(q--){
      ll ty,l,r;
      cin>>ty>>l>>r;
      if(ty==1){
         if(l%2){
            cout<<prfxa[r]-prfxa[l-1]<<'\n';
         }else{
            cout<<prfxb[r] - prfxb[l-1]<<'\n';
         }
      }else{
         if(l%2==0){
             cout<<prfxa[r]-prfxa[l-1]<<'\n';
         }else{
            cout<<prfxb[r] - prfxb[l-1]<<'\n';
         }
         
      }
   }
   return 0;
}