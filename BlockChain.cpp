#include <stdio.h>
#include <ctime>
#include <string>

#include "Block.h"
#include "BlockChain.h"

#include <vector>

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

Block *BlockChain::getLatestBlock(){
    return &chain.back();
}

//adds block to the end of the chain.
void BlockChain::addBlock(Transaction data){
    int index = (int)chain.size() - 1;
    Block newBlock(index, data, getLatestBlock()->getHash());
}

bool BlockChain::isChainValid(){

    vector<Block>::iterator i;
    int length = (int)chain.size();

    for ( i = chain.begin(); i != chain.end(); i++ ){
        Block curr = *i;
        if (!curr.isBlockValid())
            return false;
        if (length > 1){
            Block prev = *(i - 1);
            //check if the data is invalid
            if (curr.getPreviousHash() != prev.getHash())
                return false;
        }
    }
    //everything checks out
    return true;
}