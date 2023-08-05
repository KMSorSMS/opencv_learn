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

    frame = imread(argv[1], IMREAD_COLOR);
    if (!frame.data)
    {
        cout << "No image data \n";
        return -1;
    }
    
    // 将图像转换为HSV颜色空间
    cvtColor(frame, hsv, COLOR_BGR2HSV);

    // 提取绿色区域
    Mat green_mask;
    inRange(hsv, Scalar(35, 43, 46), Scalar(77, 255, 255), green_mask);

    Mat green_result;
    bitwise_and(hsv, hsv, green_result, green_mask);

    cvtColor(green_result, green_result, COLOR_HSV2BGR);
    cvtColor(green_result, green_result, COLOR_BGR2GRAY );
    // 轮廓检测
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    //对绿色
    findContours(green_result, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

    // 绘制轮廓
    Mat contour_img = Mat::zeros(frame.size(), CV_8UC3);
    for (size_t i = 0; i < contours.size(); i++)
    {
        drawContours(contour_img, contours, i, Scalar(255, 255, 255), 1, LINE_8, hierarchy);
    }

    // 显示结果
    cvtColor(hsv, hsv, COLOR_HSV2BGR);
    imshow("binary image", hsv);
    imshow("green mask", green_mask);
    imshow("green", green_result);
    imshow("contours", contour_img);
    waitKey(0);
    return 0;
}