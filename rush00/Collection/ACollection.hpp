#ifndef COLLECTION_HPP
# define COLLECTION_HPP

# include <iostream>
# include <string>
# include "../Bounds.hpp"
# include "../Object/Star.hpp"

class ACollection
{
    public:
        ACollection(void);
        ACollection(const ACollection &);
        ACollection &operator=(const ACollection &);
        ~ACollection(void);
        void    setBounds(Bounds newBounds);
        int     getSize(void) const;
        AObject *get(int index) const;
        virtual void    updateObjects(void) = 0;

    protected:
        Bounds  bounds;
        int     size;
        AObject *data;
};

std::ostream & operator<<( std::ostream & o, ACollection const & coll );

#endif