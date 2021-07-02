//Compiler Includes

#ifndef Blockchain_h
#define Blockchain_h

#include <string>
#include <iostream>
#include <stdlib.h>
#include <iterator>
#include <math.h>

//Local Includes
#include "Block.h"

class BlockChain {
    private:
        //Creates First Block
        Block constructGenesis();


    public:
        //Public Chain
        vector<Block> chain;
        //Constructor
        BlockChain();

        //Public Functions
        void addBlock(Transaction data);
        bool isChainValid();

        Block *getLatestBlock();
};
#endif