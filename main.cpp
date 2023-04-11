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
    //cout << A.size() << " " << A[0].size() << " " << B.size();
    //return vector<int>();
    vector<int> C(B.size());
    for(int i = 0; i < A.size(); ++i){
        C[i] = B[0] * A[i][0] + B[1] * A[i][1]  + B[2] * A[i][2] ;
    }
    return C;
}

vector<vector<int>> make_cube(int r){
    return {{r, -r, r}, {r, r, r}, {-r, r, r}, {-r, -r, r},
            {-r, -r, -r}, {-r, r, -r}, {r, r, -r}, {r, -r, -r} };
    //cout << "Points size "<< Points.size() << " " << Points[0].size();

}

vector<int> mat_sum(vector<int> a, vector<int> b, vector<int> c){
    if(a.size() != b.size() || a.size() != c.size()){
        throw std::runtime_error("different size of vec in vec_sum");
    }
    vector<int> d(a.size());
    for(int i = 0; i < a.size(); ++i)
        d[i] = a[i] + b[i] + c[i];
    return d;
}

void draw_cube(cv::Mat & m, int radius, const vector<int>& angles){
    if(angles.size() != 3){
        cout << "incorrect size of angles matrix" << angles.size() << "\n";
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
    vector<vector<double>> z_transform = {{cos(degrees_z), -1*sin(degrees_z), 0},
                                  {sin(degrees_z), cos(degrees_z), 0},
                                  {0, 0, 1}};

    vector<vector<int>> cube_points = make_cube(radius);

    vector<vector<int>> mod_points(8);

    for(int i = 0; i < 8; i++){
        mod_points[i] = matrix_mult(x_transform, cube_points[i]);
        mod_points[i] = matrix_mult(y_transform, mod_points[i]);
        mod_points[i] = matrix_mult(z_transform, mod_points[i]);
    }


    for(int i = 0; i < 8; i++) {

        mod_points[i][0] += m.rows/2;
        mod_points[i][1] += m.cols/2;

    }
    vector<cv::Scalar> colors = {{0,0,255}, {0,255,0}, {255,0,0}, {255, 255, 0}, {0,255,255}, {255,0,255}, {150,165,100}, {255,255,255}};
    for(int i = 1; i < 8; i++) {
        if (mod_points[i][0] > 0 && mod_points[i][1] > 0 && mod_points[i][0] < m.rows && mod_points[i][1] < m.cols) {
            //m.at<uchar>(mod_points[i][0], mod_points[i][1]) = 255;
            cv::Point p1(mod_points[i - 1][1], mod_points[i - 1][0]);
            cv::Point p2(mod_points[i][1], mod_points[i][0]);
            cv::line(m, p1, p2, colors[i], 5);
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

    cv::namedWindow("cube", 1);
    cv::resizeWindow("cube", x_size, y_size);
    cv::moveWindow("cube", 0, 0);



    int radius = 50;
    cv::createTrackbar("Radius", "track", &radius, 200);

    vector<int> angles = {0, 0, 0};

    cv::createTrackbar("X", "track", &angles[0], 360);
    cv::createTrackbar("Y", "track", &angles[1], 360);
    cv::createTrackbar("Z", "track", &angles[2], 360);

    cv::setTrackbarMin("X", "track", -360);
    cv::setTrackbarMin("Y", "track", -360);
    cv::setTrackbarMin("Z", "track", -360);

    while(true) {
        cv::Mat img = cv::Mat::zeros(x_size, y_size, CV_8UC3);




        //draw_circle(img_before, 0, 0, radius);
        //draw_circle(img_after, 0, 0, radius, transformation_matrix);

        //cout << iSliderValue1 << " " << iSliderValue2 << "\n";
        draw_cube(img, radius, angles);

        cv::imshow("cube", img);

        //cv::namedWindow("Trackbar Example");

        //int input_value = cv::getTrackbarPos("Number", "Number Input");
        if (cv::waitKey(10) == 27) {
            break;
        }
    }

}
