#pragma once

#include"Exception.h"

namespace pro{

/**
 *  引数に入れた値が範囲外の例外処理
 */
template<typename Type> class PRO_EXPORTS OutOfRangeException
	: public Exception
{
protected:
	Type num;
	string agument;
private:
	void setNum(Type aNum);
	void setNum(Type aNum, const string& aAgument);
public:
	OutOfRangeException(void);
	OutOfRangeException(Type aNum);
	OutOfRangeException(Type aNum,const string& aAgument);
	OutOfRangeException(const string& aMessage);
	OutOfRangeException(const string& aMessage,
				const string& aFile,
				const string& aFunc);
	OutOfRangeException(Type aNum,
				const string& aFile,
				const string& aFunc);
	OutOfRangeException(Type aNum,
				const string& aAgument,
				const string& aFile,
				const string& aFunc);

	~OutOfRangeException(void);
};

}