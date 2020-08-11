#include <iostream>
#include <vector>
using namespace std;


int RandomNumber (){
    return rand()%10+1;
}

template <unsigned int N>
vector <int> functionVec(){
    vector <int> vector (N);
    generate (vector.begin(), vector.end(), RandomNumber);
    for (int i=0; i<vector.size();i++)
        cout<<vector.at(i)<<" ";
    cout<<endl;
    for (int i=N-1; i>=0; i--)
        vector.insert(vector.begin()+i, vector.at(i)-1, vector.at(i));
    for (int i=0; i<vector.size();i++)
        cout<<vector.at(i)<<" ";
    return vector;
}


int main() {
    vector <int> vector=functionVec<6>();
    return 0;
}


