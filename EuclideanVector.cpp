#include "EuclideanVector.h"

//Constructor - Part 1 - Less than basic
evec::EuclideanVector::EuclideanVector(): 
    EuclideanVector(1) {}

evec::EuclideanVector::EuclideanVector(unsigned int dim): 
    EuclideanVector (dim, 0.0) {}

//Constructor - Part 2 - Basic
evec::EuclideanVector::EuclideanVector(unsigned int dim, double mag): 
    dimension_{dim} {
    magnitude_ = new double[dim];
    
    for (auto i = 0U; i < dimension_; ++i)
    {
        magnitude_[i] = mag;
    }
}

//Constructor - Part 3 - Iterator
evec::EuclideanVector::EuclideanVector(std::list<double>::iterator start, std::list<double>::iterator end){
    dimension_ = std::distance(start, end);
    magnitude_ = new double[dimension_];
    std::copy(start, end, magnitude_);
}

evec::EuclideanVector::EuclideanVector(std::vector<double>::iterator start, std::vector<double>::iterator end){
    dimension_ = std::distance(start, end);
    magnitude_ = new double[dimension_];
    std::copy(start, end, magnitude_);
}

//Constructor - Part 4 - initialiser list
evec::EuclideanVector::EuclideanVector(std::initializer_list<double> mag){
    dimension_ = std::distance(mag.begin(),mag.end());
    magnitude_ = new double[dimension_];
    std::copy(mag.begin(), mag.end(), magnitude_);
}

//Constructor - copy
evec::EuclideanVector::EuclideanVector(const evec::EuclideanVector& og): 
    dimension_{og.dimension_} {
    magnitude_ = new double[dimension_];
    for (auto i = 0U; i < dimension_; ++i){
        magnitude_[i] = og.magnitude_[i];
    }
}

//Constructor - move
evec::EuclideanVector::EuclideanVector(evec::EuclideanVector&& og): 
    dimension_{ std::move(og.dimension_) } {
    magnitude_ = std::move(og.magnitude_);

    og.dimension_ = 0;
    og.magnitude_ = new double[0];
}

//Deconstructor
evec::EuclideanVector::~EuclideanVector(){
    delete [] magnitude_;
}

//Copy assignment
evec::EuclideanVector& evec::EuclideanVector::operator= (const evec::EuclideanVector& b){
    if (*this != b){
        if(magnitude_){ delete [] magnitude_; }
        dimension_ = b.dimension_;
        magnitude_ = new double[dimension_];

        for (auto i = 0U; i < dimension_; ++i){
            magnitude_[i] = b.magnitude_[i];
        }
    }
    return *this;
}

//Move assignment
evec::EuclideanVector& evec::EuclideanVector::operator= (evec::EuclideanVector&& b){
    if (*this != b){
        if(magnitude_){ delete [] magnitude_; }
        dimension_ = std::move(b.dimension_);
        magnitude_ = std::move(b.magnitude_);
    }
    b.dimension_ = 0;
    b.magnitude_ = new double[0];
    return *this;
}

//Operator +=
evec::EuclideanVector& evec::EuclideanVector::operator+= (const evec::EuclideanVector& b){
    assert(dimension_ == b.dimension_);
    for (auto i = 0U; i < dimension_; i++){
        magnitude_[i] += b.magnitude_[i];
    }
    return *this;
}

//Operator -=
evec::EuclideanVector& evec::EuclideanVector::operator-= (const evec::EuclideanVector& b){
    assert(dimension_ == b.dimension_);
    for (auto i = 0U; i < dimension_; i++){
        magnitude_[i] -= b.magnitude_[i];
    }
    return *this;
}

//Operator *=
evec::EuclideanVector& evec::EuclideanVector::operator*= (const double& b){
    for (auto i = 0U; i < dimension_; i++){
        magnitude_[i] *= b;
    }
    return *this;
}

//Operator /=
evec::EuclideanVector& evec::EuclideanVector::operator/= (const double& b){
    for (auto i = 0U; i < dimension_; i++){
        magnitude_[i] /= b;
    }
    return *this;
}

//Type casting to vector
evec::EuclideanVector::operator std::vector<double>() const{
    std::vector<double> cast_vec;

    for (auto i = 0U; i < dimension_; ++i){
        cast_vec.push_back(magnitude_[i]);
    }

    return cast_vec;
}

//Type casting to list
evec::EuclideanVector::operator std::list<double>() const{
    std::list<double> cast_l;
    for (auto i = 0U; i < dimension_; ++i){
        cast_l.push_back(magnitude_[i]);
    }

    return cast_l;
}

//Euclidean Norm
double evec::EuclideanVector::getEuclideanNorm() const{
    double norm = 0;
    for (auto i = 0U; i < dimension_; i++){
        norm += std::pow(magnitude_[i], 2);
    }
    norm = std::sqrt(norm);
    return norm;
}

//Create Unit Vector
evec::EuclideanVector evec::EuclideanVector::createUnitVector() const{
    auto norm = getEuclideanNorm();
    assert (norm != 0);
    evec::EuclideanVector retVec(dimension_);
    for (auto i = 0U; i < dimension_; ++i){
        retVec.magnitude_[i] = magnitude_[i]/norm;
    }
    return retVec;
}

//Operator <<
std::ostream& evec::operator<<(std::ostream& out, const evec::EuclideanVector& b){
    auto dim = b.dimension_;
    out << "[";
    for (auto i = 0U; i < dim; i++){
        if (i != (dim - 1)){
            out << b.magnitude_[i] << " ";
        } else {
            out << b.magnitude_[i];
        }
    }  
    out << "]";
    return out;
}

//Operator ==
bool evec::operator==(const evec::EuclideanVector& a, const evec::EuclideanVector& b){
    if (a.dimension_ == b.dimension_){
        for (auto i = 0U; i < a.dimension_; ++i){
            if (a.magnitude_[i] != b.magnitude_[i]){
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}

//Operator !=
bool evec::operator!=(const evec::EuclideanVector& a, const evec::EuclideanVector& b){
    if (a == b){
        return false;
    } else {
        return true;
    }
}

//Operator +
evec::EuclideanVector evec::operator+(evec::EuclideanVector a, const evec::EuclideanVector& b){
    assert(a.dimension_ == b.dimension_);
    for (auto i = 0U; i < a.dimension_; i++){
        a.magnitude_[i] += b.magnitude_[i];
    }
    return a;
}

//Operator -
evec::EuclideanVector evec::operator-(evec::EuclideanVector a, const evec::EuclideanVector& b){
    assert(a.dimension_ == b.dimension_);
    for (auto i = 0U; i < a.dimension_; i++){
        a.magnitude_[i] -= b.magnitude_[i];
    }
    return a;
}

//Operator *

//1.0
double evec::operator*(const evec::EuclideanVector& a, const evec::EuclideanVector& b){
    assert(a.dimension_ == b.dimension_);
    double sol = 0;
    for (auto i = 0U; i < a.dimension_; i++){
        sol += a.magnitude_[i] * b.magnitude_[i];
    }
    return sol;
}

//2.1
evec::EuclideanVector evec::operator*(evec::EuclideanVector a, const double& b){
    for (auto i = 0U; i < a.dimension_; i++){
        a.magnitude_[i] *= b;
    }
    return a;
}

//2.2
evec::EuclideanVector evec::operator*(const double& b, evec::EuclideanVector a){
    for (auto i = 0U; i < a.dimension_; i++){
        a.magnitude_[i] *= b;
    }
    return a;
}

//Operator /
evec::EuclideanVector evec::operator/(evec::EuclideanVector a, const double& b){
    assert(b != 0);
    for (auto i = 0U; i < a.dimension_; i++){
        a.magnitude_[i] /= b;
    }
    return a;
}

