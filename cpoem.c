#include <ncurses.h>
#include <string.h>

int row, col;

struct poemInfo
{
  char title[64];
  char author[32];
};

void clearCurrentLine()
{
  int y, x;
  getyx(stdscr, y, x);
  move(y, 0);
  clrtoeol();
  move(y, x);
}

void centerType(char *value[])
{
  int ch;

  while (ch = getch()) {
    int x, y;
    switch (ch) {
      case 10: // ENTER - 10 ASCII
        return;
        break;
      case KEY_BACKSPACE:
        strncat(value, "", 0); // TODO!!!
        clearCurrentLine();
        getyx(stdscr, y, x);
        mvprintw(y, (col - strlen(value)) / 2, "%s", value);
        break;
      default:
        strncat(value, &ch, 1);
        clearCurrentLine();
        getyx(stdscr, y, x);
        mvprintw(y, (col - strlen(value)) / 2, "%s", value);
        break;
    }
  }
}

void requestInfo(WINDOW *window, struct poemInfo *info)
{
  char nameOfPoem[] = "NAME OF YOUR POEM";
  attron(A_BOLD);
  mvprintw(row / 2, (col - strlen(nameOfPoem)) / 2, "%s", nameOfPoem),
  attroff(A_BOLD);
  move(row / 2 + 2, col / 2);
  centerType(info->title);
  // getch(info->title);
  mvprintw(LINES - 2, 0, "You entered: %s", info->title);
  // printf("Name of your poem: ");
  // scanf("%s", &info->title);
  // printf("Autho: ");
  // scanf("%s", &info->author);
}

int main(void)
{
  WINDOW *window = initscr();
  cbreak();
  noecho();
  keypad(stdscr, true);
  getmaxyx(stdscr, row, col);

  struct poemInfo *info;

  requestInfo(window, &info);

  refresh();
  getch();
  endwin();

	return 0;
}
