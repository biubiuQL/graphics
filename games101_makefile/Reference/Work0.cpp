#include <cmath>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>

using namespace std;
int main()
{
    Eigen::Vector3f Point3D(2.0f, 1.0f, 1.0f);

    float theta = 45.0f*M_PI/180.0f;

    Eigen::Matrix3f RotateMatrix;
    RotateMatrix<<cos(theta), -sin(theta), 0, sin(theta), cos(theta), 0, 0, 0, 1;

    Eigen::Matrix3f MoveMatrix;
    MoveMatrix<<1, 0, 1, 0, 1, 2, 0, 0, 1;

    std::cout<<MoveMatrix*RotateMatrix*Point3D;

    return 0;
}
