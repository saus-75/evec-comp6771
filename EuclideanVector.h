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
        EuclideanVector(const unsigned int& dim);

        //Basic dim, mag constructor
        EuclideanVector(const unsigned int& dim, const double& mag);

        //Iterator constructor
        template <typename Itr>
        EuclideanVector(const Itr& start, const Itr& end){
            int dimension_ = std::distance(start, end);
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
        inline unsigned int getNumDimension() const {return dimension_;}

        //get magnitude at index
        inline double get(const unsigned int& i) const {assert(i < dimension_); return magnitude_[i];}

        //calc norm of the vector
        double getEuclideanNorm() const;

        //create a new vector by magnitude divided euclidean norm
        // EuclideanVector& createUnitVector();

        //operator <<
        friend std::ostream& operator<<(std::ostream& out, const EuclideanVector& b);

            
    private:        
        unsigned int dimension_;
        double* magnitude_;            
    };                    
}

#endif