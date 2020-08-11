#include <iostream>
using namespace std;

int main() {
    int t=51;
    int reference;
    int temporal;
    int max;
    while (t>50)
        cin>>t;
    int* arr[t];
    for (int i=0; i<t; t++)
    {
        max=0;
        reference=0;
        temporal=0;
        cin>>reference;
        cout<<reference<<endl;
        for (int z=0; z<reference; z++)
        {
            cin>>temporal;
            cout<<"Temporal"<<temporal<<endl;
            if (temporal>max)
                max=temporal;
            cout<<max<<endl;
        }
        *arr[i]=max;
    }
    for (int i=0;i<t;t++)
        cout<<"Case "<<i+1<<" "<<*arr[i];
    return 0;
}