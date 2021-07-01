#include <string>
#include <iostream>
#include <stdlib.h>
#include <iterator>
#include <math.h>

#include "BlockChain.h"

using namespace std;

//blockchain constructor
BlockChain::BlockChain(){
    
    Block genesis = constructGenesis();
    chain.push_back(genesis);

}

//creates the first block on the chain
Block BlockChain::constructGenesis(){
    time_t curr;
    Transaction data;
    data.amount = 0;
    data.reciever = "None";
    data.sender = "None";

    data.time = time(&curr);

    hash<int> hash1;
    Block genesis(0, data, hash1(0));
    return genesis;
}