#include "stdio.h"
#include "JsonObject.h"
#include "Number.h"
#include "CString.h"
#include <string.h>
#include <string>

Number LoadJsonNumber(char* &buffer);
String LoadJsonString(char* &buffer);
JsonObject LoadJsonObject(char* &buffer);
MemberJSON* CreateMemberJson(const string key, const Value* value);

int main()
{
	char* s;
	char ss[] = "{\"Key\":123}";
	s = &ss[0];
	JsonObject json = LoadJsonObject((char*&)s);

	printf("%d", *json.ListMember.back()->mValue);
	return 0;
}

MemberJSON* CreateMemberJson(const string key, const Value* value)
{
	MemberJSON* mem = new MemberJSON();
	mem->mKey = key;
	mem->mValue = (Value*)value;
	return mem;
}

JsonObject LoadJsonObject(char* &buffer)
{
	buffer += 1;
	String key = LoadJsonString(buffer);
	buffer += 1;
	Number value = LoadJsonNumber(buffer);
	JsonObject jsonObject;
	jsonObject.PushMember( CreateMemberJson(key.getString(), &value));
	return jsonObject;
}

String LoadJsonString(char* &buffer)
{
	string str;
	buffer += 1;
	while( *buffer != '"')
	{
		str += *buffer;
		buffer += 1;
	}
	buffer += 1;
	String myStr;
	myStr.setString(str);
	return myStr;
}

Number LoadJsonNumber(char* &buffer)
{
	int number = 0;
	while(*(buffer) >= '0' && *(buffer) <= '9')
	{
		number = number*10 + (*(buffer) - '0');
		buffer = buffer + 1;
	}
	Number num;
	num.setValue(number);
	return num;
}