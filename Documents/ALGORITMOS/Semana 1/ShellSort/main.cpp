#include <iostream>
#include <vector>
using namespace std;

template <class T>
void ShellSort (vector <T> & vec);

template <class T>
void printComp (const int &i, const int &N, const T &number1, const T &number2);

template<class T>
void printVec(const vector<T> &vec, int &N);




int main() {
    vector <int> vec {2, 3, 9, 9, 8, 7, 4, 3};
    ShellSort<int>(vec);

    for (auto number: vec)
        cout<<number<<" ";

    return 0;
}





template <class T>
void ShellSort (vector <T> & vec){

    int N = vec.size();
    int size = N;
    bool somethingChange = false;
    T temp;

    printVec(vec, N);

    while (N != 1)
    {
        cout<<"--------------"<<endl;
        N = N/2;
        do{
            somethingChange = false;
            printVec(vec, N);
            for (int i = 0; i<size-N; i++)
            {
                printComp(i, N, vec[i], vec[i+N]);
                if (vec[i] > vec[i+N])
                {
                    temp = vec[i];
                    vec[i] = vec[i+N];
                    vec[i+N] = temp;
                    if (!somethingChange)
                        somethingChange = true;
                }
            }
        }while (somethingChange);
    }
}

template <class T>
void printComp (const int &i, const int &N, const T &number1, const T &number2){
    for(int j = 0; j<i; j++)
        cout<<"  ";
    cout<<number1<<" ";
    for(int j = 1; j<N; j++)
        cout<<"  ";
    cout<<number2<<endl;
}

template<class T>
void printVec(const vector<T> &vec, int &N){
    for (auto element: vec)
        cout<<element<<" ";
    cout<<endl<<"N: "<<N<<endl;

}