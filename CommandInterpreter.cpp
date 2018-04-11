#include "CommandInterpreter.h"

CommandInterpreter::CommandInterpreter():tabs(NULL)
{
	tabs = new LinkedTabs();
	it = tabs->getFirst();
}

CommandInterpreter::~CommandInterpreter()
{
	if (tabs)
		delete tabs;
	tabs = NULL;
}

void CommandInterpreter::go(const char * URL)
{
	(*it)->tab.resetTab(URL);
}

void CommandInterpreter::insert(const char * URL)
{
	tabs->insertAfter(*it, BrowserTab(URL));
	++it;
}

void CommandInterpreter::back()
{
	--it;
}

void CommandInterpreter::forward()
{
	++it;
}

void CommandInterpreter::remove()
{
	if (!(*it)->previous && !(*it)->next)
	{
		tabs->removeAt(*it);
		it = tabs->getFirst();
	}

	else if ((*it)->previous && !(*it)->next)
	{
		tabs->removeAt((*(it--)));
	}

	else 
	{
		tabs->removeAt((*(it++)));
	}

}

void CommandInterpreter::print()
{
	tabs->print(it);
}

void CommandInterpreter::process(const char * commandname, const char * url)
{
	if (strcmp(commandname, "GO") == 0)
		go(url);
	else if (strcmp(commandname, "INSERT") == 0)
		insert(url);
	else if (strcmp(commandname, "BACK") == 0)
		back();
	else if (strcmp(commandname, "FORWARD") == 0)
		forward();
	else if (strcmp(commandname, "REMOVE") == 0)
		remove();
	else if (strcmp(commandname, "PRINT") == 0)
		print();
}

void CommandInterpreter::RUN(std::ostream&o,std::istream&i)
{
	char*command=new char[MAX_COMMAND_NAME_LENGHT];
	char*link = new char[MAX_URL_LENGTH];

	while (true)
	{
		o<<'\n' << '$';
		i >> command;


		i.ignore();

		if (strcmp(command, "GO") == 0 || strcmp(command, "INSERT") == 0)
		{
			i.getline(link, MAX_URL_LENGTH);
			
		}
		process(command, link);
		
	}

	delete[]command;
	command = NULL;
	delete[]link;
	link = NULL;
}




