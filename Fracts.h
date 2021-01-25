#include <string>
#include <vector>

class Fracts
{
    private:
        static std::vector<unsigned long long> firstDiv(unsigned long long n);
        static void shortenFract(std::vector<unsigned long long> &divs, std::vector<unsigned long long> & frac);
        static std::vector<unsigned long long> nonCommonDivisors(std::vector<unsigned long long> div1, std::vector<unsigned long long> div2);
    public:
        static std::string convertFrac(std::vector<std::vector<unsigned long long>> &lst);
};