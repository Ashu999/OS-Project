#include <bits/stdc++.h>
using namespace std;

int totaltime = 0;
int burstTimeSum = 0;

struct STUDENT{
    char studentName;
    int studentID;
    int arrivalTime;
    int burstTime;
    int burstTimeOrignal;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
};
struct STUDENT s[3];

int executeStudent()
{
    int indexPosition;
    while (1)
    {
         int largest = 0;
         for (int i = 0; i < 3; i++)
         {
              if (s[i].burstTime == s[largest].burstTime)
              {
                if(s[i].studentID < s[largest].studentID) {largest = i;}
              }
              if (s[i].burstTime > s[largest].burstTime) {largest = i;}
          }
        indexPosition = largest;

        cout <<s[indexPosition].studentName<<" StudentID: " << s[indexPosition].studentID << " Time: " <<  totaltime;
        s[indexPosition].burstTime--;

        totaltime++;

        if (s[indexPosition].burstTime == 0)
        {
            cout<<'\n';
            s[indexPosition].completionTime = totaltime;
            cout<<"  "<<s[indexPosition].studentName<<" StudentID: "<< s[indexPosition].studentID << " Finished. Time: " << totaltime;
        }
        cout<<'\n';

        if (totaltime == burstTimeSum)
            break;
    }
}

int main()
{
   s[0].studentName = 'a';
   s[1].studentName = 'b';
   s[2].studentName = 'c';

    s[0].studentID = 2132;
    s[1].studentID = 2102;
    s[2].studentID = 2453;

    s[0].burstTime = 2;
    s[1].burstTime = 8;
    s[2].burstTime = 8;

    s[0].arrivalTime = 0;
    s[1].arrivalTime = 0;
    s[2].arrivalTime = 0;

    for (int i = 0; i < 3; i++)
    {
        s[i].burstTimeOrignal = s[i].burstTime;
        burstTimeSum += s[i].burstTime;
    }

    executeStudent();

    int totalwaitingTime = 0;
    int totalturnAroundTime = 0;

    cout <<'\n';
    cout <<'\n';
    for (int i = 0; i < 3; i++)
   {
        s[i].turnAroundTime = s[i].completionTime - s[i].arrivalTime;
        s[i].waitingTime = s[i].turnAroundTime - s[i].burstTimeOrignal;
        totalwaitingTime += s[i].waitingTime;
        totalturnAroundTime += s[i].turnAroundTime;
    }

    cout<<'\n';
    cout << "PNo  arrivalTime  burstTime completionTime  turnAroundTime  waitingTime\n";

    for (int i = 0; i < 3; i++) {
        cout << s[i].studentID << "          ";
        cout << s[i].arrivalTime << "          ";
        cout << s[i].burstTimeOrignal << "          ";
        cout << s[i].completionTime << "          ";
        cout << s[i].turnAroundTime << "               ";
        cout << s[i].waitingTime << "            ";
        cout << '\n';
    }
    cout <<'\n'<<"Average turnAroundTime = " << totalturnAroundTime / 3.0 << '\n';
    cout <<'\n'<<"Average waitingTime = " << totalwaitingTime / 3.0 << '\n';
    return 0;
}
