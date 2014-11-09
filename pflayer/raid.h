typedef struct RAID_buf_ele {
    int fd;
    int pagenum;
    int disk;
    struct RAID_buf_ele * prev;
    struct RAID_buf_ele * next;
} RAID_buf_ele;

void insertRAIDbuf(int fd, int pagenum);
void stepTime();
int cost();
void initRAID();
