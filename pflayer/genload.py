import sys
import random

if len(sys.argv) == 1:
    sys.exit(1)

print "#include \"pf.h\""
print "#include <stdio.h>"
print "#include <string.h>"
print "int main() {"
print "PF_Init();"

n = 5
files = ["abc", "def", "ghi", "jkl", "mno"]

if sys.argv[1] == "create":
    
    print "int fd, pagenum;"
    print "char* pagebuf;"
    print "PFRAID_buf_ele * ptr;"

    for f in files:
        print "PF_CreateFile(\""+f+"\");"
        p = 15
        print "fd = PF_OpenFile(\""+f+"\");"
        for i in xrange(p):
            print "PF_AllocPage(fd, &pagenum, &pagebuf);"
            print "memset(pagebuf, 'a', PF_PAGE_SIZE);"
            print "PF_UnfixPage(fd, pagenum, 1);"
        print "PF_CloseFile(fd);"

    for i in xrange(100):
        print "stepTime();"

    for f in files:
        print "PF_TakeSnapshot(\""+f+"\");"
 
    for i in xrange(10):
        print "stepTime();"
elif sys.argv[1] == "run":
    p_read = 0.7
    p_snapshot = 0.3
    p_immediate = 0.8
    print "PF_SaveSnapshots();"
    for i in xrange(n):
        print "int fd"+str(i)+";"
        print "int sfd"+str(i)+";"
    print "char* pagebuf;"
    print "PFRAID_buf_ele * ptr;"
    print "int error;"
    for i in xrange(n):
        print "fd"+str(i)+" = PF_OpenFile(\""+files[i]+"\");"
        print "sfd"+str(i)+" = PF_OpenFile(\"snapshot_"+files[i]+"\");"        
    w = 500
    for i in xrange(w):
        r = random.random()
        fd = random.randint(0, n-1)
        page = random.randint(0, 14);
        if r > p_read:
            print "error = PF_GetThisPage(fd"+str(fd)+", "+str(page)+", &ptr, &pagebuf);"
            print "if(error == PFE_DISK) {"
            print "    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)"
            print "        stepTime();"
            print "}"
            print "PF_UnfixPage(fd"+str(fd)+", "+str(page)+", 1);"
        else:
            r = random.random()
            if r > p_snapshot:
                print "error = PF_GetThisPage(fd"+str(fd)+", "+str(page)+", &ptr, &pagebuf);"
                r = random.random()
                if r < p_immediate:
                    print "if(error == PFE_DISK) {"
                    print "    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)"
                    print "        stepTime();"
                    print "}"
                print "PF_UnfixPage(fd"+str(fd)+", "+str(page)+", 0);"  
                    
            else:
                print "error = PF_ReadSnapshot(fd"+str(fd)+", sfd"+str(fd)+", "+str(page)+", &ptr, &pagebuf);"
                r = random.random()
                if r < p_immediate:
                    print "if(error == PFE_DISK) {"
                    print "    while(fetchPFRAID_buf(ptr) != PFE_FETCHED)"
                    print "        stepTime();"
                    print "}"
 
    for i in xrange(n):
        print "PF_CloseFile(fd"+str(i)+");"
        print "PF_CloseFile(sfd"+str(i)+");"

    print "while(RAID_buf_count())"
    print "    stepTime();"
    print "printf(\"%d\", cost());"
print "return 0;"
print "}"
