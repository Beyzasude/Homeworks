#include <iostream>
#include <cmath>
#include <string.h>
#define i sqrt(-1)
using namespace std;
void yazdir(int a, int b);

class Complex {
private:
	double reel;
	double imaginer;
public:
	Complex(); //default constuctor
	Complex(int a); //integer için conversion constructor
	Complex(double b);  //double için constuctor
	Complex(int c, int d); //iki parametre alıp birini reel kısma birini imajiner kısma atayan constuctor

	void setter(int c, int d) //privatedaki memberlara erişebilmek ve girilen değerleri bu memberlara atamak için set fonksiyonu
	{
		reel = c;
		imaginer = d;
	}
	int getReel() const //privatedaki reele erişebilmek için get fonksiyonu
	{
		return reel;
	}
	int getimaginer() const //privatedaki sanala erişebilmek için get fonksiyonu
	{
		return imaginer;
	}

	int Complexyap(int a, int b)  // reel ve imaginer kısmı girilen sayıyı karmasık sayi yapan fonksiyon
	{
		cin >> a;
		cin >> b;
		cout << "Karmasik yapmak istediginiz sayilari giriniz(isaretleriyle)" << endl;
		cout << "" << a << "" << b << "i" << endl;
	}

	void ComplexToplama(int reeltoplama, int imaginertoplama)  // iki karmasık sayıyı toplama
	{
		int a, b, c, d;
		cout << "Toplama yapmak istediginiz karmasik sayinin reel  kisimini giriniz" << endl;
		cin >> a;
		cout << "Toplama yapmak istediginiz karmasik sayinin imaginer kisimini giriniz" << endl;
		cin >> b;
		cout << "Toplama yapmak istediginiz karmasik sayinin reel kismini giriniz" << endl;
		cin >> c;
		cout << "Toplama yapmak istediginiz karmasik sayinin imaginer kisimini giriniz" << endl;
		cin >> d;
		reeltoplama = a + c;
		imaginertoplama = b + d;
		cout << "Toplam: " << endl;
		cout << reeltoplama << "" << imaginertoplama << "i" << endl;
	}
	void Complexcikartma(int reelcikarma, int imaginercikarma)  //iki karmasık sayıyı biribirinden çıkartma çıkartma
	{
		int a, b, c, d;
		cout << "Toplama yapmak istediginiz karmasik sayinin reel  kisimini giriniz" << endl;
		cin >> a;
		cout << "Toplama yapmak istediginiz karmasik sayinin imaginer kisimini giriniz" << endl;
		cin >> b;
		cout << "Toplama yapmak istediginiz karmasik sayinin reel kismini giriniz" << endl;
		cin >> c;
		cout << "Toplama yapmak istediginiz karmasik sayinin imaginer kisimini giriniz" << endl;
		cin >> d;
		reelcikarma = a - c;
		imaginercikarma = b - d;

		if (imaginercikarma > 0) {
			cout << "" << imaginercikarma << "+" << imaginercikarma << "i" << endl;
		}
		else {
			cout << "" << reelcikarma << "" << imaginercikarma << "i" << endl;
		}
	}

	void Complexbolme()  //karmasık sayılarda bölme işlemi
	{
		double gercek, sanal, gercel, karmasik;
		double t1, t2, k1, k2;
		cout << "karmasik sayinin reel ve sanal kisimlarini sirasiyla  giriniz" << endl;
		cin >> gercel;
		cin >> sanal;
		cout << "karmasik sayinin reel ve sanal kisimlarini sirasiyla giriniz" << endl;
		cin >> gercek;
		cin >> karmasik;
		t1 = (gercel * gercek) + (sanal * karmasik);  //karmasık sayılarda bölme işlemi yapılırken eşlenikle çarpılır.
		t2 = (gercek * gercek) + (karmasik * karmasik);
		double tam = t1 / t2;
		k1 = (sanal * gercek) - (gercel * karmasik);
		k2 = (gercek * gercek) + (karmasik * karmasik);
		double kompleks = k1 / k2;
		if (kompleks < 0) {
			cout << " bolüm: " << tam << kompleks << "i" << endl;
		}
		else {

			cout << "bolüm: " << tam << "+" << kompleks << "i" << endl;

		}

	}
};
int main()
{
	Complex s1, s2,s3, s4;
	yazdir(s1.getReel(), s1.getimaginer());
	s2.Complexyap(s2.getReel(), s2.getimaginer());
	s2.ComplexToplama(s2.getReel(), s2.getimaginer());
	s2.Complexcikartma(s2.getReel(), s2.getimaginer());
	s3.Complexbolme();
	Complex(8, 4);
	Complex(3);
	Complex(6.1);

	return 0;
}
void yazdir(int a, int b) 
{
	cout << "Olusturmak istediginiz karmasik sayiyi giriniz(isaretleriyle)" << endl;
	cin >> a;
	cin >> b;
	cout << "" << a << "" << b << "i" << endl;
	cout << "reel kisim: " << a << endl;
	cout << "sanal kisim:" << b << endl;
}

Complex::Complex()
{
	reel = 0;
	imaginer = 0;
}

Complex::Complex(int a)
{
	reel = a;
	imaginer = 0;
	cout << "Olusuturulan karmasik sayi:" << reel << "+" << imaginer << "i" << endl;
}
Complex::Complex(double b) 
{
	imaginer = 0;
	reel = b;
	cout << "olusturulan karmasik sayi:" << reel << "+" << imaginer << "i" << endl;
}
Complex::Complex(int c, int d) 
{
	reel = c;
	imaginer = d;
	cout << c << "+" << d << "i" << endl;
}
