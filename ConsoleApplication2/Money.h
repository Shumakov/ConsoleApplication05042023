#pragma once

class Money{

	unsigned long rub{};
	unsigned char cent{};

	/*void normal() {
		rub += cent / 100;
		cent %= 100;
	}*/

public:
	Money() { std::cout << "Create Money" << std::endl; };
	Money(unsigned long r, unsigned char c):rub { r }, cent{c}
	{std::cout << "Create Money" << std::endl; };

	void normal() {
		rub += cent / 100;
		cent %= 100;
	}

	unsigned char getCent() const { return cent; };
	unsigned long getRub() const { return rub; };

	void setRub(unsigned long r) { rub = r; }
	void setCent(unsigned char c) { cent = c; }
	
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

	friend std::ostream& operator<< (std::ostream& o, const Money& m);
	friend std::istream& operator>> (std::istream& o, Money& m);

	Money& operator+= ( const Money& b);
	Money& operator++ ();
};

Money operator+ (const Money& a, const Money& b);
//Money& operator+= (Money& a, const Money& b);
//Money& operator++ (Money& a); // ++a
Money operator++ (Money& a, int); // a++
Money& operator-- (Money& a); // --a
Money operator-- (Money& a, int); // a--


