#include <Arduino.h>
#include <Motor.h>

// constructor for bidirectional control
Motor::Motor(int forward_pin, int reverse_pin)
  {
    _forward_pin = forward_pin;
    _reverse_pin = reverse_pin;
    pinMode(_forward_pin, OUTPUT);
    pinMode(_reverse_pin, OUTPUT);
    stop();
  }

void Motor::stop()
{
  digitalWrite(_forward_pin,LOW);
  digitalWrite(_reverse_pin,LOW);
}

void Motor::forward(int speed)
{
  _speed = speed;
  if(!_is_forward)
  {
    _is_forward = true;
    stop();
  }
  analogWrite(_forward_pin, _speed);
}

void Motor::reverse(int speed)
{
  _speed = speed;
  if (_is_forward)
  {
    _is_forward = false;
    stop();
  }
  analogWrite(_reverse_pin, _speed);
}

bool Motor::isForward()
{
  return _is_forward;
}

bool Motor::isReverse()
{
  return !_is_forward;
}

bool Motor::isOff()
{
  return getSpeed() == 0;
}

int Motor::getSpeed()
{
  return _speed;
}