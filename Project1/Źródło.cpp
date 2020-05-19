#include <iostream>
#include <vector>

struct turystyka
{
	int pocz;
	int kon;
	int wartosc;
	int drzewo = -1;
};


struct wierz
{
	int miasto;
	bool odwiedz = false;
};


struct temp
{
	int nrmiasta;
	int lokalizacja;
};


class Turystyka
{
private:
	int iloscdrog = 1;
	int iloscmiast = 2;
	int skad;
	int dokad;
	int ileosob;

	std::vector<turystyka>droga;
	std::vector<turystyka>drogasort;
	std::vector<turystyka>drzewa;

	std::vector<wierz> miasta;
	std::vector<temp> odwiedzone;

public:
	void setiledrog(int X);
	void setilemiast(int N);

	void settab(int miastoa, int miastob, int wart);
	void sety(int sskad, int gdzie, int ile);
	void Drzewa();
	void sort();


	void szukmiasta();
	void szukanie(int skad,int dokad);
	void sortmiast();

	void licz();


	void wyswietldroga();
	void wyswietldrogasort();
	void wyswietldrzewa();


	void wyswietlmiasta();
	void wyswietodwiedzone();
};



void Turystyka::Drzewa()
{

	int podd = 0;
	int drogi = 0;
	int siz = iloscmiast - 1;
	int ilocz;


	int sprawdzenie;
	
	for (int x=0; x<siz;x++)
	{
		ilocz = 0;
		sprawdzenie = 0;
		for (int i = 0; i < drogi; i++)
		{
			for (int j = 0; j < drogi; j++)
			{
				if (sprawdzenie == 0)
				{

					if (drogasort[x].pocz == drzewa[i].pocz && drogasort[x].kon == drzewa[j].kon)
					{
						sprawdzenie = 1;

						if (drzewa[j].drzewo == drzewa[i].drzewo)
						{
							siz++;
						}
						else
						{
							turystyka t;
							t.pocz = drogasort[x].pocz;
							t.kon = drogasort[x].kon;
							t.wartosc = drogasort[x].wartosc;
							t.drzewo = drzewa[i].drzewo;
							drzewa.push_back(t);


							int dr = drzewa[j].drzewo;
							int dr2 = drzewa[i].drzewo;
							for (int y = 0; y < drogi; y++)
							{
								if (drzewa[y].drzewo == dr)
								{
									drzewa[y].drzewo = dr2;
								}

							}

							drogi++;

						}


					}
					else if (drogasort[x].pocz == drzewa[i].kon && drogasort[x].kon == drzewa[j].pocz)
					{
						sprawdzenie = 1;

						if (drzewa[j].drzewo == drzewa[i].drzewo)
						{
							siz++;
						}
						else
						{
							turystyka t;
							t.pocz = drogasort[x].pocz;
							t.kon = drogasort[x].kon;
							t.wartosc = drogasort[x].wartosc;
							t.drzewo = drzewa[i].drzewo;
							drzewa.push_back(t);


							int dr = drzewa[j].drzewo;
							int dr2 = drzewa[i].drzewo;
							for (int y = 0; y < drogi; y++)
							{
								if (drzewa[y].drzewo == dr)
								{
									drzewa[y].drzewo = dr2;
								}

							}

							drogi++;

						}



					}
					else if (drogasort[x].pocz == drzewa[i].pocz && drogasort[x].kon == drzewa[j].pocz)
					{
						sprawdzenie = 1;

						if (drzewa[j].drzewo == drzewa[i].drzewo)
						{
							siz++;
						}
						else
						{
							turystyka t;
							t.pocz = drogasort[x].pocz;
							t.kon = drogasort[x].kon;
							t.wartosc = drogasort[x].wartosc;
							t.drzewo = drzewa[i].drzewo;
							drzewa.push_back(t);


							int dr = drzewa[j].drzewo;
							int dr2 = drzewa[i].drzewo;
							for (int y = 0; y < drogi; y++)
							{
								if (drzewa[y].drzewo == dr)
								{
									drzewa[y].drzewo = dr2;
								}

							}

							drogi++;

						}


					}
					else if (drogasort[x].pocz == drzewa[i].kon && drogasort[x].kon == drzewa[j].kon)
					{

					sprawdzenie = 1;

					if (drzewa[j].drzewo == drzewa[i].drzewo)
					{
						siz++;
					}
					else
					{
						turystyka t;
						t.pocz = drogasort[x].pocz;
						t.kon = drogasort[x].kon;
						t.wartosc = drogasort[x].wartosc;
						t.drzewo = drzewa[i].drzewo;
						drzewa.push_back(t);


						int dr = drzewa[j].drzewo;
						int dr2 = drzewa[i].drzewo;
						for (int y = 0; y < drogi; y++)
						{
							if (drzewa[y].drzewo == dr)
							{
								drzewa[y].drzewo = dr2;
							}

						}

						drogi++;

					}

					}
					else
					{

						ilocz++;


					}



				}
			}
		}



		int temp = drogi * drogi;

		if (temp == ilocz)
		{
			int t = -1;
			turystyka t2;
			t2.pocz = drogasort[x].pocz;
			t2.kon = drogasort[x].kon;
			t2.wartosc = drogasort[x].wartosc;

			for (int z = 0; z < drogi; z++)
			{

				if (drogasort[x].pocz == drzewa[z].pocz || drogasort[x].pocz == drzewa[z].kon || drogasort[x].kon == drzewa[z].pocz || drogasort[x].kon == drzewa[z].kon)
				{
					t2.drzewo = drzewa[z].drzewo;
					t = 2;
				}

			}

			if (t == -1)
			{
				t2.drzewo = podd;
				podd++;
				
			}


			drzewa.push_back(t2);
			drogi++;

		}


	}





}

void Turystyka::setilemiast(int N)
{
	iloscmiast = N;
}


void Turystyka::setiledrog(int X)
{
	iloscdrog = X;
}




void Turystyka::settab(int miastoa, int miastob, int wart)
{
	turystyka t;
	t.pocz = miastoa;
	t.kon = miastob;
	t.wartosc = wart;
	droga.push_back(t);
	drogasort.push_back(t);
}


void Turystyka::sety(int sskad, int gdzie, int ile)
{
	skad = sskad;
	dokad = gdzie;
	ileosob = ile;
}


void Turystyka::sort()
{
	for (int i = 0; i < iloscdrog; i++)
	{
		for (int j = 1; j < iloscdrog - i; j++)
		{
			if (drogasort[j - 1].wartosc < drogasort[j].wartosc)
			{
				std::swap(drogasort[j - 1], drogasort[j]);
			}
		}
	}

}


void Turystyka::sortmiast()
{
	for (int i = 0; i < miasta.size(); i++)
	{
		for (int j = 1; j <  miasta.size(); j++)
		{
			if (miasta[j - 1].miasto > miasta[j].miasto)
			{
				std::swap(miasta[j - 1], miasta[j]);
			}
		}
	}

}


void Turystyka::szukmiasta()
{
	int temp;
	int temp2;
	int temp3;
	int temp4;
	wierz w;
	w.miasto = drzewa[0].pocz;
	miasta.push_back(w);
	w.miasto = drzewa[0].kon;
	miasta.push_back(w);
	int siz = miasta.size();
	for (int j = 1; j < drzewa.size(); j++)
	{
		temp = 0;
		temp2 = 0;
		temp3 = 0;
		temp4 = 0;

		for (int x = 0; x < miasta.size(); x++)
		{
			if (miasta[x].miasto != drzewa[j].pocz)
			{
				temp++;
			}

			if (miasta[x].miasto != drzewa[j].kon)
			{
				temp2++;
			}

		}

		if (temp == siz)
		{
			w.miasto = drzewa[j].pocz;
			miasta.push_back(w);
			temp3++;
		}

		if (temp2 == siz)
		{
			w.miasto = drzewa[j].kon;
			miasta.push_back(w);
			temp4++;
		}

		if (temp3 == 1)
		{
			siz++;
		}

		if (temp4 == 1)
		{
			siz++;
		}

	}
}





void Turystyka::szukanie(int skad, int dokad)
{
	int droga;
	int rozmiar;

	int sprawdz;


	temp t;

	for (int i = 0; i < miasta.size(); i++)
	{
		if (miasta[i].miasto == skad)
		{
			miasta[i].odwiedz = true;
			t.nrmiasta = miasta[i].miasto;
			t.lokalizacja = i;
			odwiedzone.push_back(t);


			break;
		}

	}
	int jestemnumer = odwiedzone[0].nrmiasta;
	int jestem = odwiedzone[0].lokalizacja;


	int cos;

	while (jestemnumer != dokad)
	{
		cos = 0;


		for (int j = 0; j < drzewa.size(); j++)
		{
			if (miasta[jestem].miasto == drzewa[j].pocz)
			{
				sprawdz = 0;
				for (int x = 0; x < miasta.size(); x++)
				{
					if (drzewa[j].kon == miasta[x].miasto && miasta[x].odwiedz == false)
					{
						miasta[x].odwiedz = true;
						t.lokalizacja = x;
						t.nrmiasta = miasta[x].miasto;
						odwiedzone.push_back(t);
						sprawdz = 1;
					//	std::cout << "dodalem: " << t.nrmiasta << std::endl;
						break;
					}
				}

				if (sprawdz == 0)
				{
					cos++;
				}
				else
				{
					break;
				}


			}
			else if (miasta[jestem].miasto == drzewa[j].kon)
			{
				sprawdz = 0;

				for (int x = 0; x < miasta.size(); x++)
				{			
					if (drzewa[j].pocz == miasta[x].miasto && miasta[x].odwiedz == false)
					{
						miasta[x].odwiedz = true;
						t.lokalizacja = x;
						t.nrmiasta = miasta[x].miasto;
						odwiedzone.push_back(t);
						sprawdz = 1;
					//	std::cout << "dodalem: " << t.nrmiasta << std::endl;
						break;
					}
				}

				if (sprawdz == 0)
				{
					cos++;
				}
				else
				{
					break;
				}

			}
			else
			{
				cos++;
			}

		}

		if (cos == drzewa.size())
		{
			odwiedzone.pop_back();
			//std::cout << "usuwam" << std::endl;
		}

			rozmiar = odwiedzone.size() - 1;

		jestem = odwiedzone[rozmiar].lokalizacja;
		jestemnumer = odwiedzone[rozmiar].nrmiasta;
	}




}



void Turystyka::licz()
{
	int osoby=-1;
	for (int i = 1; i < odwiedzone.size(); i++)
	{

		for (int j = 0; j < drzewa.size(); j++)
		{
			if ((odwiedzone[i - 1].nrmiasta == drzewa[j].pocz && odwiedzone[i].nrmiasta == drzewa[j].kon) || (odwiedzone[i - 1].nrmiasta == drzewa[j].kon && odwiedzone[i].nrmiasta == drzewa[j].pocz))
			{
				if (osoby<0||osoby > drzewa[j].wartosc)
				{
					osoby = drzewa[j].wartosc;
				}
			}
		}
	}


	osoby--;
	int ile = 0;
	int tm = ileosob;
	while (tm > 0)
	{
		tm = tm - osoby;
		ile++;
	}
	std::cout << ile << std::endl;
}



void Turystyka::wyswietodwiedzone()
{
	for (int j = 0; j < odwiedzone.size(); j++)
	{
		std::cout << odwiedzone[j].nrmiasta <<"  ";
	}
	std::cout << std::endl << std::endl;
}



void Turystyka::wyswietldroga()
{
	for (int j = 0; j < iloscdrog; j++)
	{
		std::cout << droga[j].pocz << "  ";
		std::cout << droga[j].kon << "  ";
		std::cout << droga[j].wartosc << std::endl;
	}
	std::cout << std::endl << std::endl;
}

void Turystyka::wyswietldrogasort()
{
	for (int j = 0; j < iloscdrog; j++)
	{
		std::cout << drogasort[j].pocz << "  ";
		std::cout << drogasort[j].kon << "  ";
		std::cout << drogasort[j].wartosc << std::endl;
	}
	std::cout << std::endl << std::endl;
}


void Turystyka::wyswietldrzewa()
{
	for (int j = 0; j <drzewa.size(); j++)
	{
		std::cout << drzewa[j].pocz << "  ";
		std::cout << drzewa[j].kon << "  ";
		std::cout << drzewa[j].wartosc << "  ";
		std::cout << drzewa[j].drzewo << std::endl;
	}
	std::cout << std::endl << std::endl;
}



void Turystyka::wyswietlmiasta()
{
	std::cout << std::endl << std::endl;
	for (int i = 0; i < miasta.size(); i++)
	{
		std::cout << miasta[i].miasto << "  ";
	}
	std::cout << std::endl << std::endl;
}






int main()
{
	int a = -1;
	int b = -1;
	while (a != 0 || b != 0)
	{


		int ilemiast;
		int iledrog;

		std::cin >> ilemiast;
		std::cin >> iledrog;
		Turystyka t;


		t.setiledrog(iledrog);
		t.setilemiast(ilemiast);

		int miastoa;
		int miastob;
		int ile;

		for (int i = 0; i < iledrog; i++)
		{
			std::cin >> miastoa;
			std::cin >> miastob;
			std::cin >> ile;
			t.settab(miastoa, miastob, ile);
		}

		int skad;
		int dokad;
		int ileosob;


		std::cin >> skad;
		std::cin >> dokad;
		std::cin >> ileosob;

		t.sety(skad, dokad, ileosob);



		std::cin >> a;
		std::cin >> b;

		//t.wyswietldroga();
		t.sort();

		//	t.wyswietldrogasort();

		t.Drzewa();
		//	t.wyswietldrzewa();

		t.szukmiasta();
		t.sortmiast();
		//t.wyswietlmiasta();
		t.szukanie(skad, dokad);

		//t.wyswietodwiedzone();

		t.licz();
	}
		return 0;


}