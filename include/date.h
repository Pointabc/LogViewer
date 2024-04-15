#ifndef DATE_H
#define DATE_H

class Date
{
    public:
        Date() = default;
        Date(int day, int month, int year);
        virtual ~Date();

        int GetDay() const;
        int GetMonth() const;
        int GetYear() const;

    protected:

    private:
        int days, months, years;

        // invariant class
        void Normalize();
        bool IsLeapYear();
        int GetDaysMonth();
};

#endif // DATE_H
