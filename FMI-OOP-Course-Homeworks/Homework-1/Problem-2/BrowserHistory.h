#ifndef BROWSERHISTORY_H
#define BROWSERHISTORY_H

struct HistoryEntry
{
	int month;// 1-january; 2-february; 3-march...
	char * url;
};

class BrowserHistory
{
private:
	int maxWSitesCount;//Memory of visits.
	HistoryEntry * wSites;
	int wSitesCount;

public:
	BrowserHistory(int maxWSiteCount);
	BrowserHistory(const BrowserHistory & BrHy);//copy constructor
	~BrowserHistory();

	void addWSite();//Adds a website from the standard input(console).
	void addWSite(const HistoryEntry & currHisEntry);
	void printHistory() const;//Prints the visited sites sorted by months.
	int visits(int month) const;//Returns the number of sites visited for the given month.
	int busyMonth() const;//Returns this month from the year when most sites are visited.
	void removeLastWSite();//Removes the last added website.

	BrowserHistory concatWith(const BrowserHistory & BrHtry) const;//Concatenates two browser stories and returns a new browser history.
	BrowserHistory operator+(const BrowserHistory & BrHtry) const;//Concatenates two browser stories and returns a new browser history.
};
#endif // !BROWSERHISTORY_H
