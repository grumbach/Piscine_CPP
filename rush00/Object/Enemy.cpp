#include "Enemy.hpp"

// par defaut, on met les gameobjects en dehors de la fenetre
Enemy::Enemy(void) {
    this->pos.x = -1;
    this->pos.y = -1;
    this->enabled = false;
    this->shape = 'O';
};

Enemy::Enemy(const Enemy & src) {
	*this = src;
};

// bouge l'objet dans sa direction (pour l'instant toujours vers le bas mais on rajoutera peut etre une direction apres)
void Enemy::move(void) {
    if (this->enabled)
        this->pos.y += 1;
}

Enemy & Enemy::operator=(const Enemy & rhs) {
	if (this != &rhs) {
	    this->pos.y = rhs.pos.y;
	    this->pos.x = rhs.pos.x;
	    this->enabled = rhs.enabled;
	}
	return *this;
};

Enemy::~Enemy(void) {

};
