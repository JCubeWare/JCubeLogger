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

#include "../source/JCubeLogger.h"

int main
(
	void
)
{
	int Iterator;
	char* MultipleColoredString = "Hello I am \033[0;94;10mtesting\033[0"
		";92;10m colors haha\033[0m leave me alone";
	JCubeLogger_t Logger = {0};
	JCubeLogger_Settings_t LoggerSettings = {
		.Filename = "test.txt",
		.ModuleName = "Test Module",
		.ShowModuleName = 1,
		.UseConsole = 1,
		.ShowFunctionName = 1,
		.MinimalLogLevel = JCubeLogger_DEBUG
	};

	printf("JCubeLogger_GetVersion(): %s\n", JCubeLogger_GetVersion());

	if (JCubeLogger_StartLogger(&Logger, LoggerSettings))
		return 1;
	
	if
	(
		JCubeLogger_PrintLog(
			&Logger,
			JCubeLogger_DEBUG,
			"Hello world!"
		)
	)
		return 2;

	if
	(
		JCubeLogger_PrintLog(
			&Logger,
			JCubeLogger_ERROR,
			MultipleColoredString
		)
	)
		return 3;

	for (Iterator = 0; Iterator < JCubeLogger_LOGLEVEL_COUNT_ + 3; Iterator++)
		if
		(
			JCubeLogger_PrintLog(
				&Logger,
				Iterator,
				"Log Level: %d",
				Iterator
			)
		)
			return 4 + Iterator;

	JCubeLogger_StopLogger(&Logger);

	return 0;
}