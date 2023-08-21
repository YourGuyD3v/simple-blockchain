#include "Spacechain.h"

int main() {
    Spacechain sChain = Spacechain();

    cout << "Mining block 1..." << endl;
    sChain.addBlock(Block(1, "Block 1 Data"));

    cout << "Mining block 2..." << endl;
    sChain.addBlock(Block(2, "Block 2 Data"));

    cout << "Mining block 3..." << endl;
    sChain.addBlock(Block(3, "Block 3 Data"));

    return 0;
}
