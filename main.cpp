/**
    *****************************************************************************
    *                                 Qt Web Player                             *
    *                                                                         	*
    *	@author Kamyar Ghasemlo <k.ghasemlou@gmail.com>                         *
    *	@version 1.0 12/1/2015  												*
    *                                                                         	*
    *****************************************************************************
**/

#include <QCoreApplication>
#include <QtWebChannel>
#include <QSharedPointer>
#include <QWebSocket>
#include <QtWebSockets/QWebSocketServer>

#include "libs/websocketclientwrapper.h"
#include "libs/websockettransport.h"

#include "videostreamer.h"


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // wrap WebSocket clients in QWebChannelAbstractTransport objects
    WebSocketClientWrapper clientWrapper(2000);

//    // setup the channel
    QWebChannel channel;
    QObject::connect(&clientWrapper, &WebSocketClientWrapper::clientConnected,
                   &channel, &QWebChannel::connectTo);

    // setup the dialog and publish it to the QWebChannel
    VideoStreamer streamer_i("/home/kamyar/projects/VideoStreamer/video_files/drop.avi", 30, &app);
    channel.registerObject("videoStreamer", &streamer_i);
    streamer_i.run();

    return app.exec();
}
