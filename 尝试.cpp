#include<iostream>
#include<cstring>
using namespace std;

string weekdays[] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
int M,N,P;
string names[10];

int isRubbish(string str,int speakerID){ 
    if(str==" I have the ring." || str==" I have not the ring.")
        return speakerID;
    for (int i=0; i<M; ++i) {
        string toCheck_1 = " "+names[i]+" has the ring.";
        string toCheck_2 = " "+names[i]+" has not the ring.";
        if(str==toCheck_1||str==toCheck_2)
            return i;
    }
    return M+1;
}

int main(int argc, char const *argv[])
{
    
    cin>>M>>N>>P;
 
    string statements[20];
    for (int i = 0; i < M;)
    {
        string temp ;
        getline(cin,temp);
        if(temp!="")
        {
            names[i++] = temp;
        }
    }
    int flag1[20]={0},flag2[20]={0},flag3[20]={0};
    for (int i = 0; i < P; ++i)
    {
        getline(cin, statements[i]);

        unsigned long loc = statements[i].find(":");
        int speakerid=0;
        if(loc!=-1){
            string nameCheck = statements[i].substr(0,loc);
            
            for (; speakerid<M; ++speakerid) if(names[speakerid]==nameCheck){
                flag1[i]=speakerid;
                break;
            }
         
            unsigned long frstB=0,scndB=0;
            frstB = statements[i].find(" ");
            scndB = statements[i].substr(frstB+1,statements[i].length()).find(" ");
            
            string f2 = statements[i].substr(frstB+1,scndB);
            if(f2=="Today"){
                int weekdayId = 1;
                for (; weekdayId<=7; ++weekdayId) if(statements[i].find(weekdays[weekdayId-1])!=-1){
                    flag2[i]=weekdayId;
                    flag3[i]=3;
                    break;
                }
            }else{
                int receivedId = isRubbish(statements[i].substr(loc+1),speakerid);
                if(receivedId==M+1)
                    continue;
                flag2[i]=receivedId;
                flag3[i]=(statements[i].find("not")==-1) ? 1 : 2;
            }
        }
        
    }

    int rubbish=0;
    for (int i = 0; i < P ; ++i) {
    	if(flag3[i]!=0){
   	       cout<<flag1[i]<<" "<<flag2[i]<<" "<<flag3[i]<<endl;
   	     }
		else	rubbish++;
	}
    if(rubbish==P)	cout<<"Orz"<<endl;
    return 0;
}
