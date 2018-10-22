#include <iostream>
#include "BrowserHistory.h"

BrowserHistory::BrowserHistory(int maxWSitesCount)
{
	this->maxWSitesCount = maxWSitesCount;
	wSites = new HistoryEntry[maxWSitesCount];
	wSitesCount = 0;
}

BrowserHistory::BrowserHistory(const BrowserHistory & BrHy)
{
	maxWSitesCount = BrHy.maxWSitesCount;
	wSites = new HistoryEntry[maxWSitesCount];
	wSitesCount = BrHy.wSitesCount;
	for (int i = 0; i < wSitesCount; i++)
	{
		HistoryEntry currWSite;
		currWSite.month = BrHy.wSites[i].month;
		currWSite.url = new char[200];
		for (int j = 0; j < 200; j++)
		{
			currWSite.url[j] = BrHy.wSites[i].url[j];
		}
		wSites[i] = currWSite;
	}
}

BrowserHistory::~BrowserHistory()
{
	for (int i = 0; i < wSitesCount; i++)
	{
		delete[] wSites[i].url;
	}
	delete[] wSites;
}

void BrowserHistory::addWSite()
{
	if (wSitesCount >= maxWSitesCount)
	{
		std::cout << "The memory is full! \n";
		return;
	}
	int currMonth;
	char * currUrl = new char[200];
	std::cout << "Please enter the month (1-january; 2-february; 3-march...): \n";
	std::cin >> currMonth;
	std::cin.ignore();
	std::cout << "Please enter the URL of the website: \n";
	std::cin.get(currUrl, 200);

	HistoryEntry wSite;
	wSite.month = currMonth;
	wSite.url = currUrl;
	
	wSites[wSitesCount] = wSite;
	wSitesCount++;
}

void BrowserHistory::addWSite(const HistoryEntry & currHisEntry)
{
	if (wSitesCount >= maxWSitesCount)
	{
		std::cout << "The memory is full! \n";
		return;
	}

	HistoryEntry wSite;
	wSite.month = currHisEntry.month;
	wSite.url = new char[200];
	for (int i = 0; i < 200; i++)
	{
		wSite.url[i] = currHisEntry.url[i];
	}

	wSites[wSitesCount] = wSite;
	wSitesCount++;
}

void BrowserHistory::printHistory() const
{
	for (int i = 1; i <= 12; i++)
	{
		for (int j = 0; j < wSitesCount; j++)
		{
			if (wSites[j].month == i)
			{
				std::cout << i << "th month of the year. URL: " << wSites[j].url << "\n";
			}
		}
	}
}

int BrowserHistory::visits(int month) const
{
	int countForCurrMonth = 0;
	for (int i = 0; i < wSitesCount; i++)
	{
		if (wSites[i].month == month)
		{
			countForCurrMonth++;
		}
	}
	return countForCurrMonth;
}

int BrowserHistory::busyMonth() const
{
	int searchedMonth;
	int maxVisits = 0;
	for (int i = 1; i < 12; i++)
	{
		int currMonthVisits = 0;
		for (int j = 0; j < wSitesCount; j++)
		{
			if (wSites[j].month == i)
			{
				currMonthVisits++;
			}
		}
		if (currMonthVisits > maxVisits)
		{
			maxVisits = currMonthVisits;
			searchedMonth = i;
		}
	}
	return searchedMonth;
}

void BrowserHistory::removeLastWSite()
{
	wSitesCount--;
	delete[] wSites[wSitesCount].url;
}

BrowserHistory BrowserHistory::concatWith(const BrowserHistory & BrHtry) const
{
	int newBrMaxLength = maxWSitesCount + BrHtry.maxWSitesCount;
	BrowserHistory newBrHy(newBrMaxLength);
	
	for (int i = 0; i < wSitesCount; i++)
	{
		newBrHy.addWSite(wSites[i]);
	}
	for (int i = 0; i < BrHtry.wSitesCount; i++)
	{
		newBrHy.addWSite(BrHtry.wSites[i]);
	}
	return newBrHy;
}

BrowserHistory BrowserHistory::operator + (const BrowserHistory & currBr) const
{
	int newBrMaxLength = maxWSitesCount + currBr.maxWSitesCount;
	BrowserHistory newBrHy(newBrMaxLength);

	for (int i = 0; i < wSitesCount; i++)
	{
		newBrHy.addWSite(wSites[i]);
	}
	for (int i = 0; i < currBr.wSitesCount; i++)
	{
		newBrHy.addWSite(currBr.wSites[i]);
	}
	return newBrHy;
}