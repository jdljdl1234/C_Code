/* James Lantos, CS240, HW6 */
/* April 21, 2013 */
/*
 * gettysburg.c
 *
 */


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "getty.h"
#define MAXWORD 100

/* ===== PSEUDO CODE ======											*/
/*  define structure, array vars */
/*  get stdin file of words */
/* step through the array of words checking for validity */
/*  build the tree */
/*  print the tree */


main()
{
	struct tnode *root;
	char word[MAXWORD];
	root = NULL;
	while (getword(word, MAXWORD) != EOF) 
		if (isalpha(word[0]))
		root = addtree(root, word);
	treeprint(root);
	return 0;
}


