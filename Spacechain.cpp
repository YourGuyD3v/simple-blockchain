#include "Spacechain.h"

Spacechain::Spacechain() {
    _vChain.emplace_back(Block(0, "Genesis Block"));
    _nDifficulty = 6;
}

void Spacechain::addBlock(Block bNew) {
    bNew.sPrevHash = _getLastBlock().getHash();
    bNew.MinBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

Block Spacechain::_getLastBlock() const {
    return _vChain.back();
}