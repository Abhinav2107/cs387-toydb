#include "raid.h"
#include "pf.h"
#include <stdio.h>

struct RAID_buf_ele* RAID_buf;

int time;

RAID_buf_ele* diskaccess[4];
int diskstatus[4];
int diskfd[4];

void initRAID() {
    time = 0;
    RAID_buf = malloc(sizeof(RAID_buf_ele));
    RAID_buf->prev = RAID_buf->next = NULL;
    RAID_buf->disk = -1;
    int i;
    for(i = 0; i < 4; i++) {
        diskaccess[i] = NULL;
        diskstatus[i] = 0;
        diskfd[i] = -1;
    }
}

static RAID_buf_ele* choose(int disk, int fd) {
    RAID_buf_ele *b = RAID_buf;
    RAID_buf_ele *b_first = NULL;
    while(1) {
        b = b->next;
        if(b == NULL)
            return b_first;
        if(b->disk == -1 && b->pagenum % 2 == disk % 2) {
            if(b_first == NULL)
                b_first = b;
            if(fd == -1)
                return b_first;
            if(b->fd == fd)
                return b;
        }
    }

}

static void finish(RAID_buf_ele* b) {
    b->prev->next = b->next;
    if(b->next != NULL)
        b->next->prev = b->prev;
    donePFRAID_buf(b->fd, b->pagenum);
    free(b);
}

void stepTime() {
    time++;
    int i;
    RAID_buf_ele *b;
    for(i = 0; i < 4; i++) {
        if(diskstatus[i] == 0) {
            b = choose(i, diskfd[i]);
            if(b == NULL)
                continue;
            if(b->fd == diskfd[i]) {
                finish(b);
            }
            else {
                diskstatus[i] = 2;
                b->disk = i;
                diskfd[i] = b->fd;
                diskaccess[i] = b;
            }
        }
        else {
            diskstatus[i]--;
            if(diskstatus[i] == 0) {
                finish(diskaccess[i]);
                diskaccess[i] = NULL;
            }
        }
    }
}

int cost() {
    return time;
}

void insertRAIDbuf(int fd, int pagenum) {
RAID_buf_ele *b = RAID_buf;
    while(1) {
        if(b->next == NULL) {
            b->next = (RAID_buf_ele *) malloc(sizeof(RAID_buf_ele));
            b->next->prev = b->next;
            b->next->next = NULL;
            b->next->fd = fd;
            b->next->pagenum = pagenum;
            b->next->disk = -1;
            break;
        }
        b = b->next;
    }
}
