#pragma once

namespace Utils
{
int GetNumberAtDecimalPlace(int number, int place);
char SingleNumberToCharacter(unsigned int &number);

int GetNumberAtDecimalPlace(int number, int place)
{
    int modulator = place * 10;
    return (number % modulator) / place;
}

char SingleNumberToCharacter(unsigned int number)
{
    return number + 48;
}
}