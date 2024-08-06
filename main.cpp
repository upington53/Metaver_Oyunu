#include "karakter.h"
using namespace std;

int* Karakter::id = new int(1); //Statik deðerin baþlangýç deðeri

int main (){
	int transfer;
	char tuslama;
	int karakter_no;
	Karakter* karakter[en_fazla_karakter_sayisi];
    int karakterSayisi = 2;
	for (int i = 0; i < karakterSayisi; ++i) {
        karakter[i] = new Karakter();
    }
    // Arka planda zaman geçiþi thread'i baþlatma komutuymuþ
    thread zamanThread[en_fazla_karakter_sayisi];
    for (int i = 0; i < karakterSayisi; ++i) {
        zamanThread[i] = thread(&Karakter::zamanGecisi, karakter[i]);
    }
    karakter[0]->degerAta(1000);
	karakter[1]->degerAta(2000);
	cout<<"Karakter1 in ID: "<< karakter[0]->getID() <<endl;
	cout<<"Karakter2 nin ID: "<< karakter[1]->getID() <<endl;
	cout<<"Baslangicta oynamak istediginiz karakter secimini yapiniz: \n"<< "Karakter1 icin 1; Karakter2 icin 2 tuslayiniz."<<endl;
	
	do {
		try {
			cin>>karakter_no;
			if (karakter_no != 1 && karakter_no != 2){
				throw 3;
			}
		}
		catch (int a) {
			cout << "Yanlis tuslama yaptiniz.";
			cout << "Yalnizca 1 veya 2 tuslayiniz !!!"<<endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
			ilkEkranYenile();
		}
	} while (karakter_no != 1 && karakter_no != 2);
	

	karakter_no -= 1;

while(true){
	ekranYenile();
	try {
		cin>>tuslama;
		if (tuslama != 'k' && tuslama != 'p' && tuslama != 'g' && tuslama != 'y' &&
    tuslama != 'u' && tuslama != 'a' && tuslama != 'd' && tuslama != 'w' &&
    tuslama != 's' && tuslama != 'b' && tuslama != 'q'){
		throw 'j';
		}
		else {
			switch (tuslama){
			case 'k': {
				cout<<"Karakter seciminizi yapiniz: \n"<< "Karakter1 icin 1; Karakter2 icin 2 tuslayiniz."<<endl;
				cin>>karakter_no;
				karakter_no -= 1;
			
				break;
			}
			case 'p':{
				cout<<"Lutfen transfer yapilacak bilgileri sirasiyla giriniz"<<endl;
				cout<<"Gonderen Kisi (kullanici1 icin 1 / kullanici2 icin 2), Gonderilecek Bakiye Miktari, Gonderilecek Kisi (kullanici1 icin 1 / kullanici2 icin 2)"<<endl;
			
				int kisi, x, y;
				cin>> kisi >> x >> y;
	
				if (kisi == 1 && y == 2) {
       		    karakter[1]->paraGonder(x);
            	karakter[0]->paraAzalt(x);
        		} 

				else if (kisi == 2 && y == 1) {
        		karakter[0]->paraGonder(x);
        		karakter[1]->paraAzalt(x);
        		} 

				else {
           		cout << "Gecersiz transfer bilgileri." << endl;
       			}
        		cout << "Karakter1 yeni bakiye: " << karakter[0]->bakiye << endl;
        		cout << "Karakter2 yeni bakiye: " << karakter[1]->bakiye << endl;

        		break;
			} 
				
			case 'g': {
				karakter[0]->gucKarsilastir();
				karakter[1]->gucKarsilastir();
				if ( karakter[0]->getGuc() > karakter[1]->getGuc() ) {
					cout<< "Karakter1'in gucu > Karakter2'in gucu "<<endl;
				} else if (karakter[0]->getGuc() < karakter[1]->getGuc()){
					cout<< "Karakter2'nin gucu > Karakter1'in gucu "<<endl;
				} else if (karakter[0]->getGuc() == karakter[1]->getGuc()){
					cout<< "Karakter2'nin gucu = Karakter1'in gucu "<<endl;
				}
				break;
			}
		
			case 'y': {
				karakter[karakter_no]->yemekYe();
				cout<< "Yeni Aclik: "<< karakter[karakter_no]->getAclik() <<endl;
				break;
			}
		
			case 'u': {
				karakter[karakter_no]->suIc();
				cout<< "Yeni Susuzluk: " << karakter[karakter_no]->getSusuzluk() <<endl;
				break;
			}
		
			case 'a': {
				karakter[karakter_no]->xYondeHareket -=10;
				break;
			}
		
			case 'd': {
				karakter[karakter_no]->xYondeHareket +=10;
				break;
			}
		
			case 'w': {
				karakter[karakter_no]->yYondeHareket +=10;
				break;
			}
		
			case 's': {
				karakter[karakter_no]->yYondeHareket -=10;
				break;
			}
		
			case 'b': {
				bool uyuyorMu;
				string uykuYazi;
				cout<<"Karakter uyuyor mu?"<<endl;
				cout<<"Evet icin: 'true'"<<endl;
				cout<<"Hayir icin: 'false'"<<endl;
				cin>> uykuYazi;
				if (uykuYazi == "true" || uykuYazi == "evet") {
     	  			uyuyorMu = true;
    			} else if (uykuYazi == "false" || uykuYazi == "hayir") {
     	 			uyuyorMu = false;
  				} else {
     	   		cout << "Gecersiz giris. Varsayilan olarak 'false' degeri atanacak." << endl;
     	  		uyuyorMu = false;
    			}
				karakter[karakter_no]->setUyuyor(uyuyorMu);
				break;
			}
		
			case 'q': {
    	        Karakter::temizle();
    	    	for (int i = 0; i < karakterSayisi; ++i) {
    	          delete karakter[i];
    	        }
     	         return 0;
    	   }
        
		}
	
		cout << "Karakter1'in konumu: "<< "X yonde= " <<karakter[0]->xYondeHareket <<", Y yonde= "<< karakter[0]->yYondeHareket<<endl;
		cout << "Karakter2'nin konumu: "<< "X yonde= " <<karakter[1]->xYondeHareket <<", Y yonde= "<< karakter[1]->yYondeHareket<<endl;
		cout << "Karakter1'in acligi: "<< karakter[0]->getAclik() << ", susuzlugu: "<<  karakter[0]->getSusuzluk()  <<endl;
		cout << "Karakter2'nin acligi: "<< karakter[1]->getAclik() << ", susuzlugu: "<<  karakter[1]->getSusuzluk()  <<endl;
 		cout << "Karakter1'in bakiye: " << karakter[0]->bakiye << endl;
 		cout << "Karakter2'nin bakiye: " << karakter[1]->bakiye << endl;
 		cout << "Karakter1'in uyku durumu: " << karakter[0]->uyumak << endl;
 	   	cout << "Karakter2'nin uyku durumu: " << karakter[1]->uyumak << endl;
    
		this_thread::sleep_for(chrono::milliseconds(2000));
			}	
	} catch (char n) {
		cout << "Yanlis tuslama yaptiniz !!!"<<endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
	}

}
return 0;
}
