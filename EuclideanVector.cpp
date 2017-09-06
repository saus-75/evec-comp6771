#include <iostream>
#include <cmath>
#include "EuclideanVector.h"

//Constructor - Part 1 - Less than basic
evec::EuclideanVector::EuclideanVector(): EuclideanVector{1} {}

evec::EuclideanVector::EuclideanVector(unsigned int dim): EuclideanVector {dim, 0.0} {}

//Constructor - Part 2 - Basic
evec::EuclideanVector::EuclideanVector(unsigned int dim, double mag):
    dimension_{dim}
{
    std::cout << "Constructing with dim and mag\n";
    magnitude_ = new double[dim];
    
    for (auto i = 0U; i < dimension_; ++i)
    {
        magnitude_[i] = mag;
    }
}

//Constructor - Part 3 - Iterator - in .h file

//Constructor - Part 4 - initialiser list

//Constructor - copy

//Constructor - move

//Deconstructor
evec::EuclideanVector::~EuclideanVector()
{
    std::cout << "Deconstructing\n";
    delete [] magnitude_;
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

//Euclidean Norm
double evec::EuclideanVector::getEuclideanNorm(){
    double norm = 0;
    for (auto i = 0U; i < dimension_; i++){
        norm += std::pow(magnitude_[i], 2);
    }
    norm = std::sqrt(norm);
    return norm;
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




