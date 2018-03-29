#ifndef STARSCOLLECTION_HPP
# define STARSCOLLECTION_HPP

# include "ACollection.hpp"
# include "../Object/Star.hpp"

class StarsCollection: public ACollection
{
    public:
        StarsCollection(void);
        StarsCollection(const StarsCollection &);
        StarsCollection &operator=(const StarsCollection &);
        ~StarsCollection(void);
        void updateObjects(void);

};

std::ostream & operator<<( std::ostream & o, StarsCollection const & coll );

#endif
