#ifndef BOUNDS_HPP
# define BOUNDS_HPP

# include <iostream>
# include <string>

/**
 * Represente une bordure rectangulaire
 */
class Bounds
{
    public:
        int     cornerX;    // La position X du coin haut-gauche de la box
        int     cornerY;    // La position X du coin haut-gauche de la box
        int     height;     // La hauteur de la box
        int     width;      // La largeur de la box
        Bounds(void);
        Bounds(int cornerX, int cornerY, int height, int width);
        Bounds(const Bounds &);
        Bounds &operator=(const Bounds &);
        ~Bounds(void);
};

std::ostream & operator<<( std::ostream & o, Bounds const & Bounds );

#endif