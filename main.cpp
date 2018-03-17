//

// Header file for dense example. 
#include <iostream>

#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

void QuickExample() {
	Eigen::MatrixXi A(2, 3);
  A <<  1, 1, 1,
        0, 1, 0;
  cout << "Matrix A\n" << A <<endl;
  Eigen::MatrixXi B(3, 2);
  B << 2, 0,
       3, 0,
       1, 2;
	cout << "Matrix B \n" << B <<endl;

	Eigen::MatrixXi C = A + B.transpose();
  cout<<"A + B.transpose() \n" << C<<endl;
}



int main() {
	cout<<"\nA simple matrix example : A + B.transpose()\n";
	cout<<"_______________________________________________\n";

  QuickExample();

  cout<<"\nA typedef example\n";
  cout<<"_______________________________________________\n";
  MatrixTypeDefs();
}
