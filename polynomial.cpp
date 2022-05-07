#include "polynomial.h"


Polynomial::Polynomial() {}

Polynomial::Polynomial(int degree_) : coefficients_(degree_) {}

Polynomial::Polynomial(std::initializer_list<int> numbers_) {
    coefficients_.assign(std::begin(numbers_), std::end(numbers_));
}

Polynomial::Polynomial(const Polynomial& other) : coefficients_(other.coefficients_) {}

Polynomial& Polynomial::operator=(const Polynomial& other) {
    coefficients_ = other.coefficients_;
    return *this;
}

bool operator==(const Polynomial& left_obj, const Polynomial& right_obj) {
    return (left_obj.coefficients_ == right_obj.coefficients_);
}

bool operator!=(const Polynomial& left_obj, const Polynomial& right_obj) {
    return !(left_obj == right_obj);
}

Polynomial Polynomial::operator+=(const Polynomial other) {
    if (other.degree() > this->degree()){
        coefficients_.resize(other.degree(), 0);
    }
    for (size_t i = 0; i <= other.degree(); ++i)
        coefficients_[i] += other.coefficients_[i];
    return *this;
}

Polynomial Polynomial::operator+(const Polynomial& other) {
    *this += other;
    return *this;
}

Polynomial operator+(const Polynomial& left_obj, const Polynomial& right_obj) {
    Polynomial addiction(left_obj);
    addiction += right_obj;
    return addiction;
}

Polynomial Polynomial::operator-=(const Polynomial& other) {
    if (other.degree() > this->degree()){
        coefficients_.resize(other.degree(), 0);
    }
    for (size_t i = 0; i <= other.degree(); ++i)
        coefficients_[i] -= other.coefficients_[i];
    return *this;
}

Polynomial Polynomial::operator-(const Polynomial& other) {
    *this -= other;
    return *this;
}

Polynomial operator-(const Polynomial& left_obj, const Polynomial& right_obj) {
    Polynomial subtraction(left_obj);
    subtraction -= right_obj;
    return subtraction;
}

Polynomial Polynomial::operator*=(const Polynomial& other) {
    std::vector<int> multiplication(this->coefficients_.size() + other.coefficients_.size() - 1, 0);
    for (size_t i = 0; i < this->coefficients_.size(); ++i) {
        for(size_t j = 0; j < other.coefficients_.size(); ++j) {
            multiplication[i + j] += this->coefficients_[i] * other.coefficients_[j];
        }
    }
    this->coefficients_.swap(multiplication);
    return *this;
}

Polynomial Polynomial::operator*(const Polynomial& other) {
    Polynomial multiplication(*this);
    multiplication *= other;
    return multiplication;
}
Polynomial Polynomial::operator*=(int value) {
    for (int i = 0; i < this->coefficients_.size(); ++i) {
        coefficients_[i] *= value;
    }
    return *this;
}

Polynomial Polynomial::operator*(int value) {
    *this *= value;
    return *this;
}

Polynomial Polynomial::operator/=(int value) {
    for (int i = 0; i < this->coefficients_.size(); ++i) {
        coefficients_[i] /= value;
    }
    return *this;
}

Polynomial Polynomial::operator/(int value) {
    *this /= value;
    return *this;
}

int Polynomial::operator[](size_t i) {
    return coefficients_[i];
}

const int& Polynomial::operator[](size_t i) const {
    return coefficients_[i];
}

std::ostream& operator<<(std::ostream &os, const Polynomial& object) {
    os << object[object.degree()] << "x^" << object.degree();
    for (size_t i = object.degree() - 1; i > 0; --i){
        if (object[i] > 0){
            os << " + " << object[i] << "x^" << i;
        }
        else
            os << " " << object[i] << "x^" << i;
    }
    if (object[0] > 0)
        os << " + " << object[0];
    else
        os << " " << object[0];
}

Polynomial& operator>>(std::istream &is, Polynomial& object) {
    int number;
    object.coefficients_.clear();
    while(is >> number){
        object.coefficients_.push_back(number);
    }
    return object;
}

Polynomial::~Polynomial() {}

size_t Polynomial::degree() const {
    return coefficients_.size() - 1;
}

