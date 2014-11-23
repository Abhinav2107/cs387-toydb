#ifndef __PF_H__
#define __PF_H__
#include "pftypes.h"

/* pf.h: externs and error codes for Paged File Interface*/
#ifndef TRUE
#define TRUE 1		
#endif
#ifndef FALSE
#define FALSE 0
#endif

/************** Error Codes *********************************/
#define PFE_OK		0	/* OK */
#define PFE_NOMEM	-1	/* no memory */
#define PFE_NOBUF	-2	/* no buffer space */
#define PFE_PAGEFIXED 	-3	/* page already fixed in buffer */
#define PFE_PAGENOTINBUF -4	/* page to be unfixed is not in the buffer */
#define PFE_UNIX	-5	/* unix error */
#define PFE_INCOMPLETEREAD -6	/* incomplete read of page from file */
#define PFE_INCOMPLETEWRITE -7	/* incomplete write of page to file */
#define PFE_HDRREAD	-8	/* incomplete read of header from file */
#define PFE_HDRWRITE	-9	/* incomplte write of header to file */
#define PFE_INVALIDPAGE -10	/* invalid page number */
#define PFE_FILEOPEN	-11	/* file already open */
#define	PFE_FTABFULL	-12	/* file table is full */
#define PFE_FD		-13	/* invalid file descriptor */
#define PFE_EOF		-14	/* end of file */
#define PFE_PAGEFREE	-15	/* page already free */
#define PFE_PAGEUNFIXED	-16	/* page already unfixed */

/* Internal error: please report to the TA */
#define PFE_PAGEINBUF	-17	/* new page to be allocated already in buffer */
#define PFE_HASHNOTFOUND -18	/* hash table entry not found */
#define PFE_HASHPAGEEXIST -19	/* page already exist in hash table */

/* RAID Codes */
#define PFE_DISK -20 /* have to fetch page from disk */
#define PFE_INVALIDFETCH -21
#define PFE_FETCHED -22
#define PFE_PENDING -23


/* page size */
#define PF_PAGE_SIZE	4096

/* externs from the PF layer */
extern int PFerrno;		/* error number of last error */
extern void PF_Init();
extern void PF_PrintError();

PFRAID_buf_ele* insertPFRAID_buf(int fd, int pagenum);

int fetchPFRAID_buf(PFRAID_buf_ele* b);

void donePFRAID_buf(PFRAID_buf_ele* b);

int PF_CreateFile(char *fname);

int PF_DestroyFile(char *fname);

int PF_OpenFile(char *fname);

int PF_CloseFile(int fd);

int PF_GetFirstPage(int fd, int *pagenum, char **pagebuf);

int PF_GetThisPage(int fd, int pagenum, PFRAID_buf_ele ** ptr, char **pagebuf);

int PF_AllocPage(int fd, int *pagenum,char **pagebuf);

int PF_DisposePage(int fd, int pagenum);

int PF_UnfixPage(int fd, int pagenum, int dirty);

void PF_PrintError(char *s);

int PF_TakeSnapshot(char *fname);
    
int PF_ReadSnapshot(int fd, int snapshot_fd, int pagenum, PFRAID_buf_ele ** ptr, char **pagebuf);

void PF_SaveSnapshots();

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

void insertRAIDbuf(int fd, int pagenum, int type, PFRAID_buf_ele * ptr);
void stepTime();
int cost();
void resetCost();
void initRAID();
void printRAIDbuf();
int RAID_buf_count();

#endif
