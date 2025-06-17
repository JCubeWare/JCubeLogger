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

#ifndef JCUBELOGGER_LOGLEVELS_H
#define JCUBELOGGER_LOGLEVELS_H

/*##====[ DATA TYPES ]====##*/

/*#===[ ENUMS ]===#*/

/*
 * Currently supported log levels.
 * Each entry in the enum corresponds 
 * to an entry in the LogLevels array.
 */
enum JCubeLogger_LogLevel_e
{
	JCubeLogger_DEBUG,
	JCubeLogger_NORMAL,
	JCubeLogger_WARN,
	JCubeLogger_ERROR,
	JCubeLogger_FATAL,
	JCubeLogger_FRIDAY,
	JCubeLogger_LOGLEVEL_COUNT_
};

/*#===[ STRUCTS ]===#*/

/*
 * Holds all the information regarding a log icon.
 * Log icons represent the severity of the log.
 */
struct JCubeLogger_LogLevel
{
	char* Icon;
	int ForegroundColor;
	int BackgroundColor;
	int TextDecoration;
};

/*##====[ VARIABLES ]====##*/

/*
 * Array of all the log levels and their information,
 * such as color, text decoration and prefix.
 */
extern const struct JCubeLogger_LogLevel LogLevels[];

#endif
