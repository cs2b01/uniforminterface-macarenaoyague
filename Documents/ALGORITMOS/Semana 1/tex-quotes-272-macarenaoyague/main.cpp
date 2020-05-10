#include <iostream>
using namespace std;

void UVa272();

int main() {
    UVa272();
    return 0;
}

void UVa272(){

    string line;
    bool first = 1;

    while (getline(cin, line)){
        for (auto character: line)
        {
            if (character == '"')
            {
                if (first)
                    cout<<"``";
                else
                    cout<<"''";
                first = !first;
            }
            else
                cout<<character;
        }
        cout<<endl;
        if (line == "")
            break;
    }
}


