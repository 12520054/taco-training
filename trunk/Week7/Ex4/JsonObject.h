#ifndef __JSONOBJECT_H__
#define __JSONOBJECT_H__
#include "Value.h"
#include <string>
#include <vector>
using namespace std;

typedef struct
{
	string	mKey;
	Value*	mValue;
} MemberJSON;

class JsonObject
{
public:
	vector<MemberJSON*> ListMember;
public:
	void PushMember(MemberJSON* memberjson);
	void Print();
	JsonObject(void);
	~JsonObject(void);
};
#endif