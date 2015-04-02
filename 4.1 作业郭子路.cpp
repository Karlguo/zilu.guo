#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    // this 3 integers are used to calculate your result.
    int win_game = 0, lose_game = 0, equal_game = 0;
    
    // this array is used to represent the 52 cards, we times 2 to each card so it can become integer and we can calculate it easily.
	int card_list [4] [13] { {2,4,6,8,10,12,14,16,18,20,1,1,1} , {2,4,6,8,10,12,14,16,18,20,1,1,1} , {2,4,6,8,10,12,14,16,18,20,1,1,1} , {2,4,6,8,10,12,14,16,18,20,1,1,1} };

	// this while-loop with choice1 is used to judge whether the player want to start a new game.
	while (true)
	{
        char choice1;
        
        //sum is player's sum, com_sum is computer's sum.
	    double sum = 0,com_sum=0;
	    
	    //win_or_lose is used to judge if the player has win or lose.
		int win_or_lose = 0;
		
		//this is the array for suit(hua se) the player has ever chose.
	    int suitlist [50] {0};
	    
	    //this is the array for card(dian shu) the player has ever chose.
	    int cardlist [50] {0};
	    
	    //these 2 are suit and card for computers.
	    int com_suitlist [50] {0};
	    int com_cardlist [50] {0};
	    
	    //ask for whether the player want to play.
	    cout << "do you want to play the game?";

		//judge whether the input is legal.
		while (true)
		{
			cin >> choice1;
			
			// cleat buffer.
			cin.clear();
			cin.sync();
			
			if (choice1 == 'Y' || choice1 == 'y' || choice1 == 'N' || choice1 == 'n') break;
			else cout << "please input the right choice" << endl;
		}
	    
	    // the main program starts here.
	    if (choice1 == 'y' || choice1=='Y')
	    {
	    	// different enemys have different judgement about whether continue to take cards
	    	char enemy;
			cout << "please choose your enermy" <<endl;
			cout << "E=e=easy" << endl;
			cout << "M=m=middle" << endl;
			cout << "H=h=hard" <<endl;
			
			// judge whether the input is legal
			while (true)
			{
				cin >>enemy;
				
				// clear buffer.
				cin.clear();
				cin.sync();
				
				if (enemy == 'E' || enemy == 'e' || enemy == 'M' || enemy == 'm' || enemy == 'H' || enemy == 'h') break;
				else cout << "please input the right enemy" << endl;
			}
				
			// times represents how many time you have chosen to get a new card.
	    	int times = 0;
	    	
	    	// this array use to judge whether the random card is in the stack of remaining cards, 1 represents it is, 0 represents it isn't.
	    	int chosen_card [4] [13] {{1,1,1,1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1,1,1,1}};
	    	
		    while (true)
		    {
			    
			    // suit is (hua se) card is (dian shu), k and l will be used in the following for-loop.
		    	int suit , card , k = 0 , l = 0;
		    	
		    	// each time get a new card, times + 1.
		    	times += 1;
		    	
		    	// judge whether the card is in the stack of remaining cards.
		    	while (true)
		    	{
		    		srand (time(NULL));
			    	suit = rand() % 4;
		    	    card = rand() % 13;
		    	    
		    	    // only it is in the stack can we take it.
                    if (chosen_card[suit][card] == 1) break;
				}
				
				// put the new-get card in 2 lists for the following display.
				suitlist[times-1] = suit;
				cardlist[times-1] = card;
				
				// add the number on the card, and take it from the stack (let the position that represents it become 0).
		    	sum += card_list [suit] [card];
		    	chosen_card[suit][card] = 0;
		    	
		    	// first get 2 cards
		    	if (times >= 2)
		    	{
		    		
		    		// next part will show all cards you have and the sum of them.
		    		cout << "your cards are " << endl;
		    	
		    		// get l for circulate.
		    		for (l = 0; l<=times-1; ++l)
		    		{
		    		
		    			// suit1 and card1 means different cards in different loops
		    			int suit1 = 0 ,card1 = 0;
		    			
		    			// get the card from the list we created before.
		    			suit1 = suitlist[l];
		    			card1 = cardlist[l];
		    		
		    			// now, input the suit.
		    		    switch (suit1)
		    		    {
		    			    case 0 : cout << "spade "  ; break;
		    			    case 1 : cout << "heart "  ; break;
		    			    case 2 : cout << "club "   ; break;
		    			    case 3 : cout << "diamond "; break;
		    			    default: break ;
			   	 	}
			    		
			   		 	// input the card.
			    		if ( 1 <= card1 and card1 <= 9) cout << card1 + 1;
					    else
					    {
						    switch (card1)
						    { 
						    	case 0  : cout << 'A'; break;
							    case 10 : cout << 'J'; break;
							    case 11 : cout << 'Q'; break;
							    case 12 : cout << 'K'; break;
							    default : break ;
						    }
				   		}
		    	    	cout << endl ;
		    	    }
		        
		   		    // calculate the sum.
		    	    cout << "your sum is" << sum / 2 << endl;
		        
		    	    // if sum > 21 (we times 2 so it is 42 here).
		    		if (sum > 42) 
					{
            	    win_or_lose = -1;
            	    cout << "your sum is larger than 21! you lose!" << endl;
           	    	lose_game += 1;
					break;
			    	}
			    	
			    	// if your sum is 21, show this sentence.
			    	if (sum == 42)
			    	{
			    		cout << "your sum is exactly 21!!" << endl;
			    		break;
					}

			    	// ask whether want another card.
		    		char choice2;
	            	cout << "Do you want more cards?";
	            
	            	// avoid mistake.
	            	while (true)
					{
						cin >> choice2;
					
						// clear buffer.
						cin.clear();
						cin.sync();
						if (choice2 == 'Y' || choice2 == 'y' || choice2 == 'N' || choice2 == 'n') break;
						else cout << "please input the right choice" << endl;
					}
				
					// input n to end.
	            	if (choice2 == 'n' || choice2== 'N') break;
	            }
		    }
		    
		    cout << endl;
		    cout << "your turn ended" << endl;
		    cout <<endl;
		    
		    // if you lose, computer don't need to play the game.
		    if (win_or_lose != -1)
			{
			    
			    // show you your result.
				cout << "your result is " << sum/2 << endl;
		    	cout << "now wait the computer" << endl;
		    
		    
		    	// almost same with human-part, I add 'com' in front of every varities.
		   		int com_times = 0;
		   		int chosen_card [4] [13] {{1,1,1,1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1,1,1,1}};	
		    	while (true)
		    	{	
		    		int com_suit , com_card , k = 0 , l = 0 ;
		    		com_times += 1;
		    		while (true)
		    		{
		    			srand (time(NULL));
			    		com_suit = rand() % 4;
		    	    	com_card = rand() % 13;

						if (chosen_card[com_suit][com_card] == 1) break;
					}
					com_suitlist[com_times-1] = com_suit;
					com_cardlist[com_times-1] = com_card;
				
		    		com_sum += card_list [ com_suit ]  [ com_card ];
		    		chosen_card [com_suit][com_card] = 0;
		    		
		    		if (com_times >= 2)
		    		{
					
		    			cout << "the computer's cards are " << endl;
		    			for (l = 0; l<=com_times-1; ++l)
		    			{
		    				int com_suit1,com_card1;
		    				
		    				com_suit1=com_suitlist[l];
		    				com_card1=com_cardlist[l];
		    				
		    	    		switch (com_suit1)
		    	    		{
		    			    	case 0 : cout << "spade "  ; break;
		    			    	case 1 : cout << "heart "  ; break;
		    			    	case 2 : cout << "club "   ; break;
		    			    	case 3 : cout << "diamond "; break;
		    			    	default: break ;
			    			}
			    			if ( 1 <= com_card1 and com_card1 <= 9) cout << com_card1 + 1;
				    		else
				   		 	{
						    	switch (com_card1)
					    		{ 
					    			case 0  : cout << "A"; break;
							   		case 10 : cout << "J"; break;
							    	case 11 : cout << "Q"; break;
							    	case 12 : cout << "K"; break;
							    	default : break ;
					    		}
				    		}
		    	    		cout << endl ;
		        		}
		        		
		        		cout << "computer's sum is" << com_sum/2 << endl;
		        		
		    			if (com_sum > 42) 
						{
						win_or_lose = 1;
						cout << "computer's sum is larger than 21! you win!" << endl;
						win_game += 1;
						break;
					    
					    if  (com_sum == 21)
					    {
					    	cout << "the computer's sum is exactly 21!!!";
						}
						
						// this is the difference between different levels.
			    		}
			    		if (enemy == 'E' || enemy == 'e') 
			    		{
			    			if (com_sum >= 26) break;
						}
					
			    		if (enemy == 'M' || enemy == 'm') 
			    		{
			    			if (com_sum >= 32) break;
						}
					
			    		if (enemy == 'H' || enemy == 'h') 
			    		{
			    			if (com_sum > sum ) break;
						}
					}

	        	}
	        	
	        	cout << endl;
	        	cout << "the computer's turn ended" << endl;
	        	cout << endl;
	        	
	        // if the player or the computer's sum is over 21, we don't need to judge it again.	
	    	if (win_or_lose == 0)
	    	{
	    		cout << "your sum is " << sum/2 << endl;
	    		cout << "computer's sum is " << com_sum/2 << endl;
	    		
	    		if (sum <  com_sum) 
	    		{
				cout << "your sum is smaller than computer's, you lose!" << endl;
				lose_game += 1;
				}
				
	    		if (sum ==  com_sum) 
	    		{
	    			
	    			if (times < com_times)
	    			{
	    				cout << "your sum is equal to computer's, but the number of your cards is smaller than computer's, you lose!!" << endl;
	    				lose_game += 1;
					}
					
					if (times > com_times)
	    			{
	    				cout << "your sum is equal to computer's, but the number of your cards is larger than computer's, you win!!" << endl;
	    				win_game += 1;
					}
					
	    			if (times == com_times)
	    			{
	    				cout << "your sum is equal to computer's, and the number of your cards is eqaul to computer's, eqaul!!" << endl;
	    				equal_game += 1;
					}					
				}
				
	    		if (sum > com_sum) 
	    		{
				cout << "your sum is larger than computer's, you win!" << endl;
				win_game += 1;
				}
			}
			
			
	    	}
    			
    	}
	    else break;
    }
    // output the statistical data.
    cout << "you have won " << win_game << " times, lost " << lose_game << " times and be equal to the computer " << equal_game << " times in " << win_game + lose_game + equal_game << " games" << endl;
    return 0;
}



