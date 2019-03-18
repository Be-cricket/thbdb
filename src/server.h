/*
 * server.h
 * Define functions and fixed values for socket server(server.c)
 *
 * Written by Be-cricket on 3/18/2019
 */
#ifndef SERVER_H
#define SERVER_H

#define DEFAULT_LISTENING_PORT 9090 /* Default listening port. */



int listening_port = DEFAULT_LISTENING_PORT; /* ThBDB server socket port */

int proc_args( int argc, char* const argv[] ); /* Processing arguments */

void print_usage( char* const program_name ); /* Explain how to use ThBDB */

#endif /* SERVER_H */
