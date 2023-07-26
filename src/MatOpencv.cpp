// #include <iostream>
// #include <opencv2/core.hpp>
// #include <opencv2/imgproc.hpp>
// #include <opencv2/highgui.hpp>
// using namespace cv;
// using namespace std;
// int main(int argc, char **argv)
// {

//     if (argc != 2)
//     {
//         cout << "usage: DisplayImage.out <Image_Path>\n";
//         return -1;
//     }
//     Mat image;
//     image = imread(argv[1], 1);
//     if (!image.data)
//     {
//         cout << "No image data \n";
//         return -1;
//     }

//     // Define dilation kernel
//     cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));

//     // Dilate the image
//     cv::Mat dst;
//     cv::dilate(image, dst, kernel);
//     cv::imshow("Source", image);
//     cv::imshow("Eroded", dst);
//     waitKey(0);
//     return 0;
// }

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;
int main(int argc, char **argv)
{

    if (argc != 2)
    {
        cout << "usage: DisplayImage.out <Image_Path>\n";
        return -1;
    }
    Mat frame, hsv;

    frame = imread(argv[1], 1);
    if (!frame.data)
    {
        cout << "No image data \n";
        return -1;
    }
    // 将图像转换为HSV颜色空间
    cvtColor(frame, hsv, COLOR_BGR2HSV);

    // 提取红色区域
    Mat red_mask;
    inRange(hsv, Scalar(0, 43, 46), Scalar(10, 255, 255), red_mask);

    // 提取绿色区域
    Mat green_mask;
    inRange(hsv, Scalar(35, 43, 46), Scalar(77, 255, 255), green_mask);

    // 提取白色区域
    Mat white_mask;
    inRange(hsv, Scalar(0, 0, 221), Scalar(179, 30, 255), white_mask);
    imshow("white_mask", white_mask);
    resizeWindow("white_mask", 640, 480);
    // 将掩码与原始图像进行位运算以提取颜色
    Mat red_result, green_result, white_result;
    bitwise_and(frame, frame, red_result, red_mask);
    bitwise_and(frame, frame, green_result, green_mask);
    bitwise_and(frame, frame, white_result, white_mask);
    // 生成卷积核
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(10, 10)); // 结构体核（卷积核）
    // 图像预处理闭运算：去除小黑点
    Mat green_close, white_close, red_close;
    morphologyEx(white_result, white_close, MORPH_CLOSE, kernel);
    morphologyEx(green_result, green_close, MORPH_CLOSE, kernel);
    morphologyEx(red_result, red_close, MORPH_CLOSE, kernel); // 红色试一下闭运算
    // 进行边缘提取，先使用sobel算子
    Mat green_edge, green_edge_x, green_edge_y, white_edge, white_edge_x, white_edge_y, red_edge, red_edge_x, red_edge_y;
    // 对x方向微分
    Sobel(green_close, green_edge_x, green_close.depth(), 1, 0, 3); // 绿色
    Sobel(white_close, white_edge_x, white_close.depth(), 1, 0, 3); // 白色
    Sobel(red_close, red_edge_x, red_close.depth(), 1, 0, 3);       // 红色
    // 对y方向微分
    Sobel(green_close, green_edge_y, green_close.depth(), 0, 1, 3); // 绿色
    Sobel(white_close, white_edge_y, white_close.depth(), 0, 1, 3); // 白色
    Sobel(red_close, red_edge_y, red_close.depth(), 0, 1, 3);       // 红色
    // 合并
    addWeighted(green_edge_x, 0.5, green_edge_y, 0.5, 0, green_edge); // 绿色
    addWeighted(white_edge_x, 0.5, white_edge_y, 0.5, 0, white_edge); // 白色
    addWeighted(red_edge_x, 0.5, red_edge_y, 0.5, 0, red_edge);       // 红色
    //显示
    imshow("green_edge", green_edge);
    imshow("white_edge", white_edge);
    imshow("red_edge", red_edge);
    resizeWindow("green_edge", 640, 480);
    resizeWindow("white_edge", 640, 480);
    resizeWindow("red_edge", 640, 480);
    //显示红色图
    imshow("red", red_result);
    //红色闭运算后
    imshow("red_close",red_close);
    // 再使用canny算子
    Mat green_canny, white_canny, red_canny;
    Canny(green_edge, green_canny, 50, 150, 3); // 绿色
    Canny(white_edge, white_canny, 50, 150, 3); // 白色
    Canny(red_edge, red_canny, 50, 150, 3);     // 红色
    // 显示
    imshow("green_canny", green_canny);
    imshow("white_canny", white_canny);
    imshow("red_canny", red_canny);
    resizeWindow("green_canny", 640, 480);
    resizeWindow("white_canny", 640, 480);
    resizeWindow("red_canny", 640, 480);
    // 用findcontours寻找轮廓
    vector<vector<Point>> green_contours, white_contours, red_contours;
    vector<Vec4i> green_hierarchy, white_hierarchy, red_hierarchy;
    findContours(green_canny, green_contours, green_hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0)); // 绿色
    findContours(white_canny, white_contours, white_hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0)); // 白色
    findContours(red_canny, red_contours, red_hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));       // 红色
    // 画出轮廓
    Mat green_contours_result, white_contours_result, red_contours_result;
    green_contours_result = Mat::zeros(green_canny.size(), CV_8UC3); // 绿色
    white_contours_result = Mat::zeros(white_canny.size(), CV_8UC3); // 白色
    red_contours_result = Mat::zeros(red_canny.size(), CV_8UC3);     // 红色
    for (int i = 0; i < green_contours.size(); i++)
    {
        Scalar color = Scalar(0, 255, 0);
        drawContours(green_contours_result, green_contours, i, color, 2, 8, green_hierarchy, 0, Point()); // 绿色
    }
    for (int i = 0; i < white_contours.size(); i++)
    {
        Scalar color = Scalar(0, 255, 0);
        drawContours(white_contours_result, white_contours, i, color, 2, 8, white_hierarchy, 0, Point()); // 白色
    }
    for (int i = 0; i < red_contours.size(); i++)
    {
        Scalar color = Scalar(0, 255, 0);
        drawContours(red_contours_result, red_contours, i, color, 2, 8, red_hierarchy, 0, Point()); // 红色
    }
    // 显示
    imshow("green_contours_result", green_contours_result);
    imshow("white_contours_result", white_contours_result);
    imshow("red_contours_result", red_contours_result);
    resizeWindow("green_contours_result", 640, 480);
    resizeWindow("white_contours_result", 640, 480);
    resizeWindow("red_contours_result", 640, 480);
    waitKey(0);
}