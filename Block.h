#include <iostream>

using namespace std;

class Block {
    public:

    string sPrevHash;

    Block(uint32_t nIndexIn, const string &sDataIn);

    string getHash();

    void MinBlock(uint32_t nDifficulty);

    private:
    uint32_t _nIndex;
    uint64_t _nNonce;
    string _sData;
    string _sHash;
    time_t _tTime;

    string _CalculateHash() const;
};