#include <stdio.h>
typedef long long int ll;
int main(){
    ll t;
    scanf("%ll",&t);
    while(t--){
        ll n,k;
        scanf("%ll,%ll",&n,&k);
        while(n--){
            ll x;
            scanf("%ll",&x);
            if(x%k==0){
                printf("%d",1);
            }else{
                printf("%d",0);
            }
        }
        printf("\n");
    }
    return 0;
}