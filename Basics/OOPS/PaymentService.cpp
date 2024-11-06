#include<bits/stdc++.h>
using namespace std;

class PaymentMethod{
public:
    virtual void pay()=0;
    virtual ~PaymentMethod() = default;
};

class Card : public PaymentMethod {
    string cardNo;
    string userName;
public:
    Card(string cardNo, string userName){
        this->cardNo = cardNo;
        this->userName = userName;
    }
    string getCardNo(){
        return cardNo;
    }
    string getUserName(){
        return userName;
    }
};

class CreditCard : public Card{
    public:
    CreditCard(string cardNo, string userName) : Card(cardNo, userName){
    }
    void pay() override{
        cout<<"Amount paid using Credit Card"<<endl;
    }
};

class DebitCard : public Card{
    public:
    DebitCard(string cardNo, string userName) : Card(cardNo, userName){
    }
    void pay() override{
        cout<<"Amount paid using Debit Card"<<endl;
    }
};


class PaymentService{
    //storing and adding payment methods
    unordered_map<string, PaymentMethod*> paymentMethods;
    public:
    void addPaymentMethod(string name, PaymentMethod* pm){
        paymentMethods[name] = pm;
    }

    void makePayment(string name){
        PaymentMethod* pm = paymentMethods[name];
        pm->pay();
    }
};

class UPI: public PaymentMethod{
    public:
    void pay() override{
        cout<<"Amount paid using UPI"<<endl;
    }
};

class Wallet : public PaymentMethod{
    public:
    void pay() override{
        cout<<"Amount paid using Wallet"<<endl;
    }
};

int main(){
    //client code
    PaymentService ps;
    CreditCard cc("1234567890", "John Doe");
    DebitCard dc("0987654321", "Jane Doe");
    UPI upi;
    Wallet wallet;

    ps.addPaymentMethod("CreditCard", &cc);
    ps.addPaymentMethod("DebitCard", &dc);
    ps.addPaymentMethod("UPI", &upi);
    ps.addPaymentMethod("Wallet", &wallet);

    ps.makePayment("CreditCard");
    ps.makePayment("DebitCard");
    ps.makePayment("UPI");
    ps.makePayment("Wallet");
    return 0;
}