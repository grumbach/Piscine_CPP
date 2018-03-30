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
		void				start(void);
		void        		launch(void);								// fly the airplane
		void        		finish(void);								// land the airplane safely.
		static int  		maxHeight;
		static int  		maxWidth;

	private:
		WINDOW				*frame;
		Pilot				pilot;
		StarsCollection		stars;
		EnemiesCollection	enemies;
		bool				gameOver;
		void				printGameOver(void);
		void        		crash(std::string const stopMessage);	// in case of error, display a crash message and exit.
		void				manageCollision(void);
		void				printGame(void);
		void				keyGesture(char key);
};

std::ostream				&operator<<( std::ostream & o, Engine const & ngin );

#endif
