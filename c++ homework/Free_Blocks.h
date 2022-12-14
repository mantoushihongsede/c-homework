//空闲块表，其实是个循环队列
#pragma once
#ifndef FREE_BLOCKS
#define FREE_BLOCKS
#include<vector>
class Free_Blocks {
private:
	int length = 0;
	int number[64] = { 0 };				//编号
	int front = 0;						//指向队首
	int rear = 0;						//指向队尾
public:
	Free_Blocks(int N)														// 构造函数
	{ 
		for (rear = 0; rear < N; rear++) number[rear] = 15 - rear;
		length = N + 1;
	} 
	int full() const { return ((this->rear + 1) % this->length == this->front) ? 1 : 0; }		//检测是否为满的成员函数
	int empty() const { return (this->rear == this->front ) ? 1 : 0; }		//检测是否为空的成员函数
	void inQueue(int origin, int length, std::vector<int>& page_table);		//入队函数
	int outQueue(int number, std::vector<int>& page_table);					//出队函数
	int size() { return length; }											//返回队列实际长度
};

#endif
