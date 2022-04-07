
# cpoem

![Example](/assets/poem.png)

cpoem is a lightweight-poorly-written cli program to help you easily write a poem along the way.

It is built using Python 3.10 and does not use any external libraries or packages. The idea was not to use curses or urwid and make it as light as possible.

Tested only on Linux (Arch), using [kitty](https://github.com/kovidgoyal/kitty) terminal emulator and [Roboto Mono](https://fonts.google.com/specimen/Roboto+Mono) font.

Make sure you use a font that has **bold** and *italic* variants in order for everything to work as expected.

[Wallpaper](https://github.com/skinnzysan/Archdots2/blob/main/Pictures/wallpaper.jpg) by [skinnzysan](https://github.com/skinnzysan)
Goes great along [cbonsai](https://gitlab.com/jallbrit/cbonsai)
# Installation

Right now you can only clone and create a symlink perhaps like:
```
sudo chmod +x /path/to/cpoem.py
sudo ln -s /path/to/cpoem.py /usr/bin/cpoem
````
# Usage
If you created a symlink as described above, you can run just using:
```
cpoem
````
or run it directly with python from your cloned directory:
```
python cpoem.py
````
While in a "typing mode" you can type `e` on a line and enter the "edit mode" to edit the line you want.

While in a "typing mode" you an type `q` to quit the program.

### TODO
***Note that I am not accepting code contributions now since I am using this repo as a practice with Python.***

- [ ]  Saving the poem as a screenshot
- [ ]  Saving the poem as a .txt file or similar
- [ ]  Improve edit mode
- [ ]  Find a way to have something like status bar
- [ ]  Add the package to AUR and pip
