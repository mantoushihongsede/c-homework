#pragma once
#ifndef Process_List_Item
#define Process_List_Item
#include<string>

class Process_List_item {
public:
	friend int Add_Node(Process_List_item* head, Free_Blocks* free);
	friend int Delete_Node(Process_List_item *head);
private:
	std::string name = "NULL";
	int Priority = 0;
	int begin = 0;
	int length = 0;
	Process_List_item *next = nullptr;
};

#endif