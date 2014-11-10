toydb
=====

###Follow the original documentation except:

* Include both raid.h and pf.h in the main program.
* Only use PF\_GetThisPage to access pages. This function will return a positive integer identifier if the page is being fetched from disk, otherwise an error code (or PFE\_OK).
* Use fetchPFRAID\_buf(int identifier) to check the status of the Page Access. This method can return PFE\_INVALIDFETCH if it is an invalid identifier, PFE\_FETCHED if the page has been fetched and PFE\_PENDING if the page is still being fetched.
* Call stepTime() to update the page fetch status.
* Call cost() to get the current cost.
* Call resetCost() to set the current cost to 0.
* Call PF\_TakeSnapshot(char \*\* files) to take a snpashot of the file names provded in the argument. Only one snapshot can be taken.
* To access snapshot of a file open both the <filename> and snapshot\_<filename>.
* Call PF\_GetThisPage on the snapshot. The page will be automatically unfixed and you need not call PF\_UnfixPage.
