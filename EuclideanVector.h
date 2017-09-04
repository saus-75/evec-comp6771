#ifndef EVEC_H
#define EVEC_H

namespace evec {
    class EuclideanVector {
    public:
        //basic constructor
        EuclideanVector();

        EuclideanVector(unsigned int dim);

        //7 specific constructor

        //destructor
        ~EuclideanVector();
    
        //copy constructor
        EuclideanVector(const EuclideanVector& euclideanVector);

        //move constructor
        EuclideanVector(EuclideanVector&& euclideanVector);

        //get dimension size
        static inline unsigned int getNumDimension();

        //get magnitude at index
        static inline double get(unsigned int i);

        //calc norm of the vector
        double getEuclideanNorm();

        //create a new vector by magnitude divided euclidean norm
        EuclideanVector createUnitVector();
    
    private:        
        unsigned int dimension_;
        unsigned double* magnitude_;            
    };
}

#endif