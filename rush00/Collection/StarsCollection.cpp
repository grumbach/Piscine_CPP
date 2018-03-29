#include "StarsCollection.hpp"

StarsCollection::StarsCollection(void) {
	// create 10 birds
	this->size = 40;
	this->data = new Star[this->size];
};

StarsCollection::StarsCollection(const StarsCollection &) {

};

void StarsCollection::updateObjects() {
	Star *obj;

	// parcours de tous les object pour les desactiver si ils sont sortis de l'ecran
	// et les faire bouger le cas echeant
	for (int i = 0; i < this->size; i++) {
		obj = (Star*)&this->data[i];
		if (obj->getEnabled()) {
			if (obj->getPosition().y > this->bounds.cornerY + this->bounds.height) {
				dprintf(2, "obj disabled\n");
				obj->setEnabled(false);
			}
			obj->move();
		}
	}

	for (int i = 0; i < this->size; i++) {
		obj = (Star*)&this->data[i];
		// si l'objet n'est pas encore enabled
		if (!obj->getEnabled()) {
				dprintf(2, "objet pas actif positionne en %d,%d\n", obj->getPosition().y, obj->getPosition().x);
				// if (arc4random)
				// gotta check float point exception from % this->bounds.width.
				obj->setPosition(arc4random() % this->bounds.height - this->bounds.height, arc4random() % this->bounds.width);
				obj->setEnabled(true);
				dprintf(2, "obj activated\n");
			obj->move();
		}
	}
}

StarsCollection & StarsCollection::operator=(const StarsCollection &) {
	return *this;
};

StarsCollection::~StarsCollection(void) {

};

std::ostream & operator<<( std::ostream & o, StarsCollection const & coll ) {
	(void)coll;
	// o << coll << std::endl;

	return o;
}