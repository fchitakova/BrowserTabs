#include "BrowserTab.h"

BrowserTab::BrowserTab(const char*newURL):URL(NULL)
{
	setURL(newURL);
	this->creationTime = time(0);
}

BrowserTab::BrowserTab(const BrowserTab&rhs):URL(NULL)
{
	copy(rhs);
}

BrowserTab&BrowserTab::operator=(const BrowserTab&rhs)
{
	if (this != &rhs)
	{
		copy(rhs);
	}
	return *this;
}

BrowserTab::~BrowserTab()
{
	clear();
}


void BrowserTab::resetTab(const char*newURL)
{
	setURL(newURL);
	creationTime = time(0);
}


void BrowserTab::Print()const
{
	std::cout  <<URL << ' ' << creationTime<<'\n';
}

void BrowserTab::clear()
{
	if (URL)
	{
		delete[]URL;
	}
		URL = NULL;
	
}

void BrowserTab::copy(const BrowserTab&rhs)
{

	setURL(rhs.URL);
	creationTime = rhs.creationTime;
}


void BrowserTab::setURL(const char*newURL)
{
	if (URL)
	{
		clear();
	}
	size_t size = strlen(newURL) + 1;
	URL = new char[size];
	strcpy_s(URL, size, newURL);
}