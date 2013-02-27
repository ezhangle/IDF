#include "SerialThrustMaster.hh"
#include "IOException.hh"
#include <termios.h>
#include <errno.h>
#include <string.h>
#include <sstream>

using namespace idf;

SerialThrustMaster::SerialThrustMaster(const char *terminalPath, bool isMale) :
    SerialDevice(terminalPath),
    ThrustMaster(isMale) {}

void SerialThrustMaster::open() {
    SerialDevice::open();

    struct termios settings;
    tcgetattr(handle, &settings);
    cfsetspeed(&settings, B9600);
    settings.c_cflag |= (CLOCAL | CREAD);
    settings.c_cflag &= ~PARENB;
    settings.c_cflag &= ~CSTOPB;
    settings.c_cflag &= ~CSIZE;
    settings.c_cflag |= CS8;

    if (tcsetattr(handle, TCSANOW, &settings) == -1) {
        std::ostringstream oss;
        oss << __FILE__ << ":" << __LINE__
            << " Failed to set serial port attributes: " << strerror(errno);
        throw IOException(oss.str());
    }
}

void SerialThrustMaster::update() {
    SerialDevice::update();

    char request = 'r';

    write(&request, sizeof(request));

    int bytesRemaining = 9;
    unsigned char buffer[bytesRemaining];

    while(bytesRemaining) {
        bytesRemaining -= read(buffer + (9 - bytesRemaining), bytesRemaining);
    }

    forwardBackwardPivot.setValue(buffer[0]);
    twist.setValue(buffer[1]);
    leftRightPivot.setValue(buffer[2]);
    leftRightTranslation.setValue(buffer[3]);
    upDownTranslation.setValue(buffer[4]);
    forwardBackwardTranslation.setValue(buffer[5]);
    trigger.setValue(buffer[8] & 1);
    leftButton.setValue(buffer[8] >> 1 & 1);
    middleButton.setValue(buffer[8] >> 2 & 1);
    rightButton.setValue(buffer[8] >> 3 & 1);
}
