#include "CommandInterpreter.h"


int main()
{
	CommandInterpreter myinterpreter;
	myinterpreter.RUN(std::cout, std::cin);

	return 0;
}