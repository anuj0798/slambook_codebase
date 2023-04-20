#include <iostream>
using namespace std;

#include <ctime>
#include <Eigen/Core>

#include <Eigen/Dense>
using namespace Eigen;

#define MATRIX_SIZE 50


int main(int argc, char **argv){
    Matrix<float, 2, 3> matrix_23;
    Vector3d v_3d;
    Matrix<float, 3, 1> vd_3d;

    Matrix3d matrix_33 = Matrix3d::Zero();

    Matrix<double, Dynamic, Dynamic> matrix_dynamic;
    MatrixXd matrix_x;

    matrix_23 << 1,2,3,4,5,6;

    cout<< "matrix 2X3 from 1 to 6: \n" << matrix_23 << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
        cout << matrix_23(i, j) << "\t";
        cout << endl;
        }

    v_3d << 3,2,1;
    Matrix<double, 2, 1> result = matrix_23.cast<double>() * v_3d;
    cout << result.transpose() << endl; 
    cout << result.sum() << endl;

    matrix_33 = Matrix3d::Random();
    cout<< matrix_33 << endl;
    cout<< endl;

    SelfAdjointEigenSolver<Matrix3d> eigen_solver(matrix_33.transpose()* matrix_33);

    cout << eigen_solver.eigenvalues() << endl;
    cout << eigen_solver.eigenvectors() << endl;

    Matrix <double, MATRIX_SIZE, MATRIX_SIZE> matrix_NN = MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);

    matrix_NN = matrix_NN * matrix_NN.transpose();

    Matrix<double, MATRIX_SIZE, 1> v_Nd = MatrixXd::Random(MATRIX_SIZE, 1);

    clock_t time_stt = clock(); 
    Matrix<double, MATRIX_SIZE, MATRIX_SIZE> x_inv = matrix_NN.inverse();
    Matrix<double, MATRIX_SIZE, 1> x= x_inv * v_Nd;
    cout << (clock() - time_stt) * 1000 / (double)CLOCKS_PER_SEC  <<"ms"<<endl;
    cout << x.transpose() << endl;

    time_stt = clock();
    x = matrix_NN.colPivHouseholderQr().solve(v_Nd);
    cout << (clock() - time_stt) * 1000 / (double)CLOCKS_PER_SEC  <<"ms"<<endl;
    cout << x.transpose() << endl;

    time_stt = clock();
    x = matrix_NN.ldlt().solve(v_Nd);
    cout << (clock() - time_stt) * 1000 / (double)CLOCKS_PER_SEC  <<"ms"<<endl;
    cout << x.transpose() << endl;




















}