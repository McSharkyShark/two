#pragma once
#include <iostream>
using namespace std;

//Title
void title()
{
	cout << "        CCCCCCCCCCCCChhhhhhh                                                                    \n";
	cout << "     CCC::::::::::::Ch:::::h                                                                    \n";
	cout << "   CC:::::::::::::::Ch:::::h                                                                    \n";
	cout << "  C:::::CCCCCCCC::::Ch:::::h                                                                    \n";
	cout << " C:::::C       CCCCCC h::::h hhhhh           eeeeeeeeeeee        ssssssssss       ssssssssss    \n";
	cout << "C:::::C               h::::hh:::::hhh      ee::::::::::::ee    ss::::::::::s    ss::::::::::s   \n";
	cout << "C:::::C               h::::::::::::::hh   e::::::eeeee:::::eess:::::::::::::s ss:::::::::::::s  \n";
	cout << "C:::::C               h:::::::hhh::::::h e::::::e     e:::::es::::::ssss:::::ss::::::ssss:::::s \n";
	cout << "C:::::C               h::::::h   h::::::he:::::::eeeee::::::e s:::::s  ssssss  s:::::s  ssssss  \n";
	cout << "C:::::C               h:::::h     h:::::he:::::::::::::::::e    s::::::s         s::::::s       \n";
	cout << "C:::::C               h:::::h     h:::::he::::::eeeeeeeeeee        s::::::s         s::::::s    \n";
	cout << " C:::::C       CCCCCC h:::::h     h:::::he:::::::e           ssssss   s:::::s ssssss   s:::::s  \n";
	cout << "  C:::::CCCCCCCC::::C h:::::h     h:::::he::::::::e          s:::::ssss::::::ss:::::ssss::::::s \n";
	cout << "   CC:::::::::::::::C h:::::h     h:::::h e::::::::eeeeeeee  s::::::::::::::s s::::::::::::::s  \n";
	cout << "     CCC::::::::::::C h:::::h     h:::::h  ee:::::::::::::e   s:::::::::::ss   s:::::::::::ss   \n";
	cout << "        CCCCCCCCCCCCC hhhhhhh     hhhhhhh    eeeeeeeeeeeeee    sssssssssss      sssssssssss     \n";

}

//Pieces
char pieces(int num)
{
	//Team 1
	if (num == 0)
	{
		return 'O';
	}
	else if(num==1)
	{
		return'P';
	}
	else if (num == 2)
	{
		return'R';
	}
	else if (num == 3)
	{
		return 'K';
	}
	else if (num == 4)
	{
		return 'B';
	}
	else if (num == 5)
	{
		return 'Q';
	}
	else if (num == 6)
	{
		return 'K';
	}
	//Team 2
	if (num == 10)
	{
		return 'O';
	}
	else if (num == 11)
	{
		return 'P';
	}
	else if (num == 12)
	{
		return 'R';
	}
	else if (num == 13)
	{
		return 'K';
	}
	else if (num == 14)
	{
		return 'B';
	}
	else if (num == 15)
	{
		return'Q';
	}
	else if (num == 16)
	{
		return 'K';
	}
}