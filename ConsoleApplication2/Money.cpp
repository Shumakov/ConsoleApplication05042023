#include <iostream>
#include "Money.h"

void Money::plus(unsigned long r, unsigned char c) {
	rub += r;
	cent += c;
	normal();
}
void Money::plus(const Money& m) {
	plus(m.rub, m.cent);
}

Money operator+(const Money& a, const Money& b) {
	Money m(a.getRub() + b.getRub(), a.getCent() + b.getCent() );
	m.normal();
	return m;
}

Money& Money::operator+= (const Money& b) {
	plus(b);
	return *this;
}

Money& Money::operator++ () {	
	++rub;
	return *this;
}

Money operator++ (Money& a, int) {
	Money t = a;
	++a;
	return t;
}

Money& operator-- (Money& a) {
	a.minus(1, 0);
	return a;
}
Money operator-- (Money& a, int) {
	Money t = a;
	--a;
	return t;
}

std::ostream& operator<< (std::ostream& o, const Money& m) {
	o << m.rub << "," << (int)m.cent;
	return o;
}

std::istream& operator>> (std::istream& o, Money& m) {	
	int t;
	o >> m.rub;
	o >> t;	
	m.cent = t;
	return o;
}


void Money::minus(unsigned long r, unsigned char c) {
	if (rub < r)
		return;
	rub -= r;

	if (cent >= c)
		cent -= c;
	else {
		rub--;
		cent += 100;
		cent -= c;
	}
}
void Money::minus(const Money& m) {
	minus(m.rub, m.cent);
}

bool Money::equals(unsigned long r, unsigned char c) const {
	return (rub == r && cent == c);
}

bool Money::equals(const Money& m) const {
	return equals(m.rub, m.cent);
}

bool Money::lt(unsigned long r, unsigned char c) const {
	if (rub < r)
		return true;
	if (rub == r && cent < c)
		return true;
	return false;
}
bool Money::lt(const Money& m) const {
	return lt(m.rub, m.cent);
}

bool Money::gt(unsigned long r, unsigned char c) const {
	return !lt(r, c);
}
bool Money::gt(const Money& m) const {
	return !lt(m);
}
void Money::print() const {
	std::cout << rub << "," << (int)cent << std::endl;
}


long Money::operator[] (const char v) const {

	if (v == 'R' || v == 'r')
		return rub;
	return cent;
}

Money::operator int() {

	return rub;
}

Money::operator double() {
	return rub +cent/100.0;
}