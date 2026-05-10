#ifndef DMA1TSCMD_H
#define DMA1TSCMD_H

int d1tscCmdSync(int d2cid);

int d1tscSync(int d2cid);

int d1tscCmdFinishToUseSlot(int slot);

int d1tscFinishToUseSlot(int slot);

#endif // DMA1TSCMD_H
