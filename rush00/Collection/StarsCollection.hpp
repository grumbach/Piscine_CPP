#ifndef STARSCOLLECTION_HPP
# define STARSCOLLECTION_HPP

# include "ACollection.hpp"
# include "../Object/Star.hpp"

class StarsCollection: public ACollection
{
    public:
        StarsCollection(void);
        StarsCollection(const StarsCollection &copy);
        StarsCollection &operator=(const StarsCollection &copy);
        ~StarsCollection(void);
        void updateObjects(void);

};

#endif
