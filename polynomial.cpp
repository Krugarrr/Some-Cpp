#include "polynomial.h"

void fft(std::vector<base> &a, bool invert) {
    int size = a.size();
    if (size == 1) {
        return;
    }

    std::vector<base> a0 (size / 2),  a1 (size / 2);
    for (int i=0, j=0; i < size; i += 2, ++j) {
        a0[j] = a[i];
        a1[j] = a[i+1];
    }
    fft (a0, invert);
    fft (a1, invert);

    double ang = 2 * std::numbers::pi_v<double> / size * (invert ? -1 : 1);
    base w (1),  wn (cos(ang), sin(ang));
    for (int i=0; i < size / 2; ++i) {
        a[i] = a0[i] + w * a1[i];
        a[i + size / 2] = a0[i] - w * a1[i];
        if (invert)
            a[i] /= 2,  a[i + size / 2] /= 2;
        w *= wn;
    }
}

void multiply(const std::vector<int> & a, const std::vector<int> & b, std::vector<int> & res) {
    std::vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
    size_t n = 1;
    while (n < std::max(a.size(), b.size()))  n <<= 1;
    n <<= 1;
    fa.resize (n),  fb.resize (n);

    fft (fa, false),  fft (fb, false);
    for (size_t i=0; i<n; ++i)
        fa[i] *= fb[i];
    fft (fa, true);

    res.resize (n);
    for (size_t i=0; i<n; ++i)
        res[i] = int (fa[i].real() + 0.5);
}


Polynomial::Polynomial() {}

Polynomial::Polynomial(int degree_) : coefficients_(degree_) {}

Polynomial::Polynomial(std::initializer_list<int> numbers_) {
    coefficients_.assign(std::begin(numbers_), std::end(numbers_));
    cleaning();
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
    //cleaning();
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
    cleaning();
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
    multiply(this->coefficients_, other.coefficients_, multiplication);
    this->coefficients_.swap(multiplication);
    cleaning();
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
    cleaning();
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
    if (object.degree() == 0) {
        os << object[object.degree()];
        return os;
    }
    else {
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

void Polynomial::cleaning() {
    if (coefficients_.size() == 1) {
        return;
    }
    auto it = std::find_if(coefficients_.begin() + 1, coefficients_.end(), [](auto i) { return 0 == i; });
    coefficients_.erase(it, coefficients_.end());
}

