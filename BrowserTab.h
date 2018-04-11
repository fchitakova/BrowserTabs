#ifndef BROWSER_TAB
#define BROWSER_TAB


#include <ctime>
#include <iostream>

class BrowserTab
{
public:
	BrowserTab(const char*newURL);
	BrowserTab(const BrowserTab&rhs);
	BrowserTab&operator=(const BrowserTab&rhs);
	~BrowserTab();
	
	const char*getURL()const { return URL; }
	const time_t getTime()const { return creationTime; }

	void resetTab(const char*newURL); //will use this function for GO command
	void Print()const; 
private:
	void clear();
	void copy(const BrowserTab&rhs);
	void setURL(const char*newURL);
private:
	char*URL;
    time_t creationTime;
};

#endif
