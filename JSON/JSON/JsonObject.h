#ifndef __JSONOBJECT_H__
#define __JSONOBJECT_H__

#include "MyValue.h"
#include <string.h>
#include <string>
#include <vector>
using namespace std;

typedef struct
{
	string mKey;
	MyValue* mValue;
} JsonMember;

class JsonObject
{
private:
	vector<JsonMember*> ListMember;
public:
	JsonObject();
	~JsonObject();
	void Print();
	void PushMember(JsonMember* jsonMem);
};

#endif
