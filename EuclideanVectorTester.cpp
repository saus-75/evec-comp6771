#include "EuclideanVector.h"

int main() {
	//constructors
	evec::EuclideanVector a(2);
    
    std::list<double> l {1,2,3};
	evec::EuclideanVector b{l.begin(),l.end()};

    std::vector<double> v2 {4,5,6,7};
	evec::EuclideanVector c{v2.begin(),v2.end()};

    std::vector<double> a1 {5,4,3,2,1};
	evec::EuclideanVector d{a1.begin(),a1.end()};

    std::list<double> a2 {9,0,8,6,7};
	evec::EuclideanVector e{a2.begin(),a2.end()};
    
    // std::cout<< a << "\n";
    // std::cout<< b << "\n";
    // std::cout<< c << "\n";
    // std::cout<< d << "\n";
    // std::cout<< e << "\n";
    // evec::EuclideanVector e2{a2.begin(), a2.end()};
    // if (a != b){
    //     std::cout << "a != b is true\n";
    // }
    // if (e == e2){
    //     std::cout << "e == e2 is true\n";
    // }

    // std::cout << "\n";
	// use the copy constructor
	evec::EuclideanVector f{e};
	
	std::cout << a.getNumDimensions() << ": " << a << std::endl;
	std::cout << "D1:" << b.get(1) << " " << b << std::endl;
	std::cout << c << " Euclidean Norm = " << c.getEuclideanNorm() << std::endl;
	std::cout << d << " Unit Vector: " << d.createUnitVector() << " L = " << d.createUnitVector().getEuclideanNorm() << std::endl;
	std::cout << e << std::endl;
	std::cout << f << std::endl;

	// test the move constructor
	evec::EuclideanVector g = std::move(f);
	std::cout << g << std::endl;
	std::cout << f << std::endl;

	// // try operator overloading
	e += d;
	std::cout << e << std::endl;
	evec::EuclideanVector h = e - g;
	std::cout << h << std::endl;

	// test scalar multiplication
	h *= 2;
	std::cout << h << std::endl;
	evec::EuclideanVector j = b / 2;
	std::cout << j << std::endl;
	std::cout << "dot product = " << j * b << std::endl;
	if (g == (e - d)) std::cout << "true" << std::endl;
	if (j != b ) std::cout << "false" << std::endl;
	j[0] = 1;
	std::cout << j << std::endl;

	// type cast from EuclideanVector to a std::vector
	std::vector<double> vj = j;

	// type cast from EuclideanVector to a std::vector
	std::list<double> lj = j;
	for (auto d : lj) {
			std::cout << d << std::endl;
	}

	// list initialisation
	evec::EuclideanVector k {1, 2, 3};
	std::cout << k << std::endl;
}

// The correct output is:
// 2: [0 0]
// D1:2 [1 2 3]
// [4 5 6 7] Euclidean Norm = 11.225
// [5 4 3 2 1] Unit Vector: [0.6742 0.53936 0.40452 0.26968 0.13484] L = 1
// [9 0 8 6 7]
// [9 0 8 6 7]
// [9 0 8 6 7]
// []
// [14 4 11 8 8]
// [5 4 3 2 1]
// [10 8 6 4 2]
// [0.5 1 1.5]
// dot product = 7
// true
// false
// [1 1 1.5]
// 1
// 1
// 1.5
// [1 2 3]

