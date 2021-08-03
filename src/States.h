#pragma once
#ifndef STATES_H
#define STATES_h

enum class GameState {
	INTRO,
	MENU,
	GAMEPLAY,
	EXIT
};


enum class BulletState {
	NOT_SHOOT,
	SHOOT
};

#endif // !STATES_H

