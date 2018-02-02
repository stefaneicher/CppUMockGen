/*
 * This file has been auto-generated by CppUTestMock v0.1.0.
 *
 * Contents will NOT be preserved if it is regenerated!!!
 */

#include "Function.hpp"

#include <CppUTestExt/MockSupport.h>

Function::Function( const CXCursor &cursor, const Config &config )
: m_cursor( cursor ), m_config( config )
{
    mock().actualCall("Function::Function").withConstPointerParameter("cursor", &cursor).withConstPointerParameter("config", &config) ;
}

Function::~Function()
{
}

bool Function::IsMockable() const
{
    return mock().actualCall("Function::IsMockable").returnBoolValue();
}

std::string Function::GenerateMock() const
{
    return mock().actualCall("Function::GenerateMock").returnStringValue();
}
