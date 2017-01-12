
void Matrix_Basic_Operations()
{
    MatrixXf m1 = MatrixXf::Random(4, 3);
    cout<<m1<<endl;

    cout<< "Reshaping the matrix" <<endl;

    Map<MatrixXf> m2(m1.data(), 6, 2);
    cout<<m2<<endl;

    cout<< "Multiplying matrix with a scalar"<<endl;
    cout<<m1*2<<endl;
}
