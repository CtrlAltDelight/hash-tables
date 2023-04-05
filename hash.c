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
	// Use hash_value space or find next available space in table and use that.
	unsigned int index = hash(a_person->name);
	for(int i = 0; i < TABLE_SIZE; i++) {
		index = (index + i) % TABLE_SIZE; // Counts from our current index to max value, then wraps around to 0 and continues.
		if(table[index] == NULL) { // If an empty space is found
			table[index] = a_person;
			return true;
		}
	}

	return false; // No space in list
}

Person* lookup_in_hash_table(Person** table, char const* name) {
	unsigned int index = hash(name);
	for(int i = 0; i < TABLE_SIZE; i++) {
		index = (index + i) % TABLE_SIZE; // Counts from our current index to max value, then wraps around to 0 and continues.
		if(table[index] != NULL && strcmp(table[index]->name, name) == 0) { // If a person is found and the names match
			return table[index];
		}
	}
	return NULL; // Did not find person in table
}

bool delete_in_hash_table(Person** table, char const* name) {
	unsigned int index = hash(name);
	for(int i = 0; i < TABLE_SIZE; i++) {
		index = (index + i) % TABLE_SIZE; // Counts from our current index to max value, then wraps around to 0 and continues.
		if(table[index] != NULL && strcmp(table[index]->name, name) == 0) {
			table[index] = NULL;
			return true;
		}
	}
	return false; // Did not find person in table
}
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
