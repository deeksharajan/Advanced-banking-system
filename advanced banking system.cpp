#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class BankAccount {
private:
    double balance;
    int pin;

    string transactions[100];
    int transactionCount;

public:
    // Constructor
    BankAccount(int userPin, double initialBalance = 5000.0) {
        pin = userPin;
        balance = initialBalance;
        transactionCount = 0;
    }

    bool authenticate() {
        int enteredPin;
        cout << "Enter your PIN: ";
        cin >> enteredPin;

        if (enteredPin == pin) {
            cout << "Login Successful!\n";
            return true;
        } else {
            cout << "Incorrect PIN.\n";
            return false;
        }
    }

    void checkBalance() const {
        cout << "\nCurrent Balance: ?" << balance << endl;
    }

    void deposit() {
        double amount;
        cout << "Enter amount to deposit: ?";
        cin >> amount;

        if (amount <= 0) {
            cout << "Invalid amount.\n";
            return;
        }

        balance += amount;

        if (transactionCount < 100) {
            stringstream ss;
            ss << "Deposited ?" << amount;
            transactions[transactionCount++] = ss.str();
        }

        cout << "Deposit successful.\n";
    }

    void withdraw() {
        double amount;
        cout << "Enter amount to withdraw: ?";
        cin >> amount;

        if (amount <= 0) {
            cout << "Invalid amount.\n";
        }
        else if (amount > balance) {
            cout << "Insufficient balance.\n";
        }
        else {
            balance -= amount;

            if (transactionCount < 100) {
                stringstream ss;
                ss << "Withdrawn ?" << amount;
                transactions[transactionCount++] = ss.str();
            }

            cout << "Withdrawal successful.\n";
        }
    }

    void showTransactions() const {
        cout << "\nTransaction History:\n";

        if (transactionCount == 0) {
            cout << "No transactions yet.\n";
            return;
        }

        for (int i = 0; i < transactionCount; i++) {
            cout << i + 1 << ". " << transactions[i] << endl;
        }
    }
};

int main() {
    BankAccount account(1234);   // Default PIN = 1234
    int choice;

    if (!account.authenticate()) {
        return 0;
    }

    do {
        cout << "\n===== Mini Banking System =====\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transaction History\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                account.checkBalance();
                break;
            case 2:
                account.deposit();
                break;
            case 3:
                account.withdraw();
                break;
            case 4:
                account.showTransactions();
                break;
            case 5:
                cout << "Thank you for banking with us.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
