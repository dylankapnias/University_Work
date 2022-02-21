#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Trie {
	struct Trie *children[26];
	char isWord[26];
};

extern struct Trie *trieAlloc();
extern void trieInit(struct Trie *);
extern void trieInsert(struct Trie *, char *word);
void checkInit(struct Trie *trie);

void triePrint(struct Trie *trie, int indent) {
	for (int i = 0; i < 26; i++) {
		
		if (trie->children[i] != 0) {
			for (int i = 0; i < indent; i++) printf("\t");
			printf("-%c: %i\n", 'a' + i, trie->isWord[i]);
			triePrint(trie->children[i], indent + 1);
		} else if (trie->isWord[i] == 1) {
			for (int i = 0; i < indent; i++) printf("\t");
			printf("-%c: 1\n", 'a' + i);
		}
	}
}

void checkInit(struct Trie *trie) {
	for (int i = 0; i < 26; i++)
	{
		if (trie->children[i] == 0 && trie->isWord[i] == 0) {
			printf("Trie at index %i was properly initiated\n", i);
		} else {
			printf("Trie at index %i was not properly initiated\n", i);
		}
	}
	
}

int main(int argc, char *argv[]) {
	struct Trie *a = trieAlloc();
	trieInit(a);
	//checkInit(a);
	
	trieInsert(a, "ape");
	triePrint(a, 0);
	trieInsert(a, "bat");
	//triePrint(a, 0);
	trieInsert(a, "cat");
	//triePrint(a, 0);
	trieInsert(a, "dog");
	//triePrint(a, 0);
	trieInsert(a, "dolphine");
	
	triePrint(a, 0);
	
	/* Output: 
	
	-a: 0
		-p: 0
			-e: 1
	-b: 0
		-a: 0
			-t: 1
	-c: 0
		-a: 0
		-t: 1
	-d: 0
		-o: 0
			-g: 1
			-l: 0
				-p: 0
					-h: 0
						-i: 0
							-n: 0
								-e: 1
							
	*/
	
	return 0;
}
