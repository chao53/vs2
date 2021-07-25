//作者:陈炜潮
#pragma once
#include<iostream>
#include <ctime>

using namespace std;

struct process {
	string name;
	process* next;
	int arriveTime;
	int demandTime;
	int timer = 0;
	int priority;
	int respondTime = -1;
	int state = 0;
};

class TaskList
{
public:
	TaskList();
	~TaskList();
	void insertProcess(string name,int arriveTime,int demandTime,int priority);
	void clearProcess();//清空
	void restar();//重新加载进程
	void FCFS();
	void SJF();
	void Priority();
	void SRTF();
	void RoundRobin();
private:
	process Head;
};

TaskList::TaskList()
{
	Head.next = &Head;
}

TaskList::~TaskList()
{
}

void TaskList::insertProcess(string name, int arriveTime, int demandTime, int priority) {
	process *newProcess = new process;
	newProcess->name = name;
	newProcess->arriveTime = arriveTime;
	newProcess->demandTime = demandTime;
	newProcess->priority = priority;

	process* p = &Head;
	while (p->next != &Head) {
		p = p->next;
	}

	process* q = p->next;
	p->next = newProcess;
	newProcess->next = q;
}

void TaskList::clearProcess() {
	process* p = &Head;
	if (p->next != &Head) {
		p = p->next;
		while (p->next != &Head) {
			process* q = p;
			p = p->next;
			delete(q);
		}
		delete(p);
	}
	Head.next = &Head;
}

void TaskList::restar() {
	process* p = &Head;
	while (p->next != &Head) {
		p = p->next;
		p->state = 0;
		p->timer = 0;
		p->respondTime = -1;
	}
}

void TaskList::FCFS() {
	if (Head.next == &Head) {
		cout << "wrong!";
	}
	else
	{
		int t = 0;
		process* p = &Head;
		cout << "**************************************************************************************************************" << endl;
		cout << "FCFS:" << endl;
		cout << "作业名\t到达时间\t要求时间\t运行时间\t优先级" << endl;
		int count = 0;
		while (p->next != &Head) {
			p = p->next;
			cout << p->name << "\t" << p->arriveTime << "\t\t" << p->demandTime << "\t\t" << p->timer << "\t\t" << p->priority << endl;
			count++;
		}
		int totalWait = 0;
		int totalTurnaround = 0;
		int totalRespond = 0;
		int mark1 = 1;
		while (mark1 == 1) {
			mark1 = 0;
			p = Head.next;
			process* current = Head.next;
			while(current->state == 1) {
				current = current->next;
			}
			while (p->next != &Head) {
				p = p->next;
				if (p->state == 0) {
					if (p->arriveTime == current->arriveTime) {
						if (p->priority > current->priority) {
							current = p;
						}
					}
					else if (p->arriveTime < current->arriveTime)
					{
						current = p;
					}
				}
			}
			if (t < current->arriveTime) {
				t = current->arriveTime;
			}
			current->respondTime = t - current->arriveTime;
			totalRespond += current->respondTime;
			t += current->demandTime;
			int waitTime = t - current->demandTime - current->arriveTime;
			totalWait += waitTime;
			totalTurnaround += waitTime + current->demandTime;
			current->state = 1;
			cout << "作业名\t到达时间\t要求时间\t运行时间\t优先级\t上一进程:" << current->name <<"\t"<< "等待时间:"<< waitTime<< "\t" << "响应时间:" << current->respondTime << endl;
			p = &Head;
			while (p->next != &Head) {
				p = p->next;
				if (p->state == 0) {
					mark1 = 1;
					cout << p->name << "\t" << p->arriveTime << "\t\t" << p->demandTime << "\t\t" << p->timer << "\t\t" << p->priority << endl;
				}
			}
			
		}
		cout << "平均等待时间:"<<(float)totalWait/count<<endl;
		cout << "平均周转时间:" << (float)totalTurnaround / count << endl;
		cout << "平均响应时间:" << (float)totalRespond / count << endl;
		cout << "吞吐量:" << (float)count / t << endl;
	}
}
 
void TaskList::SJF() {
	if (Head.next == &Head) {
		cout << "wrong!";
	}
	else
	{
		int t = 0;
		process* p = &Head;
		cout << "**************************************************************************************************************" << endl;
		cout << "SJF:" << endl;
		cout << "作业名\t到达时间\t要求时间\t运行时间\t优先级" << endl;
		int count = 0;
		while (p->next != &Head) {
			p = p->next;
			cout << p->name << "\t" << p->arriveTime << "\t\t" << p->demandTime << "\t\t" << p->timer << "\t\t" << p->priority << endl;
			count++;
		}
		int totalWait = 0;
		int totalTurnaround = 0;
		int totalRespond = 0;
		process* current = Head.next;
		int mark1 = 1;
		while (mark1 == 1) {
			mark1 = 0;
			p = &Head;
			current = Head.next;
			while (current->state == 1) {
				current = current->next;
			}
			int mark2 = 0;
			while (p->next != &Head) {
				p = p->next;
				if (p->state == 0 && t >= p->arriveTime) {
					mark2 = 1;
					if (p->demandTime == current->demandTime) {
						if (p->priority > current->priority) {
							current = p;
						}
					}
					else if (p->demandTime < current->demandTime)
					{
						current = p;
					}
				}
			}
			if (mark2 == 0) {
				p = &Head;
				while (p->next != &Head) {//再定位先到达的
					p = p->next;
					if (p->state == 0) {
						if (p->arriveTime == current->arriveTime) {
							if (p->demandTime > current->demandTime) {
								current = p;
							}
						}
						else if (p->arriveTime < current->arriveTime)
						{
							current = p;
						}
					}
				}
			}
			current->state = 1;
			if (t < current->arriveTime) {
				t = current->arriveTime;
			}
			current->respondTime = t - current->arriveTime;
			totalRespond += current->respondTime;
			t += current->demandTime;
			int waitTime = t - current->demandTime - current->arriveTime;
			totalWait += waitTime;
			totalTurnaround += waitTime + current->demandTime;
			cout << "作业名\t到达时间\t要求时间\t运行时间\t优先级\t上一进程:" << current->name << "\t" << "等待时间:" << waitTime << "\t" << "响应时间:" << current->respondTime << endl;
			p = &Head;
			while (p->next != &Head) {
				p = p->next;
				if (p->state == 0) {
					mark1 = 1;
					cout << p->name << "\t" << p->arriveTime << "\t\t" << p->demandTime << "\t\t" << p->timer << "\t\t" << p->priority << endl;
				}
			}
		}
		cout << "平均等待时间:" << (float)totalWait / count << endl;
		cout << "平均周转时间:" << (float)totalTurnaround / count << endl;
		cout << "平均响应时间:" << (float)totalRespond / count << endl;
		cout << "吞吐量:" << (float)count / t << endl;
	}

}

void TaskList::Priority() {
	if (Head.next == &Head) {
		cout << "wrong!";
	}
	else
	{
		int t = 0;
		process* p = &Head;
		cout << "**************************************************************************************************************" << endl;
		cout << "Priority:" << endl;
		cout << "作业名\t到达时间\t要求时间\t运行时间\t优先级" << endl;
		int count = 0;
		while (p->next != &Head) {
			p = p->next;
			cout << p->name << "\t" << p->arriveTime << "\t\t" << p->demandTime << "\t\t" << p->timer << "\t\t" << p->priority << endl;
			count++;
		}
		int totalWait = 0;
		int totalTurnaround = 0;
		int totalRespond = 0;
		process* current = Head.next;
		while (true) {
			p = &Head;
			current = Head.next;
			while (current->state == 1) {
				current = current->next;
				if (current == &Head) {
					break;
				}
			}
			if (current == &Head) {
				break;
			}
			while (p->next != &Head)
			{
				p = p->next;
				if (p->state == 0 && t >= p->arriveTime) {
					if (p->priority == current->priority) {
						if (p->arriveTime < current->arriveTime) {
							current = p;
						}
					}
					else if (p->priority > current->priority)
					{
						current = p;
					}
				}
			}
			if (t < current->arriveTime) {
				t = current->arriveTime;
			}
			if (current->timer == 0) {
				current->respondTime = t - current->arriveTime;
				totalRespond += current->respondTime;
			}
			t++;
			current->timer++;
			if (current->timer == current->demandTime) {
				current->state = 1;
				int waitTime = t - current->demandTime - current->arriveTime;
				totalWait += waitTime;
				totalTurnaround += waitTime + current->demandTime;
				cout << "作业名\t到达时间\t要求时间\t运行时间\t优先级\t上一进程:" << current->name << "\t" << "等待时间:" << waitTime << "\t" << "响应时间:" << current->respondTime << endl;
				p = &Head;
				while (p->next != &Head) {
					p = p->next;
					if (p->state == 0) {
						cout << p->name << "\t" << p->arriveTime << "\t\t" << p->demandTime << "\t\t" << p->timer << "\t\t" << p->priority << endl;
					}
				}
			}
		}
		cout << "平均等待时间:" << (float)totalWait / count << endl;
		cout << "平均周转时间:" << (float)totalTurnaround / count << endl;
		cout << "平均响应时间:" << (float)totalRespond / count << endl;
		cout << "吞吐量:" << (float)count / t << endl;
	}
}

void TaskList::SRTF() {
	if (Head.next == &Head) {
		cout << "wrong!";
	}
	else
	{
		int t = 0;
		process* p = &Head;
		cout << "**************************************************************************************************************" << endl;
		cout << "SRTF:" << endl;
		cout << "作业名\t到达时间\t要求时间\t运行时间\t优先级" << endl;
		int count = 0;
		while (p->next != &Head) {
			p = p->next;
			cout << p->name << "\t" << p->arriveTime << "\t\t" << p->demandTime << "\t\t" << p->timer << "\t\t" << p->priority << endl;
			count++;
		}
		int totalWait = 0;
		int totalTurnaround = 0;
		int totalRespond = 0;
		process* current = Head.next;
		while (true) {
			p = &Head;
			current = Head.next;
			while (current->state == 1) {
				current = current->next;
				if (current == &Head) {
					break;
				}
			}
			if (current == &Head) {
				break;
			}
			while (p->next != &Head)
			{
				p = p->next;
				if (p->state == 0 && t >= p->arriveTime) {
					if ((p->demandTime - p->timer) == (current->demandTime - p->timer)) {
						if (p->arriveTime < current->arriveTime) {
							current = p;
						}
					}
					else if ((p->demandTime - p->timer) < (current->demandTime - p->timer))
					{
						current = p;
					}
				}
			}
			if (t < current->arriveTime) {
				t = current->arriveTime;
			}
			if (current->timer == 0) {
				current->respondTime = t - current->arriveTime;
				totalRespond += current->respondTime;
			}
			t++;
			current->timer++;
			if (current->timer == current->demandTime) {
				current->state = 1;
				int waitTime = t - current->demandTime - current->arriveTime;
				totalWait += waitTime;
				totalTurnaround += waitTime + current->demandTime;
				cout << "作业名\t到达时间\t要求时间\t运行时间\t优先级\t上一进程:" << current->name << "\t" << "等待时间:" << waitTime << "\t" << "响应时间:" << current->respondTime << endl;
				p = &Head;
				while (p->next != &Head) {
					p = p->next;
					if (p->state == 0) {
						cout << p->name << "\t" << p->arriveTime << "\t\t" << p->demandTime << "\t\t" << p->timer << "\t\t" << p->priority << endl;
					}
				}
			}
		}
		cout << "平均等待时间:" << (float)totalWait / count << endl;
		cout << "平均周转时间:" << (float)totalTurnaround / count << endl;
		cout << "平均响应时间:" << (float)totalRespond / count << endl;
		cout << "吞吐量:" << (float)count / t << endl;
	}
}

void TaskList::RoundRobin() {
	if (Head.next == &Head) {
		cout << "wrong!";
	}
	else
	{
		int t = 0;
		process* p = &Head;
		cout << "**************************************************************************************************************" << endl;
		cout << "RoundRobin:" << endl;
		cout << "作业名\t到达时间\t要求时间\t运行时间\t优先级" << endl;
		int count = 0;
		while (p->next != &Head) {
			p = p->next;
			cout << p->name << "\t" << p->arriveTime << "\t\t" << p->demandTime << "\t\t" << p->timer << "\t\t" << p->priority << endl;
			count++;
		}
		int totalWait = 0;
		int totalTurnaround = 0;
		int totalRespond = 0;
		process* current = &Head;
		while (true) {//to be continue 
			if (current->next == &Head) {
				current = Head.next;
			}
			else
			{
				current = current->next;
			}

			p = current;
			int mark1 = 0;
			int mark2 = 0;
			while (current->state != 0 || current->arriveTime > t) {
				if (current->state == 0) {
					mark1 = 1;
				}
				if (current->next == &Head) {
					current = Head.next;
				}
				else
				{
					current = current->next;
				}
				if (current == p) {
					mark2 = 1;
					break;
				}
			}

			if (mark1 == 0 && mark2 == 1) {
				break;
			}
			if (t < current->arriveTime) {
				t = current->arriveTime;
			}
			if (current->timer == 0) {
				current->respondTime = t - current->arriveTime;
				totalRespond += current->respondTime;
			}
			t++;
			current->timer++;
			if (current->timer == current->demandTime) {
				current->state = 1;
				int waitTime = t - current->demandTime - current->arriveTime;
				totalWait += waitTime;
				totalTurnaround += waitTime + current->demandTime;
				cout << "作业名\t到达时间\t要求时间\t运行时间\t优先级\t上一进程:" << current->name << "\t" << "等待时间:" << waitTime << "\t" << "响应时间:" << current->respondTime << endl;
				p = &Head;
				while (p->next != &Head) {
					p = p->next;
					if (p->state == 0) {
						cout << p->name << "\t" << p->arriveTime << "\t\t" << p->demandTime << "\t\t" << p->timer << "\t\t" << p->priority << endl;
					}
				}
			}

		}
		cout << "平均等待时间:" << (float)totalWait / count << endl;
		cout << "平均周转时间:" << (float)totalTurnaround / count << endl;
		cout << "平均响应时间:" << (float)totalRespond / count << endl;
		cout << "吞吐量:" << (float)count / t << endl;
	}
}

int main(){
	
	unsigned seed;
	seed = time(0);
	srand(seed);
	TaskList T1 = TaskList();
	T1.insertProcess("A", 3, rand() % 30 + 1, 1);
	T1.insertProcess("B", 6, rand() % 30 + 1, 1);
	T1.insertProcess("C", 8, rand() % 30 + 1, 2);
	T1.insertProcess("D", 8, rand() % 30 + 1, 1);
	T1.insertProcess("E", 12, rand() % 30 + 1, 4);
	T1.insertProcess("F", 15, rand() % 30 + 1, 2);
	T1.FCFS();
	T1.restar();
	T1.SJF();
	T1.restar();
	T1.Priority();
	T1.restar();
	T1.SRTF();
	T1.restar();
	T1.RoundRobin();
}