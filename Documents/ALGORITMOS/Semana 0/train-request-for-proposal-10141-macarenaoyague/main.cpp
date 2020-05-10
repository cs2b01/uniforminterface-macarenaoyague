#include <iostream>
using namespace std;

void UVa10141();

int main() {
    UVa10141();

    return 0;
}

void UVa10141(){

    int n, p;

    string line;
    string proposal;
    float price;
    int numberOfRequerimenst;
    int count=0;

    while (true)
    {

        cin>>n>>p;

        if (n==0 or p==0)
            break;

        float maxCompliance = 0;
        string proposalMaxCompliance;
        float priceMaxCompliance;

        for (int i=0; i<=n; i++)
            getline(cin, line);

        for (int i=0; i<p; i++)
        {

            getline(cin, proposal);
            cin>>price>>numberOfRequerimenst;

            if (i==0)
                priceMaxCompliance=price;

            for (int j=0; j<=numberOfRequerimenst; j++)
                getline(cin,line);

            if (numberOfRequerimenst/p>maxCompliance)
            {
                maxCompliance = numberOfRequerimenst/p;
                proposalMaxCompliance = proposal;
                priceMaxCompliance = price;
            }
            if (numberOfRequerimenst/p==maxCompliance and price<priceMaxCompliance)
            {
                maxCompliance = numberOfRequerimenst/p;
                proposalMaxCompliance = proposal;
                priceMaxCompliance = price;
            }
        }

        cout<<"RFP #"<<++count<<endl<<proposalMaxCompliance<<endl;
    }
}

/*6 4
engine
        brakes
tires
        ashtray
vinyl roof
trip computer
Chevrolet
20000.00 3
engine
        tires
brakes
        Cadillac
70000.00 4
ashtray
        vinyl roof
        trip computer
        engine
Hyundai
10000.00 3
engine
        tires
ashtray
        Lada
6000.00 1
tires
1 1
coffee
        Starbucks
1.50 1
coffee
0 0*/

