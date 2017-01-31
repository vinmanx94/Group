#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

class Node {
public:
	int value;
	Node *next;

	Node() {
		value = -1;
		next = NULL;
	}
};

class queue {
public:
	Node *top, *bottom;

	queue() {
		top = NULL;
		bottom = NULL;
	}
	void enqueue(int x) {
		Node *temp = new Node;
		temp ->value = x;

		if(top == NULL) {
			top = bottom = temp;
		}
		else {
			bottom ->next = temp;
			bottom = temp;
		}
	}

	void dequeue() {
		Node *temp;
		temp = top;

		if(top == NULL) {
			cout << "Empty Queue!" << endl;
			return;
		}
		else {
			top = top ->next;
			cout << "About to delete " << temp ->value << endl;
			delete temp;
		}
	}

	void checkQueue(int orderTime) {
		if(orderTime = 0 && bottom != NULL) {
			dequeue();
		}
	}

	void printContents() {
		Node *temp;
			temp = top;
			while(temp != NULL) { 
				cout << temp ->value << "---> ";
				temp = temp ->next;
			}
			cout << "NULL" << endl;
		}
	};
 
int main() {

	queue queueObject;
 
	int timeOpen = 0;
	int timeClose = 1020;
	int customer = 0;
	int orderTime = 0;
	float orderTimeTotal = 0;
	float customerTotal = 0;
	float totalWait = 0;
	int queueLength = 0;
	float serviceTime = 0;

	while(timeOpen < timeClose) {
		//check if customer entered the store
		if(timeOpen < 120) 
		{
			int number = rand(); //this actually generates the random number
			number = number%10+1; //guarantee: that number is between 1 and 10
			customer = number;
			orderTime = rand();
			orderTime = orderTime%6+1;
			if (customer <= 3) {
				//add him to the queue
				queueObject.enqueue(orderTime);
				orderTimeTotal = orderTimeTotal + orderTime;
				queueLength++;
				customerTotal++;
			}
		}

		else if(timeOpen >= 120 && timeOpen < 210) {
			int number = rand(); //this actually generates the random number
			number = number%10+1; //guarantee: that number is between 1 and 10
			customer = number;
			orderTime = rand();
			orderTime = orderTime%6+1;
			if (customer <= 1) {
				//add him to the queue
				queueObject.enqueue(orderTime);
				orderTimeTotal = orderTimeTotal + orderTime;
				queueLength++;
				customerTotal++;
			}
		}

		else if(timeOpen >= 210 && timeOpen < 330) {
			int number = rand(); //this actually generates the random number
			number = number%10+1; //guarantee: that number is between 1 and 10
			customer = number;
			orderTime = rand();
			orderTime = orderTime%6+1;
			if (customer <= 4) {
				//add him to the queue
				queueObject.enqueue(orderTime);
				orderTimeTotal = orderTimeTotal + orderTime;
				queueLength++;
				customerTotal++;
			}
		}

		else if(timeOpen >= 330 && timeOpen < 570) {
			int number = rand(); //this actually generates the random number
			number = number%10+1; //guarantee: that number is between 1 and 10
			customer = number;
			orderTime = rand();
			orderTime = orderTime%6+1;
			if (customer <= 1) {
				//add him to the queue
				queueObject.enqueue(orderTime);
				orderTimeTotal = orderTimeTotal + orderTime;
				queueLength++;
				customerTotal++;
			}
		}

	/*	else if(timeOpen >= 570 && timeOpen < 720) {
			int number = rand(); //this actually generates the random number
			number = number%100+1; //guarantee: that number is between 1 and 100
			customer = number;
			orderTime = rand();
			orderTime = orderTime%6+1;
			if (customer <= 25) {
				//add him to the queue
				queueObject.enqueue(orderTime);
				orderTimeTotal = orderTimeTotal + orderTime;
				queueLength++;
				customerTotal++;
			}
		}*/

		else if(timeOpen >= 720 && timeOpen < 900 ) {
			int number = rand(); //this actually generates the random number
			number = number%10+1; //guarantee: that number is between 1 and 10
			customer = number;
			orderTime = rand();
			orderTime = orderTime%6+1;
			if (customer <= 2) {
				//add him to the queue
				queueObject.enqueue(orderTime);
				orderTimeTotal = orderTimeTotal + orderTime;
				queueLength++;
				customerTotal++;
			}
		}

		else  {
			int number = rand(); //this actually generates the random number
			number = number%10+1; //guarantee: that number is between 1 and 10
			customer = number;
			orderTime = rand();
			orderTime = orderTime%6+1;
			if (customer <= 1) {
				//add him to the queue
				queueObject.enqueue(orderTime);
				orderTimeTotal = orderTimeTotal + orderTime;
				queueLength++;
				customerTotal++;
			}
		}
		
		queueObject.checkQueue(orderTime);
		
		timeOpen++;
		orderTime--; 

		serviceTime = serviceTime + orderTime;
		
	}

	totalWait = orderTimeTotal / customerTotal;
	serviceTime = serviceTime / customerTotal;
	queueLength = queueLength / serviceTime;

	
	cout << " " << endl;
	queueObject.printContents();
	
	cout << "Average Wait Time: " << totalWait << endl;
	cout << "Average Service Time: " << serviceTime << endl;
	cout << "Average Queue Length: " << queueLength << endl;

	system("pause");
    return 1;
	//Hello
	//Hi
}