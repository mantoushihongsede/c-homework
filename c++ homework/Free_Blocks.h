//���п����ʵ�Ǹ�ѭ������
#pragma once
#ifndef FREE_BLOCKS
#define FREE_BLOCKS
#include<vector>
class Free_Blocks {
private:
	int length = 0;
	int number[64] = { 0 };				//���
	int front = 0;						//ָ�����
	int rear = 0;						//ָ���β
public:
	Free_Blocks(int N)														// ���캯��
	{ 
		for (rear = 0; rear < N; rear++) number[rear] = 15 - rear;
		length = N + 1;
	} 
	int full() const { return ((this->rear + 1) % this->length == this->front) ? 1 : 0; }		//����Ƿ�Ϊ���ĳ�Ա����
	int empty() const { return (this->rear == this->front ) ? 1 : 0; }		//����Ƿ�Ϊ�յĳ�Ա����
	void inQueue(int origin, int length, std::vector<int>& page_table);		//��Ӻ���
	int outQueue(int number, std::vector<int>& page_table);					//���Ӻ���
	int size() { return length; }											//���ض���ʵ�ʳ���
};

#endif
