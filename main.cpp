#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
#include <Windows.h>
#include "opencv2/opencv.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/core/utils/logger.hpp>


using std::cout, std::endl, std::vector;


vector<int> matrix_mult(const vector<vector<double>>& A, const vector<int>& B){
    cout << A.size() << " " << A[0].size() << " " << B.size();
    vector<int> C(B.size());
    for(int i = 0; i < B.size(); ++i){
        C[i] = B[0] * A[i][0] + B[1] * A[i][1] + B[2] * A[i][2] + B[3] * A[i][2];
    }
    return C;
}

vector<vector<int>> make_cube(int r){
    vector<vector<int>> Points = {{r, r, 0}, {r, -r, 0}, {-r, -r, 0}, {-r, -r, 0},
                                  {r, r, r}, {r, -r, r}, {-r, -r, r}, {-r, -r, r} };
    //cout << "Points size "<< Points.size() << " " << Points[0].size();
    return Points;
}

void draw_cube(cv::Mat & m, int radius, const vector<int>& angles){
    if(angles.size() != 3){
        cout << "incorrect size of transformation matrix" << angles.size() << "\n";
        return;
    }


    const float PI = 3.14;
    double degrees_x = (angles[0] * PI) / 180.0;
    double degrees_y = (angles[1] * PI) / 180.0;
    double degrees_z = (angles[2] * PI) / 180.0;

    vector<vector<double>> x_transform = {{1 , 0, 0},
                                  {0, cos(degrees_x), -1 * sin(degrees_x)},
                                  {0, sin(degrees_x), cos(degrees_x)}};
    vector<vector<double>> y_transform = {{cos(degrees_y), 0, sin(degrees_y)},
                                  {0, 1, 0},
                                  {-1*sin(degrees_y), 0, cos(degrees_y)}};
    vector<vector<double>> z_transform = {{cos(degrees_z), -1*sin(degrees_y), 0},
                                  {sin(degrees_z), cos(degrees_z), 0},
                                  {0, 0, 1}};

    vector<vector<int>> cube_points = make_cube(radius);

    cout << "cube_points size "<< cube_points.size();// << " " << cube_points[0].size();
    vector<vector<int>> mod_points(8);

    for(int i = 0; i < 8; i++){
        matrix_mult(x_transform, cube_points[i]);
    }
return;

    for(int i = 1; i < 8; i++) {
        if (mod_points[i][0] < m.rows && mod_points[i][1] < m.cols) {
            m.at<uchar>(mod_points[i][0], mod_points[i][1]) = 255;
            cv::line(m, {mod_points[i-1][0], mod_points[i-1][1],},
                     {mod_points[i][0], mod_points[i][1],}, cv::Scalar(255),
                 2, cv::LINE_8);
        }

    }

}
int main() {
    cv::utils::logging::setLogLevel(cv::utils::logging::LogLevel::LOG_LEVEL_SILENT);
    int monitor_width = GetSystemMetrics(SM_CXSCREEN);
    int monitor_height = GetSystemMetrics(SM_CYSCREEN);

    const unsigned x_size =  monitor_height/2 - 0.1 * monitor_height,
            y_size = monitor_width/2 - 0.1 * monitor_width;

    cv::namedWindow("track", 1);
    cv::resizeWindow("track", y_size, 250);
    cv::moveWindow("track", 0, x_size + 0.05 * x_size);

    cv::namedWindow("standart circle", 1);
    cv::resizeWindow("standart circle", x_size, y_size);
    cv::moveWindow("standart circle", 0, 0);

    cv::namedWindow("modified circle", 1);
    cv::resizeWindow("modified circle", x_size, y_size);
    cv::moveWindow("modified circle", y_size, 0);

    int radius = 50;
    cv::createTrackbar("Radius", "track", &radius, 200);

    //Create trackbar to change contrast
    //vector<double> transformation_matrix(4);
    vector<int> angles = {0, 0, 0};

    cv::createTrackbar("X", "track", &angles[0], 360);
    cv::createTrackbar("Y", "track", &angles[1], 360);
    cv::createTrackbar("Z", "track", &angles[2], 360);

    cv::setTrackbarMin("X", "track", -360);
    cv::setTrackbarMin("Y", "track", -360);
    cv::setTrackbarMin("Z", "track", -360);

    while(true) {
        cv::Mat img_before = cv::Mat::zeros(x_size, y_size, CV_8UC1);
        cv::Mat img_after = cv::Mat::zeros(x_size, y_size, CV_8UC1);




        //draw_circle(img_before, 0, 0, radius);
        //draw_circle(img_after, 0, 0, radius, transformation_matrix);

        //cout << iSliderValue1 << " " << iSliderValue2 << "\n";
        draw_cube(img_after, radius, angles);

        cv::imshow("standart circle", img_before);
        cv::imshow("modified circle", img_after);

        //cv::namedWindow("Trackbar Example");

        //int input_value = cv::getTrackbarPos("Number", "Number Input");
        if (cv::waitKey(10) == 27) {
            break;
        }
    }

}