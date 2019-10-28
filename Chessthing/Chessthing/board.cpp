#include "board.h"

board::board(void) {
	piece = nullptr;
}

board::board(pieces* p) {
	piece = p;
}

board::~board(void) {

}