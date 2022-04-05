import os
import shutil

def printInfo(title, subtitle):
    if title != "":
        print(title.center(terminal_width), '\n')
    if subtitle != "":
        print(subtitle.center(terminal_width), '\n\n')

def clear():
    os.system('clear')

# Asking for title and the authors name then printing
clear()
pieceName = input("Name of your piece: ")
title = ('\033[1m' + pieceName.upper() + '\033[0m')
author = input("Author: ")
subtitle = ('\x1B[3m' + author + '\x1B[0m')
clear()
terminal_width = shutil.get_terminal_size((80, 20))[0]
printInfo(title, subtitle)

# Initiate typing scene
poem = []
while True:
    inputPosition = (int(terminal_width / 2)) - 15
    inpt = ""
    for i in range(inputPosition):
        inpt += " "
    inp = input(inpt)
    if (inp == 'q'):
        break
    if (inp == 'e'):
        clear() # TODO!!
        break
    poem.append(inp)
    clear()
    printInfo(title, subtitle)
    for p in poem:
        print(p.center(terminal_width - 9))
