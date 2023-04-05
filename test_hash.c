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

	name = "Sally";
	printf("hash(\"%s\") => %u\n", name, hash(name));

	name = "Bob";
	printf("hash(\"%s\") => %u\n", name, hash(name));

	name = "Yeller";
	printf("hash(\"%s\") => %u\n", name, hash(name));

	fputc('\n', stdout);
}

void test_initialize_hash_table() {
	Person* hash_table[TABLE_SIZE]; // One reason to use addresses instead of Person structs is it saves space.
									// Another reason is that you can use NULL for an empty space}
	init_hash_table(hash_table);
	print_table(hash_table);
	assert(hash_table[TABLE_SIZE - 1] == NULL);
}

void test_insert() {
	Person* hash_table[TABLE_SIZE];
	init_hash_table(hash_table);

	Person paul   = { .name = "Paul",   .age = 80 };
	Person john   = { .name = "John",   .age = 40 };
	Person george = { .name = "George", .age = 58 };
	Person ringo  = { .name = "Ringo",  .age = 82 };

	bool is_success = insert_in_hash_table(hash_table, &paul);
	assert(is_success);

	is_success = insert_in_hash_table(hash_table, &john);
	assert(is_success);

	is_success = insert_in_hash_table(hash_table, &george);
	assert(is_success);

	is_success = insert_in_hash_table(hash_table, &ringo);
	assert(is_success);

	print_table(hash_table);

	char const* lookup_name = "John";
	Person* lookup_result = lookup_in_hash_table(hash_table, lookup_name);
	assert(strcmp(lookup_result -> name, lookup_name) == 0);
	assert(lookup_result -> age == 40);
}

void test_delete() {
	Person* hash_table[TABLE_SIZE];
	init_hash_table(hash_table);

	Person paul   = { .name = "Paul",   .age = 80 };
	Person john   = { .name = "John",   .age = 40 };
	Person george = { .name = "George", .age = 58 };
	Person ringo  = { .name = "Ringo",  .age = 82 };

	bool is_success = insert_in_hash_table(hash_table, &paul);
	assert(is_success);

	is_success = insert_in_hash_table(hash_table, &john);
	assert(is_success);

	is_success = insert_in_hash_table(hash_table, &george);
	assert(is_success);

	is_success = insert_in_hash_table(hash_table, &ringo);
	assert(is_success);

	char const* lookup_name = "John";
	Person* lookup_result = lookup_in_hash_table(hash_table, lookup_name);
	assert(strcmp(lookup_result -> name, lookup_name) == 0);
	assert(lookup_result -> age == 40);

	printf("Before delete:\n");
	print_table(hash_table);

	is_success = delete_in_hash_table(hash_table, "John");
	assert(is_success);

	is_success = delete_in_hash_table(hash_table, "George");
	assert(is_success);

	printf("After delete:\n");
	print_table(hash_table);

	lookup_result = lookup_in_hash_table(hash_table, lookup_name);
	assert(lookup_result == NULL);
}

void test_collision() {
	Person* hash_table[TABLE_SIZE];
	init_hash_table(hash_table);

	Person paul   = { .name = "Paul",   .age = 80 };
	Person john   = { .name = "John",   .age = 40 };
	Person george = { .name = "George", .age = 58 };
	Person ringo  = { .name = "Ringo",  .age = 82 };
	Person sally  = { .name = "Sally",  .age = 42 };
	Person bob    = { .name = "Bob",    .age = 32 };
	Person yeller = { .name = "Yeller", .age = 23 }; // yeller collides with john

	bool is_success = insert_in_hash_table(hash_table, &paul);
	assert(is_success);

	is_success = insert_in_hash_table(hash_table, &john);
	assert(is_success);

	is_success = insert_in_hash_table(hash_table, &george);
	assert(is_success);

	is_success = insert_in_hash_table(hash_table, &ringo);
	assert(is_success);

	is_success = insert_in_hash_table(hash_table, &sally);
	assert(is_success);

	is_success = insert_in_hash_table(hash_table, &bob);
	assert(is_success);

	is_success = insert_in_hash_table(hash_table, &yeller);
	assert(is_success);

	print_table(hash_table);

	char const* lookup_name = "John";
	Person* lookup_result = lookup_in_hash_table(hash_table, lookup_name);
	assert(strcmp(lookup_result -> name, lookup_name) == 0);
	assert(lookup_result -> age == john.age);

	lookup_name = "Yeller";
	lookup_result = lookup_in_hash_table(hash_table, lookup_name);
	assert(strcmp(lookup_result -> name, lookup_name) == 0);
	assert(lookup_result -> age == yeller.age);
}

int main(int argc, char* argv[]) {
	print_example_hashes();
	//test_initialize_hash_table();
	//test_insert();
	test_delete();
	//test_collision();
	
	return EXIT_SUCCESS;
}

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
