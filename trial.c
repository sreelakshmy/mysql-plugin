#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <ctype.h>
#include <mysql/plugin.h>

#if !defined(__attribute__) && (defined(__cplusplus) || !defined(__GNUC__)  || __GNUC__ == 2 && __GNUC_MINOR__ < 8)
#define __attribute__(A)
#endif


/*** 
http://dev.mysql.com/doc/refman/5.1/en/writing-full-text-plugins.html

The general plugin descriptor in the library descriptor names the initialization and deinitialization 
that the server should invoke when it loads and unloads the plugin. For simple_parser, these functions
do nothing but return zero to indicate that they succeeded: */

static int trial_plugin_init(void *arg __attribute__((unused)))
	{
  	return(0);
	}

static int trial_plugin_deinit(void *arg __attribute__((unused)))
	{
 	return(0);
	}
/* Initialize the parser on the first use in the query */
static int trial_init(MYSQL_FTPARSER_PARAM *param
                              __attribute__((unused)))
	{
  	return(0);
	}
/* dispose the parser on at the end of the query */
static int trial_deinit(MYSQL_FTPARSER_PARAM *param
                                __attribute__((unused)))
	{
  	return(0);
	}




#define IS_DELIM(c) (isspace((c)) || ispunct((c)))

/* Parse a document or a search query. */
static int trial_parse(MYSQL_FTPARSER_PARAM *param)
  {
  char *curr=param->doc;
  const char *begin=param->doc;
  const char *end= begin + param->length;

  param->flags = MYSQL_FTFLAGS_NEED_COPY;
  while(curr+2<end)
	{
	if(tolower(*curr)=='#') ||(tolower(*curr)=='$')||(tolower(*curr)=='-')
	  {
            // stop the querying and return a failed message
	    
	  }
  
  return 0;
  }
  


/* Plugin type-specific descriptor */
static struct st_mysql_ftparser trial_descriptor=
  {
  MYSQL_FTPARSER_INTERFACE_VERSION, /* interface version      */
  trial_parse,              /* parsing function       */
  trial_init,               /* parser init function   */
  trial_deinit              /* parser deinit function */
  };

/* Plugin status variables for SHOW STATUS (empty ) */
static struct st_mysql_show_var simple_status[]=
	{
	{0,0,0}
	};


/* Plugin system variables. (empty) */
static struct st_mysql_sys_var* simple_system_variables[]= { NULL };

/*
  Plugin library descriptor
*/

mysql_declare_plugin(trial)
{
  MYSQL_FTPARSER_PLUGIN,      /* type                            */
  &trial_descriptor,  /* descriptor                      */
  "trial",            /* name                            */
  "Pierre Lindenbaum PhD",                 /* author                          */
  "finds rs### ids.",  /* description                     */
  PLUGIN_LICENSE_GPL,
  trial_plugin_init,  /* init function (when loaded)     */
  trial_plugin_deinit,/* deinit function (when unloaded) */
  0x0001,                     /* version                         */
  simple_status,              /* status variables                */
  simple_system_variables,    /* system variables                */
  NULL
}
mysql_declare_plugin_end;
