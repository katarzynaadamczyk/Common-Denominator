#include <string>
#include <vector>

class Fracts
{
    private:
        static std::vector<std::vector<unsigned long long>> firstDiv(unsigned long long n);
        static void shortenFract(std::vector<std::vector<unsigned long long>> &divs, std::vector<unsigned long long> & frac);
        static std::vector<std::vector<unsigned long long>> nonCommonDivisors(std::vector<std::vector<unsigned long long>> & divs, std::vector<std::vector<unsigned long long>> & divnew);
        static unsigned long long commonDenom(std::vector<std::vector<unsigned long long>> &divs);
    public:
        static std::string convertFrac(std::vector<std::vector<unsigned long long>> &lst);
};