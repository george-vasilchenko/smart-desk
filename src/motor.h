#include <Servo.h>
#define MOTOR_PIN 9

class Motor
{
  private:
    Servo *m_servo = nullptr;

  public:
    Motor();
    ~Motor();
    void Update(const unsigned int &value);
};

Motor::Motor()
{
    this->m_servo = new Servo();
    this->m_servo->attach(MOTOR_PIN);
}

Motor::~Motor()
{
    if (this->m_servo != nullptr)
    {
        delete this->m_servo;
    }
}

void Motor::Update(const unsigned int &value)
{
    if (value < 0 || value > 180)
    {
        return;
    }

    this->m_servo->write(value);
}
