#ifndef STARSCOLLECTION_HPP
# define STARSCOLLECTION_HPP

# include "ACollection.hpp"
# include "../Object/Star.hpp"

class StarsCollection: public ACollection
{
    public:
        StarsCollection(void);
        StarsCollection(const StarsCollection & src);
        StarsCollection &operator=(const StarsCollection &);
        ~StarsCollection(void);
        void updateObjects(void);

};

#endif
