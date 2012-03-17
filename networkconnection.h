
/** @author Ceren Kayalar
    @date 17.03.2012
*/

#ifndef NETWORKCONNECTION_H
#define NETWORKCONNECTION_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QObject>
#include <QFile>


class NetworkConnection : public QObject
{
    Q_OBJECT
public:
    explicit NetworkConnection(QObject *parent = 0);
    void postCoordinates(QString, QString);
    void postCoordinates(QString);

public slots:
    void httpReadyRead();
    void httpFinished();

private:
    QUrl url;
    QNetworkAccessManager qnam;
    QNetworkReply *reply;
    QFile *file;

};

#endif // NETWORKCONNECTION_H
