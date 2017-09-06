#include "EuclideanVector.h"

//Constructor - Part 1 - Less than basic
evec::EuclideanVector::EuclideanVector(): EuclideanVector(1) {}

evec::EuclideanVector::EuclideanVector(unsigned int dim): EuclideanVector (dim, 0.0) {}

//Constructor - Part 2 - Basic
evec::EuclideanVector::EuclideanVector(unsigned int dim, double mag): dimension_{dim} {
    std::cout << "Constructing with dim and mag\n";
    magnitude_ = new double[dim];
    
    for (auto i = 0U; i < dimension_; ++i)
    {
        magnitude_[i] = mag;
    }
}

//Constructor - Part 3 - Iterator
evec::EuclideanVector::EuclideanVector(std::list<double>::iterator start, std::list<double>::iterator end){
    std::cout << "List iterator constructor\n";
    dimension_ = std::distance(start, end);
    magnitude_ = new double[dimension_];
    std::copy(start, end, magnitude_);
}

evec::EuclideanVector::EuclideanVector(std::vector<double>::iterator start, std::vector<double>::iterator end){
    std::cout << "Vector iterator constructor\n";
    dimension_ = std::distance(start, end);
    magnitude_ = new double[dimension_];
    std::copy(start, end, magnitude_);
}

//Constructor - Part 4 - initialiser list
evec::EuclideanVector::EuclideanVector(std::initializer_list<double> mag){
    std::cout << "Initializer list constructor\n";
    dimension_ = std::distance(mag.begin(),mag.end());
    magnitude_ = new double[dimension_];
    std::copy(mag.begin(), mag.end(), magnitude_);
}

//Constructor - copy
evec::EuclideanVector::EuclideanVector(const evec::EuclideanVector& og): dimension_{og.dimension_} {
    std::cout << "copy constructor\n";
    magnitude_ = new double[dimension_];
    for (auto i = 0U; i < dimension_; ++i){
        magnitude_[i] = og.magnitude_[i];
    }
}

//Constructor - move

//Deconstructor
evec::EuclideanVector::~EuclideanVector(){
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
double evec::EuclideanVector::getEuclideanNorm() const{
    double norm = 0;
    for (auto i = 0U; i < dimension_; i++){
        norm += std::pow(magnitude_[i], 2);
    }
    norm = std::sqrt(norm);
    return norm;
}

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
    assert(b.dimension_ != 0);
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

