#ifndef DLLIST_H
#define DLLIST_H

#include "BrowserTab.h"


/**
doubly linked list
**/
class LinkedTabs
{
public:


	LinkedTabs();
	LinkedTabs(const LinkedTabs&rhs);
	LinkedTabs&operator=(const LinkedTabs&rhs);
	~LinkedTabs();

private:

	struct Node
	{
	
		BrowserTab tab;
		Node*previous;
		Node *next;
	
		Node(BrowserTab tab, Node*previous = NULL, Node*next = NULL) :tab(tab), previous(previous), next(next) {}


	};

	
public:
	//Iterator for this container
	class LTIterator
	{

		friend class LinkedTabs;

	private:

		Node*current;
	
		LTIterator(Node*n) :current(n) {}


	public:

		LTIterator():current(NULL) {}

		LTIterator(const LTIterator&rhs);

	    //changes the value of existing iterator
		LTIterator&operator=(const LTIterator&rhs);

		~LTIterator() {}
		
		//checks if the nodes pointed by this and rhs are the same
		bool operator==(const LTIterator&rhs);
		
		//checks if the nodes pointed by this and rhs are different
		bool operator!=(const LTIterator&rhs);
		
		Node* operator*();
		
		LTIterator&operator++();
		
		LTIterator operator++(int);
		
		LTIterator&operator--();
		
		LTIterator operator--(int);
		
		operator bool()const;
	
	};


public:

	//functions which return LTIterator fo first and last node
	LTIterator getFirst()const;
	LTIterator getLast()const;

	void insertAfter(Node*it, BrowserTab tab);
	void insertBefore(Node*it, BrowserTab tab);
	void removeAt(Node*it);
	void print(LTIterator&curr)const;
	//void sort(int)
	
private:

	void clear();
	void copyFrom(const LinkedTabs&rhs);

private:

	Node*top; //pointer to first node
	Node*end; //pointer to last node

};



#endif