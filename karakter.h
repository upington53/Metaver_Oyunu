#include <conio.h>
#include <iostream>   
#include <string>
#include <thread>
using namespace std;

const int en_fazla_karakter_sayisi = 10; 

class Karakter {
	private:
		int kimlik;
		int aclik;
		int susuzluk;
		static int *id;
		const int aclikAzalma = 10; 
    	const int susuzlukAzalma = 10; 
		
	public:
		int gonderilecek_bakiye;
		int guc;
		int bakiye;
		int xYondeHareket = 0;
		int yYondeHareket = 0;
		bool uyumak;
		
		
		Karakter (){
			kimlik = (*id)++; 
			aclik = 100; 
        	susuzluk = 100;
        	bakiye = 0; 
        	uyumak = false; 
		}
		
		int getID() const {
        	return kimlik;
		}
		
		static void temizle() {
        	delete id;
    	}
    	
		void degerAta(int bakiye){
			
			this->bakiye = bakiye;
			
		}
		
		void paraGonder(int gonderilecek_bakiye){
			this->bakiye += gonderilecek_bakiye;
		}
		void paraAzalt(int kalan_bakiye){
			this->bakiye -= kalan_bakiye;
		}
		
		void zamanGecisi() {
            //Threadler kullanarak her saniye açlýk ve susuzluðu güncelleyebiliyormuþuz
            while (true) {
                this_thread::sleep_for(chrono::seconds(10));
                if (this->aclik > 10) this->aclik = max(this->aclik - this->aclikAzalma, 10);
                if (this->susuzluk > 10) this->susuzluk = max(this->susuzluk - this->susuzlukAzalma, 10);
                if (this->aclik < 50 && this->susuzluk < 50) {
            	cout<< "Karakterlerin yemek yemesi veya su icmesi gerekmektedir!!!"<<endl;
				}
        	}
    	}
    	
		void yemekYe(){
			this->aclik += 10;
		}
		
		void suIc(){
			this->susuzluk += 10; 
		}
	
		int getAclik() const {
        	return aclik;
		}
		
		int getSusuzluk() const {
			return susuzluk;
		}
		
		void setUyuyor(bool durum) {
    		this->uyumak = durum;
		}

		void gucKarsilastir(){
			this->guc = (this->aclik + this->susuzluk)*this->bakiye;
		}
		
		int getGuc(){
			return guc;
		}


};

void ilkEkranYenile() {
		system("CLS");

		
		cout<<"Baslangicta oynamak istediginiz karakter secimini yapiniz: \n"<< "Karakter1 icin 1; Karakter2 icin 2 tuslayiniz."<<endl;
}

void ekranYenile() {
    system("CLS"); // Windows için ekraný temizleme komutuymuþ
    cout << "---------------- Metaverse Evrenine Hos Geldiniz ----------------" << endl;
    cout << "Oyun sirasinda karakter degistirmek icin k tuslayiniz" << endl;
    cout << "Para gondermek istiyorsaniz p tuslayiniz " << endl;
    cout << "Karakter guclerini karsilastirmak icin g tuslayiniz." << endl;
    cout << "Karaktere yemek yedirmek icin y tuslayiniz." << endl;
    cout << "Karaktere su icirmek icin u tuslayiniz." << endl;
    cout << "Karakterin yukari cikmasi icin w tusuna; asagi inmesi icin s tusuna basiniz." << endl;
    cout << "Karakterin saga gitmesi icin d; sola gitmesi icin a tusuna basiniz." << endl;
    cout << "Karakterin uyku durumunu guncellestirmek icin b tusuna basiniz." << endl;
    cout << "Oyundan cikmak icin q tusuna basiniz.\n" << endl;
}


