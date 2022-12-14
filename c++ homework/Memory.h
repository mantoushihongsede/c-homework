//模拟内存的数据结构，为了避免越界访问，特意封装一下
#pragma once
#ifndef MEMORY
#define MEMORY

#include<string>
#include<vector>
class Memory {
public:
	void Initialization_Memory(int M, int N);					//初始化模拟内存的数据结构
	//std::string Write(int M, int N);							//
	//std::string Read();
private:
	std::vector<std::string> memory;
};

#endif