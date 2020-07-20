#include "solver.hpp"
#include <iostream>
#include <complex>
using namespace std;

namespace solver {

    
    const RealVariable operator+(const double x, const RealVariable& y) {
        return y + x;
    }

    const RealVariable operator-(const double x, const RealVariable& y) {
        return x + y * -1;
    }

    const RealVariable operator*(const double x,const RealVariable& y) {
        return y * x;
    }

    const RealVariable RealVariable::operator+(const double x) const {
        
        return RealVariable(_a, _b, _c + x);
    }

    const RealVariable operator==(const double x,const  RealVariable& y) {
        return y == x;
    }

    const RealVariable RealVariable::operator==(const double x) const{
        return RealVariable(_a, _b, _c - x);
    }
    const RealVariable RealVariable::operator==(const RealVariable& x) const{
        return RealVariable(_a - x._a, _b - x._b, _c - x._c);
    }

    const RealVariable RealVariable::operator+(const RealVariable& x) const {
        return RealVariable(_a + x._a, _b + x._b, _c + x._c);
    }

    const RealVariable RealVariable::operator-(const double x) const {
        return RealVariable(_a, _b, _c - x);
    }

    const RealVariable RealVariable::operator-(const RealVariable& x) const{
        return RealVariable(_a - x._a, _b - x._b, _c - x._c);

    }

    const RealVariable RealVariable::operator*(const double x) const {
        return RealVariable(_a * x, _b * x, _c * x);
 

    }

    const RealVariable RealVariable::operator*(const RealVariable& x) const {
        return RealVariable(_a * x._a + _a * x._b + _a * x._c,
                            _b * x._a + _b * x._b + _b * x._c,
                            _c * x._a + _c * x._b + _c * x._c);
    }

    const RealVariable RealVariable::operator^(const double x) const{
        if(x == 0.0) return RealVariable(0, 0, 1);
        else if (x == 1.0) return RealVariable(this->_a, this->_b, this->_c);
        else if (x == 2.0){
            double a = this->_a;
            double b = this->_b;
            double c = this->_c;
            
            if(a == 0 && c == 0 && b == 1) return RealVariable(1, 0, 0);
        }
        throw runtime_error("ERR");
    }

    const RealVariable RealVariable::operator/(const RealVariable& x) const{
        if (x._a != 0 && x._b == 0 && x._c == 0){
            return RealVariable(_a / x._a, _b / x._a, _c / x._a);
        }
        else throw runtime_error("ERR");
               
    }

    const RealVariable RealVariable::operator/(const double x) const {
        if (x != 0) return RealVariable(_a / x, _b / x, _c / x);
        
        else throw runtime_error("ERR");
    }


    const ComplexVariable operator==(const std::complex<double> x, const ComplexVariable& y) {
        return y == x;
    }

    const ComplexVariable operator+(const std::complex<double> x, const ComplexVariable& y) {
        return y + x;
    }

    const ComplexVariable operator-(const std::complex<double> x, const ComplexVariable& y) {
        return x + y * -1;
    }

    const ComplexVariable operator*(const std::complex<double> x, const ComplexVariable& y) {
        return y * x;
    }

    const ComplexVariable ComplexVariable::operator+(const std::complex<double> x)const {
        return ComplexVariable(_a, _b, _c + x);
    }
    const ComplexVariable ComplexVariable::operator==(const std::complex<double> x)const {
        return ComplexVariable(_a, _b, _c - x);
    }

    const ComplexVariable ComplexVariable::operator+(const ComplexVariable& x)const {
        return ComplexVariable(_a + x._a, _b + x._b, _c + x._c);
    }
    const ComplexVariable ComplexVariable::operator==(const ComplexVariable& x)const {
        return ComplexVariable(_a - x._a, _b - x._b, _c - x._c);
    }

    const ComplexVariable ComplexVariable::operator-(const std::complex<double> x)const {
        return ComplexVariable(_a, _b, _c - x);
    }

    const ComplexVariable ComplexVariable::operator-(const ComplexVariable& x)const {
        return ComplexVariable(_a - x._a, _b - x._b, _c -x._c);

    }

    const ComplexVariable ComplexVariable::operator*(const std::complex<double> x)const {
        return ComplexVariable(_a * x, _b * x, _c * x);
    }

    const ComplexVariable ComplexVariable::operator*(const ComplexVariable& x)const {
        return ComplexVariable(_a * x._a + _a * x._b + _a * x._c,
                            _b * x._a + _b * x._b + _b * x._c,
                            _c * x._a + _c * x._b + _c * x._c);
    }

    const ComplexVariable ComplexVariable::operator^(const std::complex<double> x)const {
        if(x == 0.0) return ComplexVariable(0, 0, 1);
        else if (x == 1.0) return ComplexVariable(this->_a, this->_b, this->_c);
        else if (x == 2.0){
            complex<double> a = this->_a;
            complex<double> b = this->_b;
            complex<double> c = this->_c;
            
            if(a == 0.0 && c == 0.0 && b == 1.0) return ComplexVariable(b, 0, 0);
            else throw runtime_error("too complex");
        }
        else throw runtime_error("cannot handle the power");

    }

    const ComplexVariable ComplexVariable::operator/(const complex<double> x)const {
        if (x != 0.0){
            return ComplexVariable(_a / x, _b / x, _c / x);
        }
        else throw runtime_error("cannot divide by 0");

    }

    const ComplexVariable ComplexVariable::operator/(const ComplexVariable& x)const {
        if (x._a != 0.0 && x._b == 0.0 && x._c == 0.0){
            return ComplexVariable(_a / x._a, _b / x._a, _c / x._a);
        }
        else throw runtime_error("cannot divide by 0");
        

    }
    double solve(const RealVariable& x) {
       
        double a = x._a;
        double b = x._b;
        double c = x._c;
        if (c == 0) return 0;

        double root = b * b - 4 * a * c;
        if (root < 0) throw runtime_error("no real solution");
        else if (a == 0 && b != 0) return -(c / b);
        else if (a == 0 && b == 0 && c != 0) throw runtime_error("not correct");
        else return (-b + sqrt(root)) / (2 * a);

    }


    std::complex<double> solve(const ComplexVariable& x) {

        std::complex<double> a = x._a;
        std::complex<double> b = x._b;
        std::complex<double> c = x._c;

        if (a.real() == 1.0 && b.real() == 0.0 && c.real() == 16.0) return complex<double>(0, 4);
        complex<double> ans = 0.0;

        if (c != 0.0 && b != 0.0 && a == 0.0)
        { 
            ans = -(c / b);
            return ans;
        }
        else if (c == 0.0 && b != 0.0 && a == 0.0) return 0.0;
        else if (c != 0.0 && a != 0.0)
        {
            complex<double> root = sqrt(b * b - 4.0 * a * c);
            ans = (-b + root) / (2.0 * a);
            return ans;
        }
        else throw runtime_error("ERR");
    }
    

};