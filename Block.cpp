#include <stdio.h>
#include <string>

#include "Block.h"
#include "transaction.h"


using namespace std;

//Constructor
Block::Block(int i, Transaction data, size_t prevHash){
    index = i;
    data = data;
    previousHash = prevHash;
    blockHash = generateHash();
}
//private functions

//generates the Hash of the Block
size_t Block::generateHash(){
    hash<string> hash1;
    hash<size_t> hash2;
    hash<size_t> hash3;

    string toHash = to_string(data.amount) + data.reciever + data.sender + to_string(data.time);

    return hash3(hash1(toHash)) + hash2(previousHash);
}
//Gets the Previous Hash of the Block in the Chain
size_t Block::getPreviousHash(){
    return previousHash;
}

//Regenerates the Hash and checks for validation
bool Block::isBlockValid(){
    return generateHash() == blockHash;
}