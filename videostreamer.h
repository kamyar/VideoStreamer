/**
    *****************************************************************************
    *                                                                         	*
    *	@author Kamyar Ghasemlou, ISSD Corp. <Kamyar@issd.com.tr>				*
    *	@version ?.?.? 12/1/2015												*
    *                                                                         	*
    *****************************************************************************
**/

#ifndef VIDEOSTREAMER_H
#define VIDEOSTREAMER_H

#include <vector>

#include <QObject>
#include <QString>
#include <QDebug>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/video/video.hpp>


class VideoStreamer : public QObject
{
    Q_OBJECT

private:
    int m_frameRate;
    cv::VideoCapture m_videof;
    cv::Mat m_currFrame;
    bool m_isStreamActive;
public:
    explicit VideoStreamer(QObject *parent = 0);
    explicit VideoStreamer(std::string videoPath, int fps = 30, QObject *parent = 0);
    void run();

signals:
    void imageFrameReady(QByteArray frame);

public slots:
    QString echo(QString msg);
    int startStream();
    int stopStream();
};

#endif // VIDEOSTREAMER_H
