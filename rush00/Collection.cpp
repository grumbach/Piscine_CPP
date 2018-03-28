#include "Collection.hpp"

Collection::Collection(void) {
    // create 10 birds
    this->size = 1;
    this->data = new Object[1];
};

Collection::Collection(const Collection &) {

};

int Collection::getSize(void) const {
    return this->size;
}

Object *Collection::get(int index) const {
    return &this->data[index];
}

void Collection::setBounds(Bounds b) {
    this->bounds = b;
}

void Collection::updateObjects() {
    Object *obj;

    // parcours de tous les object pour les desactiver si ils sont sortis de l'ecran
    // et les faire bouger le cas echeant
    for (int i = 0; i < this->size; i++) {
        obj = &this->data[i];
        if (obj->getEnabled()) {
            if (obj->getPosition().y > this->bounds.cornerY + this->bounds.height) {
                dprintf(2, "obj disabled\n");
                obj->setEnabled(false);
            }
            obj->move();
        }
    }

    for (int i = 0; i < this->size; i++) {
        obj = &this->data[i];
        // si l'objet n'est pas encore enabled
        if (!obj->getEnabled()) {
            if (obj->getPosition().y < this->bounds.cornerY) {
                dprintf(2, "objet pas actif positionne en %d,%d\n", obj->getPosition().y, obj->getPosition().x);
                // gotta check float point exception from % this->bounds.width.
                obj->setPosition(3, arc4random() % this->bounds.width);
                obj->setEnabled(true);
                dprintf(2, "obj activated\n");
            } else {
                dprintf(2, "obj a fini sa course ;(\n");
            }
            obj->move();
        }
    }
}

Collection & Collection::operator=(const Collection &) {
    return *this;
};

Collection::~Collection(void) {

};

std::ostream & operator<<( std::ostream & o, Collection const & coll ) {
    (void)coll;
	// o << coll << std::endl;

	return o;
}