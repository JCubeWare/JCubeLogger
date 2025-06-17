/*
           #################################
          ###                          #####
        ###     ######################### ##
      ###     ###                   ##### ##
    ####     ########################  ## ##
  ####                          ###    ## ##
####                          ####     ## ##
################################ #     ## ##
##                     #     ##  #  ## ## ##
##                     #     ##  #  ## ## ##
##                     #     ##  #  ##### ##
##                     #     ##  # ###### ##
##                     #     ##  # #  ### ##
##                     #     ##  ###  ### ##
##                     #     ##  ##    ## ##
##########             #     ##  ##    #  ##
##       #             #     ##  ##      ###
##       #             #     ##  #      ### 
##       #             #     ##       ###   
##       ###############     ##     ####    
##                           ##   ####      
##                           ## ####        
##                           #####          
################################            

############# [J][C]ube[W]are ##############
#   Be responsible. Code for the future.   #
#         (c) 2025-2025, JCubeWare         #
############################################
*/

#pragma once

#ifndef JCUBELOGGER_LOGGING_H
#define JCUBELOGGER_LOGGING_H

/*##====[ INCLUDES ]====##*/

#include "Common.h"

/*##====[ FUNCTIONS ]====##*/

/*
 * []====[ DESCRIPTION ]====[]
 * 
 * CALL THIS FIRST!
 * Initialize the logger structure and set it up for usage.
 * All the functions will return instantly on an uninitialized structure.
 *
 * []====[ ARGUMENTS ]====[]
 * 
 * [] Instance (JCubeLogger_t*)
 * Address of the logger instance to be initialized.
 *
 * [] Settings (JCubeLogger_Settings_t)
 * Settings used to initialize the logger.
 *
 * []====[ RETURNS ]====[]
 *
 * [] JCUBELOGGER_OK
 * Success!
 *
 * [] JCUBELOGGER_*
 * ReturnState_e enum
 *
 */
int JCubeLogger_StartLogger
(
	JCubeLogger_t* Instance, 
	JCubeLogger_Settings_t Settings
);

/*
 * []====[ DESCRIPTION ]====[]
 * 
 * Stops the logger and frees the allocated memory.
 * Call at the end of the program or when you're stopping logging.
 *
 * []====[ ARGUMENTS ]====[]
 * 
 * [] Instance (JCubeLogger_t*)
 * Address of the logger instance to be stopped and cleaned.
 *
 * []====[ RETURNS ]====[]
 *
 * None
 *
 */
void JCubeLogger_StopLogger
(
	JCubeLogger_t* Instance
);

/*
 * []====[ DESCRIPTION ]====[]
 * 
 * Log the selected message into the console (and file if enabled).
 * Format: (timestamp) (priority tag) (message)
 *
 * []====[ ARGUMENTS ]====[]
 * 
 * [] Instance (JCubeLogger_t*)
 * Address of the logger instance to be stopped and cleaned.
 *
 * [] FunctionName (const char*)
 * Name of the function. Passed by the wrapper macro.
 *
 * [] LogLevel (unsigned int)
 * Log level of this message. If it's lower than the one of the logger,
 * this message will be ignored and not printed out.
 *
 * [] FormatString (char*)
 * Format string for this message. This format will be used by the printf
 * functions behind the logging.
 *
 * [] VARIADIC ARGUMENTS (ANY)
 * Arguments used for the underlying printf() call.
 * Make sure their amount matches the amount in the format string. 
 *
 * []====[ RETURNS ]====[]
 *
 * [] JCUBELOGGER_OK
 * Success!
 *
 * [] JCUBELOGGER_*
 * ReturnState_e enum
 *
 */
int JCubeLogger_Print
(
	JCubeLogger_t* Instance, 
	const char* FunctionName, 
	unsigned int LogLevel, 
	char* FormatString, 
	...
);

/*
 * Macro abstraction over the printing function.
 * ! USE THIS !
 */
#define JCubeLogger_PrintLog(Instance, LogLevel, FormatString, ...) \
JCubeLogger_Print(Instance, __func__, LogLevel, FormatString, ##__VA_ARGS__)

#endif
