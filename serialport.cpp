#include "serialport.h"

Serialport::Serialport()
{
    #ifdef _TTY_POSIX_
        port = new QextSerialPort("/dev/cu.OBDKeyPro-DevB-1", QextSerialPort::Polling);
    #else
        port = new QextSerialPort("COM1", QextSerialPort::Polling);
    #endif /*_TTY_POSIX*/
    port->setBaudRate(BAUD19200);
    port->setFlowControl(FLOW_OFF);
    port->setParity(PAR_NONE);
    port->setDataBits(DATA_8);
    port->setStopBits(STOP_2);
    //set timeouts to 500 ms
    port->setTimeout(500);
}

void Serialport::openPort()
{
//This function based on same from QESPTA example
    port->open(QIODevice::ReadWrite | QIODevice::Unbuffered);
    qDebug("is open: %d", port->isOpen());
}

void Serialport::closePort()
{
//This function based on same from QESPTA example
    port->close();
    qDebug("is open: %d", port->isOpen());
}

QString Serialport::receiveMsg()
{
//This function based on same from QESPTA example

    char buff[1024];
    int numBytes;

    numBytes = port->bytesAvailable();
    if(numBytes > 1024) {
        numBytes = 1024};

    int i = port->read(buff, numBytes);
    if (i != -1) {
        buff[i] = '\0'};
    else {
        buff[0] = '\0'};

    QString msg = buff;

    qDebug("bytes available: %d", numBytes);
    qDebug("received: %d", i);

    return msg;
}
