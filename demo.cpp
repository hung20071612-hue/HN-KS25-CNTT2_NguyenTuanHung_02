#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* ===== Enum trang thai cong viec ===== */
enum Status {
    DANG_LAM = 1,
    HOAN_THANH,
    KHONG_HOAN_THANH
};

/* ===== Lop Work ===== */
class Work {
private:
    int id;
    string content;
    int hours;
    string createdDate;
    Status status;

public:
    Work(int _id, string _content, int _hours, string _date) {
        id = _id;
        content = _content;
        hours = _hours;
        createdDate = _date;
        status = DANG_LAM; 
    }
    int getId() {
        return id;
    }
    Status getStatus() {
        return status;
    }
    void setContent(string newContent) {
        content = newContent;
    }
    void setStatus(Status newStatus) {
        status = newStatus;
    }
    string statusToString() {
        if (status == DANG_LAM) return "Dang lam";
        if (status == HOAN_THANH) return "Hoan thanh";
        return "Khong hoan thanh";
    }

    // Hien thi thong tin
    void display() {
        cout << "ID: " << id << endl;
        cout << "Noi dung: " << content << endl;
        cout << "So gio: " << hours << endl;
        cout << "Ngay tao: " << createdDate << endl;
        cout << "Trang thai: " << statusToString() << endl;
        cout << "---------------------------\n";
    }
};

/* ===== Lop WorkManager ===== */
class WorkManager {
private:
    vector<Work> works;
    int autoId = 1;

public:
    // Hien thi danh sach
    void showAll() {
        if (works.empty()) {
            cout << "Danh sach cong viec rong!\n";
            return;
        }
        for (Work w : works) {
            w.display();
        }
    }
    // Them cong viec
    void addWork() {
        string content, date;
        int hours;

        cin.ignore();
        cout << "Nhap noi dung cong viec: ";
        getline(cin, content);

        cout << "Nhap so gio thuc hien: ";
        cin >> hours;

        cin.ignore();
        cout << "Nhap ngay tao (dd/MM/yyyy): ";
        getline(cin, date);

        Work w(autoId++, content, hours, date);
        works.push_back(w);

        cout << "Them cong viec thanh cong!\n";
    }

    // Cap nhat noi dung
    void updateContent() {
        int id;
        cout << "Nhap ID cong viec: ";
        cin >> id;

        for (auto &w : works) {
            if (w.getId() == id) {
                cin.ignore();
                string newContent;
                cout << "Nhap noi dung moi: ";
                getline(cin, newContent);
                w.setContent(newContent);
                cout << "Cap nhat thanh cong!\n";
                return;
            }
        }
        cout << "Khong tim thay cong viec!\n";
    }

    // Chuyen trang thai
    void changeStatus() {
        int id;
        cout << "Nhap ID cong viec: ";
        cin >> id;

        for (auto &w : works) {
            if (w.getId() == id) {
                if (w.getStatus() != DANG_LAM) {
                    cout << "Chi duoc doi trang thai cong viec Dang lam!\n";
                    return;
                }

                int choice;
                cout << "1. Hoan thanh\n";
                cout << "2. Khong hoan thanh\n";
                cout << "Chon: ";
                cin >> choice;

                if (choice == 1)
                    w.setStatus(HOAN_THANH);
                else
                    w.setStatus(KHONG_HOAN_THANH);

                cout << "Doi trang thai thanh cong!\n";
                return;
            }
        }
        cout << "Khong tim thay cong viec!\n";
    }

    // Loc cong viec theo trang thai
    void filterByStatus() {
        int choice;
        cout << "1. Dang lam\n";
        cout << "2. Hoan thanh\n";
        cout << "3. Khong hoan thanh\n";
        cout << "Chon: ";
        cin >> choice;

        for (Work w : works) {
            if (w.getStatus() == choice) {
                w.display();
            }
        }
    }
};

int main() {
    WorkManager manager;
    int choice;

    do {
        cout << "\n--------- MENU ---------\n";
        cout << "1. Hien thi danh sach\n";
        cout << "2. Them cong viec\n";
        cout << "3. Cap nhat noi dung cong viec\n";
        cout << "4. Chuyen trang thai cong viec\n";
        cout << "5. Loc cong viec theo trang thai\n";
        cout << "6. Thoat\n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            manager.showAll();
            break;
        case 2:
            manager.addWork();
            break;
        case 3:
            manager.updateContent();
            break;
        case 4:
            manager.changeStatus();
            break;
        case 5:
            manager.filterByStatus();
            break;
        case 6:
            cout << "Thoat chuong trinh!\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 6);

    return 0;
}

