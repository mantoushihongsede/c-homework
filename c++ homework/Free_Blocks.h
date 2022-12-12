#pragma once
#ifndef FREE_BLOCKS
#define FREE_BLOCKS
#define N 64
class Free_Blocks {
public:
	Free_Blocks() = default;
	int length = 0;
private:
	int number[N + 1] = { 0 };							//编号
	int front = 0;       //指向队首
	int rear = 0;		//指向队尾
};

#endif