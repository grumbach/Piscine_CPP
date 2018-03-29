#include "Star.hpp"

// par defaut, on met les gameobjects en dehors de la fenetre
Star::Star(void): AObject(void) {
    dprintf(2, "objet init en -1,-1\n");
    this->pos.x = -1;
    this->pos.y = -1;
    this->enabled = false;
};

Star::Star(const Star &) {

};

bool Star::getEnabled(void) {
    return this->enabled;
}

t_point Star::getPosition(void) {
    return this->pos;
}

// bouge l'objet dans sa direction (pour l'instant toujours vers le bas mais on rajoutera peut etre une direction apres)
// void Star::move(void) {
//     if (this->enabled)
//         this->pos.y += 1;
//     dprintf(2, "obj a bouge en %d,%d, %d\n", this->pos.y, this->pos.x, this->enabled);
// }

void Star::setPosition(int y, int x) {
    this->pos.y = y;
    this->pos.x = x;
    dprintf(2, "My position is now %d %d\n", this->pos.y, this->pos.x);
}

void Star::setEnabled(bool enabled) {
    this->enabled = enabled;
}

Star & Star::operator=(const Star & rhs) {
    this->pos.y = rhs.pos.y;
    this->pos.x = rhs.pos.x;
    this->enabled = rhs.enabled;
    dprintf(2, "Objet modifie en %d,%d\n", this->pos.y, this->pos.x);
    return *this;
};

Star::~Star(void) {

};

std::ostream & operator<<( std::ostream & o, Star const & obj ) {
    (void)obj;
	// o << obj << std::endl;

	return o;
}