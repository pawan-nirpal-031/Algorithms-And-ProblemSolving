#include <iostream>
using namespace std;
class Graph{
    int n;
    int **mat;
    bool *visit;
    public:
     Graph(int k){
         n = k;
         mat = new int*[n];
         visit = new bool[n];
         for(int i =0;i<n;i++){
             mat[i] = new int[n];
             visit[i] = 0;
         }
         for(int i =0;i<n;i++){
             for(int j =0;j<n;j++){
                 mat[i][i] = 0;
             }
         }
         
     }
     void create(int v1,int v2,int w){
         if((v1<=n-1 && v1>=0)&&(v2>=0 && v2<=n-1)){
             mat[v1][v2] = mat[v2][v1] = w;
         }else{
             cout<<"Invalid edge "<<endl;
         }
     }
    void show(){
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<mat[i][j]<<' ';
            }
            cout<<endl;
            
        }
        
    }
    void DFS(int s){
        cout<<s<<" ";
        visit[s] = 1;
        for (int d = 0; d < n; d++)
        {
            if(mat[s][d]!=0 && visit[d]==0){
                DFS(d);
            }
        }
        
    }



};
int main(){
    int n;
    cout<<"Enter to toal no of edges "<<endl;
    cin>>n;
    Graph g1(n);
    
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter edge and weight "<<endl;
        int x,y,w;
        cin>>x>>y>>w;
        g1.create(x,y,w);
    }
    cout<<"Graph"<<endl;
    g1.show();
    cout<<"DFS enter source node "<<endl;
    int s;
    cin>>s;
    g1.DFS(s);
    

    return 0;
}