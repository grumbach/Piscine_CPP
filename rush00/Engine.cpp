#include "Engine.hpp"
#include "bindings.hpp"

int Engine::maxHeight = 1;
int Engine::maxWidth = 1;

void Engine::start() {
    this->frame = initscr();    // renvoie l'addresse de la fenetre creee
    if(!has_colors()) {
        this->crash("Cannot play if colors are disabled !");
        return ;
    } else {
        start_color();              // rend l'utilisation des couleurs possible
    }
	noecho();                       // desactive l'affichage de caractere quand on appuie sur les touches
	curs_set(0);                    // cache le curseur du terminal
    keypad(this->frame, TRUE);       // rend possible la detection de pression sur les touches fleches
    nodelay(this->frame, TRUE);      // rend l'input (avec getch) non bloquant (asynchrome en quelque sorte)

    // recupere les dimensions de la fenetre (getmaxyx est une macro qui set les deux derniers parametres)
    getmaxyx(this->frame, Engine::maxHeight, Engine::maxWidth);
    if (Engine::maxHeight <= 20 || Engine::maxWidth <= 100) {
        this->crash("The terminal is way too small ! Please enlarge the window.");
    }

    // donne des bordures au spawner d etoiles
    this->pilot.setPosition(Engine::maxHeight / 2, ((Engine::maxWidth / 2) / 2) * 2);
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
        this->manageCollision();                    // detruit les ennemis touchés
        this->pilot.getRockets().updateObjects();   // fait bouger les missiles du pilote
        pilot.move();                               // fait bouger le pilote
        this->manageCollision();                    // detruit les ennemis touchés

        this->printGame();                          // met le jeu dans le buffer ncurses
        refresh();                                  // rafraichit la fenetre du terminal

        this->keyGesture(wgetch(this->frame));      // detecte les touches
    }
}

void Engine::manageCollision(void) {
    AObject *enemy;
    AObject *rocket;

    for (int i = 0; i < this->enemies.getSize(); i++) {
        enemy = this->enemies.get(i);
        if (!enemy->getEnabled())
            continue;
        for (int i = 0; i < this->pilot.getRockets().getSize(); i++) {
            rocket = this->pilot.getRockets().get(i);
            if (!rocket->getEnabled())
                continue;
            if (rocket->getPosition().y == enemy->getPosition().y && rocket->getPosition().x == enemy->getPosition().x) {
                dprintf(2, "OMG ALERTE ROUGE CA TOUCHE\n");
                mvaddch(enemy->getPosition().y, enemy->getPosition().x, 'X');
                enemy->setPosition(-1, -1);
                enemy->setEnabled(false);
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
    mvaddch(this->pilot.getPosition().y, this->pilot.getPosition().x, this->pilot.getShape());

    // affiche toutes les etoiles ('.') qui passent en arriere plan
    for (int i = 0; i < this->stars.getSize(); i++) {
        AObject *star = this->stars.get(i);
        if (star->getEnabled()) {
            int x = star->getPosition().x;
            int y = star->getPosition().y;
            mvaddch(y, x, star->getShape());
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

    // affiche tous les missiles du pilote ('|')
    for (int i = 0; i < this->pilot.getRockets().getSize(); i++) {
        AObject *rocket = this->pilot.getRockets().get(i);
        if (rocket->getEnabled()) {
            int x = rocket->getPosition().x;
            int y = rocket->getPosition().y;
            mvaddch(y, x, rocket->getShape());
        }
    }
    // box(this->frame, 0, 0); // on le met ou pas ?
}


//////////////////////////////////////////////////////////
///
///            THINGS THAT DOESNT MATTER
///
//////////////////////////////////////////////////////////

void Engine::keyGesture(char key) {
    if (key != -1)
            dprintf(2, "key pressed: %d\n", key);
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
    this->start();
}

Engine::Engine(const Engine & src) {
    (void)src;
    this->start();
}

void Engine::printGameOver() {
    mvprintw(Engine::maxHeight / 2    , (Engine::maxWidth - 55) / 2, "   ___                                                 \n");
    mvprintw(Engine::maxHeight / 2 + 1, (Engine::maxWidth - 55) / 2, "  / _ \\ __ _  _ __ ___    ___    ___ __   __ ___  _ __ \n");
    mvprintw(Engine::maxHeight / 2 + 2, (Engine::maxWidth - 55) / 2, " / /_\\// _` || '_ ` _ \\  / _ \\  / _ \\\\ \\ / // _ \\| '__|\n");
    mvprintw(Engine::maxHeight / 2 + 3, (Engine::maxWidth - 55) / 2, "/ /_\\\\| (_| || | | | | ||  __/ | (_) |\\ V /|  __/| |   \n");
    mvprintw(Engine::maxHeight / 2 + 4, (Engine::maxWidth - 55) / 2, "\\____/ \\__,_||_| |_| |_| \\___|  \\___/  \\_/  \\___||_|   \n");
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

Engine & Engine::operator=(const Engine &) {
    return *this;
}

std::ostream & operator<<( std::ostream & o, Engine const & ngin ) {
    (void)ngin;
    // o << ngin << std::endl;

    return o;
}