#ifndef ROCKSCOLLECTION_HPP
# define ROCKSCOLLECTION_HPP

# include "ACollection.hpp"
#include "../Object/Enemy.hpp"

class RocksCollection: public ACollection
{
    public:
        RocksCollection(void);
        RocksCollection(const RocksCollection &copy);
        RocksCollection &operator=(const RocksCollection &copy);
        ~RocksCollection(void);
        void updateObjects(void);

};

#endif
