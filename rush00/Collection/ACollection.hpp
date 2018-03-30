#ifndef COLLECTION_HPP
# define COLLECTION_HPP

# include <iostream>
# include <string>
# include "../Object/Star.hpp"

class ACollection
{
    public:
        ACollection(void);
        ACollection(const ACollection & src);
        ACollection &operator=(const ACollection &);
        virtual ~ACollection(void);
        int             getSize(void) const;
        AObject         *get(int index) const;
        virtual void    updateObjects(void) = 0;
        bool            checkElapsedTime(double waitTimeMs);

    protected:
        int             size;
        AObject         *data;
        clock_t         lastUpdate;
};

#endif
