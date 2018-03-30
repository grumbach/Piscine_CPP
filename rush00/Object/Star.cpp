#include "Star.hpp"

// par defaut, on met les gameobjects en dehors de la fenetre
Star::Star(void) {
    this->pos.x = -1;
    this->pos.y = -1;
    this->enabled = false;
    this->shape = '.';
};

Star::Star(const Star & src) {
	*this = src;
};

// bouge l'objet dans sa direction (pour l'instant toujours vers le bas mais on rajoutera peut etre une direction apres)
void Star::move(void) {
    if (this->enabled)
        this->pos.y += 1;
}

Star & Star::operator=(const Star & rhs) {
	if (this != &rhs) {
	    this->pos.y = rhs.pos.y;
	    this->pos.x = rhs.pos.x;
	    this->enabled = rhs.enabled;
	}
	return *this;
};

Star::~Star(void) {

};
