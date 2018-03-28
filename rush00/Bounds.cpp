#include "Bounds.hpp"

Bounds::Bounds(void) {

};

Bounds::Bounds(int a, int b, int c, int d)
    : cornerX(a), cornerY(b), height(c), width(d) {
        return;
};

Bounds::Bounds(const Bounds & src) {
    this->cornerY = src.cornerY;
    this->cornerX = src.cornerX;
    this->height = src.height;
    this->width = src.width;
};

Bounds & Bounds::operator=(const Bounds &rhs) {
    this->cornerY = rhs.cornerY;
    this->cornerX = rhs.cornerX;
    this->height = rhs.height;
    this->width = rhs.width;
    return *this;
};

Bounds::~Bounds(void) {

};

std::ostream & operator<<( std::ostream & o, Bounds const & boundaries ) {
    (void)boundaries;
    // o << boundaries << std::endl;

    return o;
}