#include <iostream>
#include "BrowserHistory.h"

int main()
{
	BrowserHistory testBrowser(12);

	HistoryEntry testWsite;
	testWsite.month = 6;
	testWsite.url = "http.qwerw2132ew";

	HistoryEntry testWSite_2;
	testWSite_2.month = 4;
	testWSite_2.url = "http.oooosdfjdsfd";

	testBrowser.addWSite(testWsite);
	testBrowser.addWSite(testWSite_2);
	testBrowser.addWSite(testWsite);
	testBrowser.addWSite(testWSite_2);

	BrowserHistory testBrowser_2(testBrowser);

	testBrowser_2.addWSite(testWsite);
	testBrowser_2.addWSite(testWsite);

	testBrowser_2.removeLastWSite();

	testBrowser_2.addWSite();

	BrowserHistory testBrowser_3 = testBrowser + testBrowser_2;
	BrowserHistory testBrowser_4 = testBrowser.concatWith(testBrowser_3);

	std::cout << "Visited wSites count in 6th month of test_2: " << testBrowser_2.visits(6) << "\n";
	std::cout << "The month from testBrowser_2 when most sites are visited: " << testBrowser_2.busyMonth() << "th\n";

	testBrowser_2.printHistory();
	std::cout << "\n";
	testBrowser_3.printHistory();
	std::cout << "\n";
	testBrowser_4.printHistory();

	system("pause");
	return 0;
}
