#!/usr/bin/python
import os
import shutil
import readline

def clear():
    os.system("clear")

def rlinput(prompt, prefill=''):
   readline.set_startup_hook(lambda: readline.insert_text(prefill))
   try:
      return input(prompt)
   finally:
      readline.set_startup_hook()

def printInfo(title, subtitle):
    if title != "":
        print(title.center(terminal_width), "\n")
    if subtitle != "":
        print(subtitle.center(terminal_width), "\n\n")

# Asking for title and the authors name then printing
clear()
poemName = input("Name of your poem: ")
title = ("\033[1m" + poemName.upper() + '\033[0m')
author = input("Author: ")
subtitle = ("\x1B[3m" + author + "\x1B[0m")
clear()
terminal_width = shutil.get_terminal_size((80, 20))[0]
printInfo(title, subtitle)

poem = []
def refreshTyping():
    clear()
    printInfo(title, subtitle)
    for p in poem:
        print(p.center(terminal_width - 8))

# Initiate typing session
while True:
    inputPosition = (int(terminal_width / 2)) - 15
    inpt = ""
    for i in range(inputPosition):
        inpt += " "
    inp = input(inpt)
    if (inp == "q"):
        break
    if (inp == "e"):
        clear()
        print("EDIT MODE\n\n".center(terminal_width))
        for i in range(len(poem)):
            print(str(i) + '.', poem[i].center(terminal_width - 8))
        editLine = 0
        while True:
            try:
                editLine = int(input("\nEnter a line number you wish to edit: "))
                break
            except:
                print("Enter a number from 0 to",len(poem) - 1)
        poem[editLine] = rlinput("Edit: ",poem[editLine])
        refreshTyping()
        continue

    poem.append(inp)
    refreshTyping()
