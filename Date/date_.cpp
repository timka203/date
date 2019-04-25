#include "date_.h"





date_::date_(int day, int month, int year)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

void date_::setDay(int day)
{
	this->day = day;
	if (this->day < 1) this->day = 1;
	
	if (this->day > 31)
		this->day = 31;
	if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)
		if (this->day > 30) this->day = 30;
	if (this->month == 2)
	{
		if (this->day > 28)
		{
			this->day = 28;
			if (this->year % 4 == 0) this->day = 29;
		}

	}
}

void date_::setMonth(int month)
{
	this->month = month;
	if (this->month < 1)
		this->month = 1;
	else if (this->month > 12)
		this->month = 12;
}

void date_::setYear(int year)
{
	this->year = year;
	if (this->year <= 1970)
		this->year = 1970;
	else if (this->year > 2100)
		this->year = 2100;
}

int date_::getDay() const
{
	return this->day;
}

int date_::getMonth() const
{
	return this->month;
}

int date_::getYear() const
{
	return this->year;
}

string date_::WhatDay()
{
	int a = (14 - this->month) / 12;
	int y = this->year - a;
	int m = this->month + 12 * a - 2;
	string days[7] = { "Sunday","Monday","Tuesday", "Wednesday", "Thursday",
					"Friday", "Saturday"};

	 return days[(this->day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7 ];
	

}

ostream & operator<<(ostream & os, const date_ & d)
{
	cout << d.day << "." << d.month << "." << d.year;
	return os;
}

istream& operator>>(istream& is, date_& d)
{
	int g;
	cout << "set year" << endl;
	cin >> g;
	d.setYear(g);
	cout << "set month" << endl;
	cin >> g;
	d.setMonth(g);
	cout << "set day" << endl;
	cin >> g;
	d.setDay(g);
	return is;
}

bool operator<(const date_& d, const date_& a)
{
	if (d.getYear() == a.getYear())
	{
		if (d.getMonth()==a.getMonth())
		{
			if (d.getDay()==a.getDay())
			{
				return false;
			}
			else
				if (d.getDay() < a.getDay())
				{
					return true;
				}
			return false;
		}
		else
			if (d.getMonth() < a.getMonth())
			{
				return true;
			}
		return false;
	}
	else
		if (d.getYear() < a.getYear())
		{
			return true;
		}
	return false;
}

bool operator>(const date_& d, const date_& a)
{
	if (d.getYear() == a.getYear())
	{
		if (d.getMonth() == a.getMonth())
		{
			if (d.getDay() == a.getDay())
			{
				return false;
			}
			else
				if (d.getDay() > a.getDay())
				{
					return true;
				}
			return false;
		}
		else
			if (d.getMonth() > a.getMonth())
			{
				return true;
			}
		return false;
	}
	else
		if (d.getYear() > a.getYear())
		{
			return true;
		}
	return false;
}

bool operator<=(const date_& d, const date_& a)
{
	if (d.getYear() == a.getYear())
	{
		if (d.getMonth() == a.getMonth())
		{
			if (d.getDay() == a.getDay())
			{
				return true;
			}
			else
				if (d.getDay() < a.getDay())
				{
					return true;
				}
			return false;
		}
		else
			if (d.getMonth() < a.getMonth())
			{
				return true;
			}
		return false;
	}
	else
		if (d.getYear() < a.getYear())
		{
			return true;
		}
	return false;
}

bool operator==(const date_& d, const date_& a)
{
	if (d.getYear() == a.getYear())
	{
		if (d.getMonth() == a.getMonth())
		{
			if (d.getDay() == a.getDay())
			{
				return true;
			}
			
		}
	}
	return false;
}

bool operator!=(const date_& d, const date_& a)
{

		if (d.getYear() == a.getYear())
		{
			if (d.getMonth() == a.getMonth())
			{
				if (d.getDay() == a.getDay())
				{
					return false;
				}

			}
		}
		return true;
}

bool operator>=(const date_& d, const date_& a)
{
	if (d.getYear() == a.getYear())
	{
		if (d.getMonth() == a.getMonth())
		{
			if (d.getDay() == a.getDay())
			{
				return true;
			}
			else
				if (d.getDay() > a.getDay())
				{
					return true;
				}
			return false;
		}
		else
			if (d.getMonth() > a.getMonth())
			{
				return true;
			}
		return false;
	}
	else
		if (d.getYear() > a.getYear())
		{
			return true;
		}
	return false;
}


int main()
{
	// 20,8,1989
	date_ a(60,5,2019);
	date_ b;
	cout << a << endl;
	cout << a.WhatDay() << endl;
	cin >> a;
	cout << a << endl;
	if (a > b)
	{
		cout << a;
	}
	//a.setDay(25);
	system("pause");
}