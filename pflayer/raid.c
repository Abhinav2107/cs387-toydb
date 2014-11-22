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

static void finish(RAID_buf_ele* b) {
    //printf("Finishing %p\n", b);
    b->prev->next = b->next;
    if(b->next != NULL)
        b->next->prev = b->prev;
    if(b->type == RAID_READ)
        donePFRAID_buf(b->ptr);
    free(b);
}

static RAID_buf_ele* choose(int disk, int fd) {
    RAID_buf_ele *b = RAID_buf;
    RAID_buf_ele *b_first = NULL;
    while(1) {
        b = b->next;
        if(b == NULL)
            return b_first;
        if(b->disk == -1 && b->pagenum % 2 == disk % 2 && b->type == RAID_READ) {
            if(b_first == NULL)
                b_first = b;
            if(fd == -1)
                return b_first;
            if(b->fd == fd)
                return b;
        }
        if((disk == 0 || disk == 1) && b->pagenum % 2 == disk % 2 && b->type == RAID_WRITE && diskstatus[disk+2] == 0) {
            if(b_first == NULL) {
                b_first = b;
                b = b->next;
                if(b->fd == diskfd[disk+2]) {
                    finish(b);
                }
                else {
                    diskstatus[disk+2] = 2;
                    b->disk = disk+2;
                    diskfd[disk+2] = b->fd;
                    diskaccess[disk+2] = b;
                }
                return b_first;   
            }
        }
    }

}

void printRAIDbuf() {

RAID_buf_ele * b = RAID_buf;
    printf("===============\n");
    int i;
    for(i = 0; i < 4; i++)
        printf("%d ", diskstatus[i]);
    printf("\n");
    printf("%p\n", b);
    printf("Next: %p\n", b->next);
    while(b->next) {
        b = b->next;
        printf("---------------\n");
        printf("%p\n", b);
        printf("fd = %d\n", b->fd);
        printf("pagenum = %d\n", b->pagenum);
        printf("disk = %d\n", b->disk);
        printf("prev = %p\n", b->prev);
        printf("next = %p\n", b->next);
        printf("---------------\n");
    }
    printf("===============\n");
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

void resetCost() {
    time = 0;
}
void insertRAIDbuf(int fd, int pagenum, int type, PFRAID_buf_ele * ptr) {
RAID_buf_ele *b = RAID_buf;
    while(1) {
        if(b->next == NULL) {
            b->next = (RAID_buf_ele *) malloc(sizeof(RAID_buf_ele));
            b->next->prev = b;
            b->next->next = NULL;
            b->next->fd = fd;
            b->next->pagenum = pagenum;
            b->next->disk = -1;
            b->next->type = type;
            b->next->ptr = ptr;
            if(type == RAID_WRITE) {
                b = b->next;
                b->next = (RAID_buf_ele *) malloc(sizeof(RAID_buf_ele));
                b->next->prev = b;
                b->next->next = NULL;
                b->next->fd = fd;
                b->next->pagenum = pagenum;
                b->next->disk = -1;
                b->next->type = type;
                b->next->ptr = ptr; 
            }
            break;
        }
        b = b->next;
    }
}
