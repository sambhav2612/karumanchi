#include "../headers.h"
#define LOAD_FACTOR 20

struct node
{
	int key;
	int data;
	struct node *next;
};

struct hash_table_node
{
	int block_count;
	struct node *next;
};

struct hash_table
{
	int table_size;
	int element_count;
	struct hash_table_node **table;
};

struct hash_table *create_hash_table(int size)
{
	struct hash_table *h;
	h = (struct hash_table *)malloc(sizeof(struct hash_table));

	if (!h)
		return nullptr;

	h->table_size = size / LOAD_FACTOR;
	h->element_count = 0;
	h->table = (struct hash_table_node **)malloc(sizeof(struct hash_table_node *) * h->table_size);

	if (!h->table)
		return nullptr;

	for (int i = 0; i < h->table_size; ++i)
	{
		h->table[i]->next = nullptr;
		h->table[i]->block_count = 0;
	}

	return h;
}

int hash_fx(int data, int table_size)
{
	return (data % table_size);
}

void rehash(struct hash_table *h)
{
	int old_size, i, index;
	struct node *temp, *temp2;
	struct hash_table_node **old_table;

	old_size = h->table_size;
	old_table = h->table;
	h->table_size *= 2;
	h->table = (struct hash_table_node **)malloc(h->table_size * sizeof(struct hash_table_node *));

	if (!h->table)
		return;

	for (i = 0; i < old_size; ++i)
		for (temp = old_table[i]->next; temp; temp = temp->next)
		{
			index = hash_fx(temp->data, h->table_size);
			temp2 = temp;
			temp2->next = h->table[index]->next;
			h->table[index]->next = temp2;
			temp = temp->next;
		}
}

int hash_search(struct hash_table *h, int data)
{
	struct node *temp;
	temp = h->table[hash_fx(data, h->table_size)]->next; // assume hash() is a built-in function

	while (temp)
	{
		if (temp->data == data)
			return 1;
		temp = temp->next;
	}

	return 0;
}

int hash_insert(struct hash_table *h, int data)
{
	int index;
	struct node *new_node;

	if (hash_search(h, data))
		return 0;

	index = hash_fx(data, h->table_size); // assume hash() is a built-in function
	new_node = (struct node *)malloc(sizeof(struct node));

	if (!new_node)
		return -1;

	new_node->key = index;
	new_node->data = data;
	new_node->next = h->table[index]->next;
	h->table[index]->next = new_node;
	h->table[index]->block_count++;
	h->element_count++;

	if (h->element_count / h->table_size > LOAD_FACTOR)
		rehash(h);

	return 1;
}

int hash_delete(struct hash_table *h, int data)
{
	int index;
	struct node *temp, *prev;
	index = hash_fx(data, h->table_size); // assume hash() is a built - in function

	for (temp = h->table[index]->next, prev = nullptr; temp; prev = temp, temp = temp->next)
	{
		if (temp->data == data)
		{
			if (prev != nullptr)
				prev->next = temp->next;
			free(temp);
			h->table[index]->block_count--;
			h->element_count--;
			return 1;
		}
	}

	return 0;
}