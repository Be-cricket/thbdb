/*
 * This file has the errorno definitions for ThBDB.
 * Written by M.Yasaka on 7/11/2018
 *
 * thbdb_errno.h
 */
#ifndef THBDB_ERRNO_H
#define THBDB_ERRNO_H


#define THBDB_NORMAL         0          /* ThBDB state is normal */
#define THBDB_DB_OPEN_ERROR  1          /* A BDB contained in the ThBDB cannnot be opened. */
#define THBDB_DB_NOT_OPENED_ERROR  2    /* A BDB contained in the ThBDB haven't been opened yet. */
#define THBDB_DB_KEYEXIST_ERROR  3      /* The specified key is already existing on the bdb.*/
#define THBDB_DB_NOTFOUND_ERROR  4      /* The specified key is not found from the ThBDB.*/


#endif /* THBDB_ERRNO_H */
