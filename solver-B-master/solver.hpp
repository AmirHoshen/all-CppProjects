
#include <iostream>
#include <complex>
using namespace std;

namespace solver {
    class realVariable{
    public:
        double _a;
        double _b;
        double _c;
        realVariable(){
            this->_a = 0;
            this->_b = 1;
            this->_c = 0;
        }
        realVariable(double a, double b, double c):_a(a),_b(b), _c(c){};
        const realVariable operator+(const double x)const;
        const realVariable operator+(const realVariable& x)const;
        const realVariable operator-(const double x)const;
        const realVariable operator-(const realVariable& x)const;
        const realVariable operator*(const double x)const;
        const realVariable operator*(const realVariable& x)const;
        const realVariable operator^(const double x)const;
        const realVariable operator^(const realVariable& x)const;
        const realVariable operator/(const double x)const;
        const realVariable operator/(const realVariable& x)const;
    };

    double solve(const realVariable& x);
    class complexVariable{
    public:
        std::complex<double> _a;
        std::complex<double> _b;
        std::complex<double> _c;
        complexVariable(const std::complex<double>& a = 0, const std::complex<double>&  b = 1, const std::complex<double>&  c = 0)  _a(a),_b(b),_c(c){}
        const complexVariable operator+(const std::complex<double> x)const;
        const complexVariable operator+(const complexVariable& x)const;
        const complexvariable operator-(const std::complex<double> x)const;
        const complexVariable operator-(const complexVariable& x)const;
        const complexVariable operator*(const std::complex<double> x)const;
        const complexVariable operator*(const complexVariable& x)const;
        const complexVariable operator/(const std::complex<double> x)const;
        const complexVariable operator/(const complexVariable& x)const;
        const complexVariable operator^(const std::complex<double> x)const;
        const complexVariable operator==(const std::complex<double> x)const;
        const complexVariable operator==(const complexVariable& x)const;
    };
    const realVariable operator+(const double a, const realVariable& b);
    const realVariable operator-(const double a, const realVariable& b);
    const realvariable operator*(const double a, const realVariable& b);
    const realVariable operator/(const double a, const realVariable& b);
    const realVariable operator==(const double a, const realVariable& b);

    const complexVariable operator+(const std::complex<double> a, const complexVariable& b);
    const complexVariable operator-(const std::complex<double> a, const complexVariable& b);
    const complexVariable operator*(const std::complex<double> a, const complexVariable& b);
    const complexVariable operator/(const std::complex<double> a, const complexVariable& b);
    const complexVariable operator==(const std::complex<double> a, const complexVariable& b);

    std::complex<double> solve(const complexVariable& b);
}