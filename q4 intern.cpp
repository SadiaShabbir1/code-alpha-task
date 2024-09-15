#include <iostream>
#include <string>

using namespace std;

const int MAX_CUSTOMERS = 10;
const int MAX_ACCOUNTS = 5;
const int MAX_TRANSACTIONS = 10;

class Account;
class Transaction;

class Customer {
private:
    string name;
    string customerID;
    Account* accounts[MAX_ACCOUNTS];
    int numAccounts;

public:
    Customer(string n, string id) : name(n), customerID(id), numAccounts(0) {}

    string getName() const { return name; }
    string getCustomerID() const { return customerID; }
    bool addAccount(Account* account);
    void displayCustomerInfo() const;
};

// Class for Account
class Account {
private:
    string accountNumber;
    double balance;
    Transaction* transactions[MAX_TRANSACTIONS];
    int numTransactions;

public:
    Account(string accNum, double bal = 0.0) : accountNumber(accNum), balance(bal), numTransactions(0) {}

    string getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }
    void deposit(double amount);
    bool withdraw(double amount);
    bool addTransaction(Transaction* transaction);
    void displayAccountInfo() const;
    void displayTransactions() const;
};

class Transaction {
private:
    string transactionType;
    double amount;

public:
    Transaction(string type, double amt) : transactionType(type), amount(amt) {}

    void displayTransaction() const {
        cout << "Transaction: " << transactionType << ", Amount: " << amount << endl;
    }
};


bool Customer::addAccount(Account* account) {
    if (numAccounts < MAX_ACCOUNTS) {
        accounts[numAccounts++] = account;
        return true;
    } else {
        cout << "Cannot add more accounts for this customer.\n";
        return false;
    }
}

void Customer::displayCustomerInfo() const {
    cout << "Customer Name: " << name << "\nCustomer ID: " << customerID << endl;
    cout << "Accounts:\n";
    for (int i = 0; i < numAccounts; i++) {
        accounts[i]->displayAccountInfo();
    }
}

void Account::deposit(double amount) {
    balance += amount;
    addTransaction(new Transaction("Deposit", amount));
}

bool Account::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
        addTransaction(new Transaction("Withdrawal", amount));
        return true;
    } else {
        cout << "Insufficient funds.\n";
        return false;
    }
}

bool Account::addTransaction(Transaction* transaction) {
    if (numTransactions < MAX_TRANSACTIONS) {
        transactions[numTransactions++] = transaction;
        return true;
    } else {
        cout << "Transaction history is full.\n";
        return false;
    }
}

void Account::displayAccountInfo() const {
    cout << "Account Number: " << accountNumber << "\nBalance: " << balance << endl;
}

void Account::displayTransactions() const {
    cout << "Recent Transactions:\n";
    for (int i = 0; i < numTransactions; i++) {
        transactions[i]->displayTransaction();
    }
}


int main() {
  
    Customer customer1("John Doe", "C001");

    Account account1("A001", 1000.0);
    Account account2("A002", 500.0);

    customer1.addAccount(&account1);
    customer1.addAccount(&account2);

    account1.deposit(500.0);
    account1.withdraw(200.0);
    account2.deposit(300.0);

   
    customer1.displayCustomerInfo();

 
    account1.displayTransactions();
    account2.displayTransactions();

    return 0;
}

