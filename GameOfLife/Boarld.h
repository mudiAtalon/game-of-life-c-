#pragma once

#include "pch.h"
#include <vector>


class Boarld 
{
public:
	Boarld(int n, int m)
	{
		squares = std::vector<std::vector<bool>>(n);
		for (std::vector<bool> row : squares)
			row = std::vector<bool>(m);
	}

	void clear();

	void step();
	void jump(int loops);
	void set(std::vector<std::vector<bool>> squares);
	void print();

private:
	bool nextState(int n, int m);
	bool get(int n, int m);

	std::vector<std::vector<bool>> squares;
};

