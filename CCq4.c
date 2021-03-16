#include <stdio.h>
long long int n,e,h,a,b,c;

void PrintInt(long long int x)
{
    printf("%lld\n",x);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld %lld %lld %lld %lld",&n,&e,&h,&a,&b,&c);
        long long int pay =__LONG_LONG_MAX__;
        int class = 0;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                if(e>=2)
                {
                    if(a<pay)
                    {
                        class = 1;
                        pay = a;
                    }
                }
                if(h>=3)
                {
                    if(b<pay)
                    {
                        class = 2;
                        pay = b;
                    }
                }
                if(e>=1 && h>=1)
                {
                    if(c<pay)
                    {
                        class = 3;
                        pay = c;
                    }
                }
                if(class==0)
                {
                    pay = -1;
                    break;
                }else 
                {
                    if(class==1)
                    {
                        e = e-2;
                    }
                    if(class ==2)
                    {
                        h = h-3;
                    }
                    if(class==3)
                    {
                        e = e-1;
                        h = h-1;
                    }
                }
            }
            else 
            {
                class =0;
                long long int curr_order = __LONG_LONG_MAX__;
                if(e>=2)
                {
                    if(a<curr_order)
                    {
                        class = 1;
                        curr_order = a;
                    }
                }
                if(h>=3)
                {
                    if(b<curr_order)
                    {
                        curr_order = b;
                        class = 2;
                    }
                }
                if(e>=1 && h>=1)
                {
                    if(c<curr_order)
                    {
                        class = 3;
                        curr_order = c;
                    }
                }
                if(class==0)
                {
                    pay = -1;
                    break;
                }
                else 
                {
                    pay = pay + curr_order;
                    if(class==1)
                    {
                        e = e -2;
                    }
                    else if(class==2)
                    {
                        h = h -3;
                    }
                    else if(class==3)
                    {
                        e = e-1;
                        h = h-1;
                    }
                }
            }
            if(pay==-1)
            {
                break;
            }
        }
        PrintInt(pay);
    }
    return 0;
}