//============================================================================
// Name        : SocketServer
// Author      : Dmitry Shelkovsky
// Version     :
// Copyright   : This project fork free software Zabbix
// Description : GNU General Public License
//============================================================================

#include "common.h"
#include "cfg.h"

const char	*progname = NULL;
const char	title_message[] = "Cat socket server";
const char	syslog_app_name[] = "cat_server";
const char	usage_message[] = "[-hV] [-c <file>] [-R <option>]";

const char	*help_message[] = {
	"Options:",
	"  -c --config <file>              Absolute path to the configuration file",
	"  -R --runtime-control <option>   Perform administrative functions",
	"",
	"Runtime control options:",
	"  " CSS_CONFIG_CACHE_RELOAD "             Reload configuration cache",
	"  " CSS_LOG_LEVEL_INCREASE "=<target>     Increase log level, affect all processes if target is not specified",
	"  " CSS_LOG_LEVEL_DECREASE "=<target>     Decrease log level, affect all processes if target is not specified",
	"",
	"Log level control targets:",
	"  <pid>                           Process identifier",
	"  <process type>                  All processes of specified type (e.g., poller)",
	"  <process type,N>                Process type and number (e.g., poller,3)",
	"",
	"Other options:",
	"  -h --help                       Display help information",
	"  -V --version                    Display version number",
	NULL	/* end of text */
};

/* COMMAND LINE OPTIONS */

/* long options */
static struct zbx_option	longopts[] =
{
	{"config",		1,	NULL,	'c'},
	{"runtime-control",	1,	NULL,	'R'},
	{"help",		0,	NULL,	'h'},
	{"version",		0,	NULL,	'V'},
	{NULL}
};

/* short options */
static char	shortopts[] = "c:n:hVR:";

/* end of COMMAND LINE OPTIONS */

int	main(int argc, char **argv)
{
	CSS_TASK_EX	t = {CSS_TASK_START};

	progname = get_program_name(argv[0]);

	/* parse the command-line EDIT */
	while ((char)EOF != (ch = (char)zbx_getopt_long(argc, argv, shortopts, longopts, NULL)))
	{
		switch (ch)
		{
			case 'c':
				CONFIG_FILE = zbx_strdup(CONFIG_FILE, zbx_optarg);
				break;
			case 'R':
				if (SUCCEED != parse_rtc_options(zbx_optarg, daemon_type, &t.flags))
				exit(EXIT_FAILURE);

				t.task = ZBX_TASK_RUNTIME_CONTROL;
				break;
			case 'h':
				help();
				exit(EXIT_SUCCESS);
				break;
			case 'V':
				version();
				exit(EXIT_SUCCESS);
				break;
			default:
				usage();
				exit(EXIT_FAILURE);
				break;
			}
		}

	return 0;
}
