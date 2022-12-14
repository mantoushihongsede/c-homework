//与模拟内存的数据结构相关的函数
#include"Memory.h"

void Memory::Initialization_Memory(int M, int N)
{
	std::string temp;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			temp.push_back(' ');
		}
		this->memory.push_back(temp);
	}
}

//std::string write(int M, int N)
//{
//	;
//}
// 
// 
//for (auto& blocks : this->memory)
//{
//	for (auto beg = blocks.begin(), end = blocks.end(); beg != end; beg++)
//	{
//		std::
//	}
//}