#pragma once
#include <string>

struct ChainNode 
{
    std::string key;
    int value;
    ChainNode* next;
    ChainNode(std::string & key, int value);
    ~ChainNode();
};