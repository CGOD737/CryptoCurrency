//defines the structure of a Transaction

#include <ctime>
#include <vector>
#include <string>

using namespace std;
//Transaction data
struct Transaction {
    double amount; //amount in the transaction.
    string sender; //sender key
    string reciever; //reciever key
    time_t time; //timestamp of the transaction
};
