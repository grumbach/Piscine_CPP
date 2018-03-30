#include "AObject.hpp"

// par defaut, on met les gameobjects en dehors de la fenetre
AObject::AObject(void) {
    this->pos.x = -1;
    this->pos.y = -1;
    this->enabled = false;
};

AObject::AObject(const AObject &copy) {
	*this = copy;
};

bool AObject::getEnabled(void) {
    return this->enabled;
}

t_point AObject::getPosition(void) {
    return this->pos;
}

char    AObject::getShape(void) const
{
    return this->shape;
}

void AObject::setPosition(int y, int x) {
    this->pos.y = y;
    this->pos.x = x;
}

void AObject::setEnabled(bool enabled) {
    this->enabled = enabled;
}

AObject & AObject::operator=(const AObject &copy) {
	if (this != &copy) {
	    this->pos.y = copy.pos.y;
	    this->pos.x = copy.pos.x;
	    this->enabled = copy.enabled;
	}
	return *this;
};

AObject::~AObject(void) {

};
