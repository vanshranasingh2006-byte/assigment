
#include <iostream>
using namespace std;

class BaseAccountClass {
public:
    virtual void SendMoney() {
        cout << "Money Sent Successfully!" << endl;
    }

    virtual void ReceiveMoney() {
        cout << "Money Received Successfully!" << endl;
    }
};

class ConsumerAccountClass : public BaseAccountClass {
public:
    void SendMoney() override {
        cout << "Permission Denied! Account is Flagged." << endl;
    }

    void ReceiveMoney() override {
        cout << "Permission Granted! Money Received." << endl;
    }

    void TakePermission() {
        cout << "Permission Taken from User." << endl;
    }

    void GivePermission() {
        cout << "Permission Given to User." << endl;
    }
};

int main() {
    BaseAccountClass normalAccount;
    ConsumerAccountClass flaggedAccount;

    BaseAccountClass* account = &normalAccount;

    cout << "Account" << endl;
    account->SendMoney();
    account->ReceiveMoney();

    cout << "\nFlagged Account" << endl;
    account = &flaggedAccount;
    account->SendMoney();
    account->ReceiveMoney();

    //downcasting 
    ConsumerAccountClass* consumer =
        dynamic_cast<ConsumerAccountClass*>(account);

    if (consumer != nullptr) {
        consumer->TakePermission();
        consumer->GivePermission();
    }

    return 0;
}
