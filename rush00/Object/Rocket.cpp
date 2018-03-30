#include "Rocket.hpp"

// par defaut, on met les gameobjects en dehors de la fenetre
Rocket::Rocket(void) {
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
