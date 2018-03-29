#include "RocketsCollection.hpp"

RocketsCollection::RocketsCollection(void) {

	this->size = 40;
	this->data = new Rocket[this->size];
};

RocketsCollection::RocketsCollection(const RocketsCollection &) {

};

void RocketsCollection::updateObjects() {
	Rocket *obj;

	// parcours de tous les object pour les desactiver si ils sont sortis de l'ecran
	// et les faire bouger le cas echeant
	for (int i = 0; i < this->size; i++) {
		obj = (Rocket*)&this->data[i];
		if (obj->getEnabled()) {
			if (obj->getPosition().y > this->bounds.cornerY + this->bounds.height) {
				dprintf(2, "obj disabled\n");
				obj->setEnabled(false);
			}
		} else {
			dprintf(2, "objet pas actif positionne en %d,%d\n", obj->getPosition().y, obj->getPosition().x);
			obj->setPosition(arc4random() % this->bounds.height - this->bounds.height, arc4random() % this->bounds.width);
			obj->setEnabled(true);
			dprintf(2, "obj activated\n");
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
