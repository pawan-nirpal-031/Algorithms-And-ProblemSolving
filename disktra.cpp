#include <iostream>
#include <vector>
#define inf 10000
using namespace std;
class graph
{
    int **g;
    pair<int,bool>*t;
    int n;
    vector<int>v;
    public:
    graph(int k){
        n = k;
        g = new int*[n];
        t = new pair<int,bool>[n];
        for (int i = 0; i < n; i++)
        {
            g[i] = new int[n];
            t[i].first = inf;
            t[i].second = 0;

        }
         
       for (int i = 0; i < n; i++)
       {
           for (int j = 0; j < n; j++)
           {
               g[i][j] =0;
           }
           
       }
      
        
    }
    int askmin(int x,int y){
        if(x<y){
            return x;
        }
        return y;
    }
    bool all(){
        bool y =1;
        for (int i = 0; i < n; i++)
        {
            if(t[i].second==0){
                y =0;
            }
        }
        return y;
    }
    void accept(int v1,int v2,int w){
        g[v1][v2] = g[v2][v1]  =w;
    }
    void disktra(int v1,int v2,int c){

        if(c!=n){
            
            {
                t[v1].second =1;
                int min =inf;
                int x =0;
                for (int j = 0; j < n; j++)
                {
                    if(g[v1][j]!=0 && t[j].second==0){
                        t[j].first = askmin(t[j].first,(t[v1].first + g[v1][j])); 
                        if(t[j].first<min){
                            min = t[j].first;
                            x = j;
                        }
                        cout<<"for j = "<<j<< " and t["<<j<<"] = "<<t[j].first<<endl;
                    }

                }
                cout<<c<<" times "<<endl;
                t[x].second =1;
                c+=1;
                v.push_back(x);
                for (int i = 0; i < n; i++)
                {
                    cout<<t[i].first<<' '<<t[i].second<<endl;
                }
                
                disktra(x,v2,c);
 
            }
        }
    }
    vector<int> shortest(int v1,int v2){
        t[v1].first = 0;
        int c =1;
        v.push_back(v1);
        
        disktra(v1,v2,c);
        return v;

    }


};
int main(){
    int n;
    cin>>n;
    graph g(n);
    int e;
    cin>>e;
    for (int i = 0; i < e; i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        g.accept(x,y,w);
    }
    cout<<"first,second"<<endl;
    int k,y;
    cin>>k>>y;
   vector<int>v =  g.shortest(k,y);
   for ( auto x : v)
   {
       cout<<x<<' ';
   }
   
    return 0;
}