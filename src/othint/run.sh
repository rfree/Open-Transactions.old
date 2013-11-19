
# please install here a wrapper script or link to g++(>=4.7.2 ?) or clang(>=3.3 ?)
COMPILER="$HOME/.local/bin/compile-cxx"

# TODO: LEGAL: for imaginary property and licencing law reasons, do not even -lreadline (link it) when disabling GNU with -DOT_ALLOW_GNU_LIBRARIES=0
# otherwise it will be linked anyway (though not use)
$COMPILER -std=c++11 -DOT_ALLOW_GNU_LIBRARIES=1 main.cpp -g3 -O0 -o othint -lreadline && echo "Starting program:" && bash start.sh ; echo "Done."

