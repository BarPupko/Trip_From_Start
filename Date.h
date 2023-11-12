#ifndef DATE_H
#define DATE_H

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int day = 1, int month = 1, int year = 2000); // Constructor with default values
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    bool operator==(const Date& other) const;

    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    bool isLessThan(const Date& other) const;
    bool isGreaterThan(const Date& other) const;
    bool isEqualTo(const Date& other) const;
    void print() const; // Function to print the date
};

#endif // DATE_H
