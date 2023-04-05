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

unsigned int hash(char const* name) {
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

void print_table(Person** table) {
	for(int i = 0; i < TABLE_SIZE; i++) {
		Person* a_person = table[i];
		if(a_person != NULL) {
			printf("%5d   %s\n", i, a_person -> name); // %5d adds padding to the number so the names line up
		}
		else {// a_person == NULL
			printf("%5d   ---\n", i);
		}
	}
}

bool insert_in_hash_table(Person** table, Person* a_person) {
	unsigned int hash_value = hash(a_person->name);
	if(table[hash_value] != NULL) {
		return false; // Collision
	}

	table[hash_value] = a_person;
	return true;
}

Person* lookup_in_hash_table(Person** table, char const* name) {
	unsigned int hash_value = hash(name);
	return table[hash_value];
}

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
