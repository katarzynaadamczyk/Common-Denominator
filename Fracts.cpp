#include "Fracts.h"
#include <math.h>
#include <iostream>

using namespace std;

//*************************************************************************************
//definition of public functions from Fracts class

string Fracts::convertFrac(vector<std::vector<unsigned long long>> &lst)
{
    for (int i = 0; i < lst.size(); i++)
    {
        vector<unsigned long long> divs = firstDiv(lst[i][1]);
        cout << endl;
        cout << "DZIELNIKI LICZBY " << lst[i][1] << endl; 
        for (int j = 0; j < divs.size(); j++)
        {
            cout << "dzielnik nr " << j + 1 << ": " << divs[j] << endl;
        }

    }
    return "";
}

//*************************************************************************************
//definition of private functions from Fracts class

//function that returns the list of all divisors of a number
vector<unsigned long long> Fracts::firstDiv(unsigned long long n)
{
    vector<unsigned long long> ret;
    for (unsigned long long i = 2; i <= sqrt(n); i++)
    {
        while (n % i == 0)
        {
            n /= i;
            ret.push_back(i);
        }
    }
    if (n > 1)
    {
        ret.push_back(n);
    }
    return ret;
}

//function that shortens given fraction and removes the common divisor from the list of all divisors of the denominator
void Fracts::shortenFract(vector<unsigned long long> &divs, vector<unsigned long long> & frac)
{

}

vector<unsigned long long> Fracts::nonCommonDivisors(vector<unsigned long long> div1, vector<unsigned long long> div2)
{

}