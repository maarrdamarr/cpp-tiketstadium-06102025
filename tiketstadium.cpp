#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Tiket {
    string nama;
    string kategori;
    int jumlah;
    double harga;
    double total;
};

void tampilkanHeader() {
    cout << "\n========================================\n";
    cout << "   SISTEM PEMESANAN TIKET STADION\n";
    cout << "========================================\n";
}

void tampilkanKategori() {
    cout << "\nKategori Tiket:\n";
    cout << "1. VIP          - Rp 500,000\n";
    cout << "2. Tribune      - Rp 250,000\n";
    cout << "3. Festival     - Rp 150,000\n";
    cout << "4. Ekonomi      - Rp 75,000\n";
}

double getHargaTiket(int pilihan) {
    switch(pilihan) {
        case 1: return 500000;
        case 2: return 250000;
        case 3: return 150000;
        case 4: return 75000;
        default: return 0;
    }
}

string getKategoriNama(int pilihan) {
    switch(pilihan) {
        case 1: return "VIP";
        case 2: return "Tribune";
        case 3: return "Festival";
        case 4: return "Ekonomi";
        default: return "Tidak Valid";
    }
}

void tampilkanStruk(Tiket t) {
    cout << "\n========================================\n";
    cout << "           STRUK PEMESANAN\n";
    cout << "========================================\n";
    cout << "Nama Pemesan  : " << t.nama << endl;
    cout << "Kategori      : " << t.kategori << endl;
    cout << "Jumlah Tiket  : " << t.jumlah << endl;
    cout << "Harga/Tiket   : Rp " << fixed << setprecision(0) << t.harga << endl;
    cout << "----------------------------------------\n";
    cout << "Total Bayar   : Rp " << fixed << setprecision(0) << t.total << endl;
    cout << "========================================\n";
    cout << "\nTerima kasih atas pemesanan Anda!\n";
}

int main() {
    Tiket pesanan;
    int pilihan;
    char lanjut;
    
    do {
        tampilkanHeader();
        
        cout << "\nMasukkan nama pemesan: ";
        cin.ignore();
        getline(cin, pesanan.nama);
        
        tampilkanKategori();
        cout << "\nPilih kategori (1-4): ";
        cin >> pilihan;
        
        if(pilihan < 1 || pilihan > 4) {
            cout << "Pilihan tidak valid!\n";
            continue;
        }
        
        pesanan.kategori = getKategoriNama(pilihan);
        pesanan.harga = getHargaTiket(pilihan);
        
        cout << "Jumlah tiket: ";
        cin >> pesanan.jumlah;
        
        if(pesanan.jumlah <= 0) {
            cout << "Jumlah tiket harus lebih dari 0!\n";
            continue;
        }
        
        pesanan.total = pesanan.harga * pesanan.jumlah;
        
        tampilkanStruk(pesanan);
        
        cout << "\nPesan tiket lagi? (y/n): ";
        cin >> lanjut;
        
    } while(lanjut == 'y' || lanjut == 'Y');
    
    cout << "\nProgram selesai. Sampai jumpa BY damar Dstadium!\n";
    
    return 0;
}
