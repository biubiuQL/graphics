#include "Triangle.cpp"
#include "rasterizer.cpp"
#include <Eigen/Eigen>
#include <iostream>
#include <opencv.hpp>
using namespace std;

constexpr double MY_PI = 3.1415926;

Eigen::Matrix4f get_view_matrix(Eigen::Vector3f eye_pos)
{
    Eigen::Matrix4f view = Eigen::Matrix4f::Identity();

    Eigen::Matrix4f translate;
    translate << 1, 0, 0, -eye_pos[0], 0, 1, 0, -eye_pos[1], 0, 0, 1,
        -eye_pos[2], 0, 0, 0, 1;

    view = translate * view;

    return view;
}

Eigen::Matrix4f get_model_matrix(float rotation_angle)
{
    Eigen::Matrix4f model = Eigen::Matrix4f::Identity();

    // TODO: Implement this function
    // Create the model matrix for rotating the triangle around the Z axis.
    // Then return it.
    Eigen::Matrix4f translate;

    translate << cos(rotation_angle / 180 * acos(-1)), -sin(rotation_angle / 180 * acos(-1)), 0, 0,
        sin(rotation_angle / 180 * acos(-1)), cos(rotation_angle / 180 * acos(-1)), 0, 0,
        0, 0, 1, 0, 
        0, 0, 0, 1;

    model = translate * model;

    return model;
}

Eigen::Matrix4f get_projection_matrix(float eye_fov, float aspect_ratio,
                                      float zNear, float zFar)
{
    // Students will implement this function

    Eigen::Matrix4f projection = Eigen::Matrix4f::Identity();

    // TODO: Implement this function
    // Create the projection matrix for the given parameters.
    // Then return it.
    // perspective to orthographic
    Eigen::Matrix4f p2o;
    p2o << zNear, 0, 0, 0,
        0, zNear, 0, 0,
        0, 0, zNear + zFar, -zNear * zFar,
        0, 0, 1, 0;
    float zTop = tan(eye_fov * 0.5) * abs(zNear);
    float zRight = zTop * aspect_ratio;
    float zLeft = -zRight;
    float zBottom = -zTop;


    Eigen::Matrix4f orthoT;
    orthoT << 1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, -(zNear + zFar) * 0.5,
        0, 0, 0, 1;

    Eigen::Matrix4f orthoS;
    orthoS << 2 / (zRight - zLeft), 0, 0, 0,
        0, 2 / (zTop - zBottom), 0, 0,
        0, 0, 2 / (zNear - zFar), 0,
        0, 0, 0, 1;
    projection = orthoS * orthoT * p2o * projection;
    return projection;
}

Eigen::Matrix4f get_rotation(Vector3f axis, float angle)
{
    Eigen::Matrix4f rotate = Eigen::Matrix4f::Identity();
    Eigen::Matrix3f A1;
    Eigen::Matrix3f A2;
    Eigen::Matrix3f A3;
    A1 << 1, 0, 0,
        0, 1, 0,
        0, 0, 1;
    A1 = cos(angle / 180 * acos(-1)) * A1;
    A2 = axis * axis.transpose();
    A2 = (1 - cos(angle / 180 * acos(-1))) * A2;
    float nx = axis[0], ny = axis[1], nz = axis[2];
    A3 << 0, -nz, ny,
        nz, 0, -nx,
        -ny, nx, 0;
    A3 = sin(angle / 180 * acos(-1)) * A3;
    rotate.block<3, 3>(0, 0) = A1 + A2 + A3;
    rotate(0, 3) = 0.0f;
    rotate(1, 3) = 0.0f;
    rotate(2, 3) = 0.0f;
    rotate(3, 3) = 1.0f;
    return rotate;
}

int main(int argc, const char **argv)
{
    float angle = 0;
    bool command_line = false;
    std::string filename = "output.png";

    if (argc >= 3)
    {
        command_line = true;
        angle = std::stof(argv[2]); // -r by default
        if (argc == 4)
        {
            filename = std::string(argv[3]);
        }
        else
            return 0;
    }
    // 屏幕大小
    rst::rasterizer r(700, 700);
    // 人眼位置
    Eigen::Vector3f eye_pos = {0, 0, 0};
    // 三角形的三个顶点
    std::vector<Eigen::Vector3f> pos{{2, 0, -2}, {0, 2, -2}, {-2, 0, -2}};

    std::vector<Eigen::Vector3i> ind{{0, 1, 2}};

    auto pos_id = r.load_positions(pos);
    auto ind_id = r.load_indices(ind);

    int key = 0;
    int frame_count = 0;
    std::vector<Eigen::Vector3f> a = r.frame_buffer();
    if (command_line)
    {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_model_matrix(angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);
        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);

        cv::imwrite(filename, image);

        return 0;
    }

    while (key != 27)
    {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);
        // 绕Z轴
        r.set_model(get_model_matrix(angle));
        // 绕axis轴
        // Eigen::Vector3f axis(2.0f, 3.0f, 3.0f);
        // r.set_model(get_rotation(axis, angle));

        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);

        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);
        cv::imshow("image", image);
        key = cv::waitKey(10);

        std::cout << "frame count: " << frame_count++ << '\n';

        if (key == 'a')
        {
            angle += 10;
        }
        else if (key == 'd')
        {
            angle -= 10;
        }
    }

    return 0;
}