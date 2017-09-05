#include <iostream>
#include <cmath>
#include "EuclideanVector.h"

namespace evec {
    //Constructor - Part 1 - Less than basic
    evec::EuclideanVector::EuclideanVector(): EuclideanVector{1} {}

    evec::EuclideanVector::EuclideanVector(unsigned int dim): EuclideanVector {dim, 0.0} {}

    //Constructor - Part 2 - Basic
    evec::EuclideanVector::EuclideanVector(unsigned int dim, double mag):
        dimension_{dim}
    {
        magnitude_ = new double[dim];
        
        for (int i = 0; i < dim; ++i)
        {
            arr[i] = mag;
            std::cout << dim << arr[i] << "\n";
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
        delete [] arr;
    }

    //Euclidean Norm
    double evec::EuclideanVector::getEuclideanNorm(){
        double norm = 0.0;
        for (int i = 0; i < dim_; ++i){
            norm += std::pow(arr[i], 2);
        }
        norm = std::sqrt(norm);
        return norm;
    }

    evec::EuclideanVector evec::EuclideanVector::createUnitVector(){
        double en = getEuclideanNorm();
        
    }
}