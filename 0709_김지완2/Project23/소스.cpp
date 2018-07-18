#include <iostream>
#include <string>
#include<fstream>

using namespace std;
template <typename T>
class Node
{
public:
	T data; 
	Node* link; 
};
template <typename T>
class SLL
{
public:

	Node<T> * Head = nullptr;
	
/*
	SLL()
	{
		Head = NULL; 
	}
*/
	void appendNode(T data)
	{
		Node<T>* newNode = new Node<T>(); 

		newNode->data = data;
		newNode->link = NULL; 

		Node<T>* tempPoint = Head; 

		if (tempPoint != NULL) { 
			while (tempPoint->link != NULL)
				tempPoint = tempPoint->link; 

			tempPoint->link = newNode; 
		}
		else { 
			Head = newNode; 
		}
	}

	void deleteNode(T data)
	{
		Node<T>* tempPoint = Head; 
		Node<T>* prevNode = Head;       
		while (tempPoint != NULL)
		{
			
			if (data==tempPoint->data)
			{
			
				if (tempPoint == Head) Head = tempPoint->link;

				else prevNode->link = tempPoint->link;
				delete tempPoint;
				break;
			}
			prevNode = tempPoint;
			tempPoint = tempPoint->link;
		}
	}
	void deleteNode2(T data)
	{
		Node<T>* tempPoint = Head;
		Node<T>* prevNode = Head;

			if (data == 0)
			{
				Head = tempPoint->link;
			}
			else
			{
				for (int i = 0;i < data;++i)
				{
					prevNode = tempPoint;
					tempPoint = tempPoint->link;
				}
				prevNode->link = tempPoint->link;
			}
	}
	void saveNode()
	{
		ofstream outFile("Savelist.txt");
		Node<T>* tempPoint = Head;
		if (tempPoint == NULL)
		{
			outFile << "리스트가 비어 있습니다." << endl; return;
			outFile.close();
		}
		else if (tempPoint->link == NULL)
		{
			outFile << tempPoint->data << "->" << "NULL" << endl;
			outFile.close();
		}
		else
		{
			while(tempPoint!=NULL)
			{
				outFile << tempPoint->data << "->";
				tempPoint = tempPoint->link;
			}
			outFile << " NULL" << endl;
			outFile.close();
		}
	}
	void printNode() {
		Node<T>* tempPoint = Head;

						
		if (tempPoint == NULL) { cout << "리스트가 비어 있습니다." << endl; return; }
		
		if (tempPoint->link == NULL) { cout << tempPoint->data << "->" << "NULL" << endl; }
		
		else {
			while (tempPoint != NULL) 
			{
				cout << tempPoint->data << "->"; 
				tempPoint = tempPoint->link; 
			}

			cout << "NULL" << endl;
		}
	}
};

int main()
{
	SLL<double> List;

	List.appendNode(1.1);
	List.appendNode(2.2);
	List.appendNode(3.3);
	List.printNode();

	List.saveNode();

	List.deleteNode(3.3);
	List.printNode();
	List.deleteNode2(0);
	List.printNode();
	List.deleteNode(1.1);
	List.printNode();

	return 0;
}