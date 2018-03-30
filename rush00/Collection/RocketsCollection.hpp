#ifndef ROCKETSCOLLECTION_HPP
# define ROCKETSCOLLECTION_HPP

# include "ACollection.hpp"
# include "../Object/Rocket.hpp"

class RocketsCollection: public ACollection
{
    public:
        RocketsCollection(void);
        RocketsCollection(const RocketsCollection & src);
        RocketsCollection &operator=(const RocketsCollection &);
        ~RocketsCollection(void);
        void updateObjects(void);
        void fire(int y, int x);
};

#endif
