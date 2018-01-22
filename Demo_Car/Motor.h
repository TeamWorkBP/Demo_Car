#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>
class Motor
{
  public:
    Motor(int forward_pin, int reverse_pin);
    void stop();
    void forward(int speed);
    void reverse(int speed);
    bool isOff();
    bool isForward();
    bool isReverse();
    int getSpeed();
  private:
    int _forward_pin;
    int _reverse_pin;
    bool _is_forward = false;
    int _speed = 0;
};

#endif
