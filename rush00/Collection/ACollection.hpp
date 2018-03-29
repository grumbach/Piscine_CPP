#ifndef COLLECTION_HPP
# define COLLECTION_HPP

# include <iostream>
# include <string>
# include "Bounds.hpp"
# include "Object/Star.hpp"

class ACollection
{
    public:
        virtual ACollection(void);
        ACollection(const ACollection &);
        ACollection &operator=(const ACollection &);
        ~ACollection(void);
        void    setBounds(Bounds newBounds);
        int     getSize(void) const;
        Star  *get(int index) const;
        void    updateObjects(void);

    private:
        Bounds  bounds;
        Star  *data;
        int     size;
};

std::ostream & operator<<( std::ostream & o, ACollection const & coll );

#endif