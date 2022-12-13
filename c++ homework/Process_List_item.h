//进程表项

#pragma once
#ifndef Process_List_Item
#define Process_List_Item

#include<string>
#include<vector>
#include"Free_Blocks.h"
class Process_List_item {
private:
	std::string name = "NULL";
	int Priority = 0;
	int begin = 0;
	int length = 0;
	Process_List_item *next = nullptr;
public:
	friend void Clear_All(Process_List_item* head);
	friend int Add_Node(Process_List_item* head, Free_Blocks& free, std::vector<int>& page_table);
	friend Process_List_item* Delete_Node(Process_List_item* head, Free_Blocks& free, std::vector<int>& page_table, std::string process_name);
	friend void Update(std::vector<int>& new_page_table, std::vector<int>& page_table, Process_List_item* head);
};

#endif
