#include "tree.h"
#include "tree.c"
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	struct tree *tree;
	struct tree_iterator *i;
	struct tree_iterator *end;

	//make tree  and add words
	tree = tree_create((int (*)(void *, void *))strcmp);
	tree->add(tree, "hello");
	tree->add(tree, "world");
	tree->add(tree, "worchestershire");
	tree->add(tree, "kielbasa");
	tree->add(tree, "woof");
	tree->add(tree, "abba");

	//iterate and print words
	i = tree->begin(tree);
	end = tree->end(tree);
	while(!i->equals(i, end)) {
		printf("%s\n", i->get(i));
		i->next(i);
	}
	i->destroy(i);
	end->destroy(end);

	//check for words
	if(tree->contains(tree, "woof"))
		printf("tree contains \"woof\"\n");
	if(tree->contains(tree, "nope"))
		printf("tree does not contain \"nope\"");

	//remove word 'woof'
	tree->remove(tree, "woof");
	if(tree->contains(tree, "woof"))
		printf("tree contains \"how\"");

	return 0;
}