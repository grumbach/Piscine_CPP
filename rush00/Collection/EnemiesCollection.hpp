#ifndef ENEMIESCOLLECTION_CPP
# define ENEMIESCOLLECTION_CPP

# include "ACollection.hpp"
# include "../Object/Enemy.hpp"

class EnemiesCollection: public ACollection
{
    public:
        EnemiesCollection(void);
        EnemiesCollection(const EnemiesCollection &copy);
        EnemiesCollection &operator=(const EnemiesCollection &copy);
        ~EnemiesCollection(void);
        void updateObjects(void);

};

#endif
