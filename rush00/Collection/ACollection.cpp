#include "ACollection.hpp"

ACollection::ACollection(void): size(0), data(NULL) {
	// create 10 birds
	// this->size = 40;
	// this->data = new AObject[this->size];
	this->lastUpdate = clock();
};

ACollection::ACollection(const ACollection &copy) {
	*this = copy;
};

int ACollection::getSize(void) const {
	return this->size;
}

AObject *ACollection::get(int index) const {
	return &this->data[index];
}

ACollection & ACollection::operator=(const ACollection &copy) {
	this->data = copy.data;
	this->size = copy.size;
	this->lastUpdate = copy.lastUpdate;
	return *this;
}

bool ACollection::checkElapsedTime(double waitTimeMs) {
	clock_t	now = clock();
	double diffticks = now - this->lastUpdate;
	double diffms    = diffticks / ( CLOCKS_PER_SEC / 1000 );

	if (diffms < waitTimeMs)
		return false;

	this->lastUpdate = now;
	return true;
}

ACollection::~ACollection(void) {

};
