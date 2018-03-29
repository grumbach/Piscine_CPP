#include "EnemiesCollection.hpp"

EnemiesCollection::EnemiesCollection(void)
{
	this->size = 40;
	this->data = new Enemy[this->size];
};

EnemiesCollection::EnemiesCollection (const EnemiesCollection &)
{

};

void EnemiesCollection::updateObjects() {
	Star *obj;

	// parcours de tous les object pour les desactiver si ils sont sortis de l'ecran
	// et les faire bouger le cas echeant
	for (int i = 0; i < this->size; i++) {
		obj = (Star*)&this->data[i];
		if (obj->getEnabled()) {
			if (obj->getPosition().y > this->bounds.cornerY + this->bounds.height) {
				// dprintf(2, "obj disabled\n");
				obj->setEnabled(false);
			}
		} else {
			// dprintf(2, "objet pas actif positionne en %d,%d\n", obj->getPosition().y, obj->getPosition().x);
			if (arc4random() % 100 < 1) { // le faire que dans 1% des cas
				obj->setPosition(arc4random() % this->bounds.height - this->bounds.height, arc4random() % this->bounds.width);
				obj->setEnabled(true);
				// dprintf(2, "obj activated\n");
			}
		}
		obj->move();
	}
}

EnemiesCollection & EnemiesCollection::operator=(const EnemiesCollection &) {
	return *this;
};

EnemiesCollection::~EnemiesCollection(void) {

};

std::ostream & operator<<( std::ostream & o, EnemiesCollection const & coll ) {
	(void)coll;
	// o << coll << std::endl;

	return o;
}
