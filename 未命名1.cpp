#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	// win times and game times
	int win_time,total_play;
	win_time = total_play = 0;
	while (true)
	{
		char q;
		// q is 'Y' or 'N' to let p=1 or p=0 to judge whether to continue.
		int i,a,b,c,A,B;
		// a,b,c are 3 numbers that the user inputed, i is used to cauculate the times.
		// A and B have the same means as the question mentions.
		A=B=i=0;
		cout << "Do you want to play the game?(Y/N)";
		// input 'Y' or 'N'
		cin >> q;
		if (q == 'Y')
		{
			int num1,num2,num3;
			// This 3 numbers are random numbers.
			// Since the user plays the game, we have to let total_play + 1.
			total_play += 1;
			// Get the srand
			srand (time (NULL));
			// find 2 numbers.
			num1 = (rand()) % 9 + 1;
			num2 = (rand()) % 9 + 1;
			// if num2 == num1, get another num2, until it doesn't equal to num1
			while (num2 == num1)
			{
				srand (time(NULL));
			    num2  = (rand()) % 9 + 1;
		    }
		    // Get num3
			num3 = (rand())% 9 + 1;
			// if num3 == num2 or num1, get another num3, until it doesn't equal to num1 nor num2
			while (num3 == num2 or num3 == num1)
			{
				srand (time(NULL));
			    num3 = (rand())% 9 + 1;				
			}
			// This part let user guess and judge it.
			cout<<num1<<num2<<num3<<endl;
			while (i<=7)
			{
				// If i==7, that means the user has already guessed 7 times without get 3A, so he lose.
				if (i == 7) 
	    		{
		    		cout << "you lose!! The numbers are" << a << " " << b << " " << c << endl;
		    		break;
		        }
		        else
		        {
				// refresh A and B.
				A = B = 0;
				// time(i) plus 1.
				i += 1;
				// input the number you guessed.
			    cout << "input your number" << endl;
			    cin >> a >> b >> c;
			    // only if 2 ints(a,b) are equal can (a/b)*(b/a)=1, we use this to find A.
			    A = (num1 / a) * (a / num1) + (num2 / b) * (b / num2) + (num3 / c) * (c / num3) ;
			    // find B
			    B = (num1 / b) * (b / num1) + (num1 / c) * (c / num1) + (num2 / a) * (a / num2) + (num2 / c) * (c / num2) + (num3 / a) * (a / num3) + (num3 / b) * (b / num3);
			    // judge whether the user wins and give him A and B
				if (A == 3) 
				{
					// when A == 3, you win, win_time plus 1
			    	win_time += 1;
			    	cout << "you win!!" << endl;
			    	break;
			    }
			    else 
				{
					// give the user the right answer
			    	cout << A << "A" << B << "B" << endl;
				}
					
				}
				
		    }
		}
		else break;
	}
	// this sentence will appear when the user input 'N', so we let him know how many times he played and how many times he won.
	cout << "you have totally played " << total_play << " games,and win " << win_time <<" games."<<endl;
	return 0;
 } 
