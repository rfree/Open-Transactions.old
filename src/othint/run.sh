
# please install here a wrapper script or link to g++(>=4.7.2 ?) or clang(>=3.3 ?)
COMPILER="$HOME/.local/bin/compile-cxx"

$COMPILER -std=c++11 main.cpp -o othint -lreadline && echo "Starting program:" && ./othint --complete-shell ; echo "Done."
