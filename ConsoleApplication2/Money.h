#pragma once
class Money{

	unsigned long rub{};
	unsigned char cent{};

	void normal() {
		rub += cent / 100;
		cent %= 100;
	}

public:
	Money() {};
	Money(unsigned long r, unsigned char c):rub { r }, cent{c} {};

	void plus(unsigned long r, unsigned char c);
	void plus( const Money& m);

	void minus(unsigned long r, unsigned char c);
	void minus(const Money& m);

	bool equals (unsigned long r, unsigned char c) const;
	bool equals(const Money& m) const;

	bool lt(unsigned long r, unsigned char c) const;
	bool lt(const Money& m) const;

	bool gt(unsigned long r, unsigned char c) const;
	bool gt(const Money& m) const;

	void print() const;
};

