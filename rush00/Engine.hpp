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
		void				start();
		void        		launch();								// fly the airplane
		void        		finish();								// land the airplane safely.
		static int  		maxHeight;
		static int  		maxWidth;

	private:
		WINDOW				*frame;
		Pilot				pilot;
		StarsCollection		stars;
		EnemiesCollection	enemies;
		bool				gameOver;
		void				printGameOver();
		void        		crash(std::string const stopMessage);	// in case of error, display a crash message and exit.
		void				manageCollision();
		void				printGame();
		void				keyGesture(char key);
};

std::ostream				&operator<<( std::ostream & o, Engine const & ngin );

#endif
