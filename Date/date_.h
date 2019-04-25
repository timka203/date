#pragma once
#include <iostream>
#include<string>
using namespace std;

class date_
{
private:
	int day;
	int month;
	int year;
public:
	date_(int day = 1, int month = 1, int year = 1970);
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	int getDay() const;
	int getMonth()const;
	int getYear()const;
	string WhatDay();
	friend ostream& operator<<(ostream& os, const date_& d);
	friend istream& operator>>(istream& is, date_& d);
};
bool operator<(const date_& d, const date_& a);
bool operator>(const date_& d, const date_& a);
bool operator<=(const date_& d, const date_& a); 
bool operator==(const date_& d, const date_& a);
bool operator!=(const date_& d, const date_& a);
bool operator>=(const date_& d, const date_& a);