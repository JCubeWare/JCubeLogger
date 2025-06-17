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

#ifndef JCUBELOGGER_COMMON_H
#define JCUBELOGGER_COMMON_H

/*##====[ EXTERNAL INCLUDES ]====##*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

/*##====[ DATA TYPES ]====##*/

/*#===[ ENUMS ]===#*/

/*
 * Enumerated return states for the functions, both internal and external.
 * If possible, try to verify all the return values in your program.
 */
enum JCubeLogger_ReturnState_e
{
	JCubeLogger_OK,
	JCubeLogger_CONDITION_FAILED,
	JCubeLogger_NOT_INITIALIZED,
	JCubeLogger_INVALID_POINTER,
	JCubeLogger_INVALID_LENGTH,
	JCubeLogger_MEMORY_FAILURE,
	JCubeLogger_FILE_IO_ERROR,
	JCubeLogger_SNPRINTF_ERROR,
	JCubeLogger_INVALID_FUNCTION_ARGUMENT,
	JCubeLogger_RETURNSTATE_COUNT_
};

/*#===[ STRUCTS ]===#*/

/*
 * Logger settings struct. All the current options are here.
 * When running the logger itself, select which ones you require.
 */
struct JCubeLogger_Settings
{
	int UseConsole;
	int ShowModuleName;
	int ShowFunctionName;
	unsigned int MinimalLogLevel;
	char* Filename;
	char* ModuleName;
};

/*
 * Main program structure.
 * It holds the selected settings, state of the logger
 * and the log file that'll be used. 
 */
struct JCubeLogger
{
	int IsLoggerReady;
	FILE* LoggingStream;
	struct JCubeLogger_Settings Settings;
};

/*#===[ TYPEDEFS ]===#*/

/*
 * Type abstraction for the settings structure.
 */
typedef struct JCubeLogger_Settings JCubeLogger_Settings_t;

/*
 * Type abstraction for the main structure.
 */
typedef struct JCubeLogger JCubeLogger_t;

#endif
