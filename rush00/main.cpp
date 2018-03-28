#include <stdlib.h>
#include <signal.h>
#include <curses.h>
#include <sys/ioctl.h>
#include <stdio.h> 

static void					init_ncurses(void)
{
	initscr();
	start_color();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	init_color(100, 0, 0, 0);
	init_color(101, 100, 100, 100);
	init_pair(0b10000 + 1, COLOR_WHITE, 100);
	init_pair(0b00000 + 1, COLOR_WHITE, 101);
	init_pair(0b10000 + 2, COLOR_RED, 100);
	init_pair(0b00000 + 2, COLOR_RED, 101);
	init_pair(0b10000 + 3, COLOR_YELLOW, 100);
	init_pair(0b00000 + 3, COLOR_YELLOW, 101);
	init_pair(0b10000 + 4, COLOR_GREEN, 100);
	init_pair(0b00000 + 4, COLOR_GREEN, 101);
	init_pair(0b10000 + 5, COLOR_CYAN, 100);
	init_pair(0b00000 + 5, COLOR_CYAN, 101);
	init_pair(0b10000 + 6, COLOR_MAGENTA, 100);
    init_pair(0b00000 + 6, COLOR_MAGENTA, 101);
    init_pair(0b10000 + 7, COLOR_RED, COLOR_YELLOW);
    init_pair(0b00000 + 7, COLOR_YELLOW, COLOR_RED);
	return ;
}

static void             end(int osef) {
    (void)osef;
    clear();
	refresh();
    endwin();
    exit(0);
}

int main(void) {
    struct winsize	w;
    init_ncurses();
    dprintf(2, "%d %d\n", w.ws_col, COLS);
    //  move(LINES - 1, COLS - 1);
    attron(A_REVERSE);
    attron(COLOR_PAIR(7));
    attron(A_DIM);
    printw("Texte en inversion video\n");
     attron(COLOR_PAIR(0b00000 + 7));
    printw("Texte en inversion video\n");
    attron(COLOR_PAIR(0b10000 + 7));
    printw("Texte en inversion video\n");
    attroff(A_REVERSE);
    printw("test");
    signal(SIGINT, &end);
    // printw("lol");
    getch();
    while (1) {
        printw("lol");
    }
    return 0;
}