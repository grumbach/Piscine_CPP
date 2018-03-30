#include "Engine.hpp"
#include "bindings.hpp"

Engine::Engine(void) {
    this->frame = initscr();    // renvoie l'addresse de la fenetre creee
    if(!has_colors()) {
        this->crash("Cannot play if colors are disabled !");
        return ;
    } else {
        start_color();          // rend l'utilisation des couleurs possible
    }
	noecho();                   // desactive l'affichage de caractere quand on appuie sur les touches
	curs_set(0);                // cache le curseur du terminal
    keypad(this->frame, TRUE);       // rend possible la detection de pression sur les touches fleches
    nodelay(this->frame, TRUE);      // rend l'input (avec getch) non bloquant (asynchrome en quelque sorte)

    // recupere les dimensions de la fenetre (getmaxyx est une macro qui set les deux derniers parametres)
    getmaxyx(this->frame, Engine::maxHeight, Engine::maxWidth);
    if (Engine::maxHeight <= 0 || Engine::maxWidth <= 0) {
        this->crash("The terminal is way too small ! Please enlarge the window.");
    }

    // donne des bordures au spawner d etoiles
    this->pilot.setPosition(Engine::maxHeight / 2, ((Engine::maxWidth / 2) / 2) * 2);
}

Engine::Engine(const Engine & ngin) {
    (void)ngin;
}

Engine::~Engine() {
}

bool Engine::start() {
    return true;
}

// THE BIG WHILE
void Engine::launch() {
    while (42) {
        if (this->gameOver) {
            mvprintw(Engine::maxHeight / 2, (Engine::maxWidth - 55) / 2, "   ___                                                 \n");
            mvprintw(Engine::maxHeight / 2 + 1, (Engine::maxWidth - 55) / 2, "  / _ \\ __ _  _ __ ___    ___    ___ __   __ ___  _ __ \n");
            mvprintw(Engine::maxHeight / 2 + 2, (Engine::maxWidth - 55) / 2, " / /_\\// _` || '_ ` _ \\  / _ \\  / _ \\\\ \\ / // _ \\| '__|\n");
            mvprintw(Engine::maxHeight / 2 + 3, (Engine::maxWidth - 55) / 2, "/ /_\\\\| (_| || | | | | ||  __/ | (_) |\\ V /|  __/| |   \n");
            mvprintw(Engine::maxHeight / 2 + 4, (Engine::maxWidth - 55) / 2, "\\____/ \\__,_||_| |_| |_| \\___|  \\___/  \\_/  \\___||_|   \n");
            refresh();
            continue;
        }

        // efface tout l'ecran
        clear();

        // dprintf(2, "update tous les birds (%d)\n", this->stars.getSize());
        this->stars.updateObjects();
        this->enemies.updateObjects(); // bouge les ennemis
        // LA ON CHECK TOUT
        this->manageCollision();
        this->pilot.getRockets().updateObjects(); // bouge le pilote
        this->manageCollision();
        mvaddch(this->pilot.getPosition().y, this->pilot.getPosition().x, this->pilot.getShape()); // bouge les rockets

        // BERRK 3 FOIS LA MEME
        for (int i = 0; i < this->stars.getSize(); i++) {
            AObject *star = this->stars.get(i);
            if (star->getEnabled()) {
                int x = star->getPosition().x;
                int y = star->getPosition().y;
                mvaddch(y, x, star->getShape());
            }
        }

        for (int i = 0; i < this->enemies.getSize(); i++) {
            AObject *enemy = this->enemies.get(i);
            if (enemy->getEnabled()) {
                int x = enemy->getPosition().x;
                int y = enemy->getPosition().y;
                mvaddch(y, x, enemy->getShape());
            }
        }

        for (int i = 0; i < this->pilot.getRockets().getSize(); i++) {
            AObject *rocket = this->pilot.getRockets().get(i);
            if (rocket->getEnabled()) {
                int x = rocket->getPosition().x;
                int y = rocket->getPosition().y;
                mvaddch(y, x, rocket->getShape());
            }
        }


        // get keypress
        char keypressed = wgetch(this->frame);
        dprintf(2, "key pressed: %d\n", keypressed);
        switch (keypressed) {
            case KEY_ARROW_LEFT:
            case KEY_ARROW_RIGHT:
            case KEY_ARROW_UP:
            case KEY_ARROW_DOWN:
                this->pilot.setDirection(keypressed);
                keypressed = -1;
                break;
            case KEY_SPACE:
                this->pilot.shoot();
            default:
                break;

        }
        pilot.move();
        // affiche le cadre tout autour de la window
        // box(this->frame, 0, 0);
        refresh();
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



// . . O< .



void Engine::finish() {
    clear();
    refresh();
    endwin();
    exit(0);
}

void Engine::crash(std::string const stopMessage) {
    clear();
    refresh();
    endwin();
    std::cerr << stopMessage << std::endl;
    exit(-1);
}

Engine & Engine::operator=(const Engine &) {
    return *this;
}

std::ostream & operator<<( std::ostream & o, Engine const & ngin ) {
    (void)ngin;
    // o << ngin << std::endl;

    return o;
}

int Engine::maxHeight = 1;
int Engine::maxWidth = 1;