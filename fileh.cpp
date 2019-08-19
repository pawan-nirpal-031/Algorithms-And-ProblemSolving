#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream ifo("f1.txt");
char  str1[200],str2[200];
cout<<"Enter data to be written : "<<endl;
   cin.getline(str1,sizeof(str1));
   ifo<<str1;
   ifo.close();
   ifstream ofo("f1.txt");
   ofo.getline(str2,100);
   cout<<str2<<endl;
   


    
    return 0;
}