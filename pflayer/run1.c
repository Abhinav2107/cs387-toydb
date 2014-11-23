#include "pf.h"
#include <stdio.h>
#include <string.h>
int main() {
PF_Init();
PF_SaveSnapshots();
int fd0;
int sfd0;
int fd1;
int sfd1;
int fd2;
int sfd2;
int fd3;
int sfd3;
int fd4;
int sfd4;
char* pagebuf;
PFRAID_buf_ele * ptr;
int error;
fd0 = PF_OpenFile("abc");
sfd0 = PF_OpenFile("snapshot_abc");
fd1 = PF_OpenFile("def");
sfd1 = PF_OpenFile("snapshot_def");
fd2 = PF_OpenFile("ghi");
sfd2 = PF_OpenFile("snapshot_ghi");
fd3 = PF_OpenFile("jkl");
sfd3 = PF_OpenFile("snapshot_jkl");
fd4 = PF_OpenFile("mno");
sfd4 = PF_OpenFile("snapshot_mno");
error = PF_ReadSnapshot(fd1, sfd1, 3, &ptr, &pagebuf);
error = PF_GetThisPage(fd0, 12, &ptr, &pagebuf);
PF_UnfixPage(fd0, 12, 0);
error = PF_GetThisPage(fd4, 13, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 13, 0);
error = PF_GetThisPage(fd0, 12, &ptr, &pagebuf);
PF_UnfixPage(fd0, 12, 0);
error = PF_GetThisPage(fd2, 2, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 2, 0);
error = PF_GetThisPage(fd2, 9, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 9, 0);
error = PF_GetThisPage(fd4, 11, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 11, 1);
error = PF_ReadSnapshot(fd2, sfd2, 11, &ptr, &pagebuf);
error = PF_GetThisPage(fd1, 13, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 13, 0);
error = PF_GetThisPage(fd2, 12, &ptr, &pagebuf);
PF_UnfixPage(fd2, 12, 0);
error = PF_ReadSnapshot(fd0, sfd0, 9, &ptr, &pagebuf);
error = PF_ReadSnapshot(fd1, sfd1, 12, &ptr, &pagebuf);
error = PF_GetThisPage(fd0, 6, &ptr, &pagebuf);
PF_UnfixPage(fd0, 6, 0);
error = PF_GetThisPage(fd4, 6, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 6, 1);
error = PF_ReadSnapshot(fd2, sfd2, 4, &ptr, &pagebuf);
error = PF_GetThisPage(fd4, 4, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 4, 1);
error = PF_GetThisPage(fd2, 0, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 0, 1);
error = PF_ReadSnapshot(fd4, sfd4, 2, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd3, 12, &ptr, &pagebuf);
PF_UnfixPage(fd3, 12, 0);
error = PF_ReadSnapshot(fd2, sfd2, 0, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd0, 0, &ptr, &pagebuf);
PF_UnfixPage(fd0, 0, 0);
error = PF_GetThisPage(fd4, 6, &ptr, &pagebuf);
PF_UnfixPage(fd4, 6, 0);
error = PF_GetThisPage(fd2, 4, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 4, 1);
error = PF_GetThisPage(fd2, 14, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 14, 0);
error = PF_GetThisPage(fd1, 4, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 4, 0);
error = PF_GetThisPage(fd1, 7, &ptr, &pagebuf);
PF_UnfixPage(fd1, 7, 0);
error = PF_ReadSnapshot(fd3, sfd3, 7, &ptr, &pagebuf);
error = PF_GetThisPage(fd4, 7, &ptr, &pagebuf);
PF_UnfixPage(fd4, 7, 0);
error = PF_ReadSnapshot(fd0, sfd0, 6, &ptr, &pagebuf);
error = PF_GetThisPage(fd1, 12, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 12, 1);
error = PF_GetThisPage(fd4, 13, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 13, 1);
error = PF_ReadSnapshot(fd1, sfd1, 0, &ptr, &pagebuf);
error = PF_GetThisPage(fd4, 2, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 2, 0);
error = PF_ReadSnapshot(fd1, sfd1, 12, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd4, 11, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 11, 1);
error = PF_GetThisPage(fd3, 14, &ptr, &pagebuf);
PF_UnfixPage(fd3, 14, 0);
error = PF_GetThisPage(fd1, 13, &ptr, &pagebuf);
PF_UnfixPage(fd1, 13, 0);
error = PF_GetThisPage(fd3, 4, &ptr, &pagebuf);
PF_UnfixPage(fd3, 4, 0);
error = PF_ReadSnapshot(fd3, sfd3, 9, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd0, 11, &ptr, &pagebuf);
PF_UnfixPage(fd0, 11, 0);
error = PF_GetThisPage(fd1, 11, &ptr, &pagebuf);
PF_UnfixPage(fd1, 11, 0);
error = PF_GetThisPage(fd1, 7, &ptr, &pagebuf);
PF_UnfixPage(fd1, 7, 0);
error = PF_ReadSnapshot(fd4, sfd4, 12, &ptr, &pagebuf);
error = PF_GetThisPage(fd4, 12, &ptr, &pagebuf);
PF_UnfixPage(fd4, 12, 0);
error = PF_GetThisPage(fd4, 13, &ptr, &pagebuf);
PF_UnfixPage(fd4, 13, 0);
error = PF_GetThisPage(fd1, 13, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 13, 0);
error = PF_ReadSnapshot(fd3, sfd3, 8, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd3, 14, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 14, 1);
error = PF_GetThisPage(fd1, 4, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 4, 1);
error = PF_GetThisPage(fd1, 5, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 5, 1);
error = PF_GetThisPage(fd2, 0, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 0, 1);
error = PF_GetThisPage(fd1, 8, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 8, 0);
error = PF_GetThisPage(fd3, 3, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 3, 0);
error = PF_ReadSnapshot(fd2, sfd2, 13, &ptr, &pagebuf);
error = PF_GetThisPage(fd1, 0, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 0, 0);
error = PF_GetThisPage(fd0, 13, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 13, 0);
error = PF_GetThisPage(fd3, 12, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 12, 0);
error = PF_ReadSnapshot(fd4, sfd4, 6, &ptr, &pagebuf);
error = PF_ReadSnapshot(fd1, sfd1, 10, &ptr, &pagebuf);
error = PF_GetThisPage(fd4, 8, &ptr, &pagebuf);
PF_UnfixPage(fd4, 8, 0);
error = PF_GetThisPage(fd1, 3, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 3, 1);
error = PF_ReadSnapshot(fd3, sfd3, 3, &ptr, &pagebuf);
error = PF_GetThisPage(fd0, 9, &ptr, &pagebuf);
PF_UnfixPage(fd0, 9, 0);
error = PF_GetThisPage(fd1, 9, &ptr, &pagebuf);
PF_UnfixPage(fd1, 9, 0);
error = PF_GetThisPage(fd0, 9, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 9, 1);
error = PF_GetThisPage(fd3, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 10, 1);
error = PF_GetThisPage(fd2, 0, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 0, 1);
error = PF_ReadSnapshot(fd3, sfd3, 13, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd2, 5, &ptr, &pagebuf);
PF_UnfixPage(fd2, 5, 0);
error = PF_GetThisPage(fd0, 6, &ptr, &pagebuf);
PF_UnfixPage(fd0, 6, 0);
error = PF_GetThisPage(fd1, 3, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 3, 0);
error = PF_ReadSnapshot(fd2, sfd2, 12, &ptr, &pagebuf);
error = PF_GetThisPage(fd2, 9, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 9, 1);
error = PF_GetThisPage(fd4, 2, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 2, 1);
error = PF_GetThisPage(fd1, 4, &ptr, &pagebuf);
PF_UnfixPage(fd1, 4, 0);
error = PF_GetThisPage(fd1, 13, &ptr, &pagebuf);
PF_UnfixPage(fd1, 13, 0);
error = PF_GetThisPage(fd3, 6, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 6, 1);
error = PF_GetThisPage(fd0, 12, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 12, 0);
error = PF_GetThisPage(fd2, 0, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 0, 0);
error = PF_GetThisPage(fd1, 3, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 3, 0);
error = PF_GetThisPage(fd2, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 10, 0);
error = PF_GetThisPage(fd3, 7, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 7, 1);
error = PF_GetThisPage(fd3, 11, &ptr, &pagebuf);
PF_UnfixPage(fd3, 11, 0);
error = PF_GetThisPage(fd1, 5, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 5, 1);
error = PF_GetThisPage(fd2, 9, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 9, 1);
error = PF_GetThisPage(fd4, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 10, 1);
error = PF_GetThisPage(fd2, 14, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 14, 1);
error = PF_GetThisPage(fd0, 1, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 1, 0);
error = PF_GetThisPage(fd1, 1, &ptr, &pagebuf);
PF_UnfixPage(fd1, 1, 0);
error = PF_ReadSnapshot(fd3, sfd3, 14, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd1, 0, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 0, 0);
error = PF_GetThisPage(fd4, 8, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 8, 1);
error = PF_GetThisPage(fd4, 12, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 12, 1);
error = PF_GetThisPage(fd0, 2, &ptr, &pagebuf);
PF_UnfixPage(fd0, 2, 0);
error = PF_GetThisPage(fd4, 9, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 9, 1);
error = PF_GetThisPage(fd0, 13, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 13, 0);
error = PF_ReadSnapshot(fd2, sfd2, 5, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd0, 10, &ptr, &pagebuf);
PF_UnfixPage(fd0, 10, 0);
error = PF_GetThisPage(fd3, 2, &ptr, &pagebuf);
PF_UnfixPage(fd3, 2, 0);
error = PF_ReadSnapshot(fd2, sfd2, 2, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd1, 4, &ptr, &pagebuf);
PF_UnfixPage(fd1, 4, 0);
error = PF_GetThisPage(fd0, 7, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 7, 0);
error = PF_ReadSnapshot(fd1, sfd1, 6, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd4, 6, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 6, 1);
error = PF_GetThisPage(fd3, 3, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 3, 0);
error = PF_GetThisPage(fd2, 11, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 11, 1);
error = PF_GetThisPage(fd1, 7, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 7, 1);
error = PF_ReadSnapshot(fd0, sfd0, 3, &ptr, &pagebuf);
error = PF_ReadSnapshot(fd2, sfd2, 2, &ptr, &pagebuf);
error = PF_GetThisPage(fd1, 5, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 5, 1);
error = PF_ReadSnapshot(fd3, sfd3, 11, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd4, 2, &ptr, &pagebuf);
PF_UnfixPage(fd4, 2, 0);
error = PF_GetThisPage(fd3, 8, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 8, 1);
error = PF_GetThisPage(fd4, 8, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 8, 1);
error = PF_GetThisPage(fd3, 6, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 6, 0);
error = PF_GetThisPage(fd2, 9, &ptr, &pagebuf);
PF_UnfixPage(fd2, 9, 0);
error = PF_ReadSnapshot(fd0, sfd0, 8, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd3, 8, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 8, 1);
error = PF_GetThisPage(fd4, 4, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 4, 0);
error = PF_GetThisPage(fd4, 12, &ptr, &pagebuf);
PF_UnfixPage(fd4, 12, 0);
error = PF_GetThisPage(fd4, 6, &ptr, &pagebuf);
PF_UnfixPage(fd4, 6, 0);
error = PF_ReadSnapshot(fd3, sfd3, 10, &ptr, &pagebuf);
error = PF_ReadSnapshot(fd1, sfd1, 4, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd2, 14, &ptr, &pagebuf);
PF_UnfixPage(fd2, 14, 0);
error = PF_GetThisPage(fd3, 11, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 11, 1);
error = PF_ReadSnapshot(fd1, sfd1, 7, &ptr, &pagebuf);
error = PF_GetThisPage(fd1, 8, &ptr, &pagebuf);
PF_UnfixPage(fd1, 8, 0);
error = PF_ReadSnapshot(fd0, sfd0, 2, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd1, 7, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 7, 0);
error = PF_GetThisPage(fd1, 2, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 2, 0);
error = PF_GetThisPage(fd4, 4, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 4, 1);
error = PF_ReadSnapshot(fd2, sfd2, 5, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd4, 3, &ptr, &pagebuf);
PF_UnfixPage(fd4, 3, 0);
error = PF_GetThisPage(fd1, 13, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 13, 1);
error = PF_GetThisPage(fd0, 13, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 13, 1);
error = PF_GetThisPage(fd4, 7, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 7, 1);
error = PF_GetThisPage(fd0, 1, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 1, 1);
error = PF_GetThisPage(fd1, 4, &ptr, &pagebuf);
PF_UnfixPage(fd1, 4, 0);
error = PF_GetThisPage(fd1, 1, &ptr, &pagebuf);
PF_UnfixPage(fd1, 1, 0);
error = PF_GetThisPage(fd2, 1, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 1, 0);
error = PF_GetThisPage(fd0, 3, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 3, 0);
error = PF_GetThisPage(fd0, 8, &ptr, &pagebuf);
PF_UnfixPage(fd0, 8, 0);
error = PF_GetThisPage(fd2, 13, &ptr, &pagebuf);
PF_UnfixPage(fd2, 13, 0);
error = PF_GetThisPage(fd4, 2, &ptr, &pagebuf);
PF_UnfixPage(fd4, 2, 0);
error = PF_GetThisPage(fd0, 9, &ptr, &pagebuf);
PF_UnfixPage(fd0, 9, 0);
error = PF_GetThisPage(fd2, 0, &ptr, &pagebuf);
PF_UnfixPage(fd2, 0, 0);
error = PF_GetThisPage(fd1, 0, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 0, 1);
error = PF_ReadSnapshot(fd3, sfd3, 11, &ptr, &pagebuf);
error = PF_GetThisPage(fd4, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 10, 1);
error = PF_GetThisPage(fd4, 14, &ptr, &pagebuf);
PF_UnfixPage(fd4, 14, 0);
error = PF_GetThisPage(fd3, 8, &ptr, &pagebuf);
PF_UnfixPage(fd3, 8, 0);
error = PF_GetThisPage(fd4, 4, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 4, 1);
error = PF_GetThisPage(fd1, 14, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 14, 1);
error = PF_GetThisPage(fd2, 3, &ptr, &pagebuf);
PF_UnfixPage(fd2, 3, 0);
error = PF_GetThisPage(fd0, 11, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 11, 0);
error = PF_GetThisPage(fd0, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 10, 0);
error = PF_GetThisPage(fd1, 3, &ptr, &pagebuf);
PF_UnfixPage(fd1, 3, 0);
error = PF_ReadSnapshot(fd3, sfd3, 1, &ptr, &pagebuf);
error = PF_GetThisPage(fd1, 8, &ptr, &pagebuf);
PF_UnfixPage(fd1, 8, 0);
error = PF_GetThisPage(fd4, 13, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 13, 0);
error = PF_GetThisPage(fd1, 0, &ptr, &pagebuf);
PF_UnfixPage(fd1, 0, 0);
error = PF_GetThisPage(fd2, 1, &ptr, &pagebuf);
PF_UnfixPage(fd2, 1, 0);
error = PF_GetThisPage(fd2, 11, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 11, 0);
error = PF_GetThisPage(fd3, 6, &ptr, &pagebuf);
PF_UnfixPage(fd3, 6, 0);
error = PF_GetThisPage(fd1, 12, &ptr, &pagebuf);
PF_UnfixPage(fd1, 12, 0);
error = PF_GetThisPage(fd0, 12, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 12, 1);
error = PF_GetThisPage(fd0, 5, &ptr, &pagebuf);
PF_UnfixPage(fd0, 5, 0);
error = PF_GetThisPage(fd4, 2, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 2, 0);
error = PF_ReadSnapshot(fd0, sfd0, 7, &ptr, &pagebuf);
error = PF_GetThisPage(fd3, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 10, 0);
error = PF_GetThisPage(fd2, 10, &ptr, &pagebuf);
PF_UnfixPage(fd2, 10, 0);
error = PF_GetThisPage(fd0, 3, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 3, 0);
error = PF_GetThisPage(fd2, 5, &ptr, &pagebuf);
PF_UnfixPage(fd2, 5, 0);
error = PF_ReadSnapshot(fd2, sfd2, 4, &ptr, &pagebuf);
error = PF_GetThisPage(fd4, 1, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 1, 0);
error = PF_GetThisPage(fd2, 9, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 9, 0);
error = PF_ReadSnapshot(fd3, sfd3, 13, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd1, 0, &ptr, &pagebuf);
PF_UnfixPage(fd1, 0, 0);
error = PF_GetThisPage(fd3, 8, &ptr, &pagebuf);
PF_UnfixPage(fd3, 8, 0);
error = PF_ReadSnapshot(fd2, sfd2, 13, &ptr, &pagebuf);
error = PF_GetThisPage(fd3, 0, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 0, 1);
error = PF_GetThisPage(fd3, 7, &ptr, &pagebuf);
PF_UnfixPage(fd3, 7, 0);
error = PF_GetThisPage(fd3, 2, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 2, 0);
error = PF_GetThisPage(fd3, 11, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 11, 1);
error = PF_ReadSnapshot(fd4, sfd4, 5, &ptr, &pagebuf);
error = PF_GetThisPage(fd0, 0, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 0, 0);
error = PF_GetThisPage(fd3, 9, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 9, 0);
error = PF_ReadSnapshot(fd3, sfd3, 0, &ptr, &pagebuf);
error = PF_GetThisPage(fd4, 11, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 11, 1);
error = PF_ReadSnapshot(fd2, sfd2, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd1, 9, &ptr, &pagebuf);
PF_UnfixPage(fd1, 9, 0);
error = PF_GetThisPage(fd2, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 10, 0);
error = PF_GetThisPage(fd3, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 10, 1);
error = PF_GetThisPage(fd3, 3, &ptr, &pagebuf);
PF_UnfixPage(fd3, 3, 0);
error = PF_GetThisPage(fd0, 4, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 4, 0);
error = PF_GetThisPage(fd4, 9, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 9, 0);
error = PF_GetThisPage(fd0, 1, &ptr, &pagebuf);
PF_UnfixPage(fd0, 1, 0);
error = PF_GetThisPage(fd0, 2, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 2, 0);
error = PF_GetThisPage(fd1, 14, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 14, 0);
error = PF_ReadSnapshot(fd3, sfd3, 3, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd4, 12, &ptr, &pagebuf);
PF_UnfixPage(fd4, 12, 0);
error = PF_GetThisPage(fd3, 1, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 1, 0);
error = PF_GetThisPage(fd1, 7, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 7, 1);
error = PF_GetThisPage(fd2, 7, &ptr, &pagebuf);
PF_UnfixPage(fd2, 7, 0);
error = PF_GetThisPage(fd1, 7, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 7, 0);
error = PF_GetThisPage(fd4, 13, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 13, 0);
error = PF_GetThisPage(fd2, 7, &ptr, &pagebuf);
PF_UnfixPage(fd2, 7, 0);
error = PF_GetThisPage(fd2, 7, &ptr, &pagebuf);
PF_UnfixPage(fd2, 7, 0);
error = PF_GetThisPage(fd0, 8, &ptr, &pagebuf);
PF_UnfixPage(fd0, 8, 0);
error = PF_ReadSnapshot(fd4, sfd4, 6, &ptr, &pagebuf);
error = PF_GetThisPage(fd1, 2, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 2, 0);
error = PF_ReadSnapshot(fd4, sfd4, 9, &ptr, &pagebuf);
error = PF_ReadSnapshot(fd1, sfd1, 2, &ptr, &pagebuf);
error = PF_GetThisPage(fd3, 0, &ptr, &pagebuf);
PF_UnfixPage(fd3, 0, 0);
error = PF_GetThisPage(fd1, 14, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 14, 1);
error = PF_ReadSnapshot(fd4, sfd4, 5, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd1, 5, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 5, 1);
error = PF_GetThisPage(fd1, 7, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 7, 0);
error = PF_ReadSnapshot(fd1, sfd1, 10, &ptr, &pagebuf);
error = PF_ReadSnapshot(fd4, sfd4, 12, &ptr, &pagebuf);
error = PF_GetThisPage(fd0, 13, &ptr, &pagebuf);
PF_UnfixPage(fd0, 13, 0);
error = PF_ReadSnapshot(fd2, sfd2, 8, &ptr, &pagebuf);
error = PF_GetThisPage(fd3, 14, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 14, 1);
error = PF_GetThisPage(fd4, 6, &ptr, &pagebuf);
PF_UnfixPage(fd4, 6, 0);
error = PF_ReadSnapshot(fd2, sfd2, 2, &ptr, &pagebuf);
error = PF_GetThisPage(fd1, 6, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 6, 0);
error = PF_GetThisPage(fd3, 13, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 13, 0);
error = PF_GetThisPage(fd4, 1, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 1, 1);
error = PF_GetThisPage(fd3, 1, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 1, 0);
error = PF_GetThisPage(fd4, 7, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 7, 0);
error = PF_GetThisPage(fd0, 5, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 5, 0);
error = PF_GetThisPage(fd4, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 10, 1);
error = PF_GetThisPage(fd2, 5, &ptr, &pagebuf);
PF_UnfixPage(fd2, 5, 0);
error = PF_GetThisPage(fd3, 11, &ptr, &pagebuf);
PF_UnfixPage(fd3, 11, 0);
error = PF_GetThisPage(fd3, 0, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 0, 1);
error = PF_ReadSnapshot(fd0, sfd0, 5, &ptr, &pagebuf);
error = PF_ReadSnapshot(fd0, sfd0, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd0, 9, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 9, 1);
error = PF_ReadSnapshot(fd1, sfd1, 2, &ptr, &pagebuf);
error = PF_GetThisPage(fd1, 8, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 8, 1);
error = PF_GetThisPage(fd2, 11, &ptr, &pagebuf);
PF_UnfixPage(fd2, 11, 0);
error = PF_ReadSnapshot(fd1, sfd1, 3, &ptr, &pagebuf);
error = PF_GetThisPage(fd0, 14, &ptr, &pagebuf);
PF_UnfixPage(fd0, 14, 0);
error = PF_GetThisPage(fd4, 8, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 8, 0);
error = PF_ReadSnapshot(fd2, sfd2, 10, &ptr, &pagebuf);
error = PF_GetThisPage(fd3, 6, &ptr, &pagebuf);
PF_UnfixPage(fd3, 6, 0);
error = PF_GetThisPage(fd3, 2, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 2, 1);
error = PF_GetThisPage(fd2, 12, &ptr, &pagebuf);
PF_UnfixPage(fd2, 12, 0);
error = PF_GetThisPage(fd4, 3, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 3, 1);
error = PF_ReadSnapshot(fd2, sfd2, 12, &ptr, &pagebuf);
error = PF_GetThisPage(fd2, 2, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 2, 1);
error = PF_ReadSnapshot(fd3, sfd3, 5, &ptr, &pagebuf);
error = PF_ReadSnapshot(fd2, sfd2, 2, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd1, 5, &ptr, &pagebuf);
PF_UnfixPage(fd1, 5, 0);
error = PF_GetThisPage(fd4, 2, &ptr, &pagebuf);
PF_UnfixPage(fd4, 2, 0);
error = PF_ReadSnapshot(fd2, sfd2, 4, &ptr, &pagebuf);
error = PF_GetThisPage(fd4, 9, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 9, 1);
error = PF_GetThisPage(fd4, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 10, 1);
error = PF_GetThisPage(fd1, 14, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 14, 1);
error = PF_ReadSnapshot(fd3, sfd3, 4, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd0, 6, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 6, 1);
error = PF_ReadSnapshot(fd0, sfd0, 7, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd1, 2, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 2, 1);
error = PF_GetThisPage(fd2, 10, &ptr, &pagebuf);
PF_UnfixPage(fd2, 10, 0);
error = PF_GetThisPage(fd2, 4, &ptr, &pagebuf);
PF_UnfixPage(fd2, 4, 0);
error = PF_GetThisPage(fd0, 7, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 7, 1);
error = PF_GetThisPage(fd2, 14, &ptr, &pagebuf);
PF_UnfixPage(fd2, 14, 0);
error = PF_GetThisPage(fd1, 0, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 0, 1);
error = PF_GetThisPage(fd3, 8, &ptr, &pagebuf);
PF_UnfixPage(fd3, 8, 0);
error = PF_GetThisPage(fd1, 12, &ptr, &pagebuf);
PF_UnfixPage(fd1, 12, 0);
error = PF_GetThisPage(fd0, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 10, 0);
error = PF_GetThisPage(fd2, 10, &ptr, &pagebuf);
PF_UnfixPage(fd2, 10, 0);
error = PF_ReadSnapshot(fd3, sfd3, 9, &ptr, &pagebuf);
error = PF_GetThisPage(fd0, 9, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 9, 1);
error = PF_GetThisPage(fd3, 1, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 1, 0);
error = PF_GetThisPage(fd4, 3, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 3, 1);
error = PF_GetThisPage(fd4, 5, &ptr, &pagebuf);
PF_UnfixPage(fd4, 5, 0);
error = PF_ReadSnapshot(fd2, sfd2, 7, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_ReadSnapshot(fd4, sfd4, 2, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd3, 14, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 14, 0);
error = PF_ReadSnapshot(fd3, sfd3, 14, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_ReadSnapshot(fd2, sfd2, 11, &ptr, &pagebuf);
error = PF_GetThisPage(fd1, 11, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 11, 0);
error = PF_GetThisPage(fd2, 3, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 3, 0);
error = PF_GetThisPage(fd2, 14, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 14, 1);
error = PF_GetThisPage(fd4, 5, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 5, 1);
error = PF_GetThisPage(fd4, 8, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 8, 1);
error = PF_GetThisPage(fd0, 0, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 0, 1);
error = PF_GetThisPage(fd3, 11, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 11, 0);
error = PF_GetThisPage(fd3, 1, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 1, 1);
error = PF_GetThisPage(fd3, 14, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 14, 0);
error = PF_ReadSnapshot(fd0, sfd0, 13, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd0, 4, &ptr, &pagebuf);
PF_UnfixPage(fd0, 4, 0);
error = PF_GetThisPage(fd0, 14, &ptr, &pagebuf);
PF_UnfixPage(fd0, 14, 0);
error = PF_ReadSnapshot(fd2, sfd2, 3, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd0, 5, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 5, 1);
error = PF_GetThisPage(fd1, 10, &ptr, &pagebuf);
PF_UnfixPage(fd1, 10, 0);
error = PF_GetThisPage(fd2, 4, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 4, 0);
error = PF_GetThisPage(fd4, 10, &ptr, &pagebuf);
PF_UnfixPage(fd4, 10, 0);
error = PF_GetThisPage(fd1, 0, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 0, 0);
error = PF_GetThisPage(fd4, 1, &ptr, &pagebuf);
PF_UnfixPage(fd4, 1, 0);
error = PF_GetThisPage(fd3, 13, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 13, 1);
error = PF_GetThisPage(fd4, 12, &ptr, &pagebuf);
PF_UnfixPage(fd4, 12, 0);
error = PF_GetThisPage(fd1, 5, &ptr, &pagebuf);
PF_UnfixPage(fd1, 5, 0);
error = PF_GetThisPage(fd1, 4, &ptr, &pagebuf);
PF_UnfixPage(fd1, 4, 0);
error = PF_ReadSnapshot(fd1, sfd1, 1, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd0, 4, &ptr, &pagebuf);
PF_UnfixPage(fd0, 4, 0);
error = PF_GetThisPage(fd4, 12, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 12, 0);
error = PF_GetThisPage(fd4, 12, &ptr, &pagebuf);
PF_UnfixPage(fd4, 12, 0);
error = PF_GetThisPage(fd4, 7, &ptr, &pagebuf);
PF_UnfixPage(fd4, 7, 0);
error = PF_GetThisPage(fd0, 14, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 14, 1);
error = PF_GetThisPage(fd1, 14, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 14, 1);
error = PF_ReadSnapshot(fd2, sfd2, 5, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_ReadSnapshot(fd4, sfd4, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd4, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 10, 1);
error = PF_GetThisPage(fd0, 14, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 14, 1);
error = PF_GetThisPage(fd1, 14, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 14, 0);
error = PF_GetThisPage(fd0, 11, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 11, 1);
error = PF_GetThisPage(fd3, 2, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 2, 1);
error = PF_GetThisPage(fd1, 5, &ptr, &pagebuf);
PF_UnfixPage(fd1, 5, 0);
error = PF_GetThisPage(fd3, 1, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 1, 1);
error = PF_GetThisPage(fd0, 9, &ptr, &pagebuf);
PF_UnfixPage(fd0, 9, 0);
error = PF_ReadSnapshot(fd4, sfd4, 12, &ptr, &pagebuf);
error = PF_GetThisPage(fd4, 13, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 13, 0);
error = PF_GetThisPage(fd2, 9, &ptr, &pagebuf);
PF_UnfixPage(fd2, 9, 0);
error = PF_GetThisPage(fd1, 6, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 6, 0);
error = PF_GetThisPage(fd0, 7, &ptr, &pagebuf);
PF_UnfixPage(fd0, 7, 0);
error = PF_GetThisPage(fd4, 12, &ptr, &pagebuf);
PF_UnfixPage(fd4, 12, 0);
error = PF_GetThisPage(fd4, 5, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 5, 1);
error = PF_ReadSnapshot(fd0, sfd0, 2, &ptr, &pagebuf);
error = PF_GetThisPage(fd2, 11, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 11, 0);
error = PF_GetThisPage(fd0, 14, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 14, 1);
error = PF_ReadSnapshot(fd0, sfd0, 0, &ptr, &pagebuf);
error = PF_ReadSnapshot(fd0, sfd0, 4, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd0, 6, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 6, 1);
error = PF_GetThisPage(fd4, 4, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 4, 1);
error = PF_GetThisPage(fd0, 9, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 9, 0);
error = PF_GetThisPage(fd3, 3, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 3, 1);
error = PF_ReadSnapshot(fd2, sfd2, 6, &ptr, &pagebuf);
error = PF_GetThisPage(fd2, 8, &ptr, &pagebuf);
PF_UnfixPage(fd2, 8, 0);
error = PF_ReadSnapshot(fd4, sfd4, 9, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd4, 8, &ptr, &pagebuf);
PF_UnfixPage(fd4, 8, 0);
error = PF_GetThisPage(fd2, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 10, 1);
error = PF_GetThisPage(fd0, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 10, 1);
error = PF_GetThisPage(fd4, 6, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 6, 0);
error = PF_GetThisPage(fd1, 4, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 4, 1);
error = PF_GetThisPage(fd0, 2, &ptr, &pagebuf);
PF_UnfixPage(fd0, 2, 0);
error = PF_GetThisPage(fd1, 7, &ptr, &pagebuf);
PF_UnfixPage(fd1, 7, 0);
error = PF_GetThisPage(fd4, 12, &ptr, &pagebuf);
PF_UnfixPage(fd4, 12, 0);
error = PF_GetThisPage(fd4, 10, &ptr, &pagebuf);
PF_UnfixPage(fd4, 10, 0);
error = PF_ReadSnapshot(fd4, sfd4, 3, &ptr, &pagebuf);
error = PF_GetThisPage(fd2, 0, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 0, 1);
error = PF_GetThisPage(fd4, 5, &ptr, &pagebuf);
PF_UnfixPage(fd4, 5, 0);
error = PF_GetThisPage(fd0, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 10, 1);
error = PF_GetThisPage(fd4, 3, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 3, 1);
error = PF_ReadSnapshot(fd0, sfd0, 4, &ptr, &pagebuf);
error = PF_GetThisPage(fd0, 8, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 8, 0);
error = PF_ReadSnapshot(fd3, sfd3, 4, &ptr, &pagebuf);
error = PF_GetThisPage(fd2, 6, &ptr, &pagebuf);
PF_UnfixPage(fd2, 6, 0);
error = PF_GetThisPage(fd4, 0, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 0, 0);
error = PF_GetThisPage(fd0, 8, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 8, 1);
error = PF_GetThisPage(fd4, 13, &ptr, &pagebuf);
PF_UnfixPage(fd4, 13, 0);
error = PF_ReadSnapshot(fd2, sfd2, 0, &ptr, &pagebuf);
error = PF_GetThisPage(fd3, 10, &ptr, &pagebuf);
PF_UnfixPage(fd3, 10, 0);
error = PF_GetThisPage(fd2, 11, &ptr, &pagebuf);
PF_UnfixPage(fd2, 11, 0);
error = PF_GetThisPage(fd2, 13, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 13, 0);
error = PF_GetThisPage(fd3, 7, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 7, 1);
error = PF_GetThisPage(fd0, 6, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 6, 1);
error = PF_GetThisPage(fd2, 1, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 1, 1);
error = PF_GetThisPage(fd2, 4, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 4, 0);
error = PF_GetThisPage(fd0, 12, &ptr, &pagebuf);
PF_UnfixPage(fd0, 12, 0);
error = PF_GetThisPage(fd0, 2, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 2, 1);
error = PF_ReadSnapshot(fd0, sfd0, 2, &ptr, &pagebuf);
error = PF_GetThisPage(fd3, 1, &ptr, &pagebuf);
PF_UnfixPage(fd3, 1, 0);
error = PF_GetThisPage(fd3, 3, &ptr, &pagebuf);
PF_UnfixPage(fd3, 3, 0);
error = PF_GetThisPage(fd1, 1, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 1, 0);
error = PF_GetThisPage(fd1, 4, &ptr, &pagebuf);
PF_UnfixPage(fd1, 4, 0);
error = PF_GetThisPage(fd1, 0, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 0, 0);
error = PF_GetThisPage(fd1, 13, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 13, 1);
error = PF_ReadSnapshot(fd3, sfd3, 2, &ptr, &pagebuf);
error = PF_ReadSnapshot(fd2, sfd2, 10, &ptr, &pagebuf);
error = PF_GetThisPage(fd2, 11, &ptr, &pagebuf);
PF_UnfixPage(fd2, 11, 0);
error = PF_GetThisPage(fd1, 7, &ptr, &pagebuf);
PF_UnfixPage(fd1, 7, 0);
error = PF_GetThisPage(fd2, 7, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 7, 1);
error = PF_GetThisPage(fd2, 2, &ptr, &pagebuf);
PF_UnfixPage(fd2, 2, 0);
error = PF_GetThisPage(fd4, 4, &ptr, &pagebuf);
PF_UnfixPage(fd4, 4, 0);
error = PF_GetThisPage(fd3, 1, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 1, 0);
error = PF_GetThisPage(fd2, 6, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 6, 1);
error = PF_GetThisPage(fd2, 7, &ptr, &pagebuf);
PF_UnfixPage(fd2, 7, 0);
error = PF_ReadSnapshot(fd2, sfd2, 14, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_ReadSnapshot(fd1, sfd1, 12, &ptr, &pagebuf);
error = PF_GetThisPage(fd0, 2, &ptr, &pagebuf);
PF_UnfixPage(fd0, 2, 0);
error = PF_GetThisPage(fd4, 4, &ptr, &pagebuf);
PF_UnfixPage(fd4, 4, 0);
error = PF_GetThisPage(fd4, 13, &ptr, &pagebuf);
PF_UnfixPage(fd4, 13, 0);
error = PF_ReadSnapshot(fd2, sfd2, 4, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd3, 4, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 4, 1);
error = PF_GetThisPage(fd1, 12, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 12, 0);
error = PF_GetThisPage(fd3, 11, &ptr, &pagebuf);
PF_UnfixPage(fd3, 11, 0);
error = PF_GetThisPage(fd4, 0, &ptr, &pagebuf);
PF_UnfixPage(fd4, 0, 0);
error = PF_GetThisPage(fd4, 11, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 11, 1);
error = PF_GetThisPage(fd0, 4, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 4, 1);
error = PF_ReadSnapshot(fd4, sfd4, 6, &ptr, &pagebuf);
error = PF_GetThisPage(fd4, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 10, 0);
error = PF_GetThisPage(fd3, 7, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 7, 1);
error = PF_GetThisPage(fd2, 11, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 11, 1);
error = PF_GetThisPage(fd1, 11, &ptr, &pagebuf);
PF_UnfixPage(fd1, 11, 0);
error = PF_GetThisPage(fd2, 7, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 7, 0);
error = PF_GetThisPage(fd3, 14, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 14, 1);
error = PF_GetThisPage(fd3, 5, &ptr, &pagebuf);
PF_UnfixPage(fd3, 5, 0);
error = PF_GetThisPage(fd0, 2, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 2, 0);
error = PF_GetThisPage(fd0, 2, &ptr, &pagebuf);
PF_UnfixPage(fd0, 2, 0);
error = PF_GetThisPage(fd4, 7, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 7, 0);
error = PF_GetThisPage(fd2, 9, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 9, 1);
error = PF_GetThisPage(fd1, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 10, 1);
error = PF_GetThisPage(fd0, 1, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 1, 1);
error = PF_GetThisPage(fd3, 10, &ptr, &pagebuf);
PF_UnfixPage(fd3, 10, 0);
error = PF_GetThisPage(fd0, 14, &ptr, &pagebuf);
PF_UnfixPage(fd0, 14, 0);
error = PF_ReadSnapshot(fd2, sfd2, 13, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd1, 13, &ptr, &pagebuf);
PF_UnfixPage(fd1, 13, 0);
error = PF_GetThisPage(fd0, 14, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 14, 1);
error = PF_GetThisPage(fd2, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 10, 0);
error = PF_GetThisPage(fd2, 11, &ptr, &pagebuf);
PF_UnfixPage(fd2, 11, 0);
error = PF_GetThisPage(fd1, 0, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 0, 1);
error = PF_ReadSnapshot(fd0, sfd0, 5, &ptr, &pagebuf);
error = PF_GetThisPage(fd0, 3, &ptr, &pagebuf);
PF_UnfixPage(fd0, 3, 0);
error = PF_GetThisPage(fd2, 11, &ptr, &pagebuf);
PF_UnfixPage(fd2, 11, 0);
error = PF_ReadSnapshot(fd1, sfd1, 12, &ptr, &pagebuf);
error = PF_GetThisPage(fd1, 6, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 6, 0);
error = PF_GetThisPage(fd1, 6, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 6, 1);
error = PF_GetThisPage(fd3, 11, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 11, 1);
error = PF_GetThisPage(fd0, 0, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 0, 1);
error = PF_ReadSnapshot(fd4, sfd4, 14, &ptr, &pagebuf);
error = PF_GetThisPage(fd0, 12, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 12, 0);
error = PF_GetThisPage(fd1, 7, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 7, 1);
error = PF_ReadSnapshot(fd4, sfd4, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd3, 13, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 13, 0);
error = PF_GetThisPage(fd2, 11, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 11, 0);
error = PF_GetThisPage(fd0, 3, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 3, 0);
error = PF_ReadSnapshot(fd0, sfd0, 13, &ptr, &pagebuf);
error = PF_ReadSnapshot(fd4, sfd4, 13, &ptr, &pagebuf);
error = PF_GetThisPage(fd1, 7, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 7, 1);
error = PF_GetThisPage(fd1, 4, &ptr, &pagebuf);
PF_UnfixPage(fd1, 4, 0);
error = PF_GetThisPage(fd3, 8, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 8, 0);
error = PF_GetThisPage(fd1, 5, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 5, 1);
error = PF_GetThisPage(fd2, 1, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 1, 0);
error = PF_GetThisPage(fd1, 2, &ptr, &pagebuf);
PF_UnfixPage(fd1, 2, 0);
error = PF_GetThisPage(fd2, 5, &ptr, &pagebuf);
PF_UnfixPage(fd2, 5, 0);
error = PF_GetThisPage(fd4, 13, &ptr, &pagebuf);
PF_UnfixPage(fd4, 13, 0);
error = PF_ReadSnapshot(fd3, sfd3, 5, &ptr, &pagebuf);
error = PF_GetThisPage(fd3, 13, &ptr, &pagebuf);
PF_UnfixPage(fd3, 13, 0);
error = PF_GetThisPage(fd2, 3, &ptr, &pagebuf);
PF_UnfixPage(fd2, 3, 0);
error = PF_GetThisPage(fd2, 8, &ptr, &pagebuf);
PF_UnfixPage(fd2, 8, 0);
error = PF_GetThisPage(fd1, 3, &ptr, &pagebuf);
PF_UnfixPage(fd1, 3, 0);
error = PF_GetThisPage(fd3, 9, &ptr, &pagebuf);
PF_UnfixPage(fd3, 9, 0);
error = PF_GetThisPage(fd1, 3, &ptr, &pagebuf);
PF_UnfixPage(fd1, 3, 0);
error = PF_GetThisPage(fd4, 1, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 1, 1);
error = PF_GetThisPage(fd0, 7, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 7, 1);
error = PF_GetThisPage(fd0, 6, &ptr, &pagebuf);
PF_UnfixPage(fd0, 6, 0);
error = PF_ReadSnapshot(fd2, sfd2, 6, &ptr, &pagebuf);
error = PF_GetThisPage(fd3, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 10, 1);
error = PF_ReadSnapshot(fd0, sfd0, 0, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd4, 5, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 5, 1);
error = PF_GetThisPage(fd2, 5, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 5, 1);
error = PF_ReadSnapshot(fd1, sfd1, 8, &ptr, &pagebuf);
error = PF_GetThisPage(fd1, 2, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 2, 0);
error = PF_ReadSnapshot(fd1, sfd1, 11, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd0, 9, &ptr, &pagebuf);
PF_UnfixPage(fd0, 9, 0);
error = PF_GetThisPage(fd0, 6, &ptr, &pagebuf);
PF_UnfixPage(fd0, 6, 0);
error = PF_GetThisPage(fd0, 1, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 1, 0);
error = PF_GetThisPage(fd1, 0, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 0, 1);
error = PF_GetThisPage(fd2, 14, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 14, 0);
error = PF_GetThisPage(fd2, 2, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 2, 1);
error = PF_GetThisPage(fd3, 0, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 0, 1);
error = PF_GetThisPage(fd4, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 10, 0);
error = PF_GetThisPage(fd4, 1, &ptr, &pagebuf);
PF_UnfixPage(fd4, 1, 0);
error = PF_GetThisPage(fd4, 11, &ptr, &pagebuf);
PF_UnfixPage(fd4, 11, 0);
error = PF_GetThisPage(fd0, 5, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 5, 1);
error = PF_GetThisPage(fd4, 13, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 13, 1);
error = PF_GetThisPage(fd4, 12, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 12, 0);
error = PF_ReadSnapshot(fd2, sfd2, 12, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd0, 11, &ptr, &pagebuf);
PF_UnfixPage(fd0, 11, 0);
error = PF_GetThisPage(fd2, 0, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 0, 0);
error = PF_ReadSnapshot(fd0, sfd0, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
error = PF_GetThisPage(fd2, 3, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 3, 1);
error = PF_GetThisPage(fd4, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 10, 1);
error = PF_GetThisPage(fd2, 12, &ptr, &pagebuf);
PF_UnfixPage(fd2, 12, 0);
error = PF_GetThisPage(fd3, 6, &ptr, &pagebuf);
PF_UnfixPage(fd3, 6, 0);
error = PF_GetThisPage(fd1, 14, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 14, 1);
error = PF_GetThisPage(fd3, 12, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 12, 1);
error = PF_GetThisPage(fd0, 6, &ptr, &pagebuf);
PF_UnfixPage(fd0, 6, 0);
error = PF_GetThisPage(fd4, 5, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 5, 1);
error = PF_GetThisPage(fd4, 7, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd4, 7, 0);
error = PF_GetThisPage(fd2, 11, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd2, 11, 0);
error = PF_GetThisPage(fd3, 10, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd3, 10, 1);
error = PF_GetThisPage(fd1, 7, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 7, 0);
error = PF_GetThisPage(fd2, 13, &ptr, &pagebuf);
PF_UnfixPage(fd2, 13, 0);
error = PF_GetThisPage(fd2, 10, &ptr, &pagebuf);
PF_UnfixPage(fd2, 10, 0);
error = PF_GetThisPage(fd1, 1, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd1, 1, 0);
error = PF_ReadSnapshot(fd4, sfd4, 2, &ptr, &pagebuf);
error = PF_GetThisPage(fd0, 0, &ptr, &pagebuf);
if(error == PFE_DISK) {
    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)
        stepTime();
}
PF_UnfixPage(fd0, 0, 0);
PF_CloseFile(fd0);
PF_CloseFile(sfd0);
PF_CloseFile(fd1);
PF_CloseFile(sfd1);
PF_CloseFile(fd2);
PF_CloseFile(sfd2);
PF_CloseFile(fd3);
PF_CloseFile(sfd3);
PF_CloseFile(fd4);
PF_CloseFile(sfd4);
while(RAID_buf_count())
    stepTime();
printf("%d", cost());
return 0;
}
