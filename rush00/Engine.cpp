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
    keypad(stdscr, TRUE);       // rend possible la detection de pression sur les touches fleches
    nodelay(stdscr, TRUE);      // rend l'input (avec getch) non bloquant (asynchrome en quelque sorte)

    // change tous les caracteres de la fenetre en noir et blanc
    // init_pair(1, COLOR_WHITE, COLOR_BLACK);
    // wbkgd(this->frame, COLOR_PAIR(1));

    move(LINES / 2, COLS / 2 ); // test

    // TODO: placer le joueur

    // recupere les dimensions de la fenetre (getmaxyx est une macro qui set les deux derniers parametres)
    getmaxyx(this->frame, this->maxHeight, this->maxWidth);
    if (this->maxHeight <= 0 || this->maxWidth <= 0) {
        this->crash("The terminal is way too small ! Please enlarge the window.");
    }

    // donne des bordures au spawner d etoiles
    this->stars.setBounds(Bounds(0, 0, this->maxHeight, this->maxWidth));
    this->pilot.setPosition(this->maxHeight / 2, this->maxWidth / 2);
    this->enemies.setBounds(Bounds(0, 0, this->maxHeight, this->maxWidth));
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
        // efface tout l'ecran
        clear();

        // dprintf(2, "update tous les birds (%d)\n", this->stars.getSize());
        this->stars.updateObjects();
        this->pilot.getRockets().updateObjects();
        this->enemies.updateObjects();

        // BERRK 3 FOIS LA MEME
        for (int i = 0; i < this->stars.getSize(); i++) {
            AObject *star = this->stars.get(i);
            if (star->getEnabled()) {
                int x = star->getPosition().x;
                int y = star->getPosition().y;
                mvaddch(y, x, star->getShape());
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

        for (int i = 0; i < this->enemies.getSize(); i++) {
            AObject *enemy = this->enemies.get(i);
            if (enemy->getEnabled()) {
                int x = enemy->getPosition().x;
                int y = enemy->getPosition().y;
                mvaddch(y, x, enemy->getShape());
            }
        }

        mvaddch(this->pilot.getPosition().y, this->pilot.getPosition().x, this->pilot.getShape());

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
        box(this->frame, 0, 0);
        refresh();
        usleep(100000);
    }
}

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