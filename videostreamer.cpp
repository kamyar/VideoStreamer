/**
    *****************************************************************************
    *                                                                         	*
    *	@author Kamyar Ghasemlou, ISSD Corp. <Kamyar@issd.com.tr>				*
    *	@version ?.?.? 12/1/2015												*
    *                                                                         	*
    *****************************************************************************
**/

#include "videostreamer.h"

VideoStreamer::VideoStreamer(QObject *parent) : QObject(parent)
{
};

VideoStreamer::VideoStreamer(std::string videoPath, int fps, QObject *parent) : QObject(parent)
{

    m_videof.open(videoPath);
    m_frameRate = fps;
    m_isStreamActive = false;

}

void VideoStreamer::run()
{
    qDebug() << "Starting...";
    m_videof >> m_currFrame;
    std::vector<uchar> imgBuf;
    while(true)
    {
        if (m_currFrame.empty())
        {
            qDebug() << "Restarting";
            m_videof.set(CV_CAP_PROP_POS_FRAMES, 0);
            m_videof >> m_currFrame;
        }

        if (m_isStreamActive)
        {
            cv::imencode(".jpeg", m_currFrame, imgBuf, {cv::IMWRITE_JPEG_QUALITY, 50});
            emit imageFrameReady(QByteArray((const char*) imgBuf.data(), imgBuf.size()).toBase64());
        }

        cv::imshow("Video", m_currFrame);
        m_videof >> m_currFrame;
        cv::waitKey(1000/m_frameRate);
    }
}

QString VideoStreamer::echo(QString msg)
{
    qDebug() << msg;
    return msg;
}

int VideoStreamer::startStream()
{
    m_isStreamActive = true;
    qDebug() << m_isStreamActive;
    return 0;
}

int VideoStreamer::stopStream()
{
    m_isStreamActive = false;
    qDebug() << m_isStreamActive;
    return 0;
}

