#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>


int main(int argc, char** argv) {
  cv::VideoCapture camera(0);
  cv::Mat lastframe;
  cv::Mat difframe;
  cv::Mat frame;
  if (!camera.isOpened()) {
    return -1;
  }
  cv::namedWindow("Source");
  cv::namedWindow("Difference");

  camera >> frame;
  for (;;) {
    frame.copyTo(lastframe);
    camera >> frame;
    cv::absdiff(lastframe, frame, difframe);
    cv::imshow("Source", frame);
    cv::imshow("Difference", difframe);
  }
  return 0;
}
