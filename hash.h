#ifndef __HASH_H__
#define __HASH_H__

#define MAX_NAME 256
#define TABLE_SIZE 13

typedef struct {
	char name[MAX_NAME];
	int age;
	// add other stuff later maybe
} Person;

unsigned int hash(char* name);

void init_hash_table(Person** table);

void print_table(Person** table);

#endif

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
