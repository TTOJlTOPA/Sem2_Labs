#ifndef ADULT_H
#define ADULT_H

#include "Human.h"

class Adult : public Human
{
	int passport;
public:
	Adult();
	Adult(char* iname, int iage, int iweight, int ipassport);
	Adult(const Adult& init);
	virtual ~Adult();
	void Print(ostream& out);
	void setAge(const int newage);
	void setPassport(const int newpassport);
};

#endif