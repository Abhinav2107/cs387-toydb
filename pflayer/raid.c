#include "raid.h"
#include "pf.h"
#include <stdio.h>

struct RAID_buf_ele* RAID_buf;

int time;

void initRAID() {
    time = 0;
    RAID_buf = malloc(sizeof(RAID_buf_ele));
    RAID_buf->prev = RAID_buf->next = NULL;
    RAID_buf->status = 0;
}

void stepTime() {

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
            b->next->fd = fd;
            b->next->pagenum = pagenum;
            b->next->status = 0;
            break;
        }
        b = b->next;
    }
}
