#include "Player.h"

Player::Player() {
	this->x = 1;
	this->y = 1;
	this->movingDirection = 0;
}
void Player::changeDir(int m) {
	this->movingDirection = m;
}