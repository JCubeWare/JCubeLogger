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

#ifndef JCUBELOGGER_COLORS_H
#define JCUBELOGGER_COLORS_H

/*##====[ DATA TYPES ]====##*/

/*#===[ ENUMS ]===#*/

/*
 * All the aviable colors for the console as of now.
 * Background color is Foreground color + 10
 */
enum JCubeLogger_TextColor_e
{
	JCubeLogger_COLOR_NONE = 0,
	JCubeLogger_COLOR_BLACK = 30,
	JCubeLogger_COLOR_DARK_RED,
	JCubeLogger_COLOR_DARK_GREEN,
	JCubeLogger_COLOR_DARK_YELLOW,
	JCubeLogger_COLOR_DARK_BLUE,
	JCubeLogger_COLOR_DARK_MAGENTA,
	JCubeLogger_COLOR_DARK_CYAN,
	JCubeLogger_COLOR_LIGHT_GRAY,
	JCubeLogger_COLOR_DARK_GRAY = 90,
	JCubeLogger_COLOR_RED,
	JCubeLogger_COLOR_GREEN,
	JCubeLogger_COLOR_YELLOW,
	JCubeLogger_COLOR_BLUE,
	JCubeLogger_COLOR_MAGENTA,
	JCubeLogger_COLOR_CYAN,
	JCubeLogger_COLOR_WHITE,
	JCubeLogger_TEXTCOLOR_COUNT_
};

/*
 * All the available text decorations.
 * Linux should support all of these, but Windows is a tricky question
 */
enum JCubeLogger_TextDecoration_e
{
	JCubeLogger_TEXT_NORMAL = 0,
	JCubeLogger_TEXT_BOLD,
	JCubeLogger_TEXT_FAINT, // not widely supported
	JCubeLogger_TEXT_ITALIC, // not widely supported
	JCubeLogger_TEXT_UNDERLINE,
	JCubeLogger_TEXT_BLINK_SLOW,
	JCubeLogger_TEXT_BLINK_RAPID,
	JCubeLogger_TEXT_COLOR_REVERSE,
	JCubeLogger_TEXT_CONCEAL,
	JCubeLogger_TEXT_CROSSED_OUT,
	JCubeLogger_TEXT_PRIMARY_FONT,
	JCubeLogger_TEXT_ALTERNATE_FONT_1,
	JCubeLogger_TEXT_ALTERNATE_FONT_2,
	JCubeLogger_TEXT_ALTERNATE_FONT_3,
	JCubeLogger_TEXT_ALTERNATE_FONT_4,
	JCubeLogger_TEXT_ALTERNATE_FONT_5,
	JCubeLogger_TEXT_ALTERNATE_FONT_6,
	JCubeLogger_TEXT_ALTERNATE_FONT_7,
	JCubeLogger_TEXT_ALTERNATE_FONT_8,
	JCubeLogger_TEXT_ALTERNATE_FONT_9,
	JCubeLogger_TEXT_FRAKTUR,
	JCubeLogger_TEXT_UNDERLINE_DOUBLE,
	JCubeLogger_TEXTDECORATION_COUNT_
};

#endif
