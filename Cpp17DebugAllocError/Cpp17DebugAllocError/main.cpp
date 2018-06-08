#include <iostream>

#include "memorydebug.hpp"


class alignas( 32 ) TestAlign
{
private:
	int m_iArray[ 32 ];
};


int main()
{
	TestAlign *pTest = new TestAlign;
	delete pTest;

	std::cin.get();
	return 0;
}