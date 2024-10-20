# templateCppVscodium

##### INFO ABOUT SETUP #####

  # tasks.json #
  Instructed to use Makefile when using ctrl+b for building in vscodium

  # launch.json #
  Instructed to use gdb, and points to out/executable.exe (Used by Native Debug plugin)

  # settings.json #
  Adds information to settings that Code Runner extension can use to execute project

  # compile_flags.txt #
  Should reflect Makefile. Used by clangd language server for include folders
  -xc++ flag instructs some external c libraries to be compiled as c++ to prevent warnings in ide

  # dependencies/include folder #
  Put external include header files here

  # dependencies/lib folder #
  Put dynamically linked dll.lib files here.
  Actual .dll files goes into out folder where executable can find it

  # Makefile #
  Using g++ compiler (found in msys2)
  Also names executable
  Additional c/c++ libraries must be added to LIBS variable
  Can be used to suppress warnings by adding such flags to WARNINGS variable

##### EXTENSIONS TO GET #####
  clangd          -Used for language server
  Native Debug    -Used for gdb
  Code Runner     -Used for easy executable

##### FIRST STEPS #####
  1. in Makefile change executable to desired name.
  2. in settings.json for Code Runner, change executable to desired name.
  3. in launch.json for gdb, change executable to desired name.
  4. Create folder "out" in root