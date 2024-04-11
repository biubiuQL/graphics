#include <cmath>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>
using namespace std;
// 给定一个点 P=(2,1), 将该点绕原点先逆时针旋转45度，再平移 （1,2），计算出变换后点的坐标（要求用齐次坐标进行计算）。
int main()
{
    Eigen::Matrix3f mat;
    float radian = M_PI / 180 * 45;
    mat << cos(radian), -sin(radian), 1, sin(radian), cos(radian), 2, 0, 0, 1;
    Eigen::Vector3f v3(2, 1, 1);
    Eigen::Vector3f out = mat * v3;

    cout << out;
    return 0;
}
