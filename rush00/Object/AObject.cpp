#include "AObject.hpp"

// par defaut, on met les gameobjects en dehors de la fenetre
AObject::AObject(void) {
    dprintf(2, "objet init en -1,-1\n");
    this->pos.x = -1;
    this->pos.y = -1;
    this->enabled = false;
};

AObject::AObject(const AObject &) {

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

// bouge l'objet dans sa direction (pour l'instant toujours vers le bas mais on rajoutera peut etre une direction apres)
// void AObject::move(void) {
//     if (this->enabled)
//         this->pos.y += 1;
//     dprintf(2, "obj a bouge en %d,%d, %d\n", this->pos.y, this->pos.x, this->enabled);
// }

void AObject::setPosition(int y, int x) {
    this->pos.y = y;
    this->pos.x = x;
    // dprintf(2, "My position is now %d %d\n", this->pos.y, this->pos.x);
}

void AObject::setEnabled(bool enabled) {
    this->enabled = enabled;
}

AObject & AObject::operator=(const AObject & rhs) {
    this->pos.y = rhs.pos.y;
    this->pos.x = rhs.pos.x;
    this->enabled = rhs.enabled;
    dprintf(2, "Objet modifie en %d,%d\n", this->pos.y, this->pos.x);
    return *this;
};

AObject::~AObject(void) {

};
