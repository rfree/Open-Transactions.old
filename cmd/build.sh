#!/bin/bash
echo $BASH_SOURCE

this_script_filename="$(readlink -e "$BASH_SOURCE")"
this_script_dir="$(dirname "${this_script_filename}")"
${this_script_dir}/tool/new_build.sh "$@"

