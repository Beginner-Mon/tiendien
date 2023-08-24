#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
ofstream file;
typedef struct chiso{
    int cu;
    int moi;
} cs;
struct tienthang {
    cs dien;
    cs nuoc;
    float tiendien=0,dntt,dongia,tien_nuoc=0;
};

void get_dongia(tienthang *a){
    a->dongia =  a->tiendien/(a->dien.moi-a->dien.cu);
    a->tien_nuoc = 15000 * (a->nuoc.moi - a->nuoc.cu);
}
void get_tien(tienthang *a,tienthang*b){
    a->dongia = b->dongia;
    a->tiendien = b->dongia *(a->dien.moi - a->dien.cu);
    a->tien_nuoc = 15000 * (a->nuoc.moi - a->nuoc.cu);
}
void init(tienthang *a,string t){
    static int i = 1;
    cout << "nhap chi so dien cu "<< i <<endl;
    cin >> a->dien.cu; 
    cout << "nhap chi so dien moi "<< i <<endl;
    cin >> a->dien.moi;
    if (t == "cả nhà"){
        cout << "nhap tien dien "<< i <<endl;
        cin >> a->tiendien;
    }
    cout << "nhap chi so nuoc cu "<< i <<endl;
    cin >> a->nuoc.cu; 
    cout << "nhap chi so nuoc moi "<< i <<endl;
    cin >> a->nuoc.moi;
    if(t == "cả nhà"){
        cout << "nhap tien nuoc "<< i <<endl;
        cin >> a->tien_nuoc;
    }
    if (t == "cả nhà"){
        get_dongia(a); 
    }  
    ++i;
}
void output(tienthang a,string t){
    file << "\tTên chủ nhà: "<< t << endl;
    file <<"chỉ số điện cũ: " << a.dien.cu << endl;
    file <<"chỉ số điện mới: "<< a.dien.moi<<endl; 
    file <<"đơn giá điện: "<< a.dongia<<endl;
    file <<"tiền điện: "<< a.tiendien<<endl;
    file <<"chỉ số nước cũ: " << a.nuoc.cu << endl;
    file <<"chỉ số nước mới: "<< a.nuoc.moi<<endl; 
    file <<"đơn giá nước: "<< a.tien_nuoc<<endl;
}
void run(tienthang a,tienthang b,string t){
    init(&a,t);
    get_tien(&a,&b);
    output(a,t);
}

int main(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    file.open("demo.txt");
    if(file.is_open()){
        tienthang canha;
        file << "\t\ttháng " << 1 + ltm->tm_mon <<", năm " << 1900 + ltm->tm_year <<endl;
        init(&canha, "cả nhà");        
        // tienthang uyen;
        // run(uyen, "cô Uyên");
        tienthang tien;
        run(tien,canha, "cô Tiên");
    }
    file.close();
}


    

