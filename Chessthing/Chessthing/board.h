#pragma once
#include "pieces.h"

class board {
public:
	board(void);
	~board(void);
	pieces* piece;
	board(pieces*);
};