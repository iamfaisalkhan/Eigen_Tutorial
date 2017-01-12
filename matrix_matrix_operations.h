
void Matrix_Matrix_Operations()
{
    MatrixXi A(2, 3);
    A<<1, 1, 1,
        0, 1, 0;

    MatrixXi B(3, 2);
    B<<2, 0,
       3, 0,
       1, 2;

    cout<<"A\n" <<A<<endl;
    cout<<"B\n" <<B<<endl;

    // cout<<"A*B\n"<< A*B <<endl;

    B.conservativeResize(2, 3);
    cout<<B<<endl;
    cout<<"Element wise A*B\n"<<endl;
    cout<<A.array() * B.array()<<endl;

}