#include "Enemy.hpp"

// par defaut, on met les gameobjects en dehors de la fenetre
Enemy::Enemy(void)
{
    dprintf(2, "objet init en -1,-1\n");
    this->pos.x = -1;
    this->pos.y = -1;
    this->enabled = false;
    this->shape = 'O';
};

Enemy::Enemy(const Enemy &) {

};

// bouge l'objet dans sa direction (pour l'instant toujours vers le bas mais on rajoutera peut etre une direction apres)
void Enemy::move(void) {
    if (this->enabled)
        this->pos.y += 1;
    // dprintf(2, "Enemy a bouge en %d,%d, %d\n", this->pos.y, this->pos.x, this->enabled);
}

Enemy & Enemy::operator=(const Enemy & rhs) {
    this->pos.y = rhs.pos.y;
    this->pos.x = rhs.pos.x;
    this->enabled = rhs.enabled;
    dprintf(2, "Objet modifie en %d,%d\n", this->pos.y, this->pos.x);
    return *this;
};

Enemy::~Enemy(void) {

};

std::ostream & operator<<( std::ostream & o, Enemy const & obj ) {
    (void)obj;
	// o << obj << std::endl;

	return o;
}