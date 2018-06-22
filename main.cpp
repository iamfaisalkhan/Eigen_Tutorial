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

void DynamicMatrix() {
  int rows = 3;
  int cols = 4;

  Eigen::Matrix<int, Dynamic, Dynamic> A(rows, cols);
  A << 4, 5, 7, 8,
       8, 9, 10, 1,
       3, 4, 2, 0;

  Eigen::MatrixXi B(rows, cols);
  A << 12, 13, 14, 15,
        7, 8, 9, 10,
        1, 2, 3, 4;

  Eigen::MatrixXi C = Eigen::MatrixXi::Random(rows, cols);

  cout<<A<<endl;
  cout<<B<<endl;
  cout<<C<<endl;

}

void BasicOperations() {

  Eigen::Matrix3f A;
  A << 4, 7, 5,
       8, 9, 1,
       2, 6, 0;

  Eigen::MatrixXf B(3, 3);
  // Matrix of all ones. 
  B.setOnes();

  Eigen::MatrixXf C;

  cout << "Matrix A\n" << A <<endl;
  cout << "Matrix B\n" << B << endl;

  cout << "\nC = A + B" <<endl;
  C = A + B;
  cout << C << endl;

  cout << "\nC = A - B" <<endl;
  C = A - B;
  cout << C << endl;

  cout << "\nC = A * B" << endl;
  C = A * B;
  cout << C << endl;

  cout << "\n A += B" << endl;
  A += B;
  cout << A<<endl;

}

void MatrixVectorOperations() {
  Eigen::Matrix2f A;
  A << 4, 7,
       8, 9;
  Eigen::Vector2f B(2, 1);
  Eigen::Vector2f C(0, 3);

  cout << "Matrix A\n"<<A<<endl;
  cout << "Vector B\n"<<B<<endl;
  cout << "Vector C\n"<<C<<endl;

  cout <<" A * B\n"<<(A * B)<<endl;
  cout <<"B.transpose() * C\n"<<(B.transpose() * C)<<endl;
}

void MatrixScalarOperations() {

  Eigen::MatrixXf A (2, 2);
  A << 4, 7,
       8, 9;

  cout << "A\n"<<A<<endl;
  Eigen::MatrixXf C;
  C = A  * 0.5;
  cout << "\n C = A * 0.5 "<<endl;
  cout << C <<endl;

}

void MatrixReductions() {

  Eigen::Matrix3f A;
  A << 1 , 9, 12,
       14, 7, 8,
       6 , 4, 9;

  cout << "A\n" <<A<<endl;
  cout << "Sum of A = " <<A.sum()<<endl;
  cout << "Max of A = " <<A.maxCoeff()<<endl;
  cout << "Min of A = " <<A.minCoeff()<<endl;
  cout<< "Max of A along rows = " <<A.rowwise().maxCoeff().transpose()<<endl;
  cout<< "Max of A along cols = " <<A.colwise().maxCoeff()<<endl;
  cout<< "Min of A along rows = " <<A.rowwise().minCoeff().transpose()<<endl;
  cout<< "Min of A along cols = " <<A.colwise().minCoeff()<<endl;
  cout << "Sum of diagonal elements = " <<A.trace()<<endl;

}

void ArrayExample() {
  Eigen::ArrayXXd A(2, 2);
  A << 1, 4,
       8, 9;
  Eigen::ArrayXXd B(2, 2);
  B << 2, 5,
       1, 3;

  cout << "Array A \n"<<A<<endl;
  cout << "Array B \n"<<B<<endl;
  cout <<"Element wise multiplication of array A and B\n"<< (A * B)<<endl;

  Eigen::MatrixXf Am(2, 2);
  Am << 1, 4,
       8, 9;
  Eigen::MatrixXf Bm(2, 2);
  Bm << 2, 5,
       1, 3;
  cout << "Matrix A \n"<<Am<<endl;
  cout << "Matrix B \n"<<Am<<endl;
  cout << "Element wise multiplication of matrix A and B using array interface\n"<<(Am.array() * Bm.array())<<endl;

}

void IntializeExamles() {
  Matrix2f A = ArrayXXf::Zero(2, 2);
  cout<<"2 by 2 Array initialized with zeros\n"<<A<<endl;// 0 0
                                                        //  0 0

  Matrix3f B = Matrix3f::Zero(3, 3);
  cout<<B<<endl;

  Matrix3f C = Matrix3f::Ones(3, 3);
  cout<<C<<endl;

  Matrix3f D = Matrix3f::Random(3, 3);
  cout<<D<<endl;

}

void InterfaceExistingData() {
  int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  cout<<"Raw data"<<endl;
  for (int i = 0; i < 10; i++)
    printf("%d ", data[i]);

  cout<<"\nColumn Major 3 by 3 Matrix"<<endl;
  Map<Matrix<int, 3, 3>> A(data);
  cout<<A<<endl;

  cout<<"Row Major 3 by 3 Matrix"<<endl;
  Map<Matrix<int, 3, 3, RowMajor>> B(data);
  cout<<B<<endl;
}

void InterfaceExistingDataStride() {
  int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  cout<<"Raw data"<<endl;
  for (int i = 0; i < 8; i++)
    printf("%d ", data[i]);

  cout<<"\nColumn Major 3 by 2 Matrix with Stride of 1"<<endl;
  Map<Matrix<int, 3, 2>, 0, Stride<6, 2>> A(data);
  cout<<A<<endl;


  cout<<"\nColumn Major 3 by 2 Matrix with Stride of 1"<<endl;
  Map<Matrix<int, 2, 3, RowMajor>, 0, Stride<6, 2>> B(data);
  cout<<B<<endl;
}

void Broadcasting() {
  int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  Map<Matrix3i> A(data);
  cout<<"Matrix A \n"<<A<<endl;

  Vector3i B;
  B << 4, 5, 6;
  cout<<"Vector B\n"<<B<<endl;

  cout<<"Broadcast to columns \n"<<A.colwise()+B<<endl;
  cout<<"Broadcast to rows \n"<<A.rowwise()+B.transpose()<<endl;
}


void BlockOperations() {
  int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  Map<Matrix3i> A(data);
  cout<<"Matrix A \n"<<A<<endl;

  cout<<"Block of size 2, 2 starting at 1, 1\n"<<A.block(1, 1, 2, 2)<<endl;

  cout<<"Row 1 of the Matrix A.row(0)\n"<<A.row(0)<<endl;

  A.row(0) = A.row(0) * 3;

  cout<<"A.row(0)*3\n"<<A<<endl;
}

void SlicingOperations() {

  Matrix4i A;
  A << 1, 2, 3, 4,
       5, 6, 7, 8,
       9, 10, 11, 12,
       13, 14, 15, 16;
  cout<<"Original Matrix \n"<<A<<endl;

  Map<MatrixXi> B(A.data(), 4, 2);

  cout<<"Slicing first two columns \n"<<B<<endl;

  Map<MatrixXi> C(A.data()+8, 4, 2);
  cout<<"Slicing last two columns \n"<<C<<endl;
}

void SlicingOperationsStride() {

  Matrix4i A;
  A << 1, 2, 3, 4,
       5, 6, 7, 8,
       9, 10, 11, 12,
       13, 14, 15, 16;
  cout<<"Original Matrix \n"<<A<<endl;

  cout<<"Slicing first two columns\n"<<Map<MatrixXi, 0, OuterStride<8>>(A.data(), 4, 2)<<endl;;
  cout<<"Slicig first and third columns\n"<<Map<MatrixXi, 0, OuterStride<>>(A.data(), 4, 2, OuterStride<>(8))<<endl;
  cout<<"Slicing first two rows\n"<<Map<MatrixXi, 0, OuterStride<4>>(A.data(), 2, 4)<<endl;
  cout<<"Slicing first and third rows\n"<<Map<MatrixXi, 0, Stride<4, 2>>(A.data(), 2, 4)<<endl;

}


int main() {
	cout<<"\nExample 1. : A + B.transpose()\n";
	cout<<"_______________________________________________\n";

  QuickExample();

  cout<<"\nExample 2. Declaring Dyanmic Matrices\n";
  cout<<"_______________________________________________\n";
  DynamicMatrix();

  cout<<"\nExample 3. Basic Operations\n";
  cout<<"_______________________________________________\n";
  BasicOperations();

  cout<<"\nExample 4. Matrix Vector Operations\n";
  cout<<"_______________________________________________\n";
  MatrixVectorOperations();

  cout<<"\nExample 5. Matrix Scalar Operations\n";
  cout<<"_______________________________________________\n";
  MatrixScalarOperations();

  cout<<"\nExample 6. Matrix Reduction Operations\n";
  cout<<"_______________________________________________\n";
  MatrixReductions();

  cout<<"\nExample 7. Array Example\n";
  cout<<"_______________________________________________\n";
  ArrayExample();

  cout<<"\nExample 8. Initialize Examples\n";
  cout<<"_______________________________________________\n";
  IntializeExamles();

  cout<<"\nExample 9. Interface existing data \n";
  cout<<"_______________________________________________\n";
  InterfaceExistingData();

  cout<<"\nExample 10. Interface existing data with Strides\n";
  cout<<"_______________________________________________\n";
  InterfaceExistingDataStride();

  cout<<"\nExample 11. Broadcasting \n";
  cout<<"_______________________________________________\n";
  Broadcasting();

  cout<<"\nExample 12. Block Operations \n";
  cout<<"_______________________________________________\n";
  BlockOperations();

  cout<<"\nExample 13. Slicing Operations \n";
  cout<<"_______________________________________________\n";
  SlicingOperations();

  cout<<"\nExample 14. Slicing Operations \n";
  cout<<"_______________________________________________\n";
  SlicingOperationsStride();
}
