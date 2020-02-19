// ödev1.cpp : Bu program kullanıcının düz ,ters veya elmas şekillerinden birnini seçmesi , düz ve ters üçgenler için 3-15 arası tek sayı ,elmas için 5-15 arasında tek sayı girmesi eğer bu şartları sağlamıyorsa 3 seçim hakkıyla bunları bastırmaya yarar. 
//BEYZA SUDE EROL

#include <iostream>
using namespace std;
void DuzUcgen(int sayi);
void TersUcgen(int sayi);
void Elmas(int sayi);
int giris = 3;
int main()
{
    int secenek;
    int sayi;
    cout << "hangi sekli istiyorsaniz o sayiya basiniz." << endl << "1-Duz ucgen" << endl << "2-Ters ucgen"<<endl << "3-Elmas modeli" << endl << "4-cıkıs" << endl;
    cin >> secenek;
    system("cls");  // terminali şekil için temizler
	switch (secenek)
	{
	case 1:  // eğer seçenek buysa buradaki işlemler yapılır.
        cout << "3-15 arasinda tek sayi giriniz:";
        cin >> sayi;
		while (giris != 0)  // kullanıcının 3 hakkı vardır 
		{
			if (3 <= sayi && sayi <= 15 && sayi % 2 == 1)  // eğer sayı 3-15 arasında ve tekse 
			{
				DuzUcgen(sayi); // yukardaki şart geçerliyse duzuçgen fonksiyonu çağırılır.
				system("pause");

			}
			else
			{
				cout << "lutfen gecerli araliktan sayi giriniz: ";  // sayi geçerli şartı sağlamıyorsa tekrar sayı istenir.
				cin >> sayi;
				giris--;
			}
		}
		break;
	case 2:
        cout << "3-15 arasinda tek sayi giriniz: ";
        cin >> sayi;
		while (giris != 0)   // kullanıcının 3 hakkı vardır 
		{
			if (3 <= sayi && sayi <= 15 && sayi % 2 == 1)  // eğer sayı 3-15 arasında ve tekse 
			{
				TersUcgen(sayi);    // yukardaki şart geçerliyse tersuçgen fonksiyonu çağırılır.
				system("pause");

			}
			else
			{
				cout << "lutfen gecerli araliktan sayi giriniz: "; // sayi geçerli şartı sağlamıyorsa tekrar sayı istenir.
				cin >> sayi;
				giris--;
			}
		}
		break;
	case 3:
        cout << "5-15 arasinda tek sayi giriniz: ";
        cin >> sayi;
		while (giris != 0)      // kullanıcının 3 hakkı vardır 
		{
			if (3 <= sayi && sayi <= 15 && sayi % 2 == 1)    // eğer sayı 3-15 arasında ve tekse 
			{
				Elmas(sayi);  // yukardaki şart geçerliyse elmas fonksiyonu çağırılır.
				system("pause");

			}
			else
			{
				cout << "lutfen gecerli araliktan sayi giriniz: ";   // sayi geçerli şartı sağlamıyorsa tekrar sayı istenir.
				cin >> sayi;
				giris--;
			}
		}
		break;
	case 4:  // eğer kullanıcı 4 e basarsa programdan çıkılır.
		
		break;
	}
}
void DuzUcgen(int sayi)  // sadece for döngüsü ile düz üçgen basar
{
	int yildiz, bosluk;
	yildiz = 1;  //düz üçgen için yıldız sayısı 1 den başlar ve 3,5,7 diye 2 artarak devam eder.
	bosluk = sayi/2;   //bosluk sayısının ilk değeri girilen sayının yarısı kadardan başlar
	for (int i = 0; i < (sayi+1)/2; i++)  
	{
		for (int j = 0; j < bosluk; j++)   // j sayacı bosluktan küçük olduğu müddetçe bu döngü çalışır ve  bosluk basar.
		{
			cout << " ";
		}
		for (int k = 0; k < yildiz; k++)    // k sayacı yıldızdan küçük olduğu müddetçe bu döngü çalışır ve  yıldız basar.
		{
			cout << "*";
		}
		cout << endl;
	    bosluk--;  //boşluk sayısı giderek azalır
		yildiz += 2;  //yıldız sayısı bosluk sayısının 2 fazlası olarak artar.
	}
}    
void TersUcgen(int sayi)   //   sadece while döngüsü ile ters üçgen basar
{
	int  i, j, k;
	int yildiz, bosluk;
	yildiz = sayi;  //yıldız sayısı girilen  sayıya eşit olarak başlar.
	bosluk = 0; // ters üçgen için boşluk sayısı 0 dan başlar ve artarak devam eder.
    i = 0;
	while (i < sayi)   // i değişkenimiz sayidan küçük olduğu müddetçe bu döngü çalışır.
	{
		j = 0;
		while (j < bosluk)  // j sayacı bosluktan küçük olduğu müddetçe bu döngü çalışır ve  bosluk basar.
		{
			cout << " ";
			j++;
		}
		k = 0;
		while (k < yildiz)   // k sayacı yıldızdan küçük olduğu müddetçe bu döngü çalışır ve  yıldız basar.
		{
			cout << "*";
			k++;
		}
		cout << endl;
		bosluk++;  // bosluk sayısı artarak devam eder.
		yildiz -= 2;  // yıldız sayıları hep ikişer azalır.
		i++;
	}
    
}
void Elmas(int sayi)    //elmas şekli basar
{
	DuzUcgen(sayi);   //düz üçgen çağırılır
	TersUcgen(sayi);  //düz üçgenin altıa ters üçgen basılır ve elmas şekli oluşmuş olur.

}
