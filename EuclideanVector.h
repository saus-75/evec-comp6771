#ifndef EVEC_H
#define EVEC_H

#include <iterator>
#include <algorithm>

namespace evec {
    class EuclideanVector {
    public:
        //default constructor
        EuclideanVector();

        //Basic dim constructor
        EuclideanVector(unsigned int dim);

        //Basic dim, mag constructor
        EuclideanVector(unsigned int dim, double mag);

        //Iterator constructor
        template <typename Itr>
        EuclideanVector(Itr start, Itr end){
            int dimension_ = std::distance(start, end);
            magnitude_ = new double[dimension_];
            std::copy(start, end, magnitude_);
        }

        //destructor
        ~EuclideanVector();
    
        //copy constructor
        EuclideanVector(const EuclideanVector& euclideanVector);

        //move constructor
        EuclideanVector(EuclideanVector&& euclideanVector);

        //get dimension size
        inline unsigned int getNumDimension() {return dimension_; }

        //get magnitude at index
        inline double get(unsigned int i) { return magnitude_[i] };

        //calc norm of the vector
        double getEuclideanNorm();

        //create a new vector by magnitude divided euclidean norm
        EuclideanVector createUnitVector();
    
    private:        
        unsigned int dimension_;
        double* magnitude_;            
    };
}

#endif