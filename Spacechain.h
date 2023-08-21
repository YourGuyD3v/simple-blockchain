#include <vector>
#include "Block.h"

using namespace std;

class Spacechain {
    public:

    Spacechain();

    void addBlock(Block bNew);

    private:
    uint32_t _nDifficulty;
    vector<Block> _vChain;

    Block _getLastBlock() const;
};