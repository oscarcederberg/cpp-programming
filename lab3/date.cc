#include <ctime>  // time and localtime
#include <sstream>
#include <iomanip>
#include "date.h"

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
	year = std::max(1970, y);
	month = std::max(1, std::min(m, 12));
	day = std::max(1, std::min(d, daysPerMonth[month - 1]));
}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

std::ostream& operator<<(std::ostream& output, Date& date) {
	output << date.year << "-";
	output << std::setfill('0') << std::setw(2) << date.month << "-";
	output << std::setfill('0') << std::setw(2) << date.day;

	return output;
}

bool in_range(int x, int low, int high) {
    return x >= low && x <= high;
}

std::istream& operator>>(std::istream& input, Date& date) {
	int year, month, day;
	char delimiter;

	if (!(input >> year) || !(year >= 1970)) {
		input.setstate(std::ios_base::failbit);
		return input;
	}

	delimiter = input.get();
	if (delimiter != '-') {
		input.setstate(std::ios_base::failbit);
		return input;	
	}

	if (!(input >> month) || !(in_range(month, 1, 12))) {
		input.setstate(std::ios_base::failbit);
		return input;
	}

	delimiter = input.get();
	if (delimiter != '-') {
		input.setstate(std::ios_base::failbit);
		return input;	
	}

	if (!(input >> day) || !(in_range(day, 1, Date::daysPerMonth[date.month]))) {
		input.setstate(std::ios_base::failbit);
		return input;
	}

	date.year = year;
	date.month = month;
	date.day = day;

	return input;
}

void Date::next() {
	day++;
	if (day > daysPerMonth[month - 1]) {
		day = 1;
		month++;
		if (month > 12) {
			month = 1;
			year++;
		}
	}
}

