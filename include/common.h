#include "sysinc.h"
#include "csstypes.h"
#include "version.h"
#include "misc.h"

/* runtime control options */
#define CSS_CONFIG_CACHE_RELOAD	"config_cache_reload"
#define CSS_LOG_LEVEL_INCREASE	"log_level_increase"
#define CSS_LOG_LEVEL_DECREASE	"log_level_decrease"

typedef enum
{
	CSS_TASK_START = 0,
	CSS_TASK_PRINT_SUPPORTED,
	CSS_TASK_TEST_METRIC,
	CSS_TASK_SHOW_USAGE,
	CSS_TASK_INSTALL_SERVICE,
	CSS_TASK_UNINSTALL_SERVICE,
	CSS_TASK_START_SERVICE,
	CSS_TASK_STOP_SERVICE,
	CSS_TASK_RUNTIME_CONTROL
}
css_task_t;

typedef struct
{
	css_task_t	task;
	int		flags;
}
CSS_TASK_EX;
