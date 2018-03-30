#include "EnemiesCollection.hpp"
#include "../Engine.hpp"

EnemiesCollection::EnemiesCollection(void)
{
	this->size = 40;
	this->data = new Enemy[this->size];
};

EnemiesCollection::EnemiesCollection (const EnemiesCollection &copy){
	*this = copy;
};

void EnemiesCollection::updateObjects() {
	Enemy *obj;

	if (!this->checkElapsedTime(300))
		return;

	// parcours de tous les object pour les desactiver si ils sont sortis de l'ecran
	// et les faire bouger le cas echeant
	for (int i = 0; i < this->size; i++) {
		obj = (Enemy*)&this->data[i];
		if (obj->getEnabled()) {
			if (obj->getPosition().y > Engine::maxHeight) {
				// dprintf(2, "obj disabled\n");
				obj->setEnabled(false);
			}
		} else {
			// dprintf(2, "objet pas actif positionne en %d,%d\n", obj->getPosition().y, obj->getPosition().x);
			if (arc4random() % 100 < 1) { // le faire que dans 1% des cas
				obj->setPosition(arc4random() % Engine::maxHeight - Engine::maxHeight, ((arc4random() % Engine::maxWidth) / 2) * 2);
				obj->setEnabled(true);
				// dprintf(2, "obj activated\n");
			}
		}
		obj->move();
	}
}

EnemiesCollection & EnemiesCollection::operator=(const EnemiesCollection &copy) {
	if (this != &copy){
		this->data = copy.data;
		this->size = copy.size;
		this->lastUpdate = copy.lastUpdate;
	}
	return *this;
};

EnemiesCollection::~EnemiesCollection(void) {
	delete [] this->data;
};