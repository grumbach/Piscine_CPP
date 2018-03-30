#include "RocketsCollection.hpp"

RocketsCollection::RocketsCollection(void) {

	this->size = 40;
	this->data = new Rocket[this->size];
};

RocketsCollection::RocketsCollection(const RocketsCollection &copy) {
	*this = copy;
};

void RocketsCollection::fire(int y, int x) {
	Rocket *rkt;

	for (int i = 0; i < this->size; i++) {
		rkt = (Rocket*)&this->data[i];
		if (!rkt->getEnabled()) {
			rkt->setPosition(y, x);
			rkt->setEnabled(true);
			return;
		}
	}
}

void RocketsCollection::updateObjects() {
	Rocket *obj;

	if (!this->checkElapsedTime(100))
		return;

	// parcours de tous les object pour les desactiver si ils sont sortis de l'ecran
	// et les faire bouger le cas echeant
	for (int i = 0; i < this->size; i++) {
		obj = (Rocket*)&this->data[i];
		if (obj->getEnabled()) {
			if (obj->getPosition().y < 0) {
				obj->setEnabled(false);
			}
		}
		obj->move();
	}
}

RocketsCollection & RocketsCollection::operator=(const RocketsCollection &copy) {
	this->data = copy.data;
	this->size = copy.size;
	this->lastUpdate = copy.lastUpdate;
	return *this;
};

RocketsCollection::~RocketsCollection(void) {
	delete [] this->data;
};