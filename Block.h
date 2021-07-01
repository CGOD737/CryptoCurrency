#include <string>
#include <iostream>
#include <stdlib.h>
#include <iterator>
#include <math.h>

#include "transaction.h"

using namespace std;

//Block Class
class Block {
    private:
        int index;
        size_t blockHash;
        size_t previousHash;
        size_t generateHash();

    public: 
        //Constructor
        Block(int index, Transaction t, size_t prevHash );

        //Get Original Hash of the Block
        size_t getHash();

        //Get the Hash of the Previous Block
        size_t getPreviousHash();

        //Carries the Transaction DataS
        Transaction data;

        //Hash Validation
        bool isBlockValid();
};