#include "Pilot.hpp"
#include "../bindings.hpp"
#include "../Engine.hpp"

// par defaut, on met les gameobjects en dehors de la fenetre
Pilot::Pilot(void) {
    this->pos.x = -1;
    this->pos.y = -1;
    this->enabled = false;
    this->shape = '^';
};

Pilot::Pilot(const Pilot & src) {
	*this = src;
};

// bouge l'objet dans sa direction (pour l'instant toujours vers le bas mais on rajoutera peut etre une direction apres)
void Pilot::move(void) {
    switch (this->dir) {
        case KEY_ARROW_UP:
            this->pos.y -= 1;
            break;
        case KEY_ARROW_DOWN:
            this->pos.y += 1;
            break;
        case KEY_ARROW_RIGHT:
            this->pos.x += 1;
            break;
        case KEY_ARROW_LEFT:
            this->pos.x -= 1;
            break;
        default:
            break;
    }
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
    this->rockets.fire(this->pos.y - 1, this->pos.x);
}

void Pilot::setDirection(char dir) {
    this->dir = dir;
}

RocketsCollection &Pilot::getRockets(void) {
    return this->rockets;
}

Pilot & Pilot::operator=(const Pilot & rhs) {
	if (this != &rhs) {
	    this->pos.y = rhs.pos.y;
	    this->pos.x = rhs.pos.x;
	    this->enabled = rhs.enabled;
		this->dir = rhs.dir;
		this->rockets = rhs.rockets;
	}
	return *this;
};

Pilot::~Pilot(void) {

};
