#include "HashTable.h"
#include "string.h"

HashTable::HashTable() {
    mem_size = 8;  
    chain_tops = new ChainNode*[mem_size];
    for (int i = 0; i < mem_size; i++) 
    {
        chain_tops[i] = nullptr;
    }
    count = 0;
}

HashTable::~HashTable()
{
    for (int i = 0; i < mem_size; i++)
    { 
        if (chain_tops[i] != nullptr)
        {
            delete chain_tops[i];
        }
    }
    delete[] chain_tops;
}

void HashTable::add(std::string & key) 
{
    if (count / mem_size > 3)
    {
        resize();
    }
    int index = hash_func(key);
    if (chain_tops[index] != nullptr) 
    {
        ChainNode* newNode = new ChainNode(key, index);
        newNode->next = chain_tops[index];
        chain_tops[index] = newNode;
    }
    else 
    {
        chain_tops[index] = new ChainNode(key, index);
    }
    count++;
}

void HashTable::resize() {
    ChainNode** save_ct = chain_tops;
    int oldSize = mem_size;
    mem_size *= 2;  
    count = 0;
    chain_tops = new ChainNode*[mem_size];
    for (int i = 0; i < mem_size; i++) 
    {
        chain_tops[i] = nullptr;
    }
    for (int i = 0; i < oldSize; i++) 
    {
        ChainNode* current = save_ct[i];
        while (current != nullptr) 
        {
            add(current->key);
            current = current->next;
        }
        delete current;
    }
    delete [] save_ct;
}

void HashTable::del(std::string & key) 
{
    int index = hash_func(key);
    ChainNode* top = chain_tops[index];
    ChainNode* prev = nullptr;
    while (top != nullptr) 
    {
        if (!strcmp(&key[0], &top->key[0]))
        {
            if (prev != nullptr)
            {
                prev->next = top->next;
            }
            else
            {
                chain_tops[index] = top->next;
            }
            delete top;
            count--;
            break;
        }
        prev = top;
    	top = top->next;
    }
}

int HashTable::find(std::string & key)
{
    int ret = -1;
    int index = hash_func(key);
    ChainNode* ptr = chain_tops[index];
    if (ptr != nullptr)
    {
        while (true)
        {
            if (strcmp(&ptr->key[0], &key[0]) == 0)
            {
                ret = ptr->value;
                break;
            }
            if (ptr == nullptr)
            {
                break;
            }
            ptr = ptr->next;
        }
    }
    return ret;
}

int HashTable::hash_func(std::string & key)
{
    double A = 0.61;
    int N = 0;
    size_t size = key.size();
    for (size_t i = 0; i < size; i++)
    {
        N += key[i];
    }
    return (int)(mem_size * (A * N - (int)(A * N)));
}

int HashTable::getSize()
{
    return mem_size;
}

ChainNode* HashTable::getData(int i)
{
    return chain_tops[i];
}