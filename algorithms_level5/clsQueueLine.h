#pragma once
#include <iostream>
#include  <queue>
class clsQueueLine {
private:
	queue<int> MyQueue;
	string _Title = "";
	int _mins = 0;
public:
	clsQueueLine(string Title, int mins) {
		_Title = Title;
		_mins = mins;
	}
	void IssueTicket() {}
	void PrintInfo() {}
	void PrintTicketsLineRTL() {}
	void PrintTicketsLineLTR() {}
	void PrintAllTickets() {}
	void ServeNextClient() {}
};