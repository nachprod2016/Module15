#pragma once
#include <string>
#include "ChainNode.h"

class HashTable 
{
private:
    int hash_func(std::string & key);
    ChainNode** chain_tops;
    size_t mem_size;
    size_t count;
public: 
    HashTable();
    ~HashTable();
    void add(std::string & key);
    void resize();
    void del(std::string & key);
    int find(std::string & key);
    int getSize();
    ChainNode* getData(int i);
};