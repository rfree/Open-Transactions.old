
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

Build with default configuration:

	$ cmake .
	$ make

With locally installed editline and compiler wrapper:

	$ cmake . -DLOCAL_EDITLINE=ON -DWITH_WRAPPER=ON
	$ make

With ccmake can easly change options in gui:
	$ ccmake . (configure [c] and generate [g] in gui)
	make
========================================================================

