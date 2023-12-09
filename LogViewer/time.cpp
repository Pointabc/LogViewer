#include "time.h"

Time::Time(int h, int m, int s) {
    m += s / 60;
    s %= 60;
    // Если s было отрицательным, то остаток тоже будет отрицательным
    if (s < 0) {
        // Уменьшим в этом случае минуты и сделаем секунды положительными
        m -= 1;
        s += 60;
    }

    h += m / 60;
    m %= 60;
    if (m < 0) {
        h -= 1;
        m += 60;
    }

    h %= 24;
    if (h < 0) {
        h += 24;
    }

    hours = h;
    minutes = m;
    seconds = s;
}

int Time::GetHours() const {
    return hours;
}

int Time::GetMinutes() const {
    return minutes;
}

int Time::GetSeconds() const {
    return seconds;
}

Time::~Time()
{
    //dtor
}
