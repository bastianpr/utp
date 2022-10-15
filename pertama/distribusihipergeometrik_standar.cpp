#include <iostream>  
    using namespace std;  
    
    void kesimpulan() {
    	cout << "Jadi, peluangnya adalah ";
	}
	
	void batasan() {
		cout << "Anda dapat menghitung peluang dari pengambilan sampel tanpa pengembalian, tapi setiap nilai yang dimasukkan tidak boleh kurang dari 1"<<endl;
		cout<<endl;
	}
	
    int main()  
    {  
    batasan();
    //untuk nilai awal
       long long int x,k,nbesar,nkecil;
    //untuk kepentingan menampung nilai
       long long int i, kn = 1, xn = 1, nbn = 1, nkn = 1;
    //untuk bagian atas sebagai yang dibagi 
    //nb = n besar, nk = n kecil.
       long long int kminx, nbmink, nkminx,  nbminknkminx;
    //untuk bagian bawah sebagai pembagi
    //nb = n besar, nk = n kecil. 
       long long int nbminnkz;
       
    //mulai memasukkan nilai argumen atau nilai awal
    cout<<"Masukkan jumlah populasi atau N (Misalnya 7) : ";
       cin>>nbesar;
    cout<<endl<<"Masukkan jumlah sampel atau n (Misalnya 3) : ";
       cin>>nkecil;
    cout<<endl<<"Masukkan jumlah sukses atau k (Misalnya 3) : ";
       cin>>k;
    cout<<endl<<"Masukkan jumlah sukses terambil atau x (Misalnya 1) : ";
	   cin>>x;
	cout<<endl;
	
	kminx = k - x;
	nbmink = nbesar - k;
	nkminx = nkecil - x;
	nbminknkminx = nbmink - nkminx;
	nbminnkz = nbesar - nkecil;

	//lanjutan untuk kepentingan menampung nilai
	  long long int kminxn = 1, nbminkn = 1, nkminxn = 1, nbminknkminxn = 1, nbminnkzn = 1;
	        
    //faktorial untuk nbesar, nkecil, k, x 
      for(i=1;i<=nbesar;i++){    
          nbn = nbn*i;    
      }    
      for(i=1;i<=nkecil;i++){
      	 nkn = nkn*i;
	  }
      for(i=1;i<=k;i++){
      	kn = kn*i;
	  }
      for(i=1;i<=x;i++){
      	xn = xn*i;
	  }
	//faktorial untuk sisa x untuk memenuhi k, hasil dari N-k, n-x dan hasil dari ( hasil n-x ) untuk memenuhi nilai N-k
      for(i=1;i<=kminx;i++){
      	kminxn = kminxn*i;
	  }
      for(i=1;i<=nbmink;i++){
      	 nbminkn = nbminkn*i;
	  }
	  for(i=1;i<=nkminx;i++){
      	 nkminxn = nkminxn*i;
	  }
	  for(i=1;i<=nbminknkminx;i++){
      	 nbminknkminxn = nbminknkminxn*i;
	  }
	//faktorial untuk n kecil bagian bawah untuk memenuhi N atas
	  for(i=1;i<=nbminnkz;i++){
      	 nbminnkzn = nbminnkzn*i;
	  }
	  
	//catatan : ^ berarti berada di atas dan v artinya berada di bawah
	//di (^k vn)!, kalikan x! dengan sisa bagi x untuk memenuhi nilai k tadi
	 long long int kiri = kminxn * xn;
	//di (^ N - K v n - x), kalikan hasil (n - x)! dengan sisa bagi (n - x)! untuk memenuhi sisa hasil (N - k)!
	 long long int kanan = nkminxn * nbminknkminxn;
	//Ini bagian bawah, kalikan n! dengan sisa bagi n! untuk memenuhi Nilai N!
	 long long int bawah = nbminnkzn * nkn;
	 
	 long long int hasilkiri = kn / kiri;
	 long long int hasilkanan = nbminkn / kanan;
	 
	 //kalikan keduanya dari yang telah dihasilkan di atas
	 long long int totalatas = hasilkiri * hasilkanan;
	 
	 //jumlahkan di bawah
	 long long int totalbawah = nbn / bawah;
	 
	long double destotalatas = totalatas, destotalbawah = totalbawah;
	long double destotalatasbawah = destotalatas / destotalbawah;
	long double jawaban[1] = {destotalatasbawah};
	 
	 //pemberitahuan mengenai nilai yang kemungkinan terlalu banyak sehingga terhitung secara tidak benar
     if(x < 1 && k < 1 && nkecil < 1 && nbesar < 1){
     cout<<endl;
     cout<<"Tidak dapat terdefinisikan karena nilai tidak sesuai"<<endl;
     cout<<endl; } else {
	 kesimpulan();
	 cout<< totalatas << "/" << totalbawah << " atau " << jawaban[0] << endl; }
      return 0;  
  }
