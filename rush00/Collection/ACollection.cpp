#include "ACollection.hpp"

ACollection::ACollection(void) {
    // create 10 birds
    this->size = 40;
    this->data = new Object[this->size];
};

ACollection::ACollection(const ACollection &) {

};

int ACollection::getSize(void) const {
    return this->size;
}

Object *ACollection::get(int index) const {
    return &this->data[index];
}

void ACollection::setBounds(Bounds b) {
    this->bounds = b;
}

void ACollection::updateObjects() {
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

ACollection & ACollection::operator=(const ACollection &) {
    return *this;
};

ACollection::~ACollection(void) {

};

std::ostream & operator<<( std::ostream & o, ACollection const & coll ) {
    (void)coll;
	// o << coll << std::endl;

	return o;
}