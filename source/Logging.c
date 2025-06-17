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

#include "Logging.h"
#include "LogLevels.h"

/*##====[ DEFINES ]====##*/

#define TIME_STRING "00.00.0000 | 00:00:00"

#define LOG_FORMAT_TIME "{%s} "
#define LOG_FORMAT_MODULE "<%s> "
#define LOG_FORMAT_FUNCTION "(%s) "
#define LOG_FORMAT_LEVEL "[%s] "

/*##====[ HELPER FUNCTIONS ]====##*/

static char* JCubeLogger_SanitizeString
(
	char* SourceString
)
{
	unsigned int Index = 0;
	unsigned int Position = 0;
	char* SanitizedString = NULL;

	if (!SourceString)
		return NULL;

	SanitizedString = (char *)calloc(
		strlen(SourceString),
		sizeof(char)
	);
	if (!SanitizedString)
		return NULL;

	while (SourceString[Index] != '\0')
	{
		if (SourceString[Index] >= ' ')
		{
			SanitizedString[Position] = SourceString[Index];
			Position++;
		}

		if (SourceString[Index] == '\033')
		{
			while (SourceString[Index] != 'm')
				Index++;
		}

		Index++;
	}

	SanitizedString = (char *)realloc(
		SanitizedString,
		(Position + 1) * sizeof(char)
	);
	if (!SanitizedString)
		return NULL;
	SanitizedString[Position] = '\0';

	return SanitizedString;
}

static char* JCubeLogger_ColorStringCreate
(
	char* SourceString,
	int ForegroundColor,
	int BackgroundColor,
	int TextDecoration
)
{
	int AllocateBytes, Result;
	char* ColoredString = NULL;

	if (!SourceString)
		return NULL;

	AllocateBytes = snprintf(
		ColoredString,
		0,
		"\033[%d;%d;%dm%s\033[0m",
		TextDecoration,
		ForegroundColor,
		BackgroundColor + 10,
		SourceString
	);
	if (AllocateBytes < 0)
		return SourceString;

	ColoredString = (char *)calloc(
		AllocateBytes + 1, 
		sizeof(char)
	);
	if (!ColoredString)
		return NULL;

	Result = snprintf(
		ColoredString,
		AllocateBytes + 1,
		"\033[%d;%d;%dm%s\033[0m",
		TextDecoration,
		ForegroundColor,
		BackgroundColor + 10,
		SourceString
	);
	if (Result < 0)
		return SourceString;

	ColoredString[AllocateBytes] = '\0';

	return ColoredString;
}

static int JCubeLogger_TimeStringCreate
(
	char** DestinationString
)
{
	int Result;
	int TimeStringLength = strlen(TIME_STRING);
	char* TimeString = NULL;
	time_t RawTime = time(NULL);
	struct tm* TimeStruct = localtime(&RawTime);
	
	if (!DestinationString)
		return JCubeLogger_INVALID_POINTER;

	TimeString = (char *)calloc(
		TimeStringLength + 1, 
		sizeof(char)
	);
	if (!TimeString)
		return JCubeLogger_MEMORY_FAILURE;

	Result = snprintf(
		TimeString,
		TimeStringLength + 1,
		"%02d.%02d.%04d | %02d:%02d:%02d",
		TimeStruct->tm_mday,
		TimeStruct->tm_mon + 1,
		TimeStruct->tm_year + 1900,
		TimeStruct->tm_hour,
		TimeStruct->tm_min,
		TimeStruct->tm_sec
	);
	if (Result < 0)
	{
		free(TimeString);
		return JCubeLogger_SNPRINTF_ERROR;
	}

	*DestinationString = TimeString;
	return JCubeLogger_OK;
}

static void JCubeLogger_PrintToStream
(
	JCubeLogger_t* Instance,
	FILE* Stream,
	char* TimeString,
	const char* FunctionName,
	char* FormatString,
	char* LogString,
	va_list Arguments
)
{
	fprintf(Stream, LOG_FORMAT_TIME, TimeString);
	if (Instance->Settings.ShowModuleName && Instance->Settings.ModuleName)
		fprintf(Stream, LOG_FORMAT_MODULE, Instance->Settings.ModuleName);
	if (Instance->Settings.ShowFunctionName)
		fprintf(Stream, LOG_FORMAT_FUNCTION, FunctionName);
	fprintf(Stream, LOG_FORMAT_LEVEL, LogString);
	vfprintf(Stream, FormatString, Arguments);
	fprintf(Stream,	"\n");
}

/*##====[ FUNCTIONS ]====##*/

int JCubeLogger_StartLogger
(
	JCubeLogger_t* Instance,
	JCubeLogger_Settings_t Settings
)
{
	if (!Instance)
		return JCubeLogger_INVALID_POINTER;

	if (Instance->IsLoggerReady)
		return JCubeLogger_CONDITION_FAILED;

	Instance->Settings = Settings;

	if (Instance->Settings.Filename)
	{
		Instance->LoggingStream = fopen(
			Instance->Settings.Filename, 
			"a+"
		);
		if (!Instance->LoggingStream)
			return JCubeLogger_FILE_IO_ERROR;
	}

	Instance->IsLoggerReady = 1;
	return JCubeLogger_OK;
}

void JCubeLogger_StopLogger
(
	JCubeLogger_t* Instance
)
{
	if (!Instance->IsLoggerReady)
		return;

	if (Instance->LoggingStream)
	{
		fclose(Instance->LoggingStream);
		Instance->LoggingStream = NULL;
	}

	Instance->IsLoggerReady = 0;
}

int JCubeLogger_Print
(
	JCubeLogger_t* Instance,
	const char* FunctionName,
	unsigned int LogLevel,
	char* FormatString,
	...
)
{
	int TimeStringResult;
	char* TimeString = NULL;
	char* LogIcon = NULL;
	va_list Arguments;

	if (!Instance)
		return JCubeLogger_INVALID_POINTER;
	if (!Instance->IsLoggerReady)
		return JCubeLogger_NOT_INITIALIZED;
	if (LogLevel < Instance->Settings.MinimalLogLevel)
		return JCubeLogger_OK;

	if (LogLevel >= JCubeLogger_LOGLEVEL_COUNT_)
		LogLevel = JCubeLogger_LOGLEVEL_COUNT_ - 1;

	TimeStringResult = JCubeLogger_TimeStringCreate(&TimeString);
	if (TimeStringResult)
		return TimeStringResult;

	LogIcon = JCubeLogger_ColorStringCreate(
		LogLevels[LogLevel].Icon,
		LogLevels[LogLevel].ForegroundColor,
		LogLevels[LogLevel].BackgroundColor,
		LogLevels[LogLevel].TextDecoration
	);
	if (!LogIcon)
	{
		free(TimeString);
		return JCubeLogger_MEMORY_FAILURE;
	}

	if (Instance->Settings.UseConsole)
	{
		va_start(Arguments, FormatString);
		JCubeLogger_PrintToStream(
			Instance,
			stdout,
			TimeString,
			FunctionName,
			FormatString,
			LogIcon,
			Arguments
		);
		va_end(Arguments);
	}

	if (Instance->Settings.Filename)
	{
		va_start(Arguments, FormatString);
		char* SanitizedFormat = JCubeLogger_SanitizeString(FormatString);
		JCubeLogger_PrintToStream(
			Instance,
			Instance->LoggingStream,
			TimeString,
			FunctionName,
			SanitizedFormat,
			LogLevels[LogLevel].Icon,
			Arguments
		);
		free(SanitizedFormat);
		va_end(Arguments);
	}

	free(LogIcon);
	free(TimeString);
	return JCubeLogger_OK;
}
