#include "solver.hpp"
#include <iostream>
#include <complex>
using namespace std;

namespace solver {

    
    const RealVariable operator+(const double x, const RealVariable& y) {

    }

    const RealVariable operator-(const double x, const RealVariable& y) {

    }

    const RealVariable operator*(const double x,const RealVariable& y) {

    }

    const RealVariable RealVariable::operator+(const double x) const {

    }

    const RealVariable operator==(const double x,const  RealVariable& y) {

    }

    const RealVariable RealVariable::operator==(const double x) const{

    }
    const RealVariable RealVariable::operator==(const RealVariable& x) const{

    }

    const RealVariable RealVariable::operator+(const RealVariable& x) const {

    }

    const RealVariable RealVariable::operator-(const double x) const {

    }

    const RealVariable RealVariable::operator-(const RealVariable& x) const{

    }

    const RealVariable RealVariable::operator*(const double x) const {

    }

    const RealVariable RealVariable::operator*(const RealVariable& x) const {

    }

    const RealVariable RealVariable::operator^(const double x) const{

    }

    const RealVariable RealVariable::operator/(const RealVariable& x) const{

    }

    const RealVariable RealVariable::operator/(const double x) const {

    }


    const ComplexVariable operator==(const std::complex<double> x, const ComplexVariable& y) {

    }

    const ComplexVariable operator+(const std::complex<double> x, const ComplexVariable& y) {

    }

    const ComplexVariable operator-(const std::complex<double> x, const ComplexVariable& y) {

    }

    const ComplexVariable operator*(const std::complex<double> x, const ComplexVariable& y) {

    }

    const ComplexVariable ComplexVariable::operator+(const std::complex<double> x)const {

    }
    const ComplexVariable ComplexVariable::operator==(const std::complex<double> x)const {

    }

    const ComplexVariable ComplexVariable::operator+(const ComplexVariable& x)const {

    }
    const ComplexVariable ComplexVariable::operator==(const ComplexVariable& x)const {

    }

    const ComplexVariable ComplexVariable::operator-(const std::complex<double> x)const {

    }

    const ComplexVariable ComplexVariable::operator-(const ComplexVariable& x)const {

    }

    const ComplexVariable ComplexVariable::operator*(const std::complex<double> x)const {

    }

    const ComplexVariable ComplexVariable::operator*(const ComplexVariable& x)const {

    }

    const ComplexVariable ComplexVariable::operator^(const std::complex<double> x)const {

    }

    const ComplexVariable ComplexVariable::operator/(const complex<double> x)const {

    }

    const ComplexVariable ComplexVariable::operator/(const ComplexVariable& x)const {

    }
    double solve(const RealVariable& x) {

    }


    std::complex<double> solve(const ComplexVariable& x) {

    }

};