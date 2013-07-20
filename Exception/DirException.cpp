#include "DirException.h"

namespace pro{


DirException::DirException(void)
{
	name = "DirExpection";
}

DirException::DirException(const string& aMessage,
				const string& aFile,
				const string& aFunc)
			: Exception(aMessage,aFile,aFunc){
	name = "DirExpection";
}

DirException::DirException(const error_code aCode){
	setErrorCode(aCode);
	name = "DirExpection";
}

DirException::DirException(const error_code aCode,const string& aPath){
	setErrorCode(aCode,aPath);
	name = "DirExpection";
}

DirException::DirException(const error_code aCode,
				const string& aPath,
				const string& aFile,
				const string& aFunc)
				:Exception("",aFile,aFunc){
	setErrorCode(aCode,aPath);
	name = "DirExpection";
}

DirException::~DirException(void)
{
}

void DirException::setErrorCode(const error_code aCode,const string aPath){
	code = aCode;
	switch(aCode){
	case EXIST:
		message = aPath + "はすでに存在しています。";
		break;
	case NOT_EXIST:
		message = aPath + "は存在しません。";
		break;
	case NOT_EMPTY:
		message = aPath + "は空ではありません。";
		break;
	case PATH_ERROR:
		message = aPath + "は使用できない文字を含んでいます。";
		break;
	case NOT_PATH:
		message = aPath + "へ到達するパスが存在しません。";
		break;
	default:
		message = "予期せぬエラー";
		break;
	}
}

void DirException::setErrorCode(const error_code aCode){
	setErrorCode(aCode,"ファイル");
}

DirException::error_code DirException::getErrorCode() const{
	return code;
}

}