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

#include <QObject>

class VideoStreamer : public QObject
{
    Q_OBJECT
public:
    explicit VideoStreamer(QObject *parent = 0);

signals:

public slots:
};

#endif // VIDEOSTREAMER_H
