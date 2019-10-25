#ifndef DISPLAY_H
#define DISPLAY_H

struct params{
    unsigned char gear;
    float wheelAngle;
    char wheelSignFlag;
    float carSpeed;
    float accPedal;
    unsigned char epbOn;
    float gaussX;
    float gaussY;
    float pitch;
    float roll;
    float azimuth;
    unsigned char gpsConfidence;
};

#endif // DISPLAY_H

