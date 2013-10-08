Title: Compiler wrapper.
Goal: call this script instead eg gcc, so we can log, profile, optimize, cache the compilation
Usage: just install (copy files) and then using "./cmd/build" OT build script will autodetect it
Install: copy this files into your $HOME/.local/ e.g. into ./local/bin/ (make the dir if needed)
Config: customize the script if needed, now it uses clang (faster, lower memory, better PCH) and ccache
