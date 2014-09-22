#include "JsonObject.h"

JsonObject::JsonObject()
{
}
JsonObject::~JsonObject()
{}

void JsonObject::Print()
{
	if( !ListMember.empty() )
	{
		for(int i = 0; i < ListMember.size(); i++)
		{
			printf("%s:", ListMember[i]->mKey.c_str());
			ListMember[i]->mValue->Print();
		}
	}
}

void JsonObject::PushMember(JsonMember *jsonMem)
{
	ListMember.push_back(jsonMem);
}