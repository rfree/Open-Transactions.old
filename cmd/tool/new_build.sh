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

cores_max_from_ram=2 # TODO detect max possible level of threads from ram/free-ram amount

if [[ -z $CONCURENCY_LEVEL ]] ; then
	cores=2
	if command -v nproc 2>/dev/null; then
		cores=$((nproc) 2>&1)	
		if (( $cores > $cores_max_from_ram )) ; then
			cores=$cores_max_from_ram
			echo "Limied to cores=$cores (because free RAM limitation) you can override by setting CONCURENCY_LEVEL env"
		fi
	else 
		echo "Warning: can not detect number of CPUs to optimize build speed, please configure CONCURENCY_LEVEL variable if you want"
	fi
	CONCURENCY_LEVEL=$cores
fi

if [[ -z "$PKG_CONFIG_PATH" ]] ; then 
	echo "Info: The variable PKG_CONFIG_PATH is not configured ($PKG_CONFIG_PATH), we will autodetect."
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
		export PKG_CONFIG_PATH=$PKG_CONFIG_PATH_AUTO
		echo "Found PKG_CONFIG_PATH=$PKG_CONFIG_PATH good."
	else 
		die "Unable to autodetect PKG_CONFIG_PATH. It must be set because chaiscript needs it. Please build chaiscript and set PKG_CONFIG_PATH env variable as described in OT install documentation. After local installation typical path would be: \$HOME/.local/lib/pkgconfig"
	fi
fi

function detect_COMPILER_PREFIX {
	COMPILER_PREFIX_TRY="$HOME/.local/bin"
	if [[ -x "${COMPILER_PREFIX_TRY}/compile-cxx" ]] ; then
		COMPILER_PREFIX="${COMPILER_PREFIX_TRY}"
		echo "Auto-detected local compiler script COMPILER_PREFIX=$COMPILER_PREFIX"
	fi
}

function fix_problems_with_COMPILER_PREFIX {
	echo "We recommend to copy files of compiler-wrapper, as in: utils/compiler-wrapper/README.txt"
	echo "This will result in switching to more recommended compilers e.g. clang for faster compilation"
	echo "Install our scripts? You will also need to install e.g. apt-get install clang ccache"
	echo "Install compiler wrapper for use with OT? (y/n):"
	read yn
	if [[ $yn == "y" ]] ; then
		this_script_filename="$(readlink -e "$BASH_SOURCE")"
		this_script_dir="$(dirname "${this_script_filename}")"
		${this_script_dir}/../../utils/compiler-wrapper/install.sh || die "Sorry, could not install the compiler-wrapper. Try to install manually, or skip it"
	fi
}


detect_COMPILER_PREFIX ;
if [[ -z $COMPILER_PREFIX ]] ; then
	fix_problems_with_COMPILER_PREFIX ;
	detect_COMPILER_PREFIX # try again
fi

if [[ -z $COMPILER_PREFIX ]] ; then
	die "Unable to detect compiler prefix."
fi

export CPP="${COMPILER_PREFIX}/compile-cpp"
export CC="${COMPILER_PREFIX}/compile-cc"
export CXX="${COMPILER_PREFIX}/compile-cxx"

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
