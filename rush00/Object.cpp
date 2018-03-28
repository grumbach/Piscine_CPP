#include "Object.hpp"

// par defaut, on met les gameobjects en dehors de la fenetre
Object::Object(void) {
    dprintf(2, "objet init en -1,-1\n");
    this->pos.x = -1;
    this->pos.y = -1;
    this->enabled = false;
};

Object::Object(const Object &) {

};

bool Object::getEnabled(void) {
    return this->enabled;
}

t_point Object::getPosition(void) {
    return this->pos;
}

// bouge l'objet dans sa direction (pour l'instant toujours vers le bas mais on rajoutera peut etre une direction apres)
void Object::move(void) {
    if (this->enabled)
        this->pos.y += 1;
    dprintf(2, "obj a bouge en %d,%d, %d\n", this->pos.y, this->pos.x, this->enabled);
}

void Object::setPosition(int y, int x) {
    this->pos.y = y;
    this->pos.x = x;
    dprintf(2, "My position is now %d %d\n", this->pos.y, this->pos.x);
}

void Object::setEnabled(bool enabled) {
    this->enabled = enabled;
}

Object & Object::operator=(const Object & rhs) {
    this->pos.y = rhs.pos.y;
    this->pos.x = rhs.pos.x;
    this->enabled = rhs.enabled;
    dprintf(2, "Objet modifie en %d,%d\n", this->pos.y, this->pos.x);
    return *this;
};

Object::~Object(void) {

};

std::ostream & operator<<( std::ostream & o, Object const & obj ) {
    (void)obj;
	// o << obj << std::endl;

	return o;
}