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

#include "JCubeLogger.h"

/*##====[ FUNCTIONS ]====##*/

char* JCubeLogger_GetVersion
(
	void
)
{
#if defined(JCUBELOGGER_NAME) && defined(JCUBELOGGER_VERSION)
	return JCUBELOGGER_NAME " v" JCUBELOGGER_VERSION 
		" (Built on " __DATE__ " " __TIME__ ")";
#else
	return "Compiled without JCubeMakefile. Please use JCubeMakefile.";
#endif
}
