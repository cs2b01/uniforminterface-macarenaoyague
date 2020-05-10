#include <iostream>
using namespace std;

int getPlayer(const int &N, const int &K, const int &P);
void print(const int playerNumbers[], const int &nCases);

int main() {

    int nCases, N, K, P, player; //N players
    cin>>nCases;
    int playerNumbers[nCases];

    for (int i = 0; i < nCases; i++)
    {
        cin>>N>>K>>P;
        player = getPlayer(N, K, P);
        playerNumbers[i] = player;
    }

    print(playerNumbers, nCases);

    return 0;
}

int getPlayer(const int &N, const int &K, const int &P){
    int player;
    player = K +P%N;
    if (player > N)
        player %= N;
    return player;
}

void print(const int playerNumbers[], const int &nCases){
    for (int i = 0; i < nCases; i++)
        cout<<"Case "<<i+1<<": "<<playerNumbers[i]<<endl;
}

