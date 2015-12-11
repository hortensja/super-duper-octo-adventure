#include "SuerpMatemateka.h"

#include <fstream>



SuerpMatemateka::SuerpMatemateka()
{
}


SuerpMatemateka::~SuerpMatemateka()
{
}

int SuerpMatemateka::min(int a, int b)
{
	return (a > b) ? b : a;
}


char * SuerpMatemateka::readFromFile(std::string nazwaPliku)
{
	std::ifstream is(nazwaPliku, std::ifstream::binary);
	if (is) {
		// get length of file:
		is.seekg(0, is.end);
		int rozmiarDanych = is.tellg();
		is.seekg(0, is.beg);

		char *zawartoscDanych = new char[rozmiarDanych];

		std::cout << "Reading " << rozmiarDanych << " characters... ";
		// read data as a block:
		is.read(zawartoscDanych, rozmiarDanych);

		if (is)
			std::cout << "all characters read successfully.";
		else
			std::cout << "error: only " << is.gcount() << " could be read";
		std::cout << std::endl;
		is.close();

		return zawartoscDanych;

	}
	else {
		std::cout << "Nie udalo sie otworzyc pliku\n";
		return nullptr;
	}
}
