#include "../Engine.hpp"
#include "StarsCollection.hpp"

StarsCollection::StarsCollection(void) {

	this->size = 40;
	this->data = new Star[this->size];
};

StarsCollection::StarsCollection(const StarsCollection &) {

};

void StarsCollection::updateObjects() {
	Star *obj;
	if (!this->checkElapsedTime(20))
		return;

	// parcours de tous les object pour les desactiver si ils sont sortis de l'ecran
	// et les faire bouger le cas echeant
	for (int i = 0; i < this->size; i++) {
		obj = (Star*)&this->data[i];
		if (obj->getEnabled()) {
			if (obj->getPosition().y > Engine::maxHeight) {
				// dprintf(2, "obj disabled\n");
				obj->setEnabled(false);
			}
		} else {
			// dprintf(2, "objet pas actif positionne en %d,%d\n", obj->getPosition().y, obj->getPosition().x);
			obj->setPosition(arc4random() % Engine::maxHeight - Engine::maxHeight, arc4random() % Engine::maxWidth);
			obj->setEnabled(true);
			// dprintf(2, "obj activated\n");
		}
		obj->move();
	}
}

StarsCollection & StarsCollection::operator=(const StarsCollection &) {
	return *this;
};

StarsCollection::~StarsCollection(void) {
	delete [] this->data;
};
