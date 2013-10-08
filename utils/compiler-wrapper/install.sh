#!/bin/bash
# http://mywiki.wooledge.org/BashFAQ/105/ ; http://mywiki.wooledge.org/BashFAQ/101
set -e
warn() { # warn: Print a message to stderr. Usage: warn "format" ["arguments"...]
  local fmt="$1" ; shift ; printf "ERROR: $fmt in $script_title\n" "$@" >&2 ; }
die() { # Usage: some_command || die [status code] "message" ["arguments"...]
  local st="$?" ; if [[ "$1" != *[^0-9]* ]] ; then st="$1" ; shift ; fi ; warn "$@" ; exit "$st" ; }

this_script_filename="$(readlink -e "$BASH_SOURCE")"
this_script_dir="$(dirname "${this_script_filename}")"
cd ${this_script_dir}

dir="$HOME/.local/bin/"
echo "Installing into dir=$dir from pwd=$PWD"
mkdir -p "$dir" || die "Can not create (or reuse) dir=$dir"

cp -var bin/* "$dir/" || die "Can not copy the files (maybe already existing?)"
echo "All installed."


