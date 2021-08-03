#pragma once
#ifndef CONSTANTS_H
#define CONSTANTS_H
#include "GameWindow.h"

const int TILE_SIZE = 32;
const int WND_WIDTH_FULL_HD = 1920;

template<typename Type>
const Type resizer(Type firstNumber, Type secondNumber) {
	const Type resize = GameWindow::getWindowSize().x >= WND_WIDTH_FULL_HD ? firstNumber : secondNumber;
	return resize;
}

#endif // !CONSTANTS_H
