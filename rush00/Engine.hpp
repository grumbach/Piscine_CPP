#ifndef ENGINE_HPP
# define ENGINE_HPP

# include <ncurses.h>
# include <unistd.h>
# include <iostream>
# include <string>
# include "Collection/StarsCollection.hpp"
# include "Collection/EnemiesCollection.hpp"
# include "Object/Pilot.hpp"

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
		static int  maxHeight;
		static int  maxWidth;

	private:
		WINDOW      		*frame;
		Pilot				pilot;
		StarsCollection		stars;
		EnemiesCollection	enemies;
};

std::ostream &      operator<<( std::ostream & o, Engine const & ngin );

#endif
