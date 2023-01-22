#include "ChainNode.h"

ChainNode::ChainNode(std::string & key, int value) : key(key), value(value), next(nullptr) {}

ChainNode::~ChainNode()
{
    if (next != nullptr)
    {
        delete next;
    }
}