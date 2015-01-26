
#include "common.h"


/******************************************************************************
 *                                                                            *
 * Function: get_program_name                                                 *
 *                                                                            *
 * Purpose: return program name without path                                  *
 *                                                                            *
 * Parameters: path                                                           *
 *                                                                            *
 * Return value: program name without path                                    *
 *                                                                            *
 * Author: Eugene Grigorjev                                                   *
 *                                                                            *
 ******************************************************************************/
const char	*get_program_name(const char *path)
{
	const char	*filename = NULL;

	for (filename = path; path && *path; path++)
	{
		if ('\\' == *path || '/' == *path)
			filename = path + 1;
	}

	return filename;
}
