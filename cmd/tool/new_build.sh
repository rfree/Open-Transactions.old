#!/bin/bash -e

# USAGE:
# new_build.sh 3  where 3 is the level of build - see usage() function below

# http://mywiki.wooledge.org/BashFAQ/105/ ; http://mywiki.wooledge.org/BashFAQ/101
set -e
warn() { # warn: Print a message to stderr. Usage: warn "format" ["arguments"...]
  local fmt="$1" ; shift ; printf "ERROR: $fmt in $script_title\n" "$@" >&2 ; }
die() { # Usage: some_command || die [status code] "message" ["arguments"...]
  local st="$?" ; if [[ "$1" != *[^0-9]* ]] ; then st="$1" ; shift ; fi ; warn "$@" ; exit "$st" ; }
isnumber() { test "$1" && printf '%d' "$1" >/dev/null; } # http://stackoverflow.com/questions/806906/how-do-i-test-if-a-variable-is-a-number-in-bash

usage() {
	echo "Usage: script-name level"
	echo "Where level is:"
	echo "    0 - rebuild all as much as possible"
	echo "  100 - build clean entire project"
	echo "  110 - start with automake / autoreconf"
	echo "  120 - start with configure"
	echo "  150 - start with make clean"
	echo "  200 - just make (of changed files)"
}
die_usage() {
	usage
	die "$@"
}

script_title="Configuring project"
echo "START: $script_title ($@)"

level=$1
isnumber "$level" || die_usage "You need to choose the level, e.g. 0"


# configure this environment variables:
# CONCURENCY_LEVEL=4 # set to number of CPUs, unless memory constrains
# MY_

if [[ -z $CONCURENCY_LEVEL ]] ; then
	CONCURENCY_LEVEL=2
	echo "Set default concurency level $CONCURENCY_LEVEL (you can change that with export CONCURENCY_LEVEL=8 before)"
fi

if [[ -z "$PKG_CONFIG_PATH" ]] ; then 
	echo "The variable PKG_CONFIG_PATH is not configured ($PKG_CONFIG_PATH) - please set it."
	PKG_CONFIG_PATH_AUTO=""

	MAYBE="$HOME/.local/lib/pkgconfig"
	if [[ -d "$MAYBE" ]] ; then
		PKG_CONFIG_PATH_AUTO="$MAYBE"
	fi

	MAYBE="$HOME/local/lib/pkgconfig"
	if [[ -d "$MAYBE" ]] ; then
		PKG_CONFIG_PATH_AUTO="$MAYBE"
	fi

	if [[ ! -z "PKG_CONFIG_PATH" ]] ; then
		PKG_CONFIG_PATH=$PKG_CONFIG_PATH_AUTO
		echo "Found PKG_CONFIG_PATH=PKG_CONFIG_PATH"
	fi
fi

COMPILER_PREFIX_TRY="$HOME/.local/bin/"
if [[ -x "${COMPILER_PREFIX_TRY}/compile-cxx" ]] ; then
	COMPILER_PREFIX="${COMPILER_PREFIX_TRY}"
	echo "Auto-detected local compiler script COMPILER_PREFIX=$COMPILER_PREFIX"
fi

if [[ -z $COMPILER_PREFIX ]] ; then
	echo "We recommend to install in HOME/.local/bin/ our scripts compile-cpp compile-cc compile-cxx - that can compile better (e.g. with ccache+clang)"
else
	export CPP="${COMPILER_PREFIX}/compile-cpp"; 
	export CC="${COMPILER_PREFIX}/compile-cc"; 
	export CXX="${COMPILER_PREFIX}/compile-cxx";
fi

echo "Will use compilers: CPP=$CPP CC=$CC CXX=$CXX with CONCURENCY_LEVEL=$CONCURENCY_LEVEL"

if (( $level <= 110 )) ; then 
	autoreconf -vif || die "Can not do autoreconf" ; 
fi

if (( $level <= 120 )) ; then 
./configure --disable-static --prefix="$HOME/.local" || die "Can not do configure" 
fi

if (( $level <= 150 )) ; then 
	make clean -j$CONCURENCY_LEVEL
fi

if (( $level <= 200 )) ; then 
	time make -j$CONCURENCY_LEVEL install || die "Can not make the project"
fi

echo "DONE: $script_title"
