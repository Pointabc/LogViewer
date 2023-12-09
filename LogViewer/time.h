#ifndef TIME_H
#define TIME_H


class Time
{
    public:
        Time() = default;
        Time(int h, int m, int s);  // объявляем конструктор
        Time(int s): Time(0, 0, s) {}
        virtual ~Time();

        // Объявляем три функции для чтения полей:
        int GetHours() const;
        int GetMinutes() const;
        int GetSeconds() const;

    protected:

    private:
        int hours;
        int minutes;
        int seconds;
};

#endif // TIME_H
