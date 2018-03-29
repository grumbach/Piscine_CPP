#ifndef ENGINE_HPP
# define ENGINE_HPP

# include <ncurses.h>
# include <unistd.h>
# include <iostream>
# include <string>
# include "Collection/StarsCollection.hpp"
# include "Collection/RocketsCollection.hpp"

class Engine {
	public:
		Engine();
		Engine(const Engine &);
		Engine &operator=(const Engine &);
		~Engine();
		bool        start();                                // turn on the airplane
		void        launch();                               // fly the airplane
		void        finish();                               // land the airplane safely.
		void        crash(std::string const stopMessage);   // in case of error, display a crash message and exit.

	private:
		WINDOW      *frame;
		// Pilot    p;
		StarsCollection stars;
		RocketsCollection rockets;
		int         maxHeight;
		int         maxWidth;
};

std::ostream &      operator<<( std::ostream & o, Engine const & ngin );

#endif
