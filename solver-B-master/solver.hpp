
#include <iostream>
#include <complex>
using namespace std;

namespace solver {
    class RealVariable {
    public:
        double _a;
        double _b;
        double _c;
          
        RealVariable(){
            this->_a = 0;
            this->_b = 1;
            this->_c = 0;

        }
        RealVariable(const double a, const double b, const double c){
            this->_a = a;
            this->_b = b;
            this->_c = c;
        }
        
        const RealVariable operator+(const double x) const;

        const RealVariable operator+(const RealVariable& x) const;

        const RealVariable operator-(const double x) const;

        const RealVariable operator-(const RealVariable& x) const;

        const RealVariable operator*(const double x) const;

        const RealVariable operator*(const RealVariable& x) const;

        const RealVariable operator^(const double x) const;

        const RealVariable operator^(const RealVariable& x) const;

        const RealVariable operator/(const double x) const;

        const RealVariable operator/(const RealVariable& x) const;

        const RealVariable operator==(const double x) const ;
        
        const RealVariable operator==(const RealVariable& x) const;

    };

    double solve(const RealVariable& x);

    class ComplexVariable {
    public:
        std::complex<double> _a;
        std::complex<double> _b;
        std::complex<double> _c;
    
        ComplexVariable(const std::complex<double>& a = 0, const std::complex<double>& b = 1,
                        const std::complex<double>& c = 0)
                : _a(a), _b(b), _c(c)
        {}
        
        const ComplexVariable operator+(const std::complex<double> x)const ;
        
        const ComplexVariable operator+(const ComplexVariable& x)const ;
        
        const ComplexVariable operator-(const std::complex<double> x)const ;

        const ComplexVariable operator-(const ComplexVariable& x)const ;

        const ComplexVariable operator*(const std::complex<double> x)const ;

        const ComplexVariable operator*(const ComplexVariable& x)const ;

        const ComplexVariable operator^(const std::complex<double> x)const ;

        const ComplexVariable operator/(const std::complex<double> x)const ;

        const ComplexVariable operator/(const ComplexVariable& x)const ;

        const ComplexVariable operator==(const std::complex<double> x)const ;

        const ComplexVariable operator==(const ComplexVariable& x)const ;
    };

    const RealVariable operator+(const double x, const RealVariable& y);

    const RealVariable operator-(const double x, const RealVariable& y);

    const RealVariable operator*(const double x, const RealVariable& y);

    const RealVariable operator/(const double x, const RealVariable& y);

    const ComplexVariable operator+(const std::complex<double> x, const ComplexVariable& y);

    const ComplexVariable operator-(const std::complex<double> x, const ComplexVariable& y);

    const ComplexVariable operator*(const std::complex<double> x, const ComplexVariable& y);

    const ComplexVariable operator/(const std::complex<double> x, const ComplexVariable& y);

    const RealVariable operator==(const double x, const RealVariable& y);

    const ComplexVariable operator==(const std::complex<double> x, const ComplexVariable& y);

    std::complex<double> solve(const ComplexVariable& x);

}
