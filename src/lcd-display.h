#pragma once
#include "base/display/display.h"
#include "base/logger/logger.h"
#include "config/mapping.h"
#include "misc/utils.h"
#include <LiquidCrystal.h>
#include <Wire.h>

#define LCD_LINE_LENGTH 17

class LcdDisplay : public Display
{
  private:
    LiquidCrystal m_lcd = LiquidCrystal(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
    char m_messageLine0[LCD_LINE_LENGTH] = "H=000,D=000____.";
    char m_messageLine1[LCD_LINE_LENGTH] = "_______________.";
    void Refresh();

  public:
    LcdDisplay()
    {
        this->m_lcd.begin(16, 2);
        this->Refresh();
    }
    ~LcdDisplay()
    {
    }

    void SetCurrentLiftHeight(const unsigned int &value);
    void SetCurrentMeasuredDistance(const unsigned int &value);
};

void LcdDisplay::Refresh()
{
    this->m_lcd.clear();
    this->m_lcd.setCursor(0, 0);
    this->m_lcd.println(&this->m_messageLine0[0]);
    this->m_lcd.setCursor(0, 1);
    this->m_lcd.println(&this->m_messageLine1[0]);

    // Logger::WriteLine(this->m_messageLine0);
}

void LcdDisplay::SetCurrentLiftHeight(const unsigned int &value)
{
    this->m_messageLine0[2] = Utils::SingleNumberToCharacter(Utils::GetNumberAtDecimalPlace(value, 100));
    this->m_messageLine0[3] = Utils::SingleNumberToCharacter(Utils::GetNumberAtDecimalPlace(value, 10));
    this->m_messageLine0[4] = Utils::SingleNumberToCharacter(Utils::GetNumberAtDecimalPlace(value, 1));
    this->Refresh();
}

void LcdDisplay::SetCurrentMeasuredDistance(const unsigned int &value)
{
    this->m_messageLine0[8] = Utils::SingleNumberToCharacter(Utils::GetNumberAtDecimalPlace(value, 100));
    this->m_messageLine0[9] = Utils::SingleNumberToCharacter(Utils::GetNumberAtDecimalPlace(value, 10));
    this->m_messageLine0[10] = Utils::SingleNumberToCharacter(Utils::GetNumberAtDecimalPlace(value, 1));
    this->Refresh();
}
