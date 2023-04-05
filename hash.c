#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct {
	char name[MAX_NAME];
	int age;
	// add other stuff later maybe
} Person;

unsigned int hash(char* name) {
	return 5;
}

int main(int argc, char* argv[]) {
	char* name = "Paul";
	printf("hash(\"%s\") => %u\n", name, hash(name));

	name = "John";
	printf("hash(\"%s\") => %u\n", name, hash(name));

	name = "George";
	printf("hash(\"%s\") => %u\n", name, hash(name));

	name = "Ringo";
	printf("hash(\"%s\") => %u\n", name, hash(name));

	return EXIT_SUCCESS;
}
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
