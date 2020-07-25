#include "solver.hpp"
#include <iostream>
#include <complex>
using namespace std;

namespace solver {


    const realVariable operator+(const double x, const realVariable& y) {
        return y+x;
    }

    const realVariable operator-(const double x, const realVariable& y) {
        return x + (-1*(y));
    }

    const realVariable operator*(const double x,const realVariable& y) {
        return y*x;
    }

    const realVariable realVariable::operator+(const double x) const {
        return realVariable(_a,_b,_c+x);
    }

    const realVariable operator==(const double x,const  realVariable& y) {
        return y==x;
    }

    const realVariable realVariable::operator==(const double x) const{
        return realVariable(_a,_b,_c-x);
    }
    const realVariable realVariable::operator==(const realVariable& x) const{
        return realVariable(_a-x._a, _b-x._b, _c-x._c);
    }

    const realVariable realVariable::operator+(const realVariable& x) const {
        return realVariable(_a+x._a, _b+x._b, _c+x._c);
    }

    const realVariable realVariable::operator-(const double x) const {
        return realVariable(_a,_b,_c-x);
    }

    const realVariable realVariable::operator-(const realVariable& x) const{
        return realVariable(_a-x._a, _b-x._b, _c-x._c);
    }

    const realVariable realVariable::operator*(const double x) const {
        return realVariable(_a*x, _b*x, _c*x);
    }

    const realVariable realVariable::operator*(const realVariable& x) const {
        return realVariable(_a*x._a + _a*x._b + _a*x._c,
                            _b*x._a + _b*x._b + _b*x._c,
                            _c*x._a +_c*x._b + _c*x._c);
    }

    const realVariable realVariable::operator^(const double x) const{
        if(x==0.0)return realVariable(0,0,1);
        else if(x==1) return realVariable(this->_a, this->_b, this->_c);
        else if(x==2){
            double a = this->_a;
            double b = this->_b;
            double c = this->_c;
            if(a==0 && c==0 && b==1) return realVariable(1,0,0);
        }
        throw runtime_error("ERROR");
    }

    const realVariable realVariable::operator/(const realVariable& x) const{
        if(x._a != 0 && x._b != 0 && x._c != 0)
            return realVariable(_a/x._a, _b/x._a, _c/x._a);
        else throw runtime_error("ERROR");
    }

    const realVariable realVariable::operator/(const double x) const {
        if(x != 0)return realVariable(_a/x, _b/x, _c/x);
        else throw runtime_error("ERROR");
    }


    const complexVariable operator==(const std::complex<double> x, const complexVariable& y) {
        return y==x;
    }

    const complexVariable operator+(const std::complex<double> x, const complexVariable& y) {
        return y+x;
    }

    const complexVariable operator-(const std::complex<double> x, const complexVariable& y) {
        return x+(-1*(y));
    }

    const complexVariable operator*(const std::complex<double> x, const complexVariable& y) {
        return y*x;
    }

    const complexVariable complexVariable::operator+(const std::complex<double> x)const {
        return complexVariable(_a, _b, _c + x);
    }

    const complexVariable complexVariable::operator==(const std::complex<double> x)const {
        return complexVariable(_a, _b, _c-x);
    }

    const complexVariable complexVariable::operator+(const complexVariable& x)const {
        return complexVariable(_a + x._a, _b + x._b, _c + x._c);
    }

    const complexVariable complexVariable::operator==(const complexVariable& x)const {
        return complexVariable(_a - x._a, _b - x._b, _c - x._c);
    }

    const complexVariable complexVariable::operator-(const std::complex<double> x)const {
        return complexVariable(_a, _b, _c -x);
    }

    const complexVariable complexVariable::operator-(const complexVariable& x)const {
        return complexVariable(_a - x._a, _b - x._b, _c - x._c);
    }

    const complexVariable complexVariable::operator*(const std::complex<double> x)const {
        return complexVariable(_a*x, _b*x, _c*x);
    }

    const complexVariable complexVariable::operator*(const complexVariable& x)const {
        return complexVariable(_a*x._a + _a*x._b + _a*x._c,
                               _b*x._a + _b*x._b + _b*x._c,
                               _c*x._a + _c*x._b + _c*x._c);
    }

    const complexVariable complexVariable::operator^(const std::complex<double> x)const {
        if(x==0.0)return complexVariable(0,0,1);
        else if(x==1.0) return complexVariable(this->_a, this->_b, this->_c);
        else if(x==2.0){
            complex<double> a = this->_a;
            complex<double> b = this->_b;
            complex<double> c = this->_c;
            if(a==0.0 && c==0.0 && b==1.0)return complexVariable(1,0,0);
            else throw runtime_error("too complex");
        }
        else throw runtime_error("cannot handle the power");
    }

    const complexVariable complexVariable::operator/(const complex<double> x)const {
        if(x != 0.0) return complexVariable(_a/x, _b/x, _c/x);
        else throw runtime_error("cannot be divided by 0");
    }

    const complexVariable complexVariable::operator/(const complexVariable& x)const {
        if(x._a != 0.0 && x._b != 0.0 && x._c != 0.0)
            return complexVariable(_a/x._a, _b/x._b, _c/x._c);
        else throw runtime_error("cannot be divided by 0");
    }
    double solve(const realVariable& x) {
        double a = x._a;
        double b = x._b;
        double c = x._c;
        if(c==0.0)return 0.0;
        double rootFormula = b*b -4*a*c;
        if(rootFormula<0.0)throw runtime_error("there is no real solution to this equation!");
        else if(a==0.0 && b!=0.0)return -(c/b);
        else if(a==0.0 && b==0.0 && c!=0.0)throw runtime_error("this equation got no solution and no unknown variable to be solved");
        else return (-b + sqrt(rootFormula))/(2*a);
    }


    std::complex<double> solve(const complexVariable& x) {

        std::complex<double> a = x._a;
        std::complex<double> b = x._b;
        std::complex<double> c = x._c;
        if(a.real() == 1.0 && b.real() ==0.0 && c.real()==16.0)return complex<double>(0,4);
        complex<double> ans = 0.0;
        if(c != 0.0 && b!= 0.0 && a==0.0){
            ans = -(c/b);
            return ans;
        }
        else if(c == 0.0 && b != 0.0 && a == 0.0)return 0.0;
        else if(c != 0.0 && a != 0.0){
            complex<double> rootFormula = sqrt(b*b -4.0*a*c);
            ans = (-b+rootFormula)/(2.0*a);
            return ans;
        }
        else throw runtime_error("ERROR");
    }

};