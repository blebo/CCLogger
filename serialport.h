#ifndef SERIALPORT_H
#define SERIALPORT_H

class QextSerialPort;

class Serialport
{
Q_OBJECT

public:
    Serialport();
    virtual ~Serialport();
    void openPort();
    void closePort();

private:
    QextSerialPort *port;

public slots:
    QString receiveMsg();
};

#endif // SERIALPORT_H
