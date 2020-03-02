#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    VideoCapture cap(0);

    if (cap.isOpened() == false)
    {
        cout <<  "Произошла ошибка" <<  endl;
        cin.get();
        return -1;
    }

    double fps =cap.get(CAP_PROP_FPS);
    cout <<  "FPS : " <<  fps <<  endl;

    String window_name =  "Veb";
    namedWindow( window_name,  WINDOW_AUTOSIZE);

    while (true)
    {
        Mat frame;
        bool bSuccess =  cap.read(frame);
        if (bSuccess ==  false)
        {
            cout <<  "Конец видео" <<  endl;
            break;
        }
        imshow(window_name,  frame);

        if (waitKey(1)  ==  27)
        {
            break;
        }
        if (waitKey(1)  ==  9)
        {
            vector<int>  compression_params;
            compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
            compression_params.push_back(9);
            bool result = false;
            result = cv::imwrite("/home/pc/Загрузки/1.png",frame,compression_params);
            if (result)
                cout <<  "Файл сохранен" <<  endl;
            else
                cout <<  "Произошла ошибка" <<  endl;
        }
    }
    return 0 ;
}
