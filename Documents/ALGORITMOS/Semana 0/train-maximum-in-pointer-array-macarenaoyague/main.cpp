#include <iostream>
using namespace std;


int max(int *iptr[], int n);

int main() {
    int n;
    int array[100]={};
    int *iptr[100]={};
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>array[i];
        iptr[i] = &array[i];
    }
    cout<<max(iptr, n);
    return 0;
}

int max(int *iptr[], int n){

    int max = 0;
    if (n<=100)
        for (int i=0; i<n; i++)
            if (*iptr[i]>max)
                max=*iptr[i];

    return max;
}

//is missing the limit n≤100