#include "JsonObject.h"

JsonObject::JsonObject(void)
{
}

JsonObject::~JsonObject(void)
{
}

void JsonObject::PushMember(MemberJSON* memberJson)
{
	ListMember.push_back(memberJson);
}
void JsonObject::Print()
{

}