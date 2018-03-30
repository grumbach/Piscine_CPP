#include "Rocket.hpp"

// par defaut, on met les gameobjects en dehors de la fenetre
Rocket::Rocket(void)
{
    dprintf(2, "objet init en -1,-1\n");
    this->pos.x = -1;
    this->pos.y = -1;
    this->enabled = false;
    this->shape = '|';
};

Rocket::Rocket(const Rocket & src) {
	*this = src;
};

// bouge l'objet dans sa direction (pour l'instant toujours vers le bas mais on rajoutera peut etre une direction apres)
void Rocket::move(void) {
    if (this->enabled)
        this->pos.y -= 1;
    // dprintf(2, "rocket a bouge en %d,%d, %d\n", this->pos.y, this->pos.x, this->enabled);
}

Rocket & Rocket::operator=(const Rocket & rhs) {
	if (this != &rhs) {
	    this->pos.y = rhs.pos.y;
	    this->pos.x = rhs.pos.x;
	    this->enabled = rhs.enabled;
	}
	return *this;
};

Rocket::~Rocket(void) {

};
