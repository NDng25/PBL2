#include "Admin.h"
#include "DBHelper.h"

int checkid(vector<string> s, string id)
{
	int n = s.size();
	for (int i = 0; i < n; i++)
	{
		if (id == s[i])
		{
			cout << "id da ton tai, nhap id khac!" << endl;
			return 1;
		}
	}
	return 0;
}

Admin::Admin()
{
}

Admin::~Admin()
{

}

void Admin::Login()
{
	DBHelper db;
	vector<Account> acc;
	string username, password;
	username = "abc";
	password = "1";
	db.init();
	acc = db.SelectAccount(username,password);
	if (acc.empty()) cout << "Sai ten dang nhap hoac mat khau!" << endl;
}

void Admin::DisplayMovieList()
{
	DBHelper db;
	cout << "Danh sach phim: " << endl;
	db.init();
	vector<Movie> movielist;
	movielist = db.SelectMovie();
	int n = movielist.size();
	for (int i = 0; i < n; i++)
	{
		cout << movielist.at(i);
		cout << "------------------------------------------------" << endl;
	}
}

void Admin::AddMovie()
{
	DBHelper db;
	vector<Movie> m;
	db.init();
	m = db.SelectMovie();
	db.close();
	string gid, name, dir, main, release, end, des, genre;
	int run, price;
	int n = m.size();
	vector<string> id;
	for (int i = 0; i < n; i++)
	{
		id.push_back(m.at(i).getid());
	}
	cout << "Nhap thong tin phim: " << endl;
	do
	{
		cout << "id: ";
		fflush(stdin);
		cin >> gid;
	} while (checkid(id, gid));
	cout << "Ten phim: ";
	cin.ignore();
	getline(cin, name);
	cout << "Dao dien: ";
	fflush(stdout);
	getline(cin, dir);
	cout << "Dien vien: ";
	fflush(stdout);
	getline(cin, main);
	cout << "Ngay phat hanh (YYYYMMDD): ";
	fflush(stdout);
	getline(cin, release);
	cout << "Ngay dung chieu (YYYYMMDD): ";
	fflush(stdout);
	getline(cin, end);
	cout << "Mo ta: ";
	fflush(stdout);
	getline(cin, des);
	cout << "The loai: ";
	fflush(stdout);
	getline(cin, genre);
	cout << "Thoi luong: ";
	cin >> run;
	cout << "Gia ve: ";
	cin >> price;
	string s1 = "INSERT INTO movie VALUES (";
	string s=s1+"'"+gid+"','"+name+"','"+dir+"','"+main+"','"+release+"','"+end+"','"+des+"','"+genre+"',"+to_string(run)+","+to_string(price)+")";
	const char* str = s.c_str();
	db.init();
	db.Insert(str);
	db.close();
}

void Admin::DeleteMovie()
{
	DBHelper db;
	string id;
	vector<Movie> movielist;
	db.init();
	movielist = db.SelectMovie();
	int n = movielist.size();
	vector<string> idlist;
	for (int i = 0; i < n; i++)
	{
		idlist.push_back(movielist.at(i).getid());
	}
	do {
		cout << "Nhap id phim can xoa: ";
		cin >> id;
	} while (checkid(idlist, id) == 0);
	string s = "DELETE FROM movie WHERE movie_id = '" + id + "'";
	const char* str = s.c_str();
	db.init();
	db.Delete(str);
}

void Admin::UpdateMovie()
{
	string id,s;
	char c;
	DBHelper db;
	vector<Movie> m;
	vector<string> idlist;
	int choose;
	Movie m1;
	db.init();
	m = db.SelectMovie();
	for (int i = 0; i < m.size(); i++)
	{
		idlist.push_back(m.at(i).getid());
	}
	string str;
	int count = 0;
	do
	{
		cout << "Nhap id phim muon sua: ";
		cin >> id; 
		str = "SELECT COUNT(*) FROM movie WHERE movie_id = '" + id + "'";
		db.init();
		count = db.SelectCount(str);
		if (count == 0) cout << "id khong ton tai." << endl;
	} while (count == 0);
	
	for (int i = 0; i < m.size(); i++)
	{
		if (m.at(i).getid() == id)
		{
			m1 = m.at(i);
		}
	}
	//Movie m1;
	//db.init();
	//m1 = db.SelectMovie(id);
	do {
		cout << "Chon muc muon sua: ";
		cout << "1. Ten." << endl
			<< "2. Dao dien." << endl
			<< "3. Dien vien." << endl
			<< "4. Ngay phat hanh." << endl
			<< "5. Ngay dung chieu." << endl
			<< "6. Mo ta." << endl
			<< "7. The loai." << endl
			<< "8. Thoi luong." << endl
			<< "9. Gia ve." << endl;
		cin >> choose;
		switch (choose)
		{
		case 1: {
			cout << "Ten: ";
			cin.ignore();
			getline(cin, s);
			m1.setName(s);
		}
		case 2: {
			cout << "Dao dien: ";
			cin.ignore();
			getline(cin, s);
			m1.setDir(s);
		} break;
		case 3: {
			cout << "Dien vien: ";
			cin.ignore();
			getline(cin, s);
			m1.setCast(s);
		} break;
		case 4: {
			cout << "Ngay phat hanh: ";
			cin.ignore();
			getline(cin, s);
			m1.setRelease(s);
		} break;
		case 5: {
			cout << "Ngay dung chieu: ";
			cin.ignore();
			getline(cin, s);
			m1.setEnd(s);
		} break;
		case 6: {
			cout << "Mo ta: ";
			cin.ignore();
			getline(cin, s);
			m1.setDes(s);
		} break;
		case 7: {
			cout << "The loai: ";
			cin.ignore();
			getline(cin, s);
			m1.setGenre(s);
		} break;
		case 8: {
			cout << "Thoi luong: ";
			cin.ignore();
			getline(cin, s);
			m1.setRunning(stoi(s));
		} break;
		case 9: {
			cout << "Gia ve: ";
			cin.ignore();
			getline(cin, s);
			m1.setPrice(stoi(s));
		} break;
		default: cout << "loi roi!" << endl;
		}
		cout << "Nhan Y de tiep tuc sua." << endl;
		cin >> c;
	} while (c == 'Y' || c == 'y');
	string s1 = "UPDATE movie";
	string s2 = " SET movie_name ='"+m1.getName()+"',director='"+m1.getDir()+"',main_actor='"+m1.getCast()+"',release_date='"+m1.getRelease()+"',end_show='"+m1.getEnd()+"',description='"+m1.getDes()+"',genre='"+m1.getGenre()+"',running_time="+to_string(m1.getRunning())+",price ="+to_string(m1.getPrice());
	string s3 = " WHERE movie_id='" + id + "'";
	string s4 = s1 + s2 + s3;
	const char* str1 = s4.c_str();
	db.init();
	db.Insert(str1);
}
