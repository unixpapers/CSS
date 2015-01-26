#define	TYPE_INT		0
#define	TYPE_STRING		1
#define	TYPE_MULTISTRING	2
#define	TYPE_UINT64		3
#define	TYPE_STRING_LIST	4

#define	PARM_OPT	0
#define	PARM_MAND	1

/* config file parsing options */
#define	CSS_CFG_FILE_REQUIRED	0
#define	CSS_CFG_FILE_OPTIONAL	1

#define	CSS_CFG_NOT_STRICT	0
#define	CSS_CFG_STRICT		1

extern char	*CONFIG_FILE;
extern char	*CONFIG_LOG_FILE;
extern int	CONFIG_ALLOW_ROOT;
extern int	CONFIG_TIMEOUT;

struct cfg_line
{
	char		*parameter;
	void		*variable;
	int		type;
	int		mandatory;
	css_uint64_t	min;
	css_uint64_t	max;
};

int	parse_cfg_file(const char *cfg_file, struct cfg_line *cfg, int optional, int strict);

