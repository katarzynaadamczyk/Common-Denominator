#include "Fracts.h"
#include <math.h>
#include <iostream>

using namespace std;

//*************************************************************************************
//definition of public functions from Fracts class

string Fracts::convertFrac(vector<std::vector<unsigned long long>> &lst)
{
    /* TO DO */
    vector<vector<unsigned long long>> totalDivs;
    for (int i = 0; i < lst.size(); i++)
    {
        /* for now there is only cheching if algorithm works well */
        vector<vector<unsigned long long>> divs = firstDiv(lst[i][1]);
        cout << endl;
        cout << "DZIELNIKI LICZBY " << lst[i][1] << endl; 
        for (int j = 0; j < divs.size(); j++)
        {
            cout << "dzielnik nr " << j + 1 << ": " << divs[j][0] <<", ilosc powtorzen: " << divs[j][1] << endl;
        }
        cout << "SKROCENIE ULAMKA " << lst[i][0] <<" // " << lst[i][1] << endl;
        shortenFract(divs, lst[i]);
        cout << "ULAMEK PO SKROCENIU: " << lst[i][0] <<" // " << lst[i][1] << endl;
        cout << "DZIELNIKI LICZBY " << lst[i][1] << endl; 
        for (int j = 0; j < divs.size(); j++)
        {
            cout << "dzielnik nr " << j + 1 << ": " << divs[j][0] <<", ilosc powtorzen: " << divs[j][1] << endl;
        }
        if (totalDivs.empty())
        {
            totalDivs = divs;
        }
        else
        {
            nonCommonDivisors(totalDivs, divs);
        }
        cout << endl;
        cout << "WSPOLNE DZIELNIKI:" << endl; 
        for (int j = 0; j < totalDivs.size(); j++)
        {
            cout << "dzielnik nr " << j + 1 << ": " << totalDivs[j][0] <<", ilosc powtorzen: " << totalDivs[j][1] << endl;
        }  
        /* TO DO */
    }
    return "";
}

//*************************************************************************************
//definition of private functions from Fracts class

//function that returns the list of all divisors of a number
vector<vector<unsigned long long>> Fracts::firstDiv(unsigned long long n)
{
    vector<vector<unsigned long long>> ret;
    vector<unsigned long long> pom;
    unsigned long long tmp;
    for (unsigned long long i = 2; i <= sqrt(n); i++)
    {
        tmp = 0;
        while (n % i == 0)
        {
            n /= i;
            tmp++;
        }
        if (tmp)
        {
            pom.push_back(i);
            pom.push_back(tmp);
            ret.push_back(pom);
            pom.clear();
        }
    }
    if (n > 1)
    {
        pom.push_back(n);
        pom.push_back(1);
        ret.push_back(pom);
    }
    return ret;
}

//function that shortens given fraction and removes the common divisor from the list of all divisors of the denominator
void Fracts::shortenFract(vector<vector<unsigned long long>> & divs, vector<unsigned long long> & frac)
{
    for (int i = 0; i < divs.size(); )
    {
        while (frac[0] % divs[i][0] == 0 && divs[i][1] != 0)
        {
            frac[0] /= divs[i][0];
            frac[1] /= divs[i][0];
            divs[i][1]--;
        }
        if (divs[i][1] == 0)
        {
            divs.erase(divs.begin() + i);
        }
        else
        {
            i++;
        }
    }
}

vector<vector<unsigned long long>> Fracts::nonCommonDivisors(vector<vector<unsigned long long>> & divs, vector<vector<unsigned long long>> & divnew)
{
    int j {};
    for (int i = 0; i < divnew.size(); i++)
    {
        while (j < divs.size())
        {
            if (divs[j][0] <= divnew[i][0])
            {
                break;
            }
            j++;
        }
        cout << "j: " << j << ", i: " << i << endl;
            if (divnew[i][0] == divs[j][0])
            {
                if (divnew[i][1] > divs[j][1]) 
                {
                    divs[j][1] = divnew[i][1];  
                }          
            }
            else
            {
                divs.insert(divs.begin() + j, divnew[i]);
            }
    }
    return divs;
}

unsigned long long Fracts::commonDenom(vector<vector<unsigned long long>> &divs)
{
    unsigned long long ret {1};
    for (int i = 0; i < divs.size(); i++)
    {
        for (int j = 0; j < divs[i][1]; j++)
        {
            ret *= divs[i][0];
        }
    }
    return ret;
}