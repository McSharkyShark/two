#pragma once
#include <string>

using namespace std;

class pieces {
	public:
		pieces(void);
		~pieces(void);
		string naam;
		int player;
		pieces(string, int);
};