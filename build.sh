mkdir build
mkdir tmp
gcc -o tmp/main.o main.c -c
gcc -o tmp/command_exec.o command_exec.c -c
gcc -o build/kolmlenka_shell tmp/main.o tmp/command_exec.o -D_GNU_SOURCE
rm -rf tmp

