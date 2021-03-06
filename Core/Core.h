#pragma once

#include"type_c.h"
#include"Timer.h"
#include"Dir.h"
#include"Procon2013/Exception/Exceptions.h"

#include<string>

namespace pro{

std::string PRO_EXPORTS charToString(const char* str_c,int n=512);
PRO_C_EXTERN const char* stringToChar(const string& str);

}