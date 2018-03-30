#include "Pilot.hpp"
#include "../bindings.hpp"
#include "../Engine.hpp"

// par defaut, on met les gameobjects en dehors de la fenetre
Pilot::Pilot(void)
{
    dprintf(2, "objet init en bas de la map\n");
    this->pos.x = -1;
    this->pos.y = -1;
    this->enabled = false;
    this->shape = '^';
};

Pilot::Pilot(const Pilot &) {
};

// bouge l'objet dans sa direction (pour l'instant toujours vers le bas mais on rajoutera peut etre une direction apres)
void Pilot::move(void) {
    if (this->dir == KEY_NONE)
        return;
    if (this->dir == KEY_ARROW_UP)
        this->pos.y -= 1;
    if (this->dir == KEY_ARROW_DOWN)
        this->pos.y += 1;
    if (this->dir == KEY_ARROW_RIGHT)
        this->pos.x += 1;
    if (this->dir == KEY_ARROW_LEFT)
        this->pos.x -= 1;
    if (this->pos.x > Engine::maxWidth)
        this->pos.x = 1;
    if (this->pos.x < 0)
        this->pos.x = Engine::maxWidth - 1;
    if (this->pos.y > Engine::maxHeight - 1)
        this->pos.y = Engine::maxHeight - 1;
    if (this->pos.y < 0)
        this->pos.y = 1;
    this->dir = KEY_NONE;
}

void Pilot::shoot(void) {
    this->rockets.fire(this->pos.y, this->pos.x);
}

void Pilot::setDirection(char dir) {
    this->dir = dir;
}

RocketsCollection &Pilot::getRockets(void) {
    return this->rockets;
}

Pilot & Pilot::operator=(const Pilot & rhs) {
    this->pos.y = rhs.pos.y;
    this->pos.x = rhs.pos.x;
    this->enabled = rhs.enabled;
    dprintf(2, "Objet modifie en %d,%d\n", this->pos.y, this->pos.x);
    return *this;
};

Pilot::~Pilot(void) {

};

std::ostream & operator<<( std::ostream & o, Pilot const & obj ) {
    (void)obj;
	// o << obj << std::endl;

	return o;
}