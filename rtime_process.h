#ifndef RTIME_PROCESS_H
#define RTIME_PROCESS_H

#include <iostream>
#include <vector>
#include <QString>

#include <opencv2/opencv.hpp>


class Rtime_process
{
public:
    Rtime_process();

    void openmovie(QString filename);
    void rtimeprocess();

private:

    cv::VideoCapture cap;
    int videoTotalFrames, videorate;


    std::vector <cv::Mat> frameAquision;
    std::vector <cv::Mat> Bframe, Gframe, Rframe;


};

#endif // RTIME_PROCESS_H
