#include "../include/date.h"

Date::Date(int day, int month, int year) {
    days = day;
    months = month;
    years = year;
    Normalize(); // empty
}

Date::~Date()
{
    //dtor
}

int Date::GetDay() const {
    return days;
}

int Date::GetMonth() const {
    return months;
}

int Date::GetYear() const {
    return years;
}

void Date::Normalize() {
    /*int d = GetDaysMonth();
    months += days / d;
    days %= d;
    if (days < 0) {
        months -= 1;
        days += d;
    }

    years += months / 12;
    months %= 12;
    if (months < 0) {
        years -= 1;
        months += 12;
    }*/
}

bool Date::IsLeapYear() {
    if ( (years % 100 != 0 && years % 4 == 0) || years % 400 == 0 )
		return true;
	else
		return false;
}

int Date::GetDaysMonth() {
    char year[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (months == 2 && IsLeapYear())	{
		year[1]++;
	}

	return (int)year[months-1];
}
