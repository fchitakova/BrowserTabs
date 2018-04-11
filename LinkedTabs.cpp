#include "LinkedTabs.h"

LinkedTabs::LinkedTabs()
{
	top = new Node(BrowserTab("about:blank"));
	end = top;
}

LinkedTabs::LinkedTabs(const LinkedTabs&rhs):top(NULL),end(NULL)
{
	copyFrom(rhs);
}

LinkedTabs&LinkedTabs::operator=(const LinkedTabs&rhs)
{
	if (this != &rhs)
	{
		copyFrom(rhs);
	}
	return *this;
}


LinkedTabs::~LinkedTabs()
{
	clear();
}

void LinkedTabs::print(LTIterator&curr) const
{
   
	Node*temp = top;
	
	if (*curr == temp)
		std::cout << '>';
	top->tab.Print();

	while (temp->next)
	{
		temp = temp->next;
		if (*curr == temp)
			std::cout << '>';
		temp->tab.Print();
	}

}



void LinkedTabs::clear()
{

	Node*temp = top;
	while (temp->next)
	{
		temp = temp->next;
		
		delete temp->previous;
		temp->previous = NULL;
	}
	delete temp;
	top = end = NULL;
}

void LinkedTabs::copyFrom(const LinkedTabs&rhs)
{

	if (rhs.top == NULL)
		return;

	//checks if there are any elements
	if (top)
	{
		clear();
	}

	Node*temp = rhs.top;
	
	top = new Node(temp->tab);

	Node*mytop = top;

	while (temp->next)
	{
		temp = temp->next;
		mytop->next = new Node(temp->tab, mytop);
		end = mytop->next;
		mytop = mytop->next;
	}

}

//it is the place after which to insert tab

void LinkedTabs::insertAfter(Node* it, BrowserTab tab)
{
	Node*newTab = new Node(tab, it, it->next);
	if (it->next)
		newTab->next->previous = newTab;
	else
		end = newTab;
	it->next = newTab;
}

void LinkedTabs::insertBefore(Node*it, BrowserTab tab)
{
	Node*newTab = new Node(tab, it->previous, it);
		it->previous = newTab;
		if (newTab->previous)
			newTab->previous->next = newTab;
		else
			top = newTab;

}

void LinkedTabs::removeAt(Node * it)
{
	if (it->next)
		it->next->previous = it->previous;
	else
		end = it->previous;
	
	if (it->previous)
		it->previous->next = it->next;
	else
		top = it->next;
	
	if (!top && !end)
	{
		top = new Node("about:blank");
		end = top;
	}
	delete it;

}

LinkedTabs::LTIterator LinkedTabs:: getFirst()const
{
	return LTIterator(top);
}


LinkedTabs::LTIterator LinkedTabs::getLast()const
{
	return LTIterator(end);
}




LinkedTabs::LTIterator::LTIterator(const LTIterator & rhs)
{
	current = rhs.current;
}

LinkedTabs::LTIterator & LinkedTabs::LTIterator::operator=(const LTIterator & rhs)
{
	if (this != &rhs)
	{
		current = rhs.current;
	}
	return *this;
}

bool LinkedTabs::LTIterator::operator==(const LTIterator & rhs)
{
	return current == rhs.current;
}

bool LinkedTabs::LTIterator::operator!=(const LTIterator & rhs)
{
	return !(*this == rhs);
}

LinkedTabs::Node* LinkedTabs::LTIterator::operator*()
{
	return current;
}

LinkedTabs::LTIterator & LinkedTabs::LTIterator::operator++()
{
	if (current->next)
		current = current->next;
	return *this;
}

LinkedTabs::LTIterator LinkedTabs::LTIterator::operator++(int)
{
	LTIterator oldValue = *this;
	
	++(*this);

	return oldValue;
}

LinkedTabs::LTIterator & LinkedTabs::LTIterator::operator--()
{
	if (current->previous)
		current = current->previous;
	return *this;

}

LinkedTabs::LTIterator  LinkedTabs::LTIterator::operator--(int)
{
	LTIterator oldValue = *this;
	--(*this);
	return oldValue;
}

LinkedTabs::LTIterator::operator bool() const
{
	return current!=NULL;
}



