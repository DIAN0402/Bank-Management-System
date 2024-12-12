#include <iostream>
#include <string>

using namespace std;

struct BankAcc {
    int AccPin;
    string AccName;
    double AccBal;
};

void createAccount(BankAcc accounts[], int &count, int maxAccounts);
void viewAccounts(const BankAcc accounts[], int count);
void updateAccount(BankAcc accounts[], int count);
void deleteAccount(BankAcc accounts[], int &count);
void BankMenu(BankAcc accounts[], int &count, int maxAccounts);
void bankLogin(BankAcc accounts[], int count, int maxAccounts);



int main() {
    const int maxAccounts = 100;
    BankAcc accounts[maxAccounts];
    int count = 0;
    int choice1;

    do {
        cout << "\n===   Welcome to X Bank   ===\n\n";
        cout << "What can I do for you?\n";
        cout << "1. Create Account\n";
        cout << "2. Login to your account\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice1;

        switch (choice1) {
            case 1:
                createAccount(accounts, count, maxAccounts);
                break;
            case 2:
                bankLogin(accounts, count, maxAccounts);
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice1 != 3);

    return 0;
}

void bankLogin(BankAcc accounts[], int count, int maxAccounts) {
    int Npin[] = {1234, 1235, 1237, 1238, 1239};
    int size = sizeof(Npin) / sizeof(Npin[0]);
    int target;

    cout << "Enter your PIN: ";
    cin >> target;

    while (true) {
        if (target < 1000 || target > 9999) {
            cout << "Invalid PIN. Please try again...\n";
            cin >> target;
            continue;
        }

        int result = PINSearch(Npin, size, target);

        if (result != -1) {
            cout << "You entered " << target << ". You may now enter!\n";
            BankMenu(accounts, count, maxAccounts);
            break;
        } else {
            cout << "Invalid PIN. Try again...\n";
            cin >> target;
        }
    }
}

int PINSearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

void BankMenu(BankAcc accounts[], int &count, int maxAccounts) {
    int choice;

    do {
        cout << "\n=== Bank Menu ===\n";
        cout << "1. View Accounts\n";
        cout << "2. Update Account\n";
        cout << "3. Delete Account\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewAccounts(accounts, count);
                break;
            case 2:
                updateAccount(accounts, count);
                break;
            case 3:
                deleteAccount(accounts, count);
                break;
            case 4:
                cout << "Exiting...\n";    
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

void createAccount(BankAcc accounts[], int &count, int maxAccounts) {
    if (count >= maxAccounts) {
        cout << "Error: Maximum number of accounts reached!\n";
        return;
    }

    BankAcc NewAcc;

    cout << "Enter new PIN: ";
    cin >> NewAcc.AccPin;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, NewAcc.AccName);
    cout << "Enter your first deposit: ";
    cin >> NewAcc.AccBal;

    accounts[count] = NewAcc;
    count++;
    cout << "Account created successfully!\n";
}

void viewAccounts(const BankAcc accounts[], int count) {
    if (count == 0) {
        cout << "No accounts to view!\n";
        return;
    }

    cout << "\n---- Account Profiles ----\n";
    for (int i = 0; i < count; i++) {
        cout << "Account PIN: " << accounts[i].AccPin << "\n";
        cout << "Account Name: " << accounts[i].AccName << "\n";
        cout << "Account Balance: $" << accounts[i].AccBal << "\n";
        cout << "--------------------------\n";
    }
}

void updateAccount(BankAcc accounts[], int count) {
    if (count == 0) {
        cout << "No accounts to update!\n";
        return;
    }

    int accNum;
    cout << "Enter Account PIN: ";
    cin >> accNum;

    for (int i = 0; i < count; i++) {
        if (accounts[i].AccPin == accNum) {
            cout << "Enter new Account Name: ";
            cin.ignore();
            getline(cin, accounts[i].AccName);
            cout << "Account updated successfully!\n";
            return;
        }
    }
    cout << "Account not found!\n";
}

void deleteAccount(BankAcc accounts[], int &count) {
    if (count == 0) {
        cout << "No accounts to delete!\n";
        return;
    }

    int accNum;
    cout << "Enter Account PIN: ";
    cin >> accNum;

    for (int i = 0; i < count; i++) {
        if (accounts[i].AccPin == accNum) {
            for (int j = i; j < count - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            count--;
            cout << "Account deleted successfully!\n";
            return;
        }
    }
    cout << "Account not found!\n";
}
