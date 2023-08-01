#include <iostream> 
using namespace std;

void findANumber(){
    int n;
    cin>>n;
    int a[n];
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    int x; 
    cin>>x; 
    bool found = false;
    for(int i =0;i<n;i++){
        if(x==a[i]) {
            found = true;
        }
    }
    if(found==true){
        cout<<"found the number";
    }else {
        cout<<"did not find";
    }
} 


int main(){
   findANumber();
   return 0;
}
