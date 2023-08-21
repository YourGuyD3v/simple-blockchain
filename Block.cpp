#include "Block.h"
#include "sha256.h"
#include <sstream>

Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn) {
    _nNonce = -1;
    _tTime = time(nullptr);
}

string Block::getHash() {
    return _sHash;
}

void Block::MinBlock(uint32_t nDifficulty) {
    char cstr[nDifficulty + 1];

    for (int i = 0; i < nDifficulty; i++) {
        cstr[i] = '0';
    }

    cstr[nDifficulty] = '\0';

    string str(cstr);

    do {
        _nNonce++;
        _sHash = _CalculateHash();
    } while (_sHash.substr(0, nDifficulty) != str);

    cout << "Block Mined: " << _sHash << endl;
}

inline string Block::_CalculateHash() const {
    stringstream ss;
    // Serialize the block header into a stream
    ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;

    return sha256(ss.str());
}