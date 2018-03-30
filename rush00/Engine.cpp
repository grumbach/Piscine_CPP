#include "Engine.hpp"
#include "bindings.hpp"

int Engine::maxHeight = 1;
int Engine::maxWidth = 1;

void Engine::start() {
    this->frame = initscr();       // renvoie l'addresse de la fenetre creee
    if(!has_colors()) {
        this->crash("Cannot play if colors are disabled !");
        return ;
    } else {
        start_color();              // rend l'utilisation des couleurs possible
    }
	noecho();                       // desactive l'affichage de caractere quand on appuie sur les touches
	curs_set(0);                    // cache le curseur du terminal
    keypad(this->frame, TRUE);      // rend possible la detection de pression sur les touches fleches
    nodelay(this->frame, TRUE);     // rend l'input (avec getch) non bloquant (asynchrome en quelque sorte)

    // recupere les dimensions de la fenetre (getmaxyx est une macro qui set les deux derniers parametres)
    getmaxyx(this->frame, Engine::maxHeight, Engine::maxWidth);
    if (Engine::maxHeight <= 20 || Engine::maxWidth <= 100) {
        this->crash("The terminal is way too small ! Please enlarge the window.");
    }

    // donne des bordures au spawner d etoiles
    this->pilot.setPosition(Engine::maxHeight / 2, ((Engine::maxWidth / 2) / 2) * 2);
    init_color(COLOR_RED, 250, 250, 250);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
}

// Game loop
void Engine::launch() {
    while (42) {
        if (this->gameOver) {
            this->printGameOver();
            refresh();
            usleep(1000000);
            return;
        }

        clear();                                    // efface tout l'ecran
        this->stars.updateObjects();                // fait bouger les etoiles (.) en background
        this->enemies.updateObjects();              // fait bouger les ennemis
        this->rocks.updateObjects();                // fait bouger les asteroides
        this->manageCollision(this->enemies);       // detruit les ennemis touchés
        this->manageCollision(this->rocks);         // creve face a un asteroide touché
        this->pilot.getRockets().updateObjects();   // fait bouger les missiles du pilote
        pilot.move();                               // fait bouger le pilote
        this->manageCollision(this->enemies);       // detruit les ennemis touchés
        this->manageCollision(this->rocks);         // creve face a un asteroide touché

        this->printGame();                          // met le jeu dans le buffer ncurses
        refresh();                                  // rafraichit la fenetre du terminal

        this->keyGesture(wgetch(this->frame));      // detecte les touches
    }
}

void Engine::manageCollision(ACollection &col) {
    AObject *enemy;
    AObject *rocket;

    for (int i = 0; i < col.getSize(); i++) {
        enemy = col.get(i);
        if (!enemy->getEnabled())
            continue;
        for (int i = 0; i < this->pilot.getRockets().getSize(); i++) {
            rocket = this->pilot.getRockets().get(i);
            if (!rocket->getEnabled())
                continue;
            // si la rocket est sur un ennemi
            if (rocket->getPosition().y == enemy->getPosition().y && rocket->getPosition().x == enemy->getPosition().x) {
                std::cerr << typeid(enemy).name() << std::endl;
                if (enemy->getShape() == 'O'){
                    this->score++;
                    enemy->setPosition(-1, -1);
                    enemy->setEnabled(false);
                }
                rocket->setPosition(-1, -1);
                rocket->setEnabled(false);
                break;
            }
        }
        if (enemy->getPosition().y == this->pilot.getPosition().y && enemy->getPosition().x == this->pilot.getPosition().x) {
            this->gameOver = true;
        }
    }
}

void Engine::printGame() {
    // affiche le pilote
    attron(A_UNDERLINE);
    attron(A_BOLD);
    attron(COLOR_PAIR(2));
    mvaddch(this->pilot.getPosition().y, this->pilot.getPosition().x, this->pilot.getShape());
    attroff(COLOR_PAIR(2));
    attroff(A_BOLD);
    attroff(A_UNDERLINE);

    // affiche toutes les etoiles ('.') qui passent en arriere plan
    for (int i = 0; i < this->stars.getSize(); i++) {
        AObject *star = this->stars.get(i);
        if (star->getEnabled()) {
            int x = star->getPosition().x;
            int y = star->getPosition().y;
            // attron(A_DIM);
            attron(COLOR_PAIR(1));
            mvaddch(y, x, star->getShape());
            attroff(COLOR_PAIR(1));
            // attroff(A_DIM);
        }
    }

    // affiche tous les ennemis ('O')
    for (int i = 0; i < this->enemies.getSize(); i++) {
        AObject *enemy = this->enemies.get(i);
        if (enemy->getEnabled()) {
            int x = enemy->getPosition().x;
            int y = enemy->getPosition().y;
            mvaddch(y, x, enemy->getShape());
        }
    }

    // affiche tous les asteroides ('%')
    for (int i = 0; i < this->rocks.getSize(); i++) {
        AObject *rocks = this->rocks.get(i);
        if (rocks->getEnabled()) {
            int x = rocks->getPosition().x;
            int y = rocks->getPosition().y;
            mvaddch(y, x, rocks->getShape());
        }
    }

    // affiche tous les missiles du pilote ('|')
    for (int i = 0; i < this->pilot.getRockets().getSize(); i++) {
        AObject *rocket = this->pilot.getRockets().get(i);
        if (rocket->getEnabled()) {
            int x = rocket->getPosition().x;
            int y = rocket->getPosition().y;
            mvaddch(y, x, rocket->getShape());
        }
    }
    mvprintw(1, 2, "Score: %d", this->score);
}


//////////////////////////////////////////////////////////
///
///            THINGS THAT DOESNT MATTER
///
//////////////////////////////////////////////////////////

void Engine::keyGesture(char key) {
    switch (key) {
        case KEY_ARROW_LEFT:
        case KEY_ARROW_RIGHT:
        case KEY_ARROW_UP:
        case KEY_ARROW_DOWN:
            this->pilot.setDirection(key);
            key = -1;
            break;
        case KEY_SPACE:
            this->pilot.shoot();
            break;
        case KEY_ECHAP:
            this->finish();
            exit(0);
            break;
        default:
            break;

    }
}

Engine::Engine(void) {
    this->gameOver = false;
    this->score = 0;
    this->start();
}

Engine::Engine(const Engine & src) {
    *this = src;
    this->start();
}

void Engine::printGameOver() {
    mvprintw((Engine::maxHeight / 2    ) - 2, (Engine::maxWidth - 55) / 2, "   ___                                                 \n");
    mvprintw((Engine::maxHeight / 2 + 1) - 2, (Engine::maxWidth - 55) / 2, "  / _ \\ __ _  _ __ ___    ___    ___ __   __ ___  _ __ \n");
    mvprintw((Engine::maxHeight / 2 + 2) - 2, (Engine::maxWidth - 55) / 2, " / /_\\// _` || '_ ` _ \\  / _ \\  / _ \\\\ \\ / // _ \\| '__|\n");
    mvprintw((Engine::maxHeight / 2 + 3) - 2, (Engine::maxWidth - 55) / 2, "/ /_\\\\| (_| || | | | | ||  __/ | (_) |\\ V /|  __/| |   \n");
    mvprintw((Engine::maxHeight / 2 + 4) - 2, (Engine::maxWidth - 55) / 2, "\\____/ \\__,_||_| |_| |_| \\___|  \\___/  \\_/  \\___||_|   \n");
}

void Engine::finish() {
    clear();
    refresh();
    endwin();
}

void Engine::crash(std::string const stopMessage) {
    clear();
    refresh();
    endwin();
    std::cerr << stopMessage << std::endl;
    exit(-1);
}

Engine::~Engine() {
}

Engine & Engine::operator=(Engine const &copy) {
    if (this != &copy){
        this->pilot = copy.pilot;
        this->frame = copy.frame;
        this->stars = copy.stars;
        this->enemies = copy.enemies;
        this->gameOver = copy.gameOver;    
        this->score = copy.score;
    }
    this->start();
    return *this;
}