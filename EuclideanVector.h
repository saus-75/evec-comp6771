#ifndef EVEC_H
#define EVEC_H

#include <iostream>
#include <algorithm>
#include <cmath>
#include <list>
#include <vector>
#include <iterator>
#include <initializer_list>
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
        EuclideanVector(std::list<double>::iterator start, std::list<double>::iterator end);
        EuclideanVector(std::vector<double>::iterator start, std::vector<double>::iterator end);

        //Initialiser List constructor
        EuclideanVector(std::initializer_list<double> mag);

        //copy constructor
        EuclideanVector(const EuclideanVector& og);

        //move constructor
        EuclideanVector(EuclideanVector&& og);
        
        //destructor
        ~EuclideanVector();

        //member operators
        EuclideanVector& operator= (const EuclideanVector& b);
        EuclideanVector& operator= (EuclideanVector&& b);
        EuclideanVector& operator+= (const EuclideanVector& b);
        EuclideanVector& operator-= (const EuclideanVector& b);
        EuclideanVector& operator*= (const double& b);
        EuclideanVector& operator/= (const double& b);
        inline double operator[] (const unsigned int& b) const { assert(b < dimension_); return this->magnitude_[b]; }
        inline double& operator[] (const unsigned int& b) { assert(b < dimension_); return this->magnitude_[b]; }
        operator std::vector<double>() const;
        operator std::list<double>() const;

        //get dimension size
        inline unsigned int getNumDimensions() const {return dimension_;}

        //get magnitude at index
        inline double get(unsigned int i) const {assert(i < dimension_); return magnitude_[i];}

        //calc norm of the vector
        double getEuclideanNorm() const;

        //create a new vector that contains magnitude divided euclidean norm
        EuclideanVector createUnitVector() const;

        //Non-member operators
        friend std::ostream& operator<<(std::ostream& out, const EuclideanVector& b);
        friend bool operator==(const EuclideanVector& a, const EuclideanVector& b);
        friend bool operator!=(const EuclideanVector& a, const EuclideanVector& b);
        friend EuclideanVector operator+(EuclideanVector a, const EuclideanVector& b);
        friend EuclideanVector operator-(EuclideanVector a, const EuclideanVector& b);
        friend double operator*(const EuclideanVector& a, const EuclideanVector& b);
        friend EuclideanVector operator*(EuclideanVector a, const double& b);
        friend EuclideanVector operator*(const double& b, EuclideanVector a);
        friend EuclideanVector operator/(EuclideanVector a, const double& b);

    private:        
        unsigned int dimension_;
        double* magnitude_;            
    };

    //Non member function operators
    std::ostream& operator<<(std::ostream& out, const EuclideanVector& b);  
    bool operator==(const EuclideanVector& a, const EuclideanVector& b);
    bool operator!=(const EuclideanVector& a, const EuclideanVector& b);
    EuclideanVector operator+(EuclideanVector a, const EuclideanVector& b);
    EuclideanVector operator-(EuclideanVector a, const EuclideanVector& b);
    double operator*(const EuclideanVector& a, const EuclideanVector& b);
    EuclideanVector operator*(EuclideanVector a, const double& b);
    EuclideanVector operator*(const double& b, EuclideanVector a);
    EuclideanVector operator/(EuclideanVector a, const double& b);

}

#endif