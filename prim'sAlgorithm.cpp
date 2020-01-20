#include <iostream>
using namespace std;
class graph
{
    int n;
    int **g;
    int **cst;
    int **mst;
    bool *visit;  
    int *src;  
    int *dist;
     bool allVisit(){
          bool y =1;
          for (int i = 0; i < n; i++)
          {
              if(visit[i]==0){
                  y =0;
              }
          }
          return y;
      }
    public:
      graph(int k){
        n = k; 
        g = new int*[n];//
        mst = new int*[n]; 
        cst = new int*[n];//
        visit = new bool[n];
        dist = new int[n];
        src = new int[n];//
        for (int i = 0; i < n; i++)
        {
            g[i] = new int[n]; 
            cst[i] = new int[n];
            mst[i] = new int[n]; 
            visit[i] = 0;
            src[i] = 0;
            dist[i] = 9999;
           
        }
         for (int i = 0; i < n; i++)
          {
             for (int j = 0; j < n; j++)
              {
                  g[i][j] = 0;
                  cst[i][j] = 9999;
                  mst[i][j] = 0;
                  
              }
             
          }
        
        
      }
      void accept(int v1,int v2,int w){
        g[v1][v2] =  g[v2][v1]= w; 
        cst[v1][v2] = cst[v2][v1] = w;
        
        
      }
     
      void setDist(){
          for (int i = 0; i < n; i++)
          {
              dist[i] = cst[0][i];
          }
          
      }
      void show(){
          cout<<"graph : "<<endl;
          for (int i = 0; i < n; i++)
          {
              for (int j = 0; j < n; j++)
              {
                  cout<<"g("<<j<<") = "<<" -> "<<g[i][j]<<"   ";
              }
              cout<<endl;
          }
          cout<<"cost"<<endl;
          for (int i = 0; i < n; i++)
          {
              for (int j = 0; j < n; j++)
              {
                  cout<<"cost("<<j<<") = "<<" -> "<<cst[i][j]<<"   ";
              }
              cout<<endl;
          }
          cout<<"src "<<endl;
          for (int i = 0; i < n; i++)
          {
              cout<<src[i]<<' ';
          }
          cout<<"dist "<<endl;
          for (int i = 0; i < n; i++)
          {
              cout<<dist[i]<<' ';
          }
          cout<<"visit "<<endl;
          for (int i = 0; i < n; i++)
          {
              cout<<visit[i]<<' ';
          }
          
      }
      void prims(){
          visit[0] = 1;
          while(1){
                int min =dist[0];
                int x =0;
                for (int i = 0; i < n; i++)
                {
                    if(dist[i]<min && visit[i]==0){
                        min = dist[i];
                        x = i;
                    }
                }
                mst[src[x]][x] = min;
                visit[x] = 1;
                if(allVisit()==1){
                    break;
                }
                for (int j = 0; j < n; j++)
                {
                    if(visit[j]==0 && (dist[j]>cst[x][j])){
                        dist[j] = cst[x][j];
                        src[j] = x;
                    }
                }



          }
          int minCost =0;
         for (int i = 0; i < n; i++)
         {
            for (int j = 0; j < n; j++)
            {
                if (mst[i][j]!=0)
                {
                     minCost+=mst[i][j];
                    cout<<"i = "<<i<<" -> "<<j<<" cost = "<<mst[i][j]<<endl;
                }
                
            }
            
         }
          cout<<"Min cost = "<<minCost<<endl;


      }
      void look(){
          cout<<endl;
         
          for (int i = 0; i < n; i++)
          {
              for(int j =0;j<n;j++){
                  cout<<mst[i][j]<<" ";
              }
              cout<<endl;
          }
          
      }
   

   
};
int main(){
    int n;
    cout<<"vertices "<<endl;
    cin>>n;
    int e;
     cout<<"edges "<<endl;
    cin>>e;
    graph g(n);
    for (int i = 0; i < e; i++)
    {
        int v1,v2,w;
        cin>>v1>>v2>>w;
        g.accept(v1,v2,w);

    }
    g.setDist();
    g.show();
    cout<<"Starting prims ------"<<endl;
   g.prims(); 
   g.look();
    return 0;
}
