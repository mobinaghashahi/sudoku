#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>
void table(char[][50]);
void show(char[][50], int, int);
void showlogic(int[][50], int, int);
void creat(char[][50], int[][50]);
int solve(int[][50], int, int);
void solve2(int[][50], int, int, char[][50]);
void solve3(int[][50], int, int, char[][50]);
void fill(int[][50], int, int, char[][50]);
void cros(int[][50], int, int, char[][50]);
void creattl(int[][50], int[][50]);
int check(int[][50], int, int);
void save(char[][50]);
void load(char[][50], int[][50]);
void numberofnumers(int[][50]);
void medadkari(int[][50], char[][50]);
void medadkari2(int[][50], char[][50]);
void fpartion(int[][50]);
void ghanonjoft(int[][50], char[][50]);
//چیزهایی که توی اون ناحیه از سودوکو میتونن قرار بگیرن(سطر،ستون،مربع).
int b[50][50][50], number = 0, partion[10][10];
using namespace std;
int main()
{
	int lr = 1, ud = 1, tlogic[50][50] = { 0 };
	char t[50][50];

	table(t);
	load(t, tlogic);
	//fill(tlogic, 1, 1, t);
	//ghanonjoft(tlogic, t);
	//showlogic(tlogic, lr, ud);
	/*fill(tlogic, 1, 1, t);
	medadkari2(tlogic, t);
	_getch();*/
	//cros(tlogic, 1, 1, t);
	creat(t, tlogic);
	showlogic(tlogic, 1, 2);
	_getch();
}
void table(char t[][50])
{
	int i, j;
	for (i = 0; i <11; i++)
		for (j = 0; j < 11; j++)
		{
			if (i == 0 || j == 0 || i == 10 || j == 10)
				t[i][j] = '#';
			else
				t[i][j] = ' ';
		}

}
void show(char t[][50], int lr, int ud)
{
	int i, j;
	for (i = 0; i <11; i++)
		for (j = 0; j < 11; j++)
		{
			if (lr == j&&ud == i)
				cout << "a";
			else
				cout << t[i][j];
			if (j == 10)
				cout << "\n";
		}
}
void creat(char t[][50], int tlogic[][50])
{
	int lr = 1, ud = 1, gir = 1;
	int s = 0;
	char dastor = 'q';
	while (dastor != 13)
	{
		dastor = _getch();
		switch (dastor)
		{
		case 'w':
			ud--;
			break;
		case 's':
			ud++;
			break;
		case 'd':
			lr++;
			break;
		case 'a':
			lr--;
			break;
		case '1':
			t[ud][lr] = '1';
			tlogic[ud][lr] = 1;
			break;
		case '2':
			t[ud][lr] = '2';
			tlogic[ud][lr] = 2;
			break;
		case '3':
			t[ud][lr] = '3';
			tlogic[ud][lr] = 3;
			break;
		case '4':
			t[ud][lr] = '4';
			tlogic[ud][lr] = 4;
			break;
		case '5':
			t[ud][lr] = '5';
			tlogic[ud][lr] = 5;
			break;
		case '6':
			t[ud][lr] = '6';
			tlogic[ud][lr] = 6;
			break;
		case '7':
			t[ud][lr] = '7';
			tlogic[ud][lr] = 7;
			break;
		case '8':
			t[ud][lr] = '8';
			tlogic[ud][lr] = 8;
			break;
		case '9':
			t[ud][lr] = '9';
			tlogic[ud][lr] = 9;
			break;
		case 8:
			t[ud][lr] = ' ';
			tlogic[ud][lr] = 0;
			break;
		case 'z':
			save(t);
			break;
		case '.':
			solve(tlogic, 1, 1);
			system("cls");
			dastor = 13;
			break;
		case ',':
			solve2(tlogic, 1, 1, t);
			system("cls");
			dastor = 13;
			break;
		case 'm':
			while (number < 81)
			{
				s = 1;
				number = 0;
				numberofnumers(tlogic);
				gir = number;
				fill(tlogic, 1, 1, t);
				/*cout << "partion\n";
				for (int ty = 1; ty <= 9; ty++)
				{
				for (int zx = 0; zx <= partion[ty][0]; zx++)
				cout << partion[ty][zx];
				cout << "\n";
				}
				_getch();*/
				/*for (int l = 1; l <= 9; l++)
				for (int x = 1; x <= 9; x++)
				{
				cout << s << " ";
				for (int z = 0; z <= b[l][x][0]; z++)
				cout<<b[l][x][z] << " ";
				cout << "\n";
				s++;
				}
				_getch();*/
				cros(tlogic, 1, 1, t);
				medadkari(tlogic, t);
				fill(tlogic, 1, 1, t);
				numberofnumers(tlogic);
				cout << "number= " << number << "\n";
				//showlogic(tlogic, 1, 1);
				/*if (gir == number)
				solve(tlogic, 1, 1);*/
				//_getch();

				system("cls");
			}
			_getch();
			dastor = 13;
			break;
		case 'n':
			numberofnumers(tlogic);
			system("cls");
			dastor = 13;
			break;
		case'r':
			table(t);
			break;
		}
		system("cls");
		show(t, lr, ud);
	}
}
int solve(int tlogic[][50], int i, int j)
{
	int answer;
	showlogic(tlogic, i, j);
	//cout << i << " " << j;
	//_getch();
	system("cls");
	if (check(tlogic, i, j) == 0 && tlogic[j][i] != 0)
	{
		//cout << "fuck";
		tlogic[j][i] = 0;
		return 0;
	}
	if (j == 9 && i == 9)
		return 1;
	if (i == 1 && tlogic[j][i] == 0)
		for (int q = 1; q <= 9; q++)
		{

			tlogic[j][i] = q;
			answer = solve(tlogic, i, j);
			if (answer == 1)
			{
				return 1;
			}
		}
	if ((tlogic[j][i + 1] == 0 && i != 9))
		for (int q = 1; q <= 9; q++)
		{
			tlogic[j][i + 1] = q;
			answer = solve(tlogic, i + 1, j);
			if (answer == 1)
			{
				return 1;
			}
		}
	else
		if (i == 9)
			solve(tlogic, 1, ++j);
		else
			solve(tlogic, ++i, j);
	return 0;
}
int check(int tlogic[][50], int i, int j)
{
	for (int s = 1; s <= 9; s++)
		if (tlogic[j][i] == tlogic[s][i] && j != s&&tlogic[j][i] != 0)
			return 0;
		else if (tlogic[j][i] == tlogic[j][s] && i != s&&tlogic[j][i] != 0)
			return 0;
	/*دستورات*/
	if (i <= 3 && j <= 3)
	{
		int u;
		for (int c = 1; c <= 3; c++)
		{
			for (u = 1; u <= 3; u++)
			{
				if (tlogic[j][i] == tlogic[c][u] && j != c&&i != u)
					return 0;
			}
		}
	}
	//2
	if (i >= 4 && i <= 6 && j <= 3)
	{
		int u;
		for (int c = 1; c <= 3; c++)
		{
			for (u = 4; u <= 6; u++)
			{
				if (tlogic[j][i] == tlogic[c][u] && j != c&&i != u)
					return 0;
			}

		}
	}
	//3
	if (i >= 7 && i <= 9 && j <= 3)
	{
		int u;
		for (int c = 1; c <= 3; c++)
		{
			for (u = 7; u <= 9; u++)
			{
				if (tlogic[j][i] == tlogic[c][u] && j != c&&i != u)
					return 0;
			}
		}
	}
	//4
	if (i <= 3 && j >= 4 && j <= 6)
	{
		int u;
		for (int c = 4; c <= 6; c++)
		{
			for (u = 1; u <= 3; u++)
			{
				if (tlogic[j][i] == tlogic[c][u] && j != c&&i != u)
					return 0;
			}

		}
	}
	//5
	if (i >= 4 && i <= 6 && j >= 4 && j <= 6)
	{
		int u;
		for (int c = 4; c <= 6; c++)
		{
			for (u = 4; u <= 6; u++)
			{
				if (tlogic[j][i] == tlogic[c][u] && j != c&&i != u)
					return 0;
			}
		}
	}
	//6
	if (i >= 7 && i <= 9 && j >= 4 && j <= 6)
	{
		int u;
		for (int c = 4; c <= 6; c++)
		{
			for (u = 7; u <= 9; u++)
			{
				if (tlogic[j][i] == tlogic[c][u] && j != c&&i != u)
					return 0;
			}
		}
	}
	//7
	if (i >= 1 && i <= 3 && j >= 7 && j <= 9)
	{
		int u;
		for (int c = 7; c <= 9; c++)
		{
			for (u = 1; u <= 3; u++)
			{
				if (tlogic[j][i] == tlogic[c][u] && j != c&&i != u)
					return 0;
			}
		}
	}
	//8
	if (i >= 4 && i <= 6 && j >= 7 && j <= 9)
	{
		int u;
		for (int c = 7; c <= 9; c++)
		{
			for (u = 4; u <= 6; u++)
			{
				if (tlogic[j][i] == tlogic[c][u] && j != c&&i != u)
					return 0;
			}
		}
	}
	//9
	if (i >= 7 && i <= 9 && j >= 7 && j <= 9)
	{
		int u;
		for (int c = 7; c <= 9; c++)
		{
			for (u = 7; u <= 9; u++)
			{
				if (tlogic[j][i] == tlogic[c][u] && j != c&&i != u)
					return 0;
			}
		}
	}
	return 1;
}
void save(char a[50][50])
{
	ofstream mobin("d:\\sodpcp.txt", ios::out);
	for (int i = 0; i<20; i++)
		for (int j = 0; j<40; j++)
		{
			if (a[i][j] == ' ')
				a[i][j] = '-';
			if (j == 39)
				a[i][j] = 'e';
			mobin << a[i][j];
		}
}
void load(char a[50][50], int b[50][50])
{
	fstream mobin1("d:\\sodpcp.txt", ios::in);
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 40; j++)
		{
			mobin1 >> a[i][j];
			if (a[i][j] == '-')
			{
				b[i][j] = 0;
				a[i][j] = ' ';
			}
			if (a[i][j] == 'e')
			{
				b[i][j] = 0;
				a[i][j] = '#';
			}
			if (a[i][j] == '#')
				b[i][j] = 0;
			if (a[i][j] == '1')
				b[i][j] = 1;
			if (a[i][j] == '2')
				b[i][j] = 2;
			if (a[i][j] == '3')
				b[i][j] = 3;
			if (a[i][j] == '4')
				b[i][j] = 4;
			if (a[i][j] == '5')
				b[i][j] = 5;
			if (a[i][j] == '6')
				b[i][j] = 6;
			if (a[i][j] == '7')
				b[i][j] = 7;
			if (a[i][j] == '8')
				b[i][j] = 8;
			if (a[i][j] == '9')
				b[i][j] = 9;

		}
}
void showlogic(int t[][50], int lr, int ud)
{
	int i, j;
	for (i = 0; i <11; i++)
		for (j = 0; j < 11; j++)
		{
			cout << t[i][j];
			if (j == 10)
				cout << "\n";
		}
}
void solve2(int tlogic[][50], int i, int j, char t[][50])
{
	int counter = 0, a[50][50][50], checkcounter = 26, check = 0, e;
	i = 0;
	j = 0;
	numberofnumers(tlogic);
	while (number != 81)
	{
		fill(tlogic, 1, 1, t);
		cros(tlogic, i, j, t);
		medadkari(tlogic, t);
	}
}
void ghanonjoft(int tlogic[][50], char t[][50])
{
	//اعمال قانون جفت
	int chek = 0;
	for (int q = 1; q <= 9; q++)
		for (int w = 1; w <= 9; w++)
		{
			if (tlogic[q][w] == 0 && b[q][w][0] == 2)
			{
				//جست و جو در سطر
				/*cout << " aval{" << w << " " << q << "} ";*/
				for (int i = 1; i <= 9; i++)
					if (w != i&&b[q][i][0] == 2)
					{
						if ((b[q][w][1] == b[q][i][1] && b[q][w][2] == b[q][i][2]) || (b[q][w][1] == b[q][i][2] && b[q][w][2] == b[q][i][1]))
						{
							cout << " {ghanon joft " << w << q << i << "}";
							for (int j = 1; j <= 9; j++)
								if (b[q][j][0] != 0 && j != w&&j != i)
								{
									for (int zx = 1; zx <= b[q][j][0]; zx++)
									{
										if (b[q][j][zx] == b[q][w][1] || b[q][j][zx] == b[q][w][2])
										{
											cout << " " << q << " " << j << " " << b[q][j][zx] << " ";
											for (int qw = zx; qw <= b[q][j][0]; qw++)
												b[q][j][qw] = b[q][j][qw + 1];
											b[q][j][0]--;
											zx--;
										}
									}
								}
						}
					}
				for (int i = 1; i <= 9; i++)
					if (q != i&&b[i][w][0] == 2)
					{
						if ((b[q][w][1] == b[i][w][1] && b[q][w][2] == b[i][w][2]) || (b[q][w][1] == b[i][w][2] && b[q][w][2] == b[i][w][1]))
						{
							cout << " {ghanon joft amod " << w << q << i << "}";
							for (int j = 1; j <= 9; j++)
								if (b[j][w][0] != 0 && j != q&&j != i)
								{
									for (int zx = 1; zx <= b[j][w][0]; zx++)
									{
										if (b[j][w][zx] == b[q][w][1] || b[j][w][zx] == b[q][w][2])
										{
											cout << " " << w << " " << j << " " << b[j][w][zx] << " ";
											for (int qw = zx; qw <= b[j][w][0]; qw++)
												b[j][w][qw] = b[j][w][qw + 1];
											b[j][w][0]--;
											zx--;
										}
									}
								}
						}
					}
			}
		}
	//اگر چیزی تک شده باشه حذف میکنه
	for (int q = 1; q <= 9; q++)
		for (int w = 1; w <= 9; w++)
		{
			if (b[q][w][0] == 1)
			{
				tlogic[q][w] = b[q][w][1];
				b[q][w][0]--;
				b[q][w][1] = 0;
			}
		}
}
void fill(int tlogic[][50], int i, int j, char t[][50])
{
	int a[50][50][50] = { 0 }, check = 0, checkcounter = 1, e, w, q;
	//صفر کردن خونه های بی
	for (i = 0; i <= 50; i++)
		for (j = 0; j <= 50; j++)
			for (int h = 0; h <= 50; h++)
				b[i][j][h] = 0;
	for (q = 1; q <= 9; q++)
		for (w = 1; w <= 9; w++)
		{
			if (tlogic[q][w] == 0)
			{
				for (e = 1; e <= 9; e++)
				{
					if (tlogic[e][w] != 0)
						for (int y = 0; y < checkcounter; y++)
							if (tlogic[e][w] == a[q][w][y])
							{
								check = 1;
								break;
							}
					if (check == 0 && tlogic[e][w] != 0)
					{
						checkcounter++;
						a[q][w][checkcounter - 1] = tlogic[e][w];
					}
					check = 0;
				}
				for (e = 1; e <= 9; e++)
				{
					if (tlogic[q][e] != 0)
						for (int y = 0; y < checkcounter; y++)
							if (tlogic[q][e] == a[q][w][y])
							{
								check = 1;
								break;
							}
					if (check == 0 && tlogic[q][e] != 0)
					{
						checkcounter++;
						a[q][w][checkcounter - 1] = tlogic[q][e];
					}
					check = 0;
				}
				int x = 0, y = 0;

				check = 0;
				/*دستورات*/
				if (w <= 3 && q <= 3)
				{
					int u;
					for (int c = 1; c <= 3; c++)
					{
						for (u = 1; u <= 3; u++)
						{
							for (int z = 0; z <= 9; z++)
								if (a[q][w][z] == tlogic[c][u] || tlogic[c][u] == 0)
								{
									check = 1;
									break;
								}
							if (check == 0)
							{
								checkcounter++;
								a[q][w][checkcounter - 1] = tlogic[c][u];
							}
							check = 0;
						}
					}
				}
				//2
				if (w >= 4 && w <= 6 && q <= 3)
				{
					int u;
					for (int c = 1; c <= 3; c++)
					{
						for (u = 4; u <= 6; u++)
						{
							for (int z = 0; z <= 9; z++)
								if (a[q][w][z] == tlogic[c][u] || tlogic[c][u] == 0)
								{
									check = 1;
									break;
								}
							if (check == 0)
							{
								checkcounter++;
								a[q][w][checkcounter - 1] = tlogic[c][u];
							}
							check = 0;
						}

					}
				}
				//3
				if (w >= 7 && w <= 9 && q <= 3)
				{
					int u;
					for (int c = 1; c <= 3; c++)
					{
						for (u = 7; u <= 9; u++)
						{
							for (int z = 0; z <= 9; z++)
								if (a[q][w][z] == tlogic[c][u] || tlogic[c][u] == 0)
								{
									check = 1;
									break;
								}
							if (check == 0)
							{
								checkcounter++;
								a[q][w][checkcounter - 1] = tlogic[c][u];
							}
							check = 0;
						}
					}
				}
				//4
				if (w <= 3 && q >= 4 && q <= 6)
				{
					int u;
					for (int c = 4; c <= 6; c++)
					{
						for (u = 1; u <= 3; u++)
						{
							for (int z = 0; z <= 9; z++)
								if (a[q][w][z] == tlogic[c][u] || tlogic[c][u] == 0)
								{
									check = 1;
									break;
								}
							if (check == 0)
							{
								checkcounter++;
								a[q][w][checkcounter - 1] = tlogic[c][u];
							}
							check = 0;
						}

					}
				}
				//5
				if (w >= 4 && w <= 6 && q >= 4 && q <= 6)
				{
					int u;
					for (int c = 4; c <= 6; c++)
					{
						for (u = 4; u <= 6; u++)
						{
							for (int z = 0; z <= 9; z++)
								if (a[q][w][z] == tlogic[c][u] || tlogic[c][u] == 0)
								{
									check = 1;
									break;
								}
							if (check == 0)
							{
								checkcounter++;
								a[q][w][checkcounter - 1] = tlogic[c][u];
							}
							check = 0;
						}
					}
				}
				//6
				if (w >= 7 && w <= 9 && q >= 4 && q <= 6)
				{
					int u;
					for (int c = 4; c <= 6; c++)
					{
						for (u = 7; u <= 9; u++)
						{
							for (int z = 0; z <= 9; z++)
								if (a[q][w][z] == tlogic[c][u] || tlogic[c][u] == 0)
								{
									check = 1;
									break;
								}
							if (check == 0)
							{
								checkcounter++;
								a[q][w][checkcounter - 1] = tlogic[c][u];
							}
							check = 0;
						}
					}
				}
				//7
				if (w >= 1 && w <= 3 && q >= 7 && q <= 9)
				{
					int u;
					for (int c = 7; c <= 9; c++)
					{
						for (u = 1; u <= 3; u++)
						{
							for (int z = 0; z <= 9; z++)
								if (a[q][w][z] == tlogic[c][u] || tlogic[c][u] == 0)
								{
									check = 1;
									break;
								}
							if (check == 0)
							{
								checkcounter++;
								a[q][w][checkcounter - 1] = tlogic[c][u];
							}
							check = 0;
						}
					}
				}
				//8
				if (w >= 4 && w <= 6 && q >= 7 && q <= 9)
				{
					int u;
					for (int c = 7; c <= 9; c++)
					{
						for (u = 4; u <= 6; u++)
						{
							for (int z = 0; z <= 9; z++)
								if (a[q][w][z] == tlogic[c][u] || tlogic[c][u] == 0)
								{
									check = 1;
									break;
								}
							if (check == 0)
							{
								checkcounter++;
								a[q][w][checkcounter - 1] = tlogic[c][u];
							}
							check = 0;
						}
					}
				}
				//9
				if (w >= 7 && w <= 9 && q >= 7 && q <= 9)
				{
					int u;
					for (int c = 7; c <= 9; c++)
					{
						for (u = 7; u <= 9; u++)
						{
							for (int z = 0; z <= 9; z++)
								if (a[q][w][z] == tlogic[c][u] || tlogic[c][u] == 0)
								{
									check = 1;
									break;
								}
							if (check == 0)
							{
								checkcounter++;
								a[q][w][checkcounter - 1] = tlogic[c][u];
							}
							check = 0;
						}
					}
				}
			}
			a[q][w][0] = checkcounter - 1;
			checkcounter = 1;
		}
	check = 0;
	checkcounter = 1;
	for (q = 1; q <= 9; q++)
		for (w = 1; w <= 9; w++)
		{
			if (a[q][w][0] != 0)
			{
				for (int p = 1; p <= 9; p++)
				{
					for (int e = 1; e <= a[q][w][0]; e++)
					{
						if (a[q][w][e] == p)
						{
							check = 1;
							break;
						}
					}
					if (check == 0)
					{

						b[q][w][checkcounter] = p;
						checkcounter++;
					}
					check = 0;
				}
			}
			check = 0;
			b[q][w][0] = checkcounter - 1;
			checkcounter = 1;
		}

	/*if (q != i&&b[i][w][0] == 2)
	{
	if ((b[q][w][1] == b[i][w][1] && b[q][w][2] == b[i][w][2]) || (b[q][w][1] == b[i][w][2] && b[q][w][2] == b[i][w][1]))
	{
	cout << " {ghanon joft " << w << q << i << "}";
	if (w == 7 && q == 9 && i == 8)
	{
	cout << " hala ";
	for (int po = 1; po <= b[q][w][0]; po++)
	cout << b[q][w][po] << " ";
	}
	for (int j = 1; j <= 9; j++)
	if (b[j][w][0] != 0 && j != q&&j != i)
	{
	for (int zx = 1; zx <= b[j][w][0]; zx++)
	{
	if (b[j][w][zx] == b[q][w][1] || b[j][w][zx] == b[q][w][2])
	{
	cout << " " << q << " " << j << " " << b[q][j][zx] << " ";
	for (int qw = zx; qw <= b[q][j][0]; qw++)
	b[j][w][qw] = b[j][w][qw + 1];
	b[j][w][0]--;
	zx--;
	}
	}
	}
	}
	}*/
	/*cout << "FILL";
	for (int l = 1; l <= 9;l++)
	for (int x = 1; x <= 9; x++)
	{
	for (int z = 0; z <= b[l][x][0]; z++)
	cout << b[l][x][z] << " ";
	cout << "\n";
	}
	_getch();*/
	//صفر کردن خونه های پارتیشن
	for (int i = 0; i <= 10; i++)
		for (int j = 0; j <= 10; j++)
			partion[i][j] = 0;
	fpartion(tlogic);
}
void solve3(int tlogic[][50], int i, int j, char t[][50])
{
	for (int q = 1; q <= 9; q++)
		for (int w = 1; w <= 9; w++)
		{
			if (b[q][w][0] == 1)
				tlogic[q][w] = b[q][w][1];
		}
}
void cros(int tlogic[][50], int i, int j, char t[][50])
{
	int  check = 0;
	//پیدا کردن اعداد هر ناحیه
	fpartion(tlogic);
	//شروع جایگزاری
	//tl صفر و یکه
	int tl[50][50], count = 0;
	creattl(tlogic, tl);
	for (int q = 1; q <= 9; q++)
		for (int w = 1; w <= 9; w++)
		{
			if (tlogic[q][w] == 0)
			{
				//ناحیه 1
				if (w <= 3 && q <= 3)
				{
					for (int co = 1; co <= partion[1][0]; co++)
					{
						for (int x = 1; x <= 3; x++)
							for (int y = 1; y <= 9; y++)
							{
								if (tlogic[x][y] == partion[1][co])
								{
									for (y = 1; y <= 3; y++)
										tl[x][y] = 1;
									break;
								}
							}
						for (int x = 1; x <= 3; x++)
							for (int y = 1; y <= 9; y++)
							{
								if (tlogic[y][x] == partion[1][co])
								{
									for (y = 1; y <= 3; y++)
										tl[y][x] = 1;
									break;
								}
							}
						for (int x = 1; x <= 3; x++)
							for (int y = 1; y <= 3; y++)
								if (tl[x][y] == 0)
									count++;
						if (count == 1)
						{
							//cout << "cros1";
							//_getch();
							for (int x = 1; x <= 3; x++)
								for (int y = 1; y <= 3; y++)
									if (tl[x][y] == 0)
									{
										//cout << partion[1][co] << " " << y << " " << x;
										tlogic[x][y] = partion[1][co];
									}
							for (int v = co; v < partion[1][0]; v++)
								partion[1][v] = partion[1][v + 1];
							//_getch();
							partion[1][0]--;

						}
						creattl(tlogic, tl);
						count = 0;
					}
				}
				//2
				if (w >= 4 && w <= 6 && q <= 3)
				{
					for (int co = 1; co <= partion[2][0]; co++)
					{
						for (int x = 1; x <= 3; x++)
							for (int y = 1; y <= 9; y++)
							{
								if (tlogic[x][y] == partion[2][co])
								{
									for (y = 4; y <= 6; y++)
										tl[x][y] = 1;
									break;
								}
							}
						for (int x = 4; x <= 6; x++)
							for (int y = 1; y <= 9; y++)
							{
								if (tlogic[y][x] == partion[2][co])
								{
									for (y = 4; y <= 6; y++)
										tl[y][x] = 1;
									break;
								}
							}
						for (int x = 1; x <= 3; x++)
							for (int y = 4; y <= 6; y++)
								if (tl[x][y] == 0)
									count++;
						if (count == 1)
						{
							//cout << "cros2";
							//_getch();
							for (int x = 1; x <= 3; x++)
								for (int y = 4; y <= 6; y++)
									if (tl[x][y] == 0)
									{
										//cout << partion[2][co] << " " << y << " " << x;
										tlogic[x][y] = partion[2][co];
									}
							for (int v = co; v < partion[2][0]; v++)
								partion[2][v] = partion[2][v + 1];
							//_getch();
							partion[2][0]--;
						}
						creattl(tlogic, tl);
						count = 0;
					}
				}
				//3
				if (w >= 7 && w <= 9 && q <= 3)
				{
					for (int co = 1; co <= partion[3][0]; co++)
					{
						for (int x = 1; x <= 3; x++)
							for (int y = 1; y <= 9; y++)
							{
								if (tlogic[x][y] == partion[3][co])
								{
									for (y = 1; y <= 3; y++)
										tl[x][y] = 1;
									break;
								}
							}
						for (int x = 7; x <= 9; x++)
							for (int y = 1; y <= 9; y++)
							{
								if (tlogic[y][x] == partion[3][co])
								{
									for (y = 1; y <= 3; y++)
										tl[y][x] = 1;
									break;
								}
							}
						for (int x = 1; x <= 3; x++)
							for (int y = 7; y <= 9; y++)
								if (tl[x][y] == 0)
									count++;
						if (count == 1)
						{
							//cout << "cros3";
							//_getch();
							for (int x = 1; x <= 3; x++)
								for (int y = 6; y <= 9; y++)
									if (tl[x][y] == 0)
									{
										//cout << partion[3][co] << " " << y << " " << x;
										tlogic[x][y] = partion[3][co];
									}
							for (int v = co; v < partion[3][0]; v++)
								partion[3][v] = partion[3][v + 1];
							//_getch();
							partion[3][0]--;
						}
						creattl(tlogic, tl);
						count = 0;
					}
				}
				//4
				if (w <= 3 && q >= 4 && q <= 6)
				{
					for (int co = 1; co <= partion[4][0]; co++)
					{
						for (int x = 1; x <= 3; x++)
							for (int y = 1; y <= 9; y++)
							{
								if (tlogic[x][y] == partion[4][co])
								{
									for (y = 4; y <= 6; y++)
										tl[x][y] = 1;
									break;
								}
							}
						for (int x = 4; x <= 6; x++)
							for (int y = 1; y <= 9; y++)
							{
								if (tlogic[y][x] == partion[4][co])
								{
									for (y = 4; y <= 6; y++)
										tl[y][x] = 1;
									break;
								}
							}
						for (int x = 4; x <= 6; x++)
							for (int y = 1; y <= 3; y++)
								if (tl[x][y] == 0)
									count++;
						if (count == 1)
						{
							//cout << "cros4";
							//_getch();
							for (int x = 4; x <= 6; x++)
								for (int y = 1; y <= 3; y++)
									if (tl[x][y] == 0)
									{
										//cout << partion[4][co] << " " << y << " " << x;
										tlogic[x][y] = partion[4][co];
									}
							for (int v = co; v < partion[4][0]; v++)
								partion[4][v] = partion[4][v + 1];
						//	_getch();
							partion[4][0]--;
						}
						creattl(tlogic, tl);
						count = 0;
					}
				}
				//5
				if (w >= 4 && w <= 6 && q >= 4 && q <= 6)
				{
					for (int co = 1; co <= partion[5][0]; co++)
					{
						for (int x = 4; x <= 6; x++)
							for (int y = 1; y <= 9; y++)
							{
								if (tlogic[x][y] == partion[5][co])
								{
									for (y = 4; y <= 6; y++)
										tl[x][y] = 1;
									break;
								}
							}
						for (int x = 4; x <= 6; x++)
							for (int y = 1; y <= 9; y++)
							{
								if (tlogic[y][x] == partion[5][co])
								{
									for (y = 4; y <= 6; y++)
										tl[y][x] = 1;
									break;
								}
							}
						for (int x = 4; x <= 6; x++)
							for (int y = 4; y <= 6; y++)
								if (tl[x][y] == 0)
									count++;
						if (count == 1)
						{
							//cout << "cros5";
							//_getch();
							for (int x = 4; x <= 6; x++)
								for (int y = 4; y <= 6; y++)
									if (tl[x][y] == 0)
									{
										// << partion[5][co] << " " << y << " " << x;
										tlogic[x][y] = partion[5][co];
									}

							for (int v = co; v < partion[5][0]; v++)
								partion[5][v] = partion[5][v + 1];
							//_getch();
							partion[5][0]--;
						}
						creattl(tlogic, tl);
						count = 0;
					}
				}
				//6
				if (w >= 7 && w <= 9 && q >= 4 && q <= 6)
				{
					for (int co = 1; co <= partion[6][0]; co++)
					{
						for (int x = 4; x <= 6; x++)
							for (int y = 1; y <= 9; y++)
							{
								if (tlogic[x][y] == partion[6][co])
								{
									for (y = 6; y <= 9; y++)
										tl[x][y] = 1;
									break;
								}
							}
						for (int x = 7; x <= 9; x++)
							for (int y = 1; y <= 9; y++)
							{
								if (tlogic[y][x] == partion[6][co])
								{
									for (y = 6; y <= 9; y++)
										tl[y][x] = 1;
									break;
								}
							}
						for (int x = 4; x <= 6; x++)
							for (int y = 7; y <= 9; y++)
								if (tl[x][y] == 0)
									count++;
						if (count == 1)
						{
							//cout << "cros6";
							//_getch();
							for (int x = 4; x <= 6; x++)
								for (int y = 7; y <= 9; y++)
									if (tl[x][y] == 0)
									{
										//cout << partion[6][co] << " " << y << " " << x;
										tlogic[x][y] = partion[6][co];
									}
							for (int v = co; v < partion[6][0]; v++)
								partion[6][v] = partion[6][v + 1];
							//_getch();
							partion[6][0]--;
						}
						creattl(tlogic, tl);
						count = 0;
					}
				}
				//7
				if (w >= 1 && w <= 3 && q >= 7 && q <= 9)
				{
					for (int co = 1; co <= partion[7][0]; co++)
					{
						for (int x = 7; x <= 9; x++)
							for (int y = 1; y <= 9; y++)
							{
								if (tlogic[x][y] == partion[7][co])
								{
									for (y = 7; y <= 9; y++)
										tl[x][y] = 1;
									break;
								}
							}
						for (int x = 1; x <= 3; x++)
							for (int y = 1; y <= 9; y++)
							{
								if (tlogic[y][x] == partion[7][co])
								{
									for (y = 7; y <= 9; y++)
										tl[y][x] = 1;
									break;
								}
							}
						for (int x = 7; x <= 9; x++)
							for (int y = 1; y <= 3; y++)
								if (tl[x][y] == 0)
									count++;
						if (count == 1)
						{
							//cout << "cros7";
							//_getch();
							for (int x = 7; x <= 9; x++)
								for (int y = 1; y <= 3; y++)
									if (tl[x][y] == 0)
									{
										//cout << partion[7][co] << " " << y << " " << x;
										tlogic[x][y] = partion[7][co];
									}
							for (int v = co; v < partion[7][0]; v++)
								partion[7][v] = partion[7][v + 1];
						//	_getch();
							partion[7][0]--;
						}
						creattl(tlogic, tl);
						count = 0;
					}
				}
				//8
				if (w >= 4 && w <= 6 && q >= 7 && q <= 9)
				{
					for (int co = 1; co <= partion[8][0]; co++)
					{
						for (int x = 4; x <= 6; x++)
							for (int y = 1; y <= 9; y++)
							{
								if (tlogic[x][y] == partion[8][co])
								{
									for (y = 4; y <= 6; y++)
										tl[x][y] = 1;
									break;
								}
							}
						for (int x = 7; x <= 9; x++)
							for (int y = 1; y <= 9; y++)
							{
								if (tlogic[y][x] == partion[8][co])
								{
									for (y = 4; y <= 6; y++)
										tl[y][x] = 1;
									break;
								}
							}
						for (int x = 7; x <= 9; x++)
							for (int y = 4; y <= 6; y++)
								if (tl[x][y] == 0)
									count++;
						if (count == 1)
						{
							//cout << "cros8";
							//_getch();
							for (int x = 7; x <= 9; x++)
								for (int y = 4; y <= 6; y++)
									if (tl[x][y] == 0)
									{
									//	cout << partion[8][co] << " " << y << " " << x;
										tlogic[x][y] = partion[8][co];
									}
							for (int v = co; v < partion[8][0]; v++)
								partion[8][v] = partion[8][v + 1];
						//	_getch();
							partion[8][0]--;
						}
						creattl(tlogic, tl);
						count = 0;
					}
				}
				//9
				if (w >= 7 && w <= 9 && q >= 7 && q <= 9)
				{
					for (int co = 1; co <= partion[9][0]; co++)
					{
						for (int x = 7; x <= 9; x++)
							for (int y = 1; y <= 9; y++)
							{
								if (tlogic[x][y] == partion[9][co])
								{
									for (y = 6; y <= 9; y++)
										tl[x][y] = 1;
									break;
								}
							}
						for (int x = 7; x <= 9; x++)
							for (int y = 1; y <= 9; y++)
							{
								if (tlogic[y][x] == partion[9][co])
								{
									for (y = 6; y <= 9; y++)
										tl[y][x] = 1;
									break;
								}
							}
						for (int x = 7; x <= 9; x++)
							for (int y = 7; y <= 9; y++)
								if (tl[x][y] == 0)
									count++;
						if (count == 1)
						{
							//cout << "cros9";
							//_getch();
							for (int x = 7; x <= 9; x++)
								for (int y = 7; y <= 9; y++)
									if (tl[x][y] == 0)
									{
										/*if (x==9&&y==8)
										for (int qe = 0; qe <= partion[9][0]; qe++)
										cout << partion[9][qe]<<" ";*/
										//cout << partion[9][co] << " " << y << " " << x;
										tlogic[x][y] = partion[9][co];
									}
							/*for (int v = co; v < partion[9][0]; v++)
							partion[9][v] = partion[9][v + 1];*/
							fpartion(tlogic);
							//_getch();
							partion[9][0]--;

						}
						creattl(tlogic, tl);
						count = 0;
					}
				}
				showlogic(tlogic, 1, 1);
			}
		}
}
//ساختن صفر و یک سودوکو
void creattl(int tlogic[][50], int tl[][50])
{
	for (int q = 1; q <= 9; q++)
		for (int w = 1; w <= 9; w++)
			if (tlogic[q][w] == 0)
				tl[q][w] = 0;
			else
				tl[q][w] = 1;
}
//پیدا کردن تعداد اعداد غیر صفر جدول
void numberofnumers(int tlogic[][50])
{
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
		{
			if (tlogic[i][j] != 0)
				number++;
		}
}
void medadkari(int tlogic[][50], char t[][50])
{
	int checkpartion[10][10] = { 0 };
	//برای استفاده در قانون دوم
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
		{
			/*cout << "ghanon aval";
			_getch();*/
			//اون های که یدونه هست توشون
			if (b[i][j][0] == 1)
			{
				tlogic[i][j] = b[i][j][1];
				fill(tlogic, 1, 1, t);
				//cout << "medad" << tlogic[i][j] << " " << i << " " << j << " ";
				//showlogic(tlogic, 1, 1);
				//_getch();
			}
		}
	//	قانون دوم
	int chek = 0;
	for (int q = 1; q <= 9; q++)
		for (int w = 1; w <= 9; w++)
		{
			if (tlogic[q][w] == 0)
			{
				//1
				if (w <= 3 && q <= 3)
				{
					for (int e = 1; e <= b[q][w][0]; e++)
					{
					a1:
						if (e > b[q][w][0])
							break;
						for (int i = 1; i <= 3; i++)
							for (int j = 1; j <= 3; j++)
							{
								if (q != i || w != j&&tlogic[i][j] == 0)
								{
									for (int o = 1; o <= b[i][j][0]; o++)
										if (b[q][w][e] == b[i][j][o] || e>b[q][w][0])
										{
											chek = 1;
											break;
										}
									if (chek == 1)
									{
										e++;
										chek = 0;
										goto a1;
									}
								}
							}
						if (chek == 0)
						{
							tlogic[q][w] = b[q][w][e];

						}
						fill(tlogic, 1, 1, t);
						chek = 0;
					}
				}
				//2
				if (w >= 4 && w <= 6 && q <= 3)
				{
					for (int e = 1; e <= b[q][w][0]; e++)
					{
					a2:
						if (e > b[q][w][0])
							break;
						for (int i = 1; i <= 3; i++)
							for (int j = 4; j <= 6; j++)
							{
								if (q != i || w != j&&tlogic[i][j] == 0)
								{
									for (int o = 1; o <= b[i][j][0]; o++)
										if (b[q][w][e] == b[i][j][o] || e>b[q][w][0])
										{
											chek = 1;
											break;
										}
									if (chek == 1)
									{
										e++;
										chek = 0;
										goto a2;
									}
								}
							}
						if (chek == 0)
						{
							tlogic[q][w] = b[q][w][e];

						}
						fill(tlogic, 1, 1, t);
						chek = 0;
					}
				}
				//3
				if (w >= 7 && w <= 9 && q <= 3)
				{
					for (int e = 1; e <= b[q][w][0]; e++)
					{
					a3:
						if (e > b[q][w][0])
							break;
						for (int i = 1; i <= 3; i++)
							for (int j = 7; j <= 9; j++)
							{
								if (q != i || w != j&&tlogic[i][j] == 0)
								{
									for (int o = 1; o <= b[i][j][0]; o++)
										if (b[q][w][e] == b[i][j][o] || e>b[q][w][0])
										{
											chek = 1;
											break;
										}
									if (chek == 1)
									{
										e++;
										chek = 0;
										goto a3;
									}
								}
							}
						if (chek == 0)
						{
							tlogic[q][w] = b[q][w][e];

						}
						fill(tlogic, 1, 1, t);
						chek = 0;
					}
				}
				//4
				if (w <= 3 && q >= 4 && q <= 6)
				{
					for (int e = 1; e <= b[q][w][0]; e++)
					{
					a4:
						if (e > b[q][w][0])
							break;
						for (int i = 4; i <= 6; i++)
							for (int j = 1; j <= 3; j++)
							{
								if (q != i || w != j&&tlogic[i][j] == 0)
								{
									for (int o = 1; o <= b[i][j][0]; o++)
										if (b[q][w][e] == b[i][j][o] || e>b[q][w][0])
										{
											chek = 1;
											break;
										}
									if (chek == 1)
									{
										e++;
										chek = 0;
										goto a4;
									}
								}
							}
						if (chek == 0)
						{
							tlogic[q][w] = b[q][w][e];

						}
						fill(tlogic, 1, 1, t);
						chek = 0;
					}
				}
				//5
				if (w >= 4 && w <= 6 && q >= 4 && q <= 6)
				{
					for (int e = 1; e <= b[q][w][0]; e++)
					{
					a5:
						if (e > b[q][w][0])
							break;
						for (int i = 4; i <= 6; i++)
							for (int j = 4; j <= 6; j++)
							{
								if (q != i || w != j&&tlogic[i][j] == 0)
								{
									for (int o = 1; o <= b[i][j][0]; o++)
										if (b[q][w][e] == b[i][j][o] || e>b[q][w][0])
										{
											chek = 1;
											break;
										}
									if (chek == 1)
									{
										e++;
										chek = 0;
										goto a5;
									}
								}
							}
						if (chek == 0)
						{
							tlogic[q][w] = b[q][w][e];

						}
						fill(tlogic, 1, 1, t);
						chek = 0;
					}
				}
				//6
				if (w >= 7 && w <= 9 && q >= 4 && q <= 6)
				{
					for (int e = 1; e <= b[q][w][0]; e++)
					{
					a6:
						if (e > b[q][w][0])
							break;
						for (int i = 4; i <= 6; i++)
							for (int j = 7; j <= 9; j++)
							{
								if (q != i || w != j&&tlogic[i][j] == 0)
								{
									for (int o = 1; o <= b[i][j][0]; o++)
										if (b[q][w][e] == b[i][j][o] || e>b[q][w][0])
										{
											chek = 1;
											break;
										}
									if (chek == 1)
									{
										e++;
										chek = 0;
										goto a6;
									}
								}
							}
						if (chek == 0)
						{
							tlogic[q][w] = b[q][w][e];

						}
						fill(tlogic, 1, 1, t);
						chek = 0;
					}
				}
				//7
				if (w >= 1 && w <= 3 && q >= 7 && q <= 9)
				{
					for (int e = 1; e <= b[q][w][0]; e++)
					{
					a7:
						if (e > b[q][w][0])
							break;
						for (int i = 7; i <= 9; i++)
							for (int j = 1; j <= 3; j++)
							{
								if (q != i || w != j&&tlogic[i][j] == 0)
								{
									for (int o = 1; o <= b[i][j][0]; o++)
										if (b[q][w][e] == b[i][j][o] || e>b[q][w][0])
										{
											chek = 1;
											break;
										}
									if (chek == 1)
									{
										e++;
										chek = 0;
										goto a7;
									}
								}
							}
						if (chek == 0)
						{
							tlogic[q][w] = b[q][w][e];

						}
						fill(tlogic, 1, 1, t);
						chek = 0;
					}
				}
				//8
				if (w >= 4 && w <= 6 && q >= 7 && q <= 9)
				{
					for (int e = 1; e <= b[q][w][0]; e++)
					{
					a8:
						if (e > b[q][w][0])
							break;
						for (int i = 7; i <= 9; i++)
							for (int j = 4; j <= 6; j++)
							{
								if (q != i || w != j&&tlogic[i][j] == 0)
								{
									for (int o = 1; o <= b[i][j][0]; o++)
										if (b[q][w][e] == b[i][j][o] || e>b[q][w][0])
										{
											chek = 1;
											break;
										}
									if (chek == 1)
									{
										e++;
										chek = 0;
										goto a8;
									}
								}
							}
						if (chek == 0)
						{
							tlogic[q][w] = b[q][w][e];

						}
						fill(tlogic, 1, 1, t);
						chek = 0;
					}
				}
				//9
				if (w >= 7 && w <= 9 && q >= 7 && q <= 9)
				{
					for (int e = 1; e <= b[q][w][0]; e++)
					{
					a9:
						if (e > b[q][w][0])
							break;
						for (int i = 7; i <= 9; i++)
							for (int j = 7; j <= 9; j++)
							{
								if (q != i || w != j&&tlogic[i][j] == 0)
								{
									for (int o = 1; o <= b[i][j][0]; o++)
										if (b[q][w][e] == b[i][j][o] || e>b[q][w][0])
										{
											chek = 1;
											break;
										}
									if (chek == 1)
									{
										e++;
										chek = 0;
										goto a9;
									}
								}
							}
						if (chek == 0)
						{
							tlogic[q][w] = b[q][w][e];

						}
						fill(tlogic, 1, 1, t);
						chek = 0;
					}
				}
			}
			fill(tlogic, 1, 1, t);
		}
}
void medadkari2(int tlogic[][50], char t[][50])
{
	int checkpartion[10][10] = { 0 };
	//قانون اول
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
		{
			/*cout << "ghanon aval";
			_getch();*/
			//اون های که یدونه هست توشون
			if (b[i][j][0] == 1)
			{
				tlogic[i][j] = b[i][j][1];
				fill(tlogic, 1, 1, t);
			//	cout << "medad" << tlogic[i][j] << " " << i << " " << j << " ";
				//showlogic(tlogic, 1, 1);
				//_getch();
			}
		}
	//	قانون دوم
	//cout << "ghanon dovom";
	//_getch();
	int chek = 0;
	for (int q = 1; q <= 9; q++)
		for (int w = 1; w <= 9; w++)
		{
			if (tlogic[q][w] == 0)
			{
				//1
				if (w <= 3 && q <= 3)
				{
					for (int e = 1; e <= b[q][w][0]; e++)
					{
					a1:
						if (e > b[q][w][0])
							break;
						for (int i = 1; i <= 3; i++)
							for (int j = 1; j <= 3; j++)
							{
								if (q != i || w != j&&tlogic[i][j] == 0)
								{
									for (int o = 1; o <= b[i][j][0]; o++)
										if (b[q][w][e] == b[i][j][o] || e>b[q][w][0])
										{
											chek = 1;
											break;
										}
									if (chek == 1)
									{
										e++;
										chek = 0;
										goto a1;
									}
								}
							}
						if (chek == 0)
						{
							tlogic[q][w] = b[q][w][e];
							//cout << b[q][w][e] << " w=" << w << " q=" << q;

						}
						fill(tlogic, 1, 1, t);
						chek = 0;
					}
				}
				//2
				if (w >= 4 && w <= 6 && q <= 3)
				{
					for (int e = 1; e <= b[q][w][0]; e++)
					{
					a2:
						if (e > b[q][w][0])
							break;
						for (int i = 1; i <= 3; i++)
							for (int j = 4; j <= 6; j++)
							{
								if (q != i || w != j&&tlogic[i][j] == 0)
								{
									for (int o = 1; o <= b[i][j][0]; o++)
										if (b[q][w][e] == b[i][j][o] || e>b[q][w][0])
										{
											chek = 1;
											break;
										}
									if (chek == 1)
									{
										e++;
										chek = 0;
										goto a2;
									}
								}
							}
						if (chek == 0)
						{
							tlogic[q][w] = b[q][w][e];
							//cout << b[q][w][e] << " w=" << w << " q=" << q;
						}
						fill(tlogic, 1, 1, t);
						chek = 0;
					}
				}
				//3
				if (w >= 7 && w <= 9 && q <= 3)
				{
					for (int e = 1; e <= b[q][w][0]; e++)
					{
					a3:
						if (e > b[q][w][0])
							break;
						for (int i = 1; i <= 3; i++)
							for (int j = 7; j <= 9; j++)
							{
								if (q != i || w != j&&tlogic[i][j] == 0)
								{
									for (int o = 1; o <= b[i][j][0]; o++)
										if (b[q][w][e] == b[i][j][o] || e>b[q][w][0])
										{
											chek = 1;
											break;
										}
									if (chek == 1)
									{
										e++;
										chek = 0;
										goto a3;
									}
								}
							}
						if (chek == 0)
						{
							tlogic[q][w] = b[q][w][e];
							//cout << b[q][w][e] << " w=" << w << " q=" << q;
						}
						fill(tlogic, 1, 1, t);
						chek = 0;
					}
				}
				//4
				if (w <= 3 && q >= 4 && q <= 6)
				{
					for (int e = 1; e <= b[q][w][0]; e++)
					{
					a4:
						if (e > b[q][w][0])
							break;
						for (int i = 4; i <= 6; i++)
							for (int j = 1; j <= 3; j++)
							{
								if (q != i || w != j&&tlogic[i][j] == 0)
								{
									for (int o = 1; o <= b[i][j][0]; o++)
										if (b[q][w][e] == b[i][j][o] || e>b[q][w][0])
										{
											chek = 1;
											break;
										}
									if (chek == 1)
									{
										e++;
										chek = 0;
										goto a4;
									}
								}
							}
						if (chek == 0)
						{
							tlogic[q][w] = b[q][w][e];
							//cout << b[q][w][e] << " w=" << w << " q=" << q;
						}
						fill(tlogic, 1, 1, t);
						chek = 0;
					}
				}
				//5
				if (w >= 4 && w <= 6 && q >= 4 && q <= 6)
				{
					for (int e = 1; e <= b[q][w][0]; e++)
					{
					a5:
						if (e > b[q][w][0])
							break;
						for (int i = 4; i <= 6; i++)
							for (int j = 4; j <= 6; j++)
							{
								if (q != i || w != j&&tlogic[i][j] == 0)
								{
									for (int o = 1; o <= b[i][j][0]; o++)
										if (b[q][w][e] == b[i][j][o] || e>b[q][w][0])
										{
											chek = 1;
											break;
										}
									if (chek == 1)
									{
										e++;
										chek = 0;
										goto a5;
									}
								}
							}
						if (chek == 0)
						{
							tlogic[q][w] = b[q][w][e];
						//	cout << b[q][w][e] << " w=" << w << " q=" << q;
						}
						fill(tlogic, 1, 1, t);
						chek = 0;
					}
				}
				//6
				if (w >= 7 && w <= 9 && q >= 4 && q <= 6)
				{
					for (int e = 1; e <= b[q][w][0]; e++)
					{
					a6:
						if (e > b[q][w][0])
							break;
						for (int i = 4; i <= 6; i++)
							for (int j = 7; j <= 9; j++)
							{
								if (q != i || w != j&&tlogic[i][j] == 0)
								{
									for (int o = 1; o <= b[i][j][0]; o++)
										if (b[q][w][e] == b[i][j][o] || e>b[q][w][0])
										{
											chek = 1;
											break;
										}
									if (chek == 1)
									{
										e++;
										chek = 0;
										goto a6;
									}
								}
							}
						if (chek == 0)
						{
							tlogic[q][w] = b[q][w][e];
							//cout << b[q][w][e] << " w=" << w << " q=" << q;
						}
						fill(tlogic, 1, 1, t);
						chek = 0;
					}
				}
				//7
				if (w >= 1 && w <= 3 && q >= 7 && q <= 9)
				{
					for (int e = 1; e <= b[q][w][0]; e++)
					{
					a7:
						if (e > b[q][w][0])
							break;
						for (int i = 7; i <= 9; i++)
							for (int j = 1; j <= 3; j++)
							{
								if (q != i || w != j&&tlogic[i][j] == 0)
								{
									for (int o = 1; o <= b[i][j][0]; o++)
										if (b[q][w][e] == b[i][j][o] || e>b[q][w][0])
										{
											chek = 1;
											break;
										}
									if (chek == 1)
									{
										e++;
										chek = 0;
										goto a7;
									}
								}
							}
						if (chek == 0)
						{
							tlogic[q][w] = b[q][w][e];
							//cout << b[q][w][e] << " w=" << w << " q=" << q;
						}
						fill(tlogic, 1, 1, t);
						chek = 0;
					}
				}
				//8
				if (w >= 4 && w <= 6 && q >= 7 && q <= 9)
				{
					for (int e = 1; e <= b[q][w][0]; e++)
					{
					a8:
						if (e > b[q][w][0])
							break;
						for (int i = 7; i <= 9; i++)
							for (int j = 4; j <= 6; j++)
							{
								if (q != i || w != j&&tlogic[i][j] == 0)
								{
									for (int o = 1; o <= b[i][j][0]; o++)
										if (b[q][w][e] == b[i][j][o] || e>b[q][w][0])
										{
											chek = 1;
											break;
										}
									if (chek == 1)
									{
										e++;
										chek = 0;
										goto a8;
									}
								}
							}
						if (chek == 0)
						{
							tlogic[q][w] = b[q][w][e];
							//cout << b[q][w][e] << " w=" << w << " q=" << q;
						}
						fill(tlogic, 1, 1, t);
						chek = 0;
					}
				}
				//9
				if (w >= 7 && w <= 9 && q >= 7 && q <= 9)
				{
					for (int e = 1; e <= b[q][w][0]; e++)
					{
					a9:
						if (e > b[q][w][0])
							break;
						for (int i = 7; i <= 9; i++)
							for (int j = 7; j <= 9; j++)
							{
								if (q != i || w != j&&tlogic[i][j] == 0)
								{
									for (int o = 1; o <= b[i][j][0]; o++)
										if (b[q][w][e] == b[i][j][o] || e>b[q][w][0])
										{
											chek = 1;
											break;
										}
									if (chek == 1)
									{
										e++;
										chek = 0;
										goto a9;
									}
								}
							}
						if (chek == 0)
						{
							tlogic[q][w] = b[q][w][e];
							//cout << b[q][w][e] << " w=" << w << " q=" << q;
						}
						fill(tlogic, 1, 1, t);
						chek = 0;
					}
				}
			}
			fill(tlogic, 1, 1, t);
		}
	ghanonjoft(tlogic, t);
}
void fpartion(int tlogic[][50])
{
	int check = 0;
	for (int q = 1; q <= 9; q++)
		for (int w = 1; w <= 9; w++)
		{
			if (tlogic[q][w] == 0)
			{
				//ناحیه 1
				if (w <= 3 && q <= 3)
				{
					for (int u = 1; u <= b[q][w][0]; u++)
					{
						if (partion[1][0] == 0)
						{
							partion[1][0]++;
							partion[1][partion[1][0]] = b[q][w][u];
							check = 1;
						}
						else
							for (int o = 1; o <= partion[1][0]; o++)
								if (b[q][w][u] == partion[1][o])
								{
									check = 1;
									break;
								}
						if (check == 0)
						{
							partion[1][0]++;
							partion[1][partion[1][0]] = b[q][w][u];
						}
						check = 0;
					}
				}
				//2
				if (w >= 4 && w <= 6 && q <= 3)
				{
					for (int u = 1; u <= b[q][w][0]; u++)
					{
						if (partion[2][0] == 0)
						{
							partion[2][0]++;
							partion[2][partion[2][0]] = b[q][w][u];
							check = 1;
						}
						else
							for (int o = 1; o <= partion[2][0]; o++)
								if (b[q][w][u] == partion[2][o])
								{
									check = 1;
									break;
								}
						if (check == 0)
						{
							partion[2][0]++;
							partion[2][partion[2][0]] = b[q][w][u];
						}
						check = 0;
					}
				}
				//3
				if (w >= 7 && w <= 9 && q <= 3)
				{
					for (int u = 1; u <= b[q][w][0]; u++)
					{
						if (partion[3][0] == 0)
						{
							partion[3][0]++;
							partion[3][partion[3][0]] = b[q][w][u];
							check = 1;
						}
						else
							for (int o = 1; o <= partion[3][0]; o++)
								if (b[q][w][u] == partion[3][o])
								{
									check = 1;
									break;
								}
						if (check == 0)
						{
							partion[3][0]++;
							partion[3][partion[3][0]] = b[q][w][u];
						}
						check = 0;
					}
				}
				//4
				if (w <= 3 && q >= 4 && q <= 6)
				{
					for (int u = 1; u <= b[q][w][0]; u++)
					{
						if (partion[4][0] == 0)
						{
							partion[4][0]++;
							partion[4][partion[4][0]] = b[q][w][u];
							check = 1;
						}
						else
							for (int o = 1; o <= partion[4][0]; o++)
								if (b[q][w][u] == partion[4][o])
								{
									check = 1;
									break;
								}
						if (check == 0)
						{
							partion[4][0]++;
							partion[4][partion[4][0]] = b[q][w][u];
						}
						check = 0;
					}
				}
				//5
				if (w >= 4 && w <= 6 && q >= 4 && q <= 6)
				{
					for (int u = 1; u <= b[q][w][0]; u++)
					{
						if (partion[5][0] == 0)
						{
							partion[5][0]++;
							partion[5][partion[5][0]] = b[q][w][u];
							check = 1;
						}
						else
							for (int o = 1; o <= partion[5][0]; o++)
								if (b[q][w][u] == partion[5][o])
								{
									check = 1;
									break;
								}
						if (check == 0)
						{
							partion[5][0]++;
							partion[5][partion[5][0]] = b[q][w][u];
						}
						check = 0;
					}
				}
				//6
				if (w >= 7 && w <= 9 && q >= 4 && q <= 6)
				{
					for (int u = 1; u <= b[q][w][0]; u++)
					{
						if (partion[6][0] == 0)
						{
							partion[6][0]++;
							partion[6][partion[6][0]] = b[q][w][u];
							check = 1;
						}
						else
							for (int o = 1; o <= partion[6][0]; o++)
								if (b[q][w][u] == partion[6][o])
								{
									check = 1;
									break;
								}
						if (check == 0)
						{
							partion[6][0]++;
							partion[6][partion[6][0]] = b[q][w][u];
						}
						check = 0;
					}
				}
				//7
				if (w >= 1 && w <= 3 && q >= 7 && q <= 9)
				{
					for (int u = 1; u <= b[q][w][0]; u++)
					{
						if (partion[7][0] == 0)
						{
							partion[7][0]++;
							partion[7][partion[7][0]] = b[q][w][u];
							check = 1;
						}
						else
							for (int o = 1; o <= partion[7][0]; o++)
								if (b[q][w][u] == partion[7][o])
								{
									check = 1;
									break;
								}
						if (check == 0)
						{
							partion[7][0]++;
							partion[7][partion[7][0]] = b[q][w][u];
						}
						check = 0;
					}
				}
				//8
				if (w >= 4 && w <= 6 && q >= 7 && q <= 9)
				{
					for (int u = 1; u <= b[q][w][0]; u++)
					{
						if (partion[8][0] == 0)
						{
							partion[8][0]++;
							partion[8][partion[8][0]] = b[q][w][u];
							check = 1;
						}
						else
							for (int o = 1; o <= partion[8][0]; o++)
								if (b[q][w][u] == partion[8][o])
								{
									check = 1;
									break;
								}
						if (check == 0)
						{
							partion[8][0]++;
							partion[8][partion[8][0]] = b[q][w][u];
						}
						check = 0;
					}
				}
				//9
				if (w >= 7 && w <= 9 && q >= 7 && q <= 9)
				{
					for (int u = 1; u <= b[q][w][0]; u++)
					{
						if (partion[9][0] == 0)
						{
							partion[9][0]++;
							partion[9][partion[9][0]] = b[q][w][u];
							check = 1;
						}
						else
							for (int o = 1; o <= partion[9][0]; o++)
								if (b[q][w][u] == partion[9][o])
								{
									check = 1;
									break;
								}
						if (check == 0)
						{
							partion[9][0]++;
							partion[9][partion[9][0]] = b[q][w][u];
						}
						check = 0;
					}
				}
			}
		}
}
