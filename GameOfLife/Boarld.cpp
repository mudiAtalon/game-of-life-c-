#include "pch.h"
#include <vector>
#include "Boarld.h"

void Boarld::clear()
{
	squares.clear();
}

void Boarld::set(std::vector<std::vector<bool>> squares)
{
	this->squares = squares;
}

bool Boarld::get(int n, int m)
{
	if (n < 0 || n >= squares.size() || m < 0 || m >= squares.at(0).size())
		return false;
	return squares.at(n).at(m);
}

bool Boarld::nextState(int n, int m)
{
	int cnt = 0;
	for (int n2 = n - 1; n2 <= n + 1; n2++)
		for (int m2 = m - 1; m2 <= m + 1; m2++)
			if (get(n,m))
				cnt++;
	if (squares.at(n).at(m))
		cnt--;
	return cnt == 3 || (cnt == 2 && squares.at(n).at(m));
}

void Boarld::step()
{
	std::vector<std::vector<bool>> tmp = std::vector<std::vector<bool>>(squares.size());
	for (int n = 0; n < squares.size(); n++)
	{
		tmp.at(n) = std::vector<bool>(squares.at(n).size());
		for (int m = 0; m < squares.at(n).size(); m++)
			tmp.at(n).at(m) = nextState(n, m);
	}
	squares = tmp;
}

void Boarld::jump(int loops)
{
	for (int loop = 0; loop < loops; loop++)
		step();
}

void Boarld::print()
{
	for (int n = 0; n < squares.size(); n++)
	{
		for (int m = 0; m < squares.at(n).size(); m++)
			std::cout << squares.at(n).at(m) ? '*' : ' ';
		std::cout << std::endl;
	}
}
