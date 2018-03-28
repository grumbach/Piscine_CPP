#include "Object.hpp"

Object::Object(void) {

};

Object::Object(const Object &) {

};

bool Object::isEnabled(void) {
    return this->enabled == true;
}

t_point Object::getPosition(void) {
    return this->pos;
}

// bouge l'objet dans sa direction (pour l'instant toujours vers le bas mais on rajoutera peut etre une direction apres)
void Object::move(void) {
    if (this->enabled)
        this->pos.y += 1;
}

Object & Object::operator=(const Object &) {
    return *this;
};

Object::~Object(void) {

};

std::ostream & operator<<( std::ostream & o, Object const & obj ) {
    (void)obj;
	// o << obj << std::endl;

	return o;
}