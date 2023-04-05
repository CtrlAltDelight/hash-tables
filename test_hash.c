#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "hash.h"


void print_example_hashes() {
	char* name = "Paul";
	printf("hash(\"%s\") => %u\n", name, hash(name));

	name = "John";
	printf("hash(\"%s\") => %u\n", name, hash(name));

	name = "George";
	printf("hash(\"%s\") => %u\n", name, hash(name));

	name = "Ringo";
	printf("hash(\"%s\") => %u\n", name, hash(name));

}

void test_initialize_hash_table() {
	Person* hash_table[TABLE_SIZE]; // One reason to use addresses instead of Person structs is it saves space.
									// Another reason is that you can use NULL for an empty space}
	init_hash_table(hash_table);
	assert(hash_table[TABLE_SIZE - 1] == NULL);
}

int main(int argc, char* argv[]) {
	print_example_hashes();
	test_initialize_hash_table();
	return EXIT_SUCCESS;
}

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
