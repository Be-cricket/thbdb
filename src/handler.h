/*
 * handler.h
 * Handling the basic operation for the bdb.
 *
 * Written by Be-cricket on 6/17/2018
 */
#ifndef HANDLER_H
#define HANDLER_H

#include <thrift/c_glib/processor/thrift_dispatch_processor.h>
//#include "gen-cglib/thbdb_thbdb_types.h"

/* for glib gerror */
GQuark
g_thbdb_error_quark (void);

/** for glib error proc */
#define G_THBDB_ERROR g_thbdb_error_quark() 


/* --------------------------------------------------------------------- */
/*         Following: Values returned by handler methods.                */
/* --------------------------------------------------------------------- */
#define THBDB_STATUS_DB_RUNNING 1
#define THBDB_STATUS_DB_NOT_OPEND  2    


/* --------------------------------------------------------------------- */
/*         Following: The declareration for GLib                         */
/* --------------------------------------------------------------------- */
G_BEGIN_DECLS

/* In the C (GLib) implementation of Thrift, the actual work done by a
   server---that is, the code that runs when a client invokes a
   service method---is defined in a separate "handler" class that
   implements the service interface. Here we define the
   ThbdbBasicImplHandler class

   If you're new to GObject, try not to be intimidated by the quantity
   of code here---much of it is boilerplate and can mostly be
   copied-and-pasted from existing work. For more information refer to
   the GObject Reference Manual, available online at
   https://developer.gnome.org/gobject/. */

#define TYPE_THBDB_BASICIMPL_HANDLER \
  (thbdb_basicimpl_handler_get_type ())

#define THBDB_BASICIMPL_HANDLER(obj)                                \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj),                                   \
                               TYPE_THBDB_BASICIMPL_HANDLER,        \
                               ThbdbBasicimplHandler))
#define THBDB_BASICIMPL_HANDLER_CLASS(c)                    \
  (G_TYPE_CHECK_CLASS_CAST ((c),                                \
                            TYPE_THBDB_BASICIMPL_HANDLER,   \
                            ThbdbBasicimplHandlerClass))
#define IS_THBDB_BASICIMPL_HANDLER(obj)                             \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj),                                   \
                               TYPE_THBDB_BASICIMPL_HANDLER))
#define IS_THBDB_BASICIMPL_HANDLER_CLASS(c)                 \
  (G_TYPE_CHECK_CLASS_TYPE ((c),                                \
                            TYPE_THBDB_BASICIMPL_HANDLER))
#define THBDB_BASICIMPL_HANDLER_GET_CLASS(obj)              \
  (G_TYPE_INSTANCE_GET_CLASS ((obj),                            \
                              TYPE_THBDB_BASICIMPL_HANDLER, \
                              ThbdbBasicimplHandlerClass))

struct _ThbdbBasicimplHandler {
  thbdbBasicHandler parent_instance;

  /* private */
  GHashTable *log;
};
typedef struct _ThbdbBasicimplHandler ThbdbBasicimplHandler;

struct _ThbdbBasicimplHandlerClass {
  thbdbBasicHandlerClass parent_class;
};
typedef struct _ThbdbBasicimplHandlerClass ThbdbBasicimplHandlerClass;

GType thbdb_basicimpl_handler_get_type (void);

G_END_DECLS


#endif /* HANDLER_H */
