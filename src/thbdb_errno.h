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
#define THBDB_DB_COMPACT_ERROR  5       /* ThBDB compact state is not normal */
#define THBDB_DB_CURSOR_OPEN_ERROR  6   /* A BDB contained in the ThBDB cannnot be opened cursor. */
#define THBDB_DB_CURSOR_ALREADY_OPENED_ERROR  7   /* A BDB contained in the ThBDB cannnot be opened cursor. */
#define THBDB_DB_CURSOR_CLOSE_ERROR  8  /* A BDB contained in the ThBDB happend error to close cursor. */
#define THBDB_DB_CURSOR_NOT_OPENED_ERROR  9  /* A BDB contained in the ThBDB happend error to close cursor. */
#define THBDB_DB_GET_KEYS_ERROR  10      /* A BDB contained in the ThBDB happend error to get keys by position. */


#endif /* THBDB_ERRNO_H */
