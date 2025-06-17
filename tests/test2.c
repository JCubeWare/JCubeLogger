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
	JCubeLogger_t Logger = {0};
	JCubeLogger_Settings_t LoggerSettings = {
		.Filename = NULL,
		.ModuleName = NULL,
		.ShowModuleName = 1,
		.UseConsole = 1,
		.ShowFunctionName = 0,
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
			JCubeLogger_DEBUG,
			NULL
		)
	)
		return 3;

	if
	(
		!JCubeLogger_PrintLog(
			NULL,
			JCubeLogger_DEBUG,
			NULL,
			NULL
		)
	)
		return 4;

	if
	(
		JCubeLogger_PrintLog(
			&Logger,
			-1,
			"This message should have {Friday} in it"
		)
	)
		return 5;

	JCubeLogger_StopLogger(&Logger);

	return 0;
}