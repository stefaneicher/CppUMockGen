/**
 * @file
 * @brief      Implementation of ConsoleColorizer class
 * @project    CppUMockGen
 * @authors    Jesus Gonzalez <jgonzalez@gdr-sistemas.com>
 * @copyright  Copyright (c) 2017-2018 Jesus Gonzalez. All rights reserved.
 * @license    See LICENSE.txt
 */

#include "ConsoleColorizer.hpp"

ConsoleColorizer cerrColorizer( ConsoleColorizer::ConsoleType::STD_ERROR );

ConsoleColorizer::ConsoleColorizer( ConsoleType consoleType ) noexcept
{
#ifdef WIN32
    m_handle = GetStdHandle( ( consoleType == ConsoleType::STD_ERROR ) ? STD_ERROR_HANDLE : STD_OUTPUT_HANDLE );

    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo( m_handle, &consoleInfo );

    m_origConsoleAttrs = consoleInfo.wAttributes;
#endif
}

ConsoleColorizer::~ConsoleColorizer() noexcept
{
#ifdef WIN32
    SetConsoleTextAttribute( m_handle, m_origConsoleAttrs );
#endif
}

void ConsoleColorizer::SetColor( Color color ) noexcept
{
#ifdef WIN32
    if( color >= Color::RESET )
    {
        SetConsoleTextAttribute( m_handle, m_origConsoleAttrs );
    }
    else
    {
        SetConsoleTextAttribute( m_handle, static_cast<WORD>(color) );
    }
#endif
}
