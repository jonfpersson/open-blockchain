#include <iostream>
#include <string>
#include <iostream>
#include <vector>
#include "block.h"

int isChainValid(std::vector<block> blocks){

    for(int i = 1; i < blocks.size(); i++){
        
        if(blocks[i].hash != blocks[i].calculateHash()){
            std::cout << "Hash invalid" << std::endl;
            return 1;
        }

        if(blocks[i-1].hash != blocks[i-1].calculateHash()){
            std::cout << "Previous hash invalid" << std::endl ;
            return 2;
        }
        
    }
    return 0;

}

int main(int argc, char* argv[]) {
    std::vector<block> blocks;

    block firstBlock("block one", "0");
    block secondBlock("block two", firstBlock.hash);
    block thirdBlock("block three", secondBlock.hash);
    blocks.push_back(firstBlock);
    blocks.push_back(secondBlock);
    blocks.push_back(thirdBlock);

    if(isChainValid(blocks) != 0){
        std::cout << "Error, chain invalid" << std::endl ;
    }
    
    blocks[1].hash = "aaaa";
    if(isChainValid(blocks) != 0){
        std::cout << "Error, chain invalid" << std::endl ;
    }
    return 0;
}
