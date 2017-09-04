#include <iostream>
#include "EuclideanVector.h"

namespace evec {
    //Constructor - Part 1
    evec::EuclideanVector::EuclideanVector(): EuclideanVector{1} {}

    evec::EuclideanVector::EuclideanVector(unsigned int dim):
        dimension_{dim}
    {
        magnitude_ = new double[dim];
        
        for (int i = 0; i < dim; ++i)
        {
            arr[dim] = 0.0;
            std::cout << dim << " " << arr[dim] << "\n";
        }
    }

    evec::EuclideanVector::EuclideanVector(unsigned int dim, double mag):
        dimension_{dim}
    {
        magnitude_ = new double[dim];
        
        for (int i = 0; i < dim; ++i)
        {
            arr[dim] = mag;
            std::cout << dim << arr[dim] << "\n";
        }
    }
}