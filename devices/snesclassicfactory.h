#ifndef SNESCLASSICFACTORY_H
#define SNESCLASSICFACTORY_H

#include <QObject>
#include <QTcpSocket>

#include "../devicefactory.h"

#include "snesclassic.h"

class SNESClassicFactory : public DeviceFactory
{
public:
    SNESClassicFactory();

    // DeviceFactory interface
public:
    QStringList listDevices();
    ADevice *attach(QString deviceName);
    bool deleteDevice(ADevice *);
    QString status();
    QString name() const;
private:
    QTcpSocket*         socket;
    QByteArray          canoePid;
    SNESClassic*        device;
    unsigned int        romLocation;
    unsigned int        sramLocation;
    unsigned int        ramLocation;

    void executeCommand(QByteArray toExec);
    void writeSocket(QByteArray toWrite);
    QByteArray readCommandReturns(QTcpSocket *msocket);
    void findMemoryLocations();
    bool checkStuff();
};

#endif // SNESCLASSICFACTORY_H
