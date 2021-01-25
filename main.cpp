#include <iostream>
#include "Fracts.h"

using namespace std;

int main(void)
{
    int n {};
    do
    {
        cout << "Please put in the number of fractions you want to check." << endl;
        cin >> n;
    } while (n <= 0);
    
    vector<vector<unsigned long long>> fractions;
    vector<unsigned long long> pom;
    pom.resize(2);

    for (int i = 0; i < n; i++)
    {
        cout << "Please put in nominator number " << i + 1 << ": ";
        cin >> pom[0];
        do
        {
            cout << "Please put in denominator number " << i + 1 << ": ";
            cin >> pom[1];
        } while (pom[1] <= 0);
        fractions.push_back(pom);
        pom[0] = 0;
        pom[1] = 0;
    }

    string s = Fracts::convertFrac(fractions);
    
    return 0;
}