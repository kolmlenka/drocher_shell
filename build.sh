mkdir build
mkdir tmp
gcc -o tmp/main.o main.c -c
gcc -o build/kolmlenka_shell tmp/main.o
rm -rf tmp