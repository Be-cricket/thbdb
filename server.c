/*
 * This file is the thbdb's main program.
 * 
 * Written by M.Yasaka on 6/17/2018
 */

#include <glib-object.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>

#include <thrift/c_glib/thrift.h>
#include <thrift/c_glib/protocol/thrift_binary_protocol_factory.h>
#include <thrift/c_glib/protocol/thrift_protocol_factory.h>
#include <thrift/c_glib/server/thrift_server.h>
#include <thrift/c_glib/server/thrift_simple_server.h>
#include <thrift/c_glib/transport/thrift_buffered_transport_factory.h>
#include <thrift/c_glib/transport/thrift_server_socket.h>
#include <thrift/c_glib/transport/thrift_server_transport.h>

#include "gen-c_glib/thbdb_basic.h"
#include "gen-c_glib/thbdb_thbdb_types.h"
#include "handler.h"

#if 0
G_BEGIN_DECLS

/* In the C (GLib) implementation of Thrift, the actual work done by a
   server---that is, the code that runs when a client invokes a
   service method---is defined in a separate "handler" class that
   implements the service interface. Here we define the
   TutorialCalculatorHandler class, which implements the CalculatorIf
   interface and provides the behavior expected by tutorial clients.
   (Typically this code would be placed in its own module but for
   clarity this tutorial is presented entirely in a single file.)

   For each service the Thrift compiler generates an abstract base
   class from which handler implementations should inherit. In our
   case TutorialCalculatorHandler inherits from CalculatorHandler,
   defined in gen-c_glib/calculator.h.

   If you're new to GObject, try not to be intimidated by the quantity
   of code here---much of it is boilerplate and can mostly be
   copied-and-pasted from existing work. For more information refer to
   the GObject Reference Manual, available online at
   https://developer.gnome.org/gobject/. */

#define TYPE_MYSAMPLE_HELLO_HANDLER \
  (mysample_hello_handler_get_type ())

#define MYSAMPLE_HELLO_HANDLER(obj)                                \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj),                                   \
                               TYPE_MYSAMPLE_HELLO_HANDLER,        \
                               MysampleHelloHandler))
#define TUTORIAL_CALCULATOR_HANDLER_CLASS(c)                    \
  (G_TYPE_CHECK_CLASS_CAST ((c),                                \
                            TYPE_MYSAMPLE_HELLO_HANDLER,   \
                            MysampleHelloHandlerClass))
#define IS_MYSAMPLE_HELLO_HANDLER(obj)                             \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj),                                   \
                               TYPE_MYSAMPLE_HELLO_HANDLER))
#define IS_MYSAMPLE_HELLO_HANDLER_CLASS(c)                 \
  (G_TYPE_CHECK_CLASS_TYPE ((c),                                \
                            TYPE_MYSAMPLE_HELLO_HANDLER))
#define MYSAMPLE_HELLO_HANDLER_GET_CLASS(obj)              \
  (G_TYPE_INSTANCE_GET_CLASS ((obj),                            \
                              TYPE_MYSAMPLE_HELLO_HANDLER, \
                              MysampleHelloHandlerClass))

struct _MysampleHelloHandler {
  sampleHelloHandler parent_instance;

  /* private */
  GHashTable *log;
};
typedef struct _MysampleHelloHandler MysampleHelloHandler;

struct _MysampleHelloHandlerClass {
  sampleHelloHandlerClass parent_class;
};
typedef struct _MysampleHelloHandlerClass MysampleHelloHandlerClass;

GType mysample_hello_handler_get_type (void);

G_END_DECLS

/* ---------------------------------------------------------------- */

/* ---------------------------------------------------------------- */

/* The implementation of SampleHandlerHandler follows. */

G_DEFINE_TYPE (MysampleHelloHandler,
               mysample_hello_handler,
               SAMPLE_TYPE_HELLO_HANDLER)

/* Each of a handler's methods accepts at least two parameters: A
   pointer to the service-interface implementation (the handler object
   itself) and a handle to a GError structure to receive information
   about any error that occurs.

   On success, a handler method returns TRUE. A return value of FALSE
   indicates an error occurred and the error parameter has been
   set. (Methods should not return FALSE without first setting the
   error parameter.) */
static gboolean
  
mysample_hello_handler_hello(sampleHelloIf * iface, gchar ** _return, const gchar * arg, GError ** error)
{
  THRIFT_UNUSED_VAR (iface);
  THRIFT_UNUSED_VAR (error);

  //@@@

  puts (" ^^ hello() ^^");

  return TRUE;
}





/* TutorialCalculatorHandler's instance finalizer (destructor) */
static void
mysample_hello_handler_finalize (GObject *object)
{
  MysampleHelloHandler *self =
    MYSAMPLE_HELLO_HANDLER (object);

  /* Free our calculation-log hash table */
  g_hash_table_unref (self->log);
  self->log = NULL;

  /* Chain up to the parent class */
  G_OBJECT_CLASS (mysample_hello_handler_parent_class)->
    finalize (object);
}

/* MysampleHelloHandler's instance initializer (constructor) */
static void
mysample_hello_handler_init (MysampleHelloHandler *self)
{
  //@@@
  g_printf( "mysample_hello_handler_init was called ¥n " );
  /* Create our calculation-log hash table */
  self->log = g_hash_table_new_full (g_int_hash,
                                     g_int_equal,
                                     g_free,
                                     g_object_unref);
}

/* TutorialCalculatorHandler's class initializer */
static void
mysample_hello_handler_class_init (MysampleHelloHandlerClass *klass)
{
  //@@@
  printf( "class init ¥n " );
  
  GObjectClass *gobject_class = G_OBJECT_CLASS (klass);
  //SharedServiceHandlerClass *shared_service_handler_class =
  //SHARED_SERVICE_HANDLER_CLASS (klass);
  sampleHelloHandlerClass *sample_hello_handler_class =
    SAMPLE_HELLO_HANDLER_CLASS (klass);

  /* Register our destructor */
  gobject_class->finalize = mysample_hello_handler_finalize;

  /* Register our implementations of CalculatorHandler's methods */
  sample_hello_handler_class->hello =
    mysample_hello_handler_hello;

  /* Register our implementation of SharedServiceHandler's method */
  //shared_service_handler_class->get_struct =
  //tutorial_calculator_handler_get_struct;
}


/* That ends the implementation of ThbdbBasicimplHandler.
   Everything below is fairly generic code that sets up a minimal
   Thrift server for Thbdb clients. */


/* ---------------------------------------------------------------- */

#endif


/* ---------------------------------------------------------------- */


/* Our server object, declared globally so it is accessible within the
   SIGINT signal handler */
ThriftServer *server = NULL;

/* A flag that indicates whether the server was interrupted with
   SIGINT (i.e. Ctrl-C) so we can tell whether its termination was
   abnormal */
gboolean sigint_received = FALSE;

/* Handle SIGINT ("Ctrl-C") signals by gracefully stopping the
   server */
static void
sigint_handler (int signal_number)
{
  THRIFT_UNUSED_VAR (signal_number);

  /* Take note we were called */
  sigint_received = TRUE;

  /* Shut down the server gracefully */
  if (server != NULL)
    thrift_server_stop (server);
}


int main ( void ){

  ThbdbBasicimplHandler *handler;
  thbdbBasicProcessor *processor;
    
  ThriftServerTransport *server_transport;
  ThriftTransportFactory *transport_factory;
  ThriftProtocolFactory *protocol_factory;

  struct sigaction sigint_action;

  GError *error = NULL;
  int exit_status = 0;

#if (!GLIB_CHECK_VERSION (2, 36, 0))
  g_type_init ();
#endif

 //@@@
 puts( " before handler  " );
  /* Create an instance of our handler, which provides the service's
     methods' implementation */

 //@@@
 handler = 
     g_object_new (TYPE_THBDB_BASICIMPL_HANDLER, 
                   NULL); 
 /* handler =  */
 /*     g_object_new (THBDB_TYPE_BASIC_HANDLER,  */
 /*                   NULL);  */

  
  /* Create an instance of the service's processor, automatically
     generated by the Thrift compiler, which parses incoming messages
     and dispatches them to the appropriate method in the handler */
  processor =
    g_object_new (THBDB_TYPE_BASIC_PROCESSOR,
                  "handler", handler,
                  NULL);

  /* Create our server socket, which binds to the specified port and
     listens for client connections */
  server_transport =
    g_object_new (THRIFT_TYPE_SERVER_SOCKET,
                  "port", 9090,
                  NULL);

  /* Create our transport factory, used by the server to wrap "raw"
     incoming connections from the client (in this case with a
     ThriftBufferedTransport to improve performance) */
  transport_factory =
    g_object_new (THRIFT_TYPE_BUFFERED_TRANSPORT_FACTORY,
                  NULL);

  /* Create our protocol factory, which determines which wire protocol
     the server will use (in this case, Thrift's binary protocol) */
  protocol_factory =
    g_object_new (THRIFT_TYPE_BINARY_PROTOCOL_FACTORY,
                  NULL);

  /* Create the server itself */
  server =
    g_object_new (THRIFT_TYPE_SIMPLE_SERVER,
                  "processor",                processor,
                  "server_transport",         server_transport,
                  "input_transport_factory",  transport_factory,
                  "output_transport_factory", transport_factory,
                  "input_protocol_factory",   protocol_factory,
                  "output_protocol_factory",  protocol_factory,
                  NULL);

  /* Install our SIGINT handler, which handles Ctrl-C being pressed by
     stopping the server gracefully (not strictly necessary, but a
     nice touch) */
  memset (&sigint_action, 0, sizeof (sigint_action));
  sigint_action.sa_handler = sigint_handler;
  sigint_action.sa_flags = SA_RESETHAND;
  sigaction (SIGINT, &sigint_action, NULL);

  /* Start the server, which will run until its stop method is invoked
     (from within the SIGINT handler, in this case) */
  puts ("Starting the server...");
  thrift_server_serve (server, &error);

  /* If the server stopped for any reason other than having been
     interrupted by the user, report the error */
  if (!sigint_received) {
    g_message ("thrift_server_serve: %s",
               error != NULL ? error->message : "(null)");
    g_clear_error (&error);
  }

  puts ("done.");

  g_object_unref (server);
  g_object_unref (transport_factory);
  g_object_unref (protocol_factory);
  g_object_unref (server_transport);

  g_object_unref (processor);
  g_object_unref (handler);

  return exit_status;

}

