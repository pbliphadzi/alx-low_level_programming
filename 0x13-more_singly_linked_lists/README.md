README file for 0x13-more_singly_linked_lists



Task0: Write a function that prints all the elements of a listint_t list.

			Prototype: size_t print_listint(const listint_t *h);
			Return: the number of nodes
			Format: see example
			You are allowed to use printf

Task 1: Write a function that returns the number of elements in a linked listint_t list.

			Prototype: size_t listint_len(const listint_t *h);

Task 2: Write a function that adds a new node at the beginning of a listint_t list.

			Prototype: listint_t *add_nodeint(listint_t **head, const int n);
			Return: the address of the new element, or NULL if it failed

Task 3: Write a function that adds a new node at the end of a listint_t list.

			Prototype: listint_t *add_nodeint_end(listint_t **head, const int n);
			Return: the address of the new element, or NULL if it failed

Task 4: Write a function that frees a listint_t list.

			Prototype: void free_listint(listint_t *head);

Task 5:Write a function that frees a listint_t list.

			Prototype: void free_listint2(listint_t **head);
			The function sets the head to NULL
