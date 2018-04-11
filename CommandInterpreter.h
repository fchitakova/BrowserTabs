#ifndef COMMAND_INTERPRETER
#define COMMMAND_INTERPRETER

const int MAX_COMMAND_NAME_LENGHT = 16;

const int MAX_URL_LENGTH = 2048;


#include "LinkedTabs.h"

class CommandInterpreter
{
public:
	CommandInterpreter();
	~CommandInterpreter();

	void RUN(std::ostream&o, std::istream&i);

private:

	void go(const char*URL);
	void insert(const char*URL);
	void back();
	void forward();
	void remove();
	void print();
	
	void process(const char*commandname, const char*url);


private:

	
	LinkedTabs *tabs;
	
	LinkedTabs::LTIterator it;
};

#endif
