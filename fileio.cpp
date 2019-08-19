#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream fout("sample.txt");
    char ch;
    cout<<"Enter text to be written, enter * to terminate : "<<endl;
    cin>>ch;
    while (ch!='*')
    {
        fout.put(ch);
        ch = getchar();
    }
    fout.close();
    ifstream fin("sample.txt");
    while (fin)
    {
        ch = fin.get();
        cout<<ch;
    }
    cout<<"file status "<<fin.is_open()<<endl;
    int vc =0;
    while (fin)
    {
        ch = fin.get();
        if (ch==' '|| ch =='\n')
        {
            cout<<"hi"<<endl;
            vc+=1;
        }
        
    }
    cout<<"no of vowels is "<<vc<<endl;

    
    
    return 0;
}