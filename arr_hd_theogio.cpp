#include "hd_theogio.cpp" 
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include <fstream>
using namespace std;

class arr_hd_theogio:public hd_theogio 
{
	private:
	vector<hd_theogio*> list_hd_theogio;
	public:
	
    void nhap() 
    {
    	//Nhap ma hoa don 
    	string mahd; 
	    cout << "Nhap ma hoa don moi: ";
        getline(cin,mahd);
		
    	//Doc file kiem tra maHD da ton tai hay chua 
    	ifstream filein;
		filein.open("HD_THEOGIO.TXT", ios::in);
        for(int i=0; i<list_hd_theogio.size(); i++)
		{
			if (strcmp(list_hd_theogio.size()->getMaHD(), mahd ==0)) 
            cout << "Ma hoa don da ton tai!" << endl;
            return; 
        }
        filein.close(); 
        
        //Nhap hoa don moi vao file 
        hd_theogio.nhap();
        this->list_hd_theogio.push_back(&hd_theogio); 
        ofstream fileout;
		fileout.open("HD_THEOGIO.TXT",ios::app);
		hd_theogio.ghifile(fileout);
		cout<<"Luu thanh cong !!"<<endl;
		fileout.close(); 
    } 
    
    //Tim kiem thong tin hoa don bang maHD 
    void search()
	{
//	    hd_theogio hdtg;
	    string mahd; 
	    cout<<"Nhap ma hoa don muon tim kiem: ";
		getline(cin,mahd);

    	//Doc file  
    	ifstream filein;
		filein.open("HD_THEOGIO.TXT", ios::in);
        for(int i=0; i<list_hd_theogio.size(); i++)
		{
			if (strcmp(list_hd_theogio.size()->getMaHD()), mahd ==0)) 
                hd_theogio::docfile(filein);
            else
			    cout<<"Ma khong ton tai"<<endl; 
        }
        filein.close(); 
	} 
 
    //Hien thi 
    void display()
	{
	    for(int i=0;i<list_hd_theongay.size();i++)
    	{
    		list_hd_theongay[i]->xuat();	
		}
	} 
	
    //Thong ke so luong hoa don theo gio
    int thongKeSoLuongHoaDonTheoGio() 
	{
	    int dem=0;
    	int d,m,y;
    	cout <<"Nhap ngay: "; cin>>d;
	    cout <<"Nhap thang: "; cin>>m;
    	cout <<"Nhap nam: "; cin>>y;
	for(int i=0; i< list_hd_theogio.size(); i++)
	{
		if(y == list_hd_theogio[i]->ngayHD.getY())
		{
			if(m == list_hd_theogio[i]->ngayHD.getM())
			{
				if(d == list_hd_theogio[i]->ngayHD.getD())
				{
					dem=dem+1;	
				}
			}
		}
	}
	ofstream fileout;
	fileout.open("ThongKeSoLuongHoaDonTheoGio.txt",ios::base());
	fileout<<"So luong hoa don ngay ";
	fileout<<d<<"/";
	fileout<<m<<"/";
	fileout<<y<<"la :";
	fileout<<dem<<endl;
	fileout.close();
	return dem; 
    }


    int delete()
	{
    // Tao file tempfile.txt de luu các hoa don khong bi xoa
    ofstream tempFile("tempfile.txt");
    
    // Nhap ma hoa don muon xoa thong tin
    string maHoaDonCanXoa;
    cout << "Nhap ma hoa don can xoa: ";
    getline(cin, maHoaDonCanXoa);
    
    // Mo file hd_theogio.txt de doc
    ifstream inFile("HD_THEOGIO.TXT");
    string line;
    bool daXoa = false; // Bien kiem tra xem co xoa hoa don hay khong
    
    // Doc file HD_THEOGIO.TXT và ghi cac hoa don khong bi xoa vào tempfile.txt
    while (getline(inFile, line)) 
	{
        // Tách du lieu cua moi hoa don thanh cac phan tu rieng biet
        string ma, ngay, tienStr;
        double tien;
        istringstream iss(line);
        iss >> ma >> ngay >> tienStr;
        tien = stod(tienStr);

        // Kiem tra xem ma hoa don co trung voi ma can xoa hay khong. Neu khong trung thi ghi thông tin hoa don vào tempfile.txt
        if (ma != maHoaDonCanXoa) 
		    {
               tempFile << line << endl;
            }
		    else 
	        {
            daXoa = true; // Ðanh dau da xoa
            }
    }

    // Ðóng file hd_theogio.txt và tempfile.txt
    inFile.close();
    tempFile.close();

    // Xóa file HD_THEOGIO.TXT và doi ten tempfile.txt thành HD_THEOGIO.TXT
    remove("HD_THEOGIO.TXT");
    rename("tempfile.txt", "HD_THEOGIO.TXT");

    cout << "Da xoa hoa don co ma " << maHoaDonCanXoa << " thanh cong\n";

    return 0;
    }  
	 
	 
    void option() 
	{
    	arr_hd_theogio listtheogio;
	    int luachon;
	    cout<<"Danh sach chuc nang:"<<endl
	    <<"1. Nhap moi thong tin."<<endl
	    <<"2. Tim kiem theo ma hoa don."<<endl
    	<<"3. Hien thi tat ca thong tin hoa don."<<endl
    	<<"4. Thong ke so luong thong tin hoa don theo ngay."<<endl
    	<<"5. Xoa thong tin hoa don theo ma hoa don."<<endl
    	<<"Vui long nhap lua chon theo so thu tu cua tung chuc nang!!"<<endl;
    	cout<<"Thuc hien chuc nang thu: ";cin>>luachon;
    	switch(luachon)
	    {
	    	case 1: //chuc nang nhap
		    	listtheogio.nhap();
		    	break;
	    	case 2: //chuc nang tim kiem
		    	listtheogio.search();
		    	break;
		    case 3: //chuc nang hien thi
	    		listtheogio.display();
		    	break;
	    	case 4: //chuc nang thong ke
		    	listtheogio.thongKeSoLuongHoaDonTheoGio();
		    	break;
	    	case 5: //chuc nang xoa thong tin
		    	listtheogio.delete(); 
		    	break;
	       	default: 
			cout<<"Khong phai chuc nang he thong!!";
			break;
    	}
	}
};


	 
 


