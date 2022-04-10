#include <ncurses.h>
#include <string.h>
#include <locale.h>

int row, col;

struct poemInfo
{
  char title[64];
  char author[64];
};

void clearCurrentLine()
{
  int y, x;
  getyx(stdscr, y, x);
  move(y, 0);
  clrtoeol();
  move(y, x);
}

void centerType(char value[])
{
  strcpy(value, "");
  int ch;

  while (ch = getch()) {
    int x, y;
    switch (ch) {
      case 10: // ENTER - 10 ASCII
        return;
        break;
      case KEY_BACKSPACE:
        value[strlen(value) - 1] = '\0';
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

void requestSingleInfo(char question[], char input[])
{
  attron(A_BOLD);
  mvprintw(row / 2, (col - strlen(question)) / 2, "%s", question),
  attroff(A_BOLD);
  move(row / 2 + 2, col / 2);
  centerType(input);
  clear();
}

void requestInfo(WINDOW *window, struct poemInfo *info)
{
  requestSingleInfo("NAME OF YOUR POEM", info->title);
  clear();
  requestSingleInfo("AUTHOR", info->author);

  // TEST
  mvprintw(LINES - 3, 0, "Name: %s", info->title);
  mvprintw(LINES - 2, 0, "Author: %s", info->author);
}

int main(void)
{
  setlocale(LC_ALL, "");
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
