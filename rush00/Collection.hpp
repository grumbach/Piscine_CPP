#ifndef COLLECTION_HPP
# define COLLECTION_HPP

# include <iostream>
# include <string>
# include "Bounds.hpp"
# include "Object.hpp"

class Collection
{
    public:
        Collection(void);
        Collection(const Collection &);
        Collection &operator=(const Collection &);
        ~Collection(void);
        void    setBounds(Bounds newBounds);
        int     getSize(void) const;
        Object  *get(int index) const;
        void    updateObjects(void);

    private:
        Bounds  bounds;
        Object  *data;
        int     size;
};

std::ostream & operator<<( std::ostream & o, Collection const & coll );

#endif