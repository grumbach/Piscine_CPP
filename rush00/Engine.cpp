#include "Engine.hpp"

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

    // pose un cadre de la taille de toute la fenetre
    box(this->frame, 0, 0);

    move(LINES / 2, COLS / 2 ); // test

    // TODO: placer le joueur

    // recupere les dimensions de la fenetre (getmaxyx est une macro qui set les deux derniers parametres)
    getmaxyx(this->frame, this->maxHeight, this->maxWidth);

    // donne des bordures au spawner de birds
    this->birds.setBounds(Bounds(0, 0, this->maxHeight, this->maxWidth));
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
    printw("lol");
    while (1) {

        // remplace les anciens oiseaux par un espace
        for (int i = 0; i < this->birds.getSize(); i++) {
            Object *obj = this->birds.get(i);
            if (obj->getEnabled()) {
                int x = obj->getPosition().x;
                int y = obj->getPosition().y;
                mvaddch(y, x, ' ');
            }
        }

        // update la position de tous les oiseaux
        dprintf(2, "update tous les birds (%d)\n", this->birds.getSize());
        this->birds.updateObjects();

        usleep(100000);

        // place des etoiles sur les nouvelles positions d'oiseaux
        for (int i = 0; i < this->birds.getSize(); i++) {
            Object *obj = this->birds.get(i);
            dprintf(2, "bird %d: %d\n", i, obj->getEnabled());
            if (obj->getEnabled()) {
                int x = obj->getPosition().x;
                int y = obj->getPosition().y;
                dprintf(2, "maintenant je place une etoile en %d, %d\n", y, x);
                mvaddch(y, x, '*');
            }
        }
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