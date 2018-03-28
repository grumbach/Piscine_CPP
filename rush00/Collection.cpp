#include "Collection.hpp"

Collection::Collection(void) {
    // create 10 birds
    this->size = 10;
    this->data = new Object[10];
};

Collection::Collection(const Collection &) {

};

int Collection::getSize(void) const {
    return this->size;
}

Object Collection::get(int index) {
    return this->data[index];
}

void Collection::setBounds(Bounds b) {
    this->bounds = b;
}

void Collection::updateObjects() {
    for (int i = 0; i < this->size; i++) {
        if (this->data[i].isEnabled()) {
            this->data[i].move();
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