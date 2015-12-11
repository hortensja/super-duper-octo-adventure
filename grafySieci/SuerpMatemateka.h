#pragma once

#include <iostream>


class SuerpMatemateka
{
public:
	SuerpMatemateka();
	~SuerpMatemateka();

	static int min(int a, int b);
	static char * readFromFile(std::string nazwaPliku);
};

