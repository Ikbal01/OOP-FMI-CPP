#include<iostream>
#include<vector>
#include<string>

#include"Bank.h"
#include"Customer.h"
#include"CurrentAccount.h"
#include"PivilegeAccount.h"
#include"SavingsAccount.h"

using namespace std;

int main()
{
	
	// deposit and withdraw...
	CurrentAccount b("BG3424Ho", "1453H", 8134.32);
	PivilegeAccount e("BG78834HA", "5678H", 8562.45);

	cout << "Sum before depositing 1000 lv: " << b.getBalance();
	b.deposit(1000);
	cout << " Sum after depositing: " << b.getBalance() << endl << endl;
	
	cout << "Sum before withdrawing 2000 lv: " << e.getBalance() << endl;
	cout << "Successfully withdrawn 2000 lv: " << ( e.withdraw(2000) ? "true" : "false" ) << endl;
	cout << "Sum after withdrawing: " << e.getBalance() << endl << endl;

	Bank bank("DSK", "bul.Bulgaria");

	// Add new customer:
	bank.addCustomer("ivanID", "Ivan", "Lilac sites");
	bank.addCustomer("georgiID", "Georgi", "Sheep's Elevation");
	bank.addCustomer("petarID", "Petar", "Upper Bathroom");

	//List all customers: 
	cout << "Bank customers: " << endl;
	bank.listCustomers();
	cout << endl;

	// Add new account:
	bank.addAccount("CurrentAccount", "BG1234HH", "ivanID", 11234.4);
	bank.addAccount("CurrentAccount", "BG3424Ho", "georgiID", 8134.32);
	bank.addAccount("CurrentAccount", "BG6565kH", "petarID", 5234.97);

	bank.addAccount("PivilegeAccount", "BG7734HH", "ivanID", 3452.45);
	bank.addAccount("PivilegeAccount", "BG78834HA", "petarID", 8562.45);

	bank.addAccount("SavingsAccount", "BG77334HH", "georgiID", 9993.19);
	bank.addAccount("SavingsAccount", "BG77134HH", "ivanID", 1293.19);

	//List all accounts:
	cout << "Bank accounts: " << endl;
	bank.listAccounts();
	cout << endl;

	//List customer accounts:
	bank.listCustomerAccount("ivanID");
	cout << endl;

	// Delete account:
	bank.deleteAccount("BG6565kH");
	cout << "After deleting an account: " << endl;
	bank.listAccounts();
	cout << endl;

	// Transfer from Ivan's CurrentAccount to Georgi's SavingsAccount: 
	// Before transfer:
	cout << "Before transfer from Ivan's to Georgi's account" << endl;
	bank.listCustomerAccount("ivanID");
	bank.listCustomerAccount("georgiID");
	bank.transfer("BG1234HH", "BG77334HH", 3000);
	// After transfer:
	cout << "After transfer: " << endl;
	bank.listCustomerAccount("ivanID");
	bank.listCustomerAccount("georgiID");
	cout << endl;

	//Delete customer(Petar):
	bank.deleteCustomer("petarID");
	cout << "List of customers after deleting Petar: " << endl;
	bank.listCustomers();
	cout << endl;

	cout << "Bank info:" << endl;
	bank.display();

	system("pause");
	return 0;
}