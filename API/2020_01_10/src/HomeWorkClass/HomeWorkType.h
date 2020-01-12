#pragma once

#define BIT(x) (1 << x)

#ifndef MYTYPE
#define MYTYPE
enum PlayerState {
	playerNone		= 0,
	playerStop		= BIT(0),
	playerRunning	= BIT(1),
	playerJumping	= BIT(2),
	playerCrash		= BIT(3),
	playerDie		= BIT(4),
	playerGoal		= BIT(5)
};

inline PlayerState operator|=(PlayerState& ps1, const PlayerState& ps2) {
	int temp = int(ps1);
	temp |= int(ps2);
	return ps1 = (PlayerState)temp;
}

inline PlayerState operator^=(PlayerState& ps1, const PlayerState& ps2) {
	int temp = int(ps1);
	temp ^= int(ps2);
	return ps1 = (PlayerState)temp;
}

inline bool operator&(const PlayerState& ps1, const PlayerState& ps2) {
	return (int)ps1 & (int)ps2;
}

inline PlayerState operator-=(PlayerState& ps1, const PlayerState& ps2) {
	int temp = int(ps1);
	if (ps1 & ps2) {
		temp -= (int)ps2;
	}
	return ps1 = (PlayerState)temp;
}

#endif