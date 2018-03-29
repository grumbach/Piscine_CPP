#include "ACollection.hpp"

ACollection::ACollection(void): size(0), data(NULL) {
	// create 10 birds
	// this->size = 40;
	// this->data = new AObject[this->size];
};

ACollection::ACollection(const ACollection &) {

};

int ACollection::getSize(void) const {
	return this->size;
}

AObject *ACollection::get(int index) const {
	return &this->data[index];
}

void ACollection::setBounds(Bounds b) {
	this->bounds = b;
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
