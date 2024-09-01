#pragma once
#include <iostream>
#include  <queue>
#include "clsDate.h"
class clsTicket
{
private:

	short _Number = 0;
	string _Prefix;
	string _TicketTime;
	short _WaitingClients = 0;
	short _AverageServeTime = 0;
	short _ExpectedServeTime = 0;

public:
	clsTicket(string Prefix, short Number, short WaitingClients, short AverageServeTime)
	{

		_Number = Number;
		_TicketTime = clsDate::GetSystemDateTimeString();
		_Prefix = Prefix;
		_WaitingClients = WaitingClients;
		_AverageServeTime = AverageServeTime;
	}

	string Prefix()
	{
		return _Prefix;

	}
	short Number()
	{
		return _Number;
	}

	string FullNumber()
	{
		return _Prefix + to_string(_Number);
	}

	string TicketTime()
	{
		return _TicketTime;
	}

	short WaitingClients()
	{
		return _WaitingClients;
	}

	short ExpectedServeTime()
	{
		return _AverageServeTime * _WaitingClients;
	}

	void Print()
	{
		cout << "\n\t\t\t  _______________________\n";
		cout << "\n\t\t\t\t    " << FullNumber();
		cout << "\n\n\t\t\t    " << _TicketTime;
		cout << "\n\t\t\t    Wating Clients = " << _WaitingClients;
		cout << "\n\t\t\t      Serve Time In";
		cout << "\n\t\t\t       " << ExpectedServeTime() << " Minutes.";
		cout << "\n\t\t\t  _______________________\n";


	}
};
class clsQueueLine {
private:
	short _TotalTickets = 0;
	short _AverageServeTime = 0;
	string _Prefix = "";

public:
	queue<clsTicket>  QueueLine;
	clsQueueLine(string Prefix, int AverageServeTime) {
		_Prefix = Prefix;
		_AverageServeTime = AverageServeTime;
	}

	int TotalTickets() {
		return  _TotalTickets;
	}
	int ServedClients() {
		return  _TotalTickets - QueueLine.size();
	}
	int WaitingClients() {
		return   QueueLine.size() - 1;
	}
	void IssueTicket() {
		_TotalTickets++;
		clsTicket ticket = clsTicket(
			_Prefix, _TotalTickets, WaitingClients(), _AverageServeTime
		);
		QueueLine.push(ticket);
	}
	void PrintInfo() {
		cout << "_________________________________" << endl;
		cout << "            Queue info           " << endl;
		cout << "_________________________________" << endl;
		cout << "   Prefix          =  " << _Prefix << endl;
		//cout << "   Prefix  =  " << _AverageServeTime << endl;
		cout << "   Total Tickets   =  " << TotalTickets() << endl;
		cout << "   Served Clients  =  " << ServedClients() << endl;
		cout << "   Waiting Clients =  " << WaitingClients() << endl;
		cout << "_________________________________" << endl;

	}
	void PrintTicketsLineRTL() {
		if (QueueLine.empty())
			cout << "\nTickets: No Tickets.";
		else
			cout << "\nTickets: ";
		queue<clsTicket>  _Temp = QueueLine;
		while (!_Temp.empty())
		{
			cout << " " << _Temp.front().FullNumber() << " <-- ";
			_Temp.pop();
		}
		cout << endl;
	}
	void PrintTicketsLineLTR() {
		if (QueueLine.empty())
			cout << "\nTickets: No Tickets.";
		else
			cout << "\nTickets: ";
		//we copy the queue in order not to lose the original
		queue <clsTicket> TempQueueLine = QueueLine;
		stack <clsTicket> TempStackLine;
		while (!TempQueueLine.empty())
		{
			TempStackLine.push(TempQueueLine.front());
			TempQueueLine.pop();
		}
		while (!TempStackLine.empty())
		{
			cout << " --> " << TempStackLine.top().FullNumber() << "  ";
			TempStackLine.pop();
		}
		cout << endl;
	}
	void PrintAllTickets() {
		if (QueueLine.empty()) cout << "\nTickets: No Tickets.";
		queue<clsTicket>  _Temp = QueueLine;
		while (!_Temp.empty())
		{
			_Temp.front().Print();
			_Temp.pop();
		}
		cout << endl;
	}
	void ServeNextClient() {
		QueueLine.pop();
	}
};