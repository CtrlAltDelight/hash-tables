#ifndef __HASH_H__
#define __HASH_H__

#define MAX_NAME 256
#define TABLE_SIZE 13

typedef struct {
	char name[MAX_NAME];
	int age; // It would be better to store the date of birth for practical applications. 
			 // Never goes out of date.
} Person;

unsigned int hash(char const* name);
void init_hash_table(Person** table);
void print_table(Person** table);
bool insert_in_hash_table(Person** table, Person* a_person);
Person* lookup_in_hash_table(Person** table, char const* name);
bool delete_in_hash_table(Person** table, char const* name);

#endif

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
