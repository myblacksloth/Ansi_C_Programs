# Linked Lists

## by Antonio Maulucci

![enter image description here](http://www.geeksforgeeks.org/wp-content/uploads/gq/2013/03/Linkedlist.png)

    typedef struct ss
    {
		char* name;
		struct ss *link;
	} Node;


----------
Where you find

    malloc((sizeof(stringa)+1)*sizeof(char))
you can substitute it with

    malloc((strlen(stringa)+1)*sizeof(char))
   to obtain a best result!


