
========================================================================
BUILDING
========================================================================
building Othint

Dependencies:
- System libs, tools
- Editline
- OpenTransactions (development - with includes headers)

Dependencies installation (Debian):
	* aptitude install build-essential cmake libedit2 libedit-dev
	* Download OpenTransactions and build it, using instructions from  ../../docs/INSTALL-linux-modern.txt or other suitable
	* Install also the header files into ~/.local/
	* Checklist, in ~ .local you shoul have files like:
		find  /home/opentransactions/.local/lib/ | grep libot
			/home/opentransactions/.local/lib/libot.so.0
			/home/opentransactions/.local/lib/libot.a
			/home/opentransactions/.local/lib/libotapi.so
			/home/opentransactions/.local/lib/libotapi.la
			etc.
		if missing, install them from OpenTransactions sources:
			mkdir  ~/.local/include/ot
			cp -ar Open-Transactions/include/* ~/.local/include/ot/ # where Open-Transactions/ are the sources e.g. from github


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

