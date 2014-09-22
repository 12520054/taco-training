#include <stdio.h>
#include "JsonObject.h"
#include <string.h>
#include <string>
#include "Number.h"
#include "CString.h"

Number LoadJsonNumber(char* &buffer);
CString LoadJsonString(char* &buffer);
JsonObject LoadJsonObject(char* &buffer);
JsonMember* CreateMemberJson(const string key,const MyValue* value);

int main()
{
	char* s = "\"Number\":123111111, \"Key\":123456";
	JsonObject json = LoadJsonObject(s);
	json.Print();
	return 0;
}

Number LoadJsonNumber(char* &buffer)
{
	int numb = 0;
	while(*buffer >= '0' && *buffer <= '9')
	{
		numb = numb*10 + (*buffer - '0');
		buffer += 1;
	}
	Number num;
	num.setValue(numb);
	return num;
}
CString LoadJsonString(char* &buffer)
{
	string str = "";
	buffer += 1;
	while(*buffer != '"')
	{
		str += *buffer;
		buffer += 1;
	}
	CString myString;
	myString.setString(str);
	return myString;
}
JsonObject LoadJsonObject(char* &buffer)
{
	CString key;
	Number value;
	key = LoadJsonString(buffer);
	buffer += 2;
	value = LoadJsonNumber(buffer);
	JsonObject jsonObject;
	jsonObject.PushMember(CreateMemberJson(key.getString(), &value));

	return jsonObject;
}

JsonMember* CreateMemberJson(const string key, const MyValue* value)
{
	JsonMember* jsonMem = new JsonMember();
	jsonMem->mKey = key;
	jsonMem->mValue = new Number( (Number*)value);
	return jsonMem;
}
