#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char** argv) {
  cv::VideoCapture camera(0);
  cv::Mat frame;
  if (!camera.isOpened()) {
    return -1;
  }
  cv::namedWindow("Source");
  
  for (;;) {
    camera >> frame;
    cv::imshow("Source", frame);
    if (cv::waitKey(1) == 27) {
      break;
    } 
  }
  return 0;
}
