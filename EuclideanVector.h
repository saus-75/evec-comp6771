#ifndef EVEC_H
#define EVEC_H

#include <iostream>
#include <iterator>
#include <algorithm>
#include <assert.h>

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
            std::cout << "Iterator constructor\n";
            dimension_ = std::distance(start, end);
            magnitude_ = new double[dimension_];
            std::copy(start, end, magnitude_);
        }

        //destructor
        ~EuclideanVector();
    
        // //copy constructor
        // EuclideanVector(const EuclideanVector& euclideanVector);

        // //move constructor
        // EuclideanVector(EuclideanVector&& euclideanVector);

        //operator +=
        EuclideanVector& operator+= (const EuclideanVector& b);

        //operator -=
        EuclideanVector& operator-= (const EuclideanVector& b);

        //operator *=
        EuclideanVector& operator*= (const double& b);
        
        //operator /=
        EuclideanVector& operator/= (const double& b);

        //get dimension size
        inline unsigned int getNumDimensions() {return dimension_;}

        //get magnitude at index
        inline double get(unsigned int i) {assert(i < dimension_); return magnitude_[i];}

        //calc norm of the vector
        double getEuclideanNorm();

        //create a new vector by magnitude divided euclidean norm
        // EuclideanVector& createUnitVector();

        //operator <<
        friend std::ostream& operator<<(std::ostream& out, const EuclideanVector& b);

            
    private:        
        unsigned int dimension_;
        double* magnitude_;            
    };
    std::ostream& operator<<(std::ostream& out, const EuclideanVector& b);                    
}

#endif