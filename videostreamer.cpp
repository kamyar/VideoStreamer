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

}

QString VideoStreamer::echo(QString msg)
{
    qDebug() << msg;
    return msg;
}

