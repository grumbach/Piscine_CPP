#include "RocketsCollection.hpp"

RocketsCollection::RocketsCollection(void) {

	this->size = 40;
	this->data = new Rocket[this->size];
};

RocketsCollection::RocketsCollection(const RocketsCollection &) {

};

void RocketsCollection::fire(int y, int x) {
	Rocket *rkt;

	dprintf(2, "FIRE ROCKET COLLECYION\n");
	for (int i = 0; i < this->size; i++) {
		rkt = (Rocket*)&this->data[i];
		if (!rkt->getEnabled()) {
			rkt->setPosition(y, x);
			rkt->setEnabled(true);
			dprintf(2, "set rkt (%d) to %d,%d\n", rkt->getEnabled(), rkt->getPosition().y, rkt->getPosition().x);
			return;
		}
	}
}

void RocketsCollection::updateObjects() {
	Rocket *obj;

	// parcours de tous les object pour les desactiver si ils sont sortis de l'ecran
	// et les faire bouger le cas echeant
	for (int i = 0; i < this->size; i++) {
		obj = (Rocket*)&this->data[i];
		if (obj->getEnabled()) {
			if (obj->getPosition().y < this->bounds.cornerY) {
				// dprintf(2, "obj disabled\n");
				obj->setEnabled(false);
			}
		}
		obj->move();
	}
}

RocketsCollection & RocketsCollection::operator=(const RocketsCollection &) {
	return *this;
};

RocketsCollection::~RocketsCollection(void) {

};

std::ostream & operator<<( std::ostream & o, RocketsCollection const & coll ) {
	(void)coll;
	// o << coll << std::endl;

	return o;
}
