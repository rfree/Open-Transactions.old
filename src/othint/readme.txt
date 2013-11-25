
========================================================================
building Othint

Dependencies:
-Editline

Dependencies installation (Debian):
	# aptitude install build-essential cmake libedit2 libedit-dev

If want to use ccmake (curses gui):
	# aptitude install cmake-curses-gui
Or Qt gui:
	# aptitude install cmake-gui

Build:
	$ cmake . ( or $ ccmake . )
	$ make
========================================================================

