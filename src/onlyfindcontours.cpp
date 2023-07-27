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

    frame = imread(argv[1], IMREAD_GRAYSCALE);
    if (!frame.data)
    {
        cout << "No image data \n";
        return -1;
    }
    // 轮廓检测
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(frame, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    // 绘制轮廓
    Mat contour_img = Mat::zeros(frame.size(), CV_8UC3);
    for (size_t i = 0; i < contours.size(); i++)
    {
        drawContours(contour_img, contours, i, Scalar(255, 255, 255), 2, LINE_8, hierarchy);
    }

    // 显示结果
    imshow("binary image", frame);
    imshow("contours", contour_img);
    waitKey(0);
    return 0;
}