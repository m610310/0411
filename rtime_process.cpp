#include "rtime_process.h"
#include <QString>

Rtime_process::Rtime_process()
{
}

void Rtime_process::openmovie(QString filename)
{
    if(cap.isOpened()){
        cap.release();
    }
    if(!cap.isOpened()){
        cap.open(filename.toStdString());
    }
    if(cap.isOpened()){

        videoTotalFrames = cap.get(CV_CAP_PROP_FRAME_COUNT);
        videorate = cap.get(CV_CAP_PROP_FPS);

        frameAquision.resize(videoTotalFrames + 1);
        Bframe.resize(videoTotalFrames + 1);
        Gframe.resize(videoTotalFrames + 1);
        Rframe.resize(videoTotalFrames + 1);

        for(int framenum =  0; framenum < videoTotalFrames; framenum ++){

            cap.set(CV_CAP_PROP_POS_FRAMES, framenum);
            cv::Mat tmp_frame;
            cap >> tmp_frame;

            frameAquision[framenum] = tmp_frame;

            std::vector <cv::Mat> tmp_channels;
            tmp_channels.resize(3);

            Bframe[framenum] = tmp_channels[0];
            Gframe[framenum] = tmp_channels[1];
            Rframe[framenum] = tmp_channels[2];

            cv::imshow("Rframe", Rframe[framenum]);

        }


    }
}


void Rtime_process::rtimeprocess()
{
    std::vector <cv::Mat> Rhosonaga;
    Rhosonaga.resize(videoTotalFrames + 1);

    cv::Mat Rconcat;

    for(int framenum = 0; framenum < videoTotalFrames; framenum ++){
        cv::reduce(Rframe[framenum], Rhosonaga[framenum], 1, CV_REDUCE_AVG);

        if(framenum == 0){
            Rconcat = Rframe[0];

        }
       else if(framenum > 0){
       cv::hconcat(Rconcat, Rhosonaga[framenum], Rconcat);


    }

    cv::Mat rtime_img = Rconcat;
    cv::imshow("Rtime", rtime_img);
}
}
