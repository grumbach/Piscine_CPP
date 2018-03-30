#include "Star.hpp"

// par defaut, on met les gameobjects en dehors de la fenetre
Star::Star(void)
{
    dprintf(2, "objet init en -1,-1\n");
    this->pos.x = -1;
    this->pos.y = -1;
    this->enabled = false;
    this->shape = '.';
};

Star::Star(const Star &) {

};

// bouge l'objet dans sa direction (pour l'instant toujours vers le bas mais on rajoutera peut etre une direction apres)
void Star::move(void) {
    if (this->enabled)
        this->pos.y += 1;
    // dprintf(2, "star a bouge en %d,%d, %d\n", this->pos.y, this->pos.x, this->enabled);
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
