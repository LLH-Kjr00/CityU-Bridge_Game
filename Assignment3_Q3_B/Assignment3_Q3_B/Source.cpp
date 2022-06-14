#include<iostream>
#include<cstring>
using namespace std;
class Card
{
public:
	Card() {};
	void setSuit(char* n)
	{
		suit = n;
	};
	void setValue(int v)
	{
		value = v;
	};
	void setNum(int num)
	{
		number = num;
	};
	void setcheck()
	{
		check = 1;
	};
	char* getSuit()
	{
		return suit;
	};
	int getVal()
	{
		return value;
	}
	int getNum()
	{
		return number;
	}
	bool getcheck()
	{
		return check;
	}
private:
	int value, number;
	char* suit;
	bool check = 0; // whether the card has been played
};

void initSequence(Card* cardSeq, char suitName[][10], int* j, int* num);
void printSequence(Card* cardSeq);
void printCard(Card card);
void printLine(int rnd);
int* p_chooseCard_1st(Card* cardSeq, int* v, int* n);
int* c_chooseCard_2nd(Card* cardSeq, int* v);
int* c_chooseCard_1st(Card* cardSeq);
int* p_chooseCard_2nd(Card* cardSeq, int* c_v, int*c_n, int*v, int* n);



int main() {
	int rnd = 1, p_win = 0, c_win = 0;
	bool state = true;
	int player = 0, computer = 0;
	Card cardSeq[13];
	Card ComcardSeq[13];  //card sequence for the computer
	char suitName[][10] = { "Heart","Diamond","Club","Spade" };
	int seed;
	cout << "Enter the seed for random number generation: ";
	cin >> seed;
	int j[13];
	int num[13];
	switch (seed) {
	case 1:
		j[0] = 4; j[1] = 3; j[2] = 2, j[3] = 1, j[4] = 1, j[5] = 2; j[6] = 4; j[7] = 3; j[8] = 3; j[9] = 2; j[10] = 2; j[11] = 2; j[12] = 3;
		num[0] = 12; num[1] = 11; num[2] = 10; num[3] = 11; num[4] = 4; num[5] = 11; num[6] = 11; num[7] = 13; num[8] = 3; num[9] = 7; num[10] = 2; num[11] = 5; num[12] = 9;
		break;
	case 2:
		j[0] = 2; j[1] = 2; j[2] = 3, j[3] = 1, j[4] = 3, j[5] = 4; j[6] = 4; j[7] = 4; j[8] = 3; j[9] = 4; j[10] = 4; j[11] = 2; j[12] = 4;
		num[0] = 3; num[1] = 5; num[2] = 7; num[3] = 8; num[4] = 11; num[5] = 4; num[6] = 10; num[7] = 2; num[8] = 12; num[9] = 9; num[10] = 11; num[11] = 12; num[12] = 3;
		break;
	case 3:
		j[0] = 4; j[1] = 3; j[2] = 2, j[3] = 1, j[4] = 2, j[5] = 4; j[6] = 2; j[7] = 1; j[8] = 3; j[9] = 3; j[10] = 3; j[11] = 1; j[12] = 3;
		num[0] = 11; num[1] = 10; num[2] = 10; num[3] = 10; num[4] = 1; num[5] = 13; num[6] = 7; num[7] = 7; num[8] = 9; num[9] = 6; num[10] = 12; num[11] = 4; num[12] = 11;
		break;
	case 4:
		j[0] = 4; j[1] = 4; j[2] = 2, j[3] = 1, j[4] = 3, j[5] = 3; j[6] = 3; j[7] = 1; j[8] = 1; j[9] = 3; j[10] = 4; j[11] = 4; j[12] = 4;
		num[0] = 10; num[1] = 7; num[2] = 9; num[3] = 4; num[4] = 10; num[5] = 12; num[6] = 3; num[7] = 13; num[8] = 5; num[9] = 13; num[10] = 4; num[11] = 1; num[12] = 11;
		break;
	case 5:
		j[0] = 4; j[1] = 3; j[2] = 3, j[3] = 4, j[4] = 4, j[5] = 2; j[6] = 3; j[7] = 4; j[8] = 1; j[9] = 1; j[10] = 1; j[11] = 1; j[12] = 1;
		num[0] = 5; num[1] = 4; num[2] = 13; num[3] = 1; num[4] = 3; num[5] = 7; num[6] = 12; num[7] = 11; num[8] = 10; num[9] = 13; num[10] = 7; num[11] = 5; num[12] = 4;
		break;
	case 6:
		j[0] = 3; j[1] = 4; j[2] = 4, j[3] = 4, j[4] = 1, j[5] = 4; j[6] = 2; j[7] = 1; j[8] = 3; j[9] = 4; j[10] = 4; j[11] = 3; j[12] = 3;
		num[0] = 7; num[1] = 3; num[2] = 11; num[3] = 4; num[4] = 13; num[5] = 2; num[6] = 12; num[7] = 10; num[8] = 3; num[9] = 10; num[10] = 6; num[11] = 10; num[12] = 9;
		break;
	case 7:
		j[0] = 2; j[1] = 1; j[2] = 4, j[3] = 4, j[4] = 1, j[5] = 2; j[6] = 1; j[7] = 4; j[8] = 3; j[9] = 2; j[10] = 4; j[11] = 4; j[12] = 2;
		num[0] = 5; num[1] = 3; num[2] = 1; num[3] = 9; num[4] = 4; num[5] = 12; num[6] = 11; num[7] = 2; num[8] = 12; num[9] = 2; num[10] = 11; num[11] = 13; num[12] = 9;
		break;
	case 8:
		j[0] = 3; j[1] = 1; j[2] = 4, j[3] = 2, j[4] = 4, j[5] = 4; j[6] = 1; j[7] = 2; j[8] = 4; j[9] = 1; j[10] = 3; j[11] = 2; j[12] = 4;
		num[0] = 3; num[1] = 8; num[2] = 2; num[3] = 11; num[4] = 3; num[5] = 9; num[6] = 5; num[7] = 2; num[8] = 5; num[9] = 4; num[10] = 12; num[11] = 10; num[12] = 7;
		break;
	case 9:
		j[0] = 4; j[1] = 3; j[2] = 2, j[3] = 3, j[4] = 2, j[5] = 3; j[6] = 4; j[7] = 4; j[8] = 3; j[9] = 3; j[10] = 1; j[11] = 2; j[12] = 1;
		num[0] = 11; num[1] = 12; num[2] = 12; num[3] = 4; num[4] = 10; num[5] = 7; num[6] = 6; num[7] = 1; num[8] = 6; num[9] = 13; num[10] = 13; num[11] = 5; num[12] = 4;
		break;
	case 10:
		j[0] = 3; j[1] = 3; j[2] = 4, j[3] = 4, j[4] = 2, j[5] = 4; j[6] = 3; j[7] = 2; j[8] = 4; j[9] = 2; j[10] = 2; j[11] = 3; j[12] = 1;
		num[0] = 10; num[1] = 6; num[2] = 7; num[3] = 12; num[4] = 9; num[5] = 6; num[6] = 11; num[7] = 11; num[8] = 5; num[9] = 5; num[10] = 1; num[11] = 13; num[12] = 4;
		break;
	case 11:
		j[0] = 1; j[1] = 2; j[2] = 1, j[3] = 4, j[4] = 1, j[5] = 3; j[6] = 4; j[7] = 2; j[8] = 1; j[9] = 4; j[10] = 3; j[11] = 4; j[12] = 3;
		num[0] = 11; num[1] = 2; num[2] = 4; num[3] = 5; num[4] = 13; num[5] = 3; num[6] = 7; num[7] = 7; num[8] = 3; num[9] = 1; num[10] = 12; num[11] = 10; num[12] = 4;
		break;
	case 12:
		j[0] = 1; j[1] = 1; j[2] = 3, j[3] = 4, j[4] = 4, j[5] = 4; j[6] = 3; j[7] = 2; j[8] = 1; j[9] = 4; j[10] = 2; j[11] = 1; j[12] = 2;
		num[0] = 3; num[1] = 4; num[2] = 3; num[3] = 4; num[4] = 5; num[5] = 13; num[6] = 11; num[7] = 11; num[8] = 5; num[9] = 2; num[10] = 5; num[11] = 13; num[12] = 12;
		break;
	case 13:
		j[0] = 3; j[1] = 4; j[2] = 4, j[3] = 4, j[4] = 1, j[5] = 3; j[6] = 1; j[7] = 2; j[8] = 2; j[9] = 1; j[10] = 2; j[11] = 4; j[12] = 4;
		num[0] = 10; num[1] = 10; num[2] = 5; num[3] = 6; num[4] = 7; num[5] = 9; num[6] = 8; num[7] = 10; num[8] = 2; num[9] = 11; num[10] = 12; num[11] = 4; num[12] = 2;
		break;
	case 14:
		j[0] = 2; j[1] = 1; j[2] = 2, j[3] = 2, j[4] = 3, j[5] = 4; j[6] = 1; j[7] = 2; j[8] = 4; j[9] = 1; j[10] = 2; j[11] = 1; j[12] = 4;
		num[0] = 7; num[1] = 13; num[2] = 12; num[3] = 1; num[4] = 6; num[5] = 1; num[6] = 7; num[7] = 2; num[8] = 2; num[9] = 4; num[10] = 5; num[11] = 5; num[12] = 9;
		break;
	case 15:
		j[0] = 3; j[1] = 3; j[2] = 2, j[3] = 4, j[4] = 4, j[5] = 1; j[6] = 2; j[7] = 4; j[8] = 3; j[9] = 4; j[10] = 3; j[11] = 2; j[12] = 2;
		num[0] = 7; num[1] = 10; num[2] = 3; num[3] = 9; num[4] = 12; num[5] = 5; num[6] = 1; num[7] = 5; num[8] = 6; num[9] = 3; num[10] = 3; num[11] = 9; num[12] = 2;
		break;
	case 16:
		j[0] = 4; j[1] = 4; j[2] = 4, j[3] = 4, j[4] = 4, j[5] = 2; j[6] = 4; j[7] = 1; j[8] = 2; j[9] = 2; j[10] = 4; j[11] = 3; j[12] = 2;
		num[0] = 5; num[1] = 9; num[2] = 2; num[3] = 11; num[4] = 3; num[5] = 7; num[6] = 1; num[7] = 4; num[8] = 12; num[9] = 9; num[10] = 12; num[11] = 7; num[12] = 10;
		break;
	case 17:
		j[0] = 4; j[1] = 3; j[2] = 3, j[3] = 3, j[4] = 4, j[5] = 4; j[6] = 3; j[7] = 4; j[8] = 2; j[9] = 1; j[10] = 3; j[11] = 2; j[12] = 1;
		num[0] = 9; num[1] = 13; num[2] = 9; num[3] = 12; num[4] = 6; num[5] = 10; num[6] = 7; num[7] = 4; num[8] = 10; num[9] = 13; num[10] = 6; num[11] = 8; num[12] = 4;
		break;
	case 18:
		j[0] = 3; j[1] = 3; j[2] = 3, j[3] = 3, j[4] = 1, j[5] = 3; j[6] = 3; j[7] = 4; j[8] = 2; j[9] = 1; j[10] = 4; j[11] = 2; j[12] = 2;
		num[0] = 3; num[1] = 4; num[2] = 12; num[3] = 9; num[4] = 11; num[5] = 13; num[6] = 11; num[7] = 4; num[8] = 12; num[9] = 4; num[10] = 13; num[11] = 5; num[12] = 9;
		break;
	case 19:
		j[0] = 2; j[1] = 1; j[2] = 1, j[3] = 3, j[4] = 1, j[5] = 4; j[6] = 2; j[7] = 3; j[8] = 4; j[9] = 4; j[10] = 4; j[11] = 2; j[12] = 2;
		num[0] = 2; num[1] = 4; num[2] = 13; num[3] = 13; num[4] = 5; num[5] = 1; num[6] = 5; num[7] = 3; num[8] = 2; num[9] = 4; num[10] = 5; num[11] = 12; num[12] = 7;
		break;
	case 20:
		j[0] = 2; j[1] = 3; j[2] = 3, j[3] = 4, j[4] = 4, j[5] = 1; j[6] = 2; j[7] = 3; j[8] = 2; j[9] = 2; j[10] = 4; j[11] = 3; j[12] = 2;
		num[0] = 7; num[1] = 3; num[2] = 9; num[3] = 13; num[4] = 9; num[5] = 3; num[6] = 9; num[7] = 10; num[8] = 5; num[9] = 3; num[10] = 3; num[11] = 13; num[12] = 1;
		break;
	}
	// TODO: generate and print card sequence for the player
	initSequence(cardSeq, suitName, j, num);
	cout << "Your card sequence:" << endl;
	printSequence(cardSeq);
	j[0] = 1; j[1] = 3; j[2] = 1, j[3] = 2, j[4] = 4, j[5] = 1; j[6] = 3; j[7] = 2; j[8] = 3; j[9] = 1; j[10] = 1; j[11] = 2; j[12] = 3;
	num[0] = 12; num[1] = 8; num[2] = 9; num[3] = 6; num[4] = 8; num[5] = 1; num[6] = 1; num[7] = 13; num[8] = 2; num[9] = 6; num[10] = 2; num[11] = 4; num[12] = 5;
	//generate card sequence for the computer
	initSequence(ComcardSeq, suitName, j, num);
	cout << "Computer's card sequence:" << endl;
	printSequence(ComcardSeq);
	while (rnd !=14)
	{
		int p_v, p_n;
		int c_valid,c_show, c_value,c_number;
		int p_valid, p_value, p_number;
		int *c_arr = NULL, *p_arr =NULL;
		printLine(rnd);
		rnd++;
		if (state == true)
		{
			do
			{
				cout << "Please input two integers to represent the card you plan to play: ";
				cin >> p_v >> p_n;
				p_arr = p_chooseCard_1st(cardSeq, &p_v, &p_n);
				p_valid = p_arr[0];
				p_value = p_arr[1];
				p_number = p_arr[2];
				if (p_valid == 0)
				{
					cout << "Selected card is not in card squence" << endl;
				}
				else if (p_valid == -1)
				{
					cout << "Playing against the rules." << endl;
				}
			} while (p_valid <= 0);
			c_arr = c_chooseCard_2nd(ComcardSeq, &p_v);
			c_value = c_arr[1];
			c_number = c_arr[2];
			c_show = c_arr[3];
			cout << "The computer plays ";
			printCard(ComcardSeq[c_show]);
			cout << endl;
		}
		else if (state == false)
		{
			c_arr = c_chooseCard_1st(ComcardSeq);
			c_value = c_arr[1];
			c_number = c_arr[2];
			c_show = c_arr[3];
			cout << "The computer plays ";
			printCard(ComcardSeq[c_show]);
			cout << endl;
			do
			{
				cout << "Please input two integers to represent the card you plan to play: ";
				cin >> p_v >> p_n;
				p_arr = p_chooseCard_2nd(cardSeq, &c_value, &c_number ,&p_v, &p_n);
				p_valid = p_arr[0];
				p_value = p_arr[1];
				p_number = p_arr[2];
				if (p_valid == 0)
				{
					cout << "Selected card is not in card squence" << endl;
				}
				else if (p_valid == -1)
				{
					cout << "Playing against the rules." << endl;
				}
			} while (p_valid <= 0);
		}
		
		if (p_value > c_value)
		{
			cout << "Player won this round" << endl;
			player++;
			state = true;
		}
		else if (p_value < c_value)
		{
			cout << "Computer won this round" << endl;
			computer++;
			state = false;
		}
		else if (p_value == c_value)
		{
			if (p_number > c_number)
			{
				cout << "Player won this round" << endl;
				player++;
				state = true;
			}
			else if (p_number < c_number)
			{
				cout << "Computer won this round" << endl;
				computer++;
				state = false;
			}
			else if (p_number == c_number)
			{
				if (state == true)
				{
					cout << "Player won this round" << endl;
					player++;
					state = true;
				}
				else if (state == false)
				{
					cout << "Computer won this round" << endl;
					computer++;
					state = false;
				}
			}
		}
		cout << "Your card sequence:" << endl;
		printSequence(cardSeq);
		//cout << "COM sequence:" << endl;
		//printSequence(ComcardSeq);
	}
	cout << "Player got " << player << " points, Computer got " << computer << " points" << endl;
	if (player > computer)
	{
		cout << "Player win" << endl;
	}
	else if (player < computer)
	{
		cout << "Computer win" << endl;
	}
	else if (player == computer)
	{
		cout << "Draw" << endl;
	}
	return 0;
}
void initSequence(Card* cardSeq, char suitName[][10], int* j, int* num) {
	for (int i = 0; i < 13; i++) {
		cardSeq[i].setSuit(suitName[j[i] - 1]);
		cardSeq[i].setValue(j[i]);
		cardSeq[i].setNum(num[i]);
	}
}
void printSequence(Card* cardSeq) {
	for (int i = 0; i < 13; i++) {
		if (cardSeq[i].getcheck() == 0)
			printCard(cardSeq[i]);
	}
	cout << endl;
}
void printCard(Card card) {
	if (card.getNum() == 1)
		cout << card.getSuit() << 'A' << " ";
	else if (card.getNum() == 11)
		cout << card.getSuit() << 'J' << " ";
	else if (card.getNum() == 12)
		cout << card.getSuit() << 'Q' << " ";
	else if (card.getNum() == 13)
		cout << card.getSuit() << 'K' << " ";
	else
		cout << card.getSuit() << card.getNum() << " ";
}
void printLine(int rnd)
{
	cout << "========== " << " Round " << rnd << " ==========" << endl;
}
int* p_chooseCard_1st(Card* cardSeq,int* v, int*n)
{
	int p_arr[3];
	p_arr[0] = 0;
	for (int i = 0; i < 13; i++)
	{
		if (cardSeq[i].getVal() == *v && cardSeq[i].getNum() == *n)
		{
			if (cardSeq[i].getcheck() == 1)
			{
				p_arr[0] = 0;
				return p_arr;
			}
			else
			{
				cardSeq[i].setcheck();
				p_arr[0] = 1;
				if (cardSeq[i].getNum() == 1)
				{
					p_arr[1] = cardSeq[i].getVal();
					p_arr[2] = 14;
					return p_arr;
				}
				else
				{
					p_arr[1] = cardSeq[i].getVal();
					p_arr[2] = cardSeq[i].getNum();
					return p_arr;
				}
				p_arr[1] = 0;
				p_arr[2] = 1;
			}
		}
	}
	return p_arr;
}
int* c_chooseCard_2nd(Card* cardSeq, int*v)
{
	int c_arr[4];
	int c_v = 0, c_n, result = 0;
	int pos = 0;
	bool found = false;

	for (int i = 0; i != 13; i++)
	{
		if (cardSeq[i].getVal() == *v)
		{
			if (cardSeq[i].getcheck() == 1)
			{
				continue;
			}
			else
			{
				found = true;
				
				if (cardSeq[i].getNum() == 1)
				{
					c_n = 14;
				}
				else
				{
					c_n = cardSeq[i].getNum();
				}
				if (c_n > result)
				{
					c_v = *v;
					pos = i;
					result = c_n;
				}
			}
			
		}
	}
	if (found == true)
	{
		cardSeq[pos].setcheck();
		c_arr[0] = 1;
		c_arr[1] = c_v;
		c_arr[2] = result;
		c_arr[3] = pos;
		return c_arr;
	}
	else
	{
		result = 14, c_v =4;
		for (int i = 0; i != 13; i++)
		{
			if (cardSeq[i].getcheck() == 1)
			{
				continue;
			}
			else
			{
				if (cardSeq[i].getNum() == 1)
				{
					c_n = 14;
				}
				else
				{
					c_n = cardSeq[i].getNum();
				}
				if (c_n < result)
				{
					c_v = cardSeq[i].getVal();
					pos = i;
					result = c_n;
				}
			}
		}
		cardSeq[pos].setcheck();
		c_arr[0] = 1;
		c_arr[1] = c_v;
		c_arr[2] = result;
		c_arr[3] = pos;
		return c_arr;
	}
}
int* c_chooseCard_1st(Card* cardSeq)
{
	int arr[4];
	int c_v = 0, c_n, result = 0;
	int pos;
	bool found = false;

	for (int i = 0; i != 13; i++)
	{
			if (cardSeq[i].getcheck() == 1)
			{
				continue;
			}
			else
			{
				found = true;
				if (cardSeq[i].getNum() == 1)
				{
					c_n = 14;
				}
				else
				{
					c_n = cardSeq[i].getNum();
				}
				if (c_n > result)
				{
					pos = i;
					c_v = cardSeq[i].getVal();
					result = c_n;
				}
			}
	}
	if (found == true)
	{
		cardSeq[pos].setcheck();
		arr[0] = 1;
		arr[1] = c_v;
		arr[2] = result;
		arr[3] = pos;
		return arr;
	}
}
int* p_chooseCard_2nd(Card* cardSeq, int* c_v, int* c_n, int* v, int* n)
{
	int p_arr[3];
	p_arr[0] = 0;
	for (int i = 0; i < 13; i++)
	{
		if (cardSeq[i].getVal() == *v && cardSeq[i].getNum() == *n)
		{
			if (*v == *c_v)
			{
				if (cardSeq[i].getcheck() == 1)
				{
					p_arr[0] = 0;
					return p_arr;
				}
				else
				{
					cardSeq[i].setcheck();
					p_arr[0] = 1;
					if (cardSeq[i].getNum() == 1)
					{
						p_arr[2] = 14;
					}
					else
					{
						p_arr[2] = cardSeq[i].getNum();
					}
					p_arr[1] = cardSeq[i].getVal();
					return p_arr;
				}
			}
			else
			{
				if (cardSeq[i].getcheck() == 1)
				{
					p_arr[0] = 0;
					return p_arr;
				}
				else
				{
					for (int j = 0; j < 13; j++)
					{
						if (cardSeq[j].getcheck() == 0 && cardSeq[j].getVal() == *c_v)
						{
							p_arr[0] = -1;
							return p_arr;
						}
					}
					cardSeq[i].setcheck();
					p_arr[0] = 1;
					p_arr[1] = 0;
					p_arr[2] = 1;
					return p_arr;
				}
			}
		}
	}
	return p_arr;
}