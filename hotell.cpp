#include<iostream>
using namespace std;

class Hotel {
private:
    struct Node {
        int id, date;
        string name, roomtype;
        Node* next;
    };
public:
    Node* head = NULL;
    void insert();
    void menu();
    void update();
    void search();
    void del();
    void sort();
    void show();
};

void Hotel::menu() {
    int choice;
    cout << "\nWelcome To Hotel Management System Application\n" << endl;
    cout << "\n\t__ Hotel Management System___";
    cout << "\n\nS.No       Functions              Desciption       " << endl;
    cout << "1\tAllocate Room\t\tInsert New Room";
    cout << "\n2\tSearch Room\t\tSearch Room with RoomID";
    cout << "\n3\tUpdate Room\t\tUpdate Room Record";
    cout << "\n4\tDelete Room\t\tDelete Room with RoomID";
    cout << "\n5\tShow Room Records\tShow All the Room Records";
    cout << "\n6\tExit" << endl;

    cout << "Enter Your Choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        insert();
        menu();
        break;

    case 2:
        search();
        menu();
        break;

    case 3:
        update();
        menu();
        break;

    case 4:
        del();
        menu();
        break;

    case 5:
        sort();
        show();
        menu();
        break;

    case 6:
        return;

    default:
        cout << "Invalid Choice";
    }
}

void Hotel::insert() {
    cout << "\n\t___ Hotel Management System__";
    Node* new_node = new Node;
    cout << "\nEnter Room ID: ";
    cin >> new_node->id;

    cout << "\nEnter Customer Name: ";
    cin >> new_node->name;

    cout << "\nEnter Allocated Date: ";
    cin >> new_node->date;

    cout << "\nEnter Room Type (single/double/twin): ";
    cin >> new_node->roomtype;

    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    }
    else {
        Node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    cout << "\n\t\t New Room Inserted";
}

void Hotel::search() {
    cout << "\n\t__ Hotel Management System___";
    int t_id;
    if (head == NULL) {
        cout << "\n\nLinked List is Empty";
    }
    else {
        cout << "\n\nEnter Room ID: ";
        cin >> t_id;
        Node* ptr = head;
        while (ptr != NULL) {
            if (t_id == ptr->id) {
                cout << "\n\nRoom ID: " << ptr->id;
                cout << "\n\nCustomer Name: " << ptr->name;
                cout << "\n\nRoom Allocated: " << ptr->date;
                cout << "\n\nRoom Type: " << ptr->roomtype;
            }
            ptr = ptr->next;
        }
    }
}

void Hotel::update() {
    cout << "\n\t__ Hotel Management System___";
    int t_id;
    if (head == NULL) {
        cout << "\n\nLinked List is Empty";
    }
    else {
        cout << "\n\nEnter Room ID: ";
        cin >> t_id;
        Node* ptr = head;
        while (ptr != NULL) {
            if (t_id == ptr->id) {
                cout << "\n\nEnter Room ID: ";
                cin >> ptr->id;

                cout << "\n\nEnter Customer Name: ";
                cin >> ptr->name;

                cout << "\n\nEnter Allocated Date: ";
                cin >> ptr->date;

                cout << "\n\nEnter Room Type (single/double/twin): ";
                cin >> ptr->roomtype;

                cout << "\n\nRecord Updated Successfully!";
            }
            ptr = ptr->next;
        }
    }
}

void Hotel::del() {
    cout << "\n\t__ Hotel Management System___";
    int t_id;
    if (head == NULL) {
        cout << "\n\nLinked List is Empty";
    }
    else {
        cout << "\n\nEnter Room ID: ";
        cin >> t_id;
        if (t_id == head->id) {
            Node* ptr = head;
            head = head->next;
            delete ptr;
            cout << "Room Record Deleted Successfully!";
        }
        else {
            Node* pre = head;
            Node* ptr = head;
            while (ptr != NULL) {
                if (t_id == ptr->id) {
                    pre->next = ptr->next;
                    delete ptr;
                    cout << "Room Record Deleted Successfully!";
                    break;
                }
                pre = ptr;
                ptr = ptr->next;
            }
        }
    }
}

void Hotel::show() {
    Node* ptr = head;
    while (ptr != NULL) {
        cout << "\n\nRoomId: " << ptr->id;
        cout << "\n\nCustomer Name: " << ptr->name;
        cout << "\n\nAllocated Room: " << ptr->date;
        cout << "\n\nRoom Type: " << ptr->roomtype;
        ptr = ptr->next;
    }
}

void Hotel::sort() {
    if (head == NULL) {
        cout << "\n\n Linked List is Empty";
        menu();
    }

    int count = 0, t_date, t_id;
    string t_name, t_roomtype;
    Node* ptr = head;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }

    for (int i = 1; i <= count; i++) {
        Node* ptr = head;
        for (int j = 1; j < count; j++) {
            if (ptr->id > ptr->next->id) {
                t_id = ptr->id;
                t_name = ptr->name;
                t_date = ptr->date;
                t_roomtype = ptr->roomtype;

                ptr->id = ptr->next->id;
                ptr->name = ptr->next->name;
                ptr->date = ptr->next->date;
                ptr->roomtype = ptr->next->roomtype;

                ptr->next->id = t_id;
                ptr->next->name = t_name;
                ptr->next->date = t_date;
                ptr->next->roomtype = t_roomtype;
            }
            ptr = ptr->next;
        }
    }
}

int main() {
    Hotel h;
    h.menu();
    return 0;
}
