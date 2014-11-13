#ifndef __RAID_H__
#define __RAID_H__
#include "pf.h"

#define RAID_READ 0
#define RAID_WRITE 1

typedef struct RAID_buf_ele {
    int fd;
    int pagenum;
    int disk;
    struct PFRAID_buf_ele * ptr;
    struct RAID_buf_ele * prev;
    struct RAID_buf_ele * next;
    int type;
} RAID_buf_ele;

void insertRAIDbuf(int fd, int pagenum, int type);
void stepTime();
int cost();
void resetCost();
void initRAID();

#endif
