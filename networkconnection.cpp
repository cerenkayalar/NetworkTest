
/** @author Ceren Kayalar
    @date 17.03.2012
*/
#include "networkconnection.h"

NetworkConnection::NetworkConnection(QObject *parent) :
    QObject(parent)
{

}


void NetworkConnection::postCoordinates(QString urlStr, QString postStr) {
    /*
http://localhost/REST/rest/VisionTest/0,20485,13,52.80,28.93+0,20508,3,64.92,13.46+0,20556,20,68.56,43.40+1,20597,38,53.79,28.53+1,20598,16,51.24,29.06+0,20600,55,71.07,31.65+0,20603,15,71.63,26.00+1,20609,-1,51.87,11.12+2,20612,90,53.13,27.43+1,20615,5,71.25,24.66+1,20616,4,43.04,36.60+1,20618,6,44.84,24.26+4,20620,1,13.77,32.38+0,20632,6,65.07,35.59+1,20634,88,62.11,7.04+0,20641,11,51.42,27.67+3,20642,99,102.12,32.53+1,20645,10,59.10,40.05+0,20647,28,61.75,31.44+0,20648,8,57.a58,25.02+1,20649,3,53.21,27.50+0,20650,7,50.25,21.63+1,20652,77,65.52,63.13+:+

    */
//    urlStr = "http://localhost/REST/rest/VisionTest/";
urlStr = "http://localhost/REST/rest/VisionTest/0,20485,13,52.80,28.93+0,20508,3,64.92,13.46+0,20556,20,68.56,43.40+1,20597,38,53.79,28.53+1,20598,16,51.24,29.06+0,20600,55,71.07,31.65+0,20603,15,71.63,26.00+1,20609,-1,51.87,11.12+2,20612,90,53.13,27.43+1,20615,5,71.25,24.66+1,20616,4,43.04,36.60+1,20618,6,44.84,24.26+4,20620,1,13.77,32.38+0,20632,6,65.07,35.59+1,20634,88,62.11,7.04+0,20641,11,51.42,27.67+3,20642,99,102.12,32.53+1,20645,10,59.10,40.05+0,20647,28,61.75,31.44+0,20648,8,57.a58,25.02+1,20649,3,53.21,27.50+0,20650,7,50.25,21.63+1,20652,77,65.52,63.13+:+";
    url = QUrl(urlStr);
    file = new QFile("serverResponse.txt");
    file->open(QIODevice::WriteOnly);
   reply = qnam.get(QNetworkRequest(url));//, "0,20485,13,52.80,28.93+0,20508,3,64.92,13.46+0,20556,20,68.56,43.40+1,20597,38,53.79,28.53+1,20598,16,51.24,29.06+0,20600,55,71.07,31.65+0,20603,15,71.63,26.00+1,20609,-1,51.87,11.12+2,20612,90,53.13,27.43+1,20615,5,71.25,24.66+1,20616,4,43.04,36.60+1,20618,6,44.84,24.26+4,20620,1,13.77,32.38+0,20632,6,65.07,35.59+1,20634,88,62.11,7.04+0,20641,11,51.42,27.67+3,20642,99,102.12,32.53+1,20645,10,59.10,40.05+0,20647,28,61.75,31.44+0,20648,8,57.a58,25.02+1,20649,3,53.21,27.50+0,20650,7,50.25,21.63+1,20652,77,65.52,63.13+:+");
   // reply = qnam.post(QNetworkRequest(url), "fname=11111&lname=22222222");
    connect(reply, SIGNAL(readyRead()),
            this, SLOT(httpReadyRead()));
    connect(reply, SIGNAL(finished()),
            this, SLOT(httpFinished()));
}

void NetworkConnection::postCoordinates(QString postStr) {

    url = QUrl(postStr);
    file = new QFile("serverResponse.txt");
    file->open(QIODevice::WriteOnly);
   reply = qnam.get(QNetworkRequest(url));
    connect(reply, SIGNAL(readyRead()),
            this, SLOT(httpReadyRead()));
    connect(reply, SIGNAL(finished()),
            this, SLOT(httpFinished()));
}

void NetworkConnection::httpReadyRead()
{
    // this slot gets called every time the QNetworkReply has new data.
    // We read all of its new data and write it into the file.
    // That way we use less RAM than when reading it at the finished()
    // signal of the QNetworkReply
    if (file)
        file->write(reply->readAll());

}

void NetworkConnection::httpFinished(){
    file->flush();
    file->close();
    reply->deleteLater();
    reply = 0;
    delete file;
    file = 0;
}
