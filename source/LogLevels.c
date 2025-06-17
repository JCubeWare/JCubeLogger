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

/*##====[ INCLUDES ]====##*/

#include "LogLevels.h"
#include "Colors.h"

/*##====[ VARIABLES ]====##*/

const struct JCubeLogger_LogLevel LogLevels[] = {
	{
		.Icon = "@",
		.ForegroundColor = JCubeLogger_COLOR_LIGHT_GRAY,
		.BackgroundColor = JCubeLogger_COLOR_NONE,
		.TextDecoration = JCubeLogger_TEXT_NORMAL
	},
	{
		.Icon = "OK",
		.ForegroundColor = JCubeLogger_COLOR_GREEN,
		.BackgroundColor = JCubeLogger_COLOR_NONE,
		.TextDecoration = JCubeLogger_TEXT_NORMAL
	},
	{
		.Icon = "WARN", 
		.ForegroundColor = JCubeLogger_COLOR_YELLOW,
		.BackgroundColor = JCubeLogger_COLOR_NONE,
		.TextDecoration = JCubeLogger_TEXT_NORMAL
	},
	{
		.Icon = "ERROR",
		.ForegroundColor = JCubeLogger_COLOR_RED,
		.BackgroundColor = JCubeLogger_COLOR_NONE,
		.TextDecoration = JCubeLogger_TEXT_NORMAL
	},
	{
		.Icon = "! FATAL !",
		.ForegroundColor = JCubeLogger_COLOR_DARK_RED,
		.BackgroundColor = JCubeLogger_COLOR_NONE,
		.TextDecoration = JCubeLogger_TEXT_BOLD
	},
	{
		.Icon = "{Friday}",
		.ForegroundColor = JCubeLogger_COLOR_CYAN,
		.BackgroundColor = JCubeLogger_COLOR_NONE,
		.TextDecoration = JCubeLogger_TEXT_BOLD
	},
	{0}
};
