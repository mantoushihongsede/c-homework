//空闲块表，其实是个循环队列
#pragma once
#ifndef FREE_BLOCKS
#define FREE_BLOCKS
#define N 64
#include<vector>

class Free_Blocks {
private:
	int number[N + 1] = { 0 };							//编号
	int front = 0;       //指向队首
	int rear = 0;		//指向队尾
public:
	Free_Blocks() { for (rear = 0; rear < N; rear++) number[rear] = rear; } // 默认构造函数
	int full() const { return (this->rear == this->front) ? 1 : 0; }		//检测是否为满的成员函数
	int empty() const { return (this->rear == this->front) ? 1 : 0; }		//检测是否为空的成员函数
	void inQueue(int origin, int length, std::vector<int>& page_table);		//入队函数
	int outQueue(int number, std::vector<int>& page_table);					//出队函数
	int size() { return this->rear - this->front; }							//返回队列实际长度
};

#endif
