#pragma once
#include <iostream>

using namespace std;

struct queueNode
{
	string data;
	queueNode* nextNode;

	queueNode(string data)
	{
		this->data = data;
		// queueNode(string nodeData)
		// data = nodeData
		nextNode = nullptr;
	}
};

class QueueLinkedList
{
	queueNode* front;
	queueNode* rear;
	int queueSize;
	string queueName;

public:
	QueueLinkedList(string queueName, )
};

