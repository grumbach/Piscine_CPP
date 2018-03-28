#include "Bounds.hpp"

Bounds::Bounds(void) {

};

Bounds::Bounds(int a, int b, int c, int d)
    : cornerX(a), cornerY(b), height(c), width(d) {
        return;
};

Bounds::Bounds(const Bounds &) {

};

Bounds & Bounds::operator=(const Bounds &) {
    return *this;
};

Bounds::~Bounds(void) {

};

std::ostream & operator<<( std::ostream & o, Bounds const & boundaries ) {
    (void)boundaries;
    // o << boundaries << std::endl;

    return o;
}