#pragma once
#ifndef FREE_BLOCKS
#define FREE_BLOCKS
#define N 64
class Free_Blocks {
public:
	Free_Blocks() = default;
	int length = 0;
private:
	int number[N + 1] = { 0 };							//���
	int front = 0;       //ָ�����
	int rear = 0;		//ָ���β
};

#endif