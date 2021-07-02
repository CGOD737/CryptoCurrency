#include <iostream>
#include <ctime>
#include <vector>

#include "transaction.h"
#include "Block.h"
#include "BlockChain.h

using namespace std;

int main(){
    //intializes BlockChain

    BlockChain GucchiCoin;

    //Data for first user added Block
    Transaction data;
    time_t dataTime;
    data.amount = 1.0;
    data.reciever = "Chris";
    data.sender = "Godfrey";
    data.time = time(&dataTime);

    GucchiCoin.addBlock(data);

    cout << "Checking if Chain is valid:+ " << endl << GucchiCoin.isChainValid() << endl;
	
	return 0;

}
