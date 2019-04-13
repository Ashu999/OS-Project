#include <bits/stdc++.h>
using namespace std;

int totaltime = 0;
int burstTimeSum = 0;

struct PROCESS{
    string processName;
    int arrivalTime;
    int burstTime;
    int completionTime;
};
struct PROCESS s[5];

int executeProcess();

int main()
{
   s[0].processName = "p1";
   s[1].processName = "p2";
   s[2].processName = "p3";
   s[3].processName = "pi";
   s[4].processName = "p5";


    s[0].burstTime = 10;
    s[1].burstTime = 29;
    s[2].burstTime = 3;
    s[3].burstTime = 7;
    s[4].burstTime = 12;

    s[0].arrivalTime = 0;
    s[1].arrivalTime = 0;
    s[2].arrivalTime = 0;
    s[3].arrivalTime = 0;
    s[4].arrivalTime = 0;

    for (int i = 0; i < 3; i++)
    {
        burstTimeSum += s[i].burstTime;
    }

    executeProcess();

    cout <<endl;
    cout <<endl;

    cout<<endl;
    cout << "PNo  arrivalTime completionTime\n";

    for (int i = 0; i < 5; i++) {
        cout << s[i].processName << "          ";
        cout << s[i].arrivalTime << "          ";
        cout << s[i].completionTime << "          ";
        cout << endl;
    }

    cout<<endl<<"Ending time of process pi :"<<s[3].completionTime<<endl<<endl;
    return 0;
}

int executeProcess()
{
    int indexPosition;
    int smallest = 0;
    int counter = 0;
    while (1)
    {
         if(counter == 5) {return 0;}
         for (int i = 0; i < 5; i++)
         {
              if (s[i].burstTime < s[smallest].burstTime) {smallest = i;}
         }
        indexPosition = smallest;

        cout <<s[indexPosition].processName<< " Time: " <<  totaltime;

        totaltime = totaltime + s[indexPosition].burstTime;
        s[indexPosition].burstTime = INT_MAX;

        cout<<endl;
        s[indexPosition].completionTime = totaltime;
        cout<<"  "<<s[indexPosition].processName<< " Finished. Time: " << totaltime;

        cout<<endl;
        counter++;
    }
}
