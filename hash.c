#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "hash.h"

void init_hash_table(Person** table) {
	for(int i = 0; i < TABLE_SIZE; i++) {
		table[i] = NULL;
	}
}

unsigned int hash(char* name) {
	int length = strlen(name);
	unsigned int hash_value = 0;
	for(int i = 0; i < length; i++) {
		char curr_character = name[i];
		hash_value += curr_character; // Do some random calculations
		hash_value *= curr_character; // NOTE: Must be deterministic AND fit in our TABLE_SIZE.
		hash_value %= TABLE_SIZE;
	}
	return hash_value;
}

static void _print_person(Person person) {
	printf("%s, age %d\n", person.name, person.age);
}

void print_table(Person** table) {
	for(int i = 0; i < TABLE_SIZE; i++) {
		Person* a_person = table[TABLE_SIZE];
		if(a_person != NULL) {
			_print_person(*a_person);
		}
		
	}
}

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
