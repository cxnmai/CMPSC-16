// file: ll_functions.cpp

// Used in the function createLL()
// This function is started for you correctly - you have to complete it.
//   Use the comments to help you figure out what to do.
void h_insert(LinkNodePtr& head, string nom, int num) {
    LinkNodePtr tmp_ptr;
    tmp_ptr = new LinkNode;

    tmp_ptr->name = nom;
    tmp_ptr->number = num;
    tmp_ptr->link = nullptr; 

// If the list is empty, the new node becomes the head
    if (head == nullptr) {
        head = tmp_ptr;
        return;
    }

// If the list is not empty, traverse to the last node
    LinkNodePtr cur = head;
    while (cur->link != nullptr) {
        cur = cur->link;
    }

// Change the pointer of the last node to the new node
    cur->link = tmp_ptr;
}

void createLL(LinkNodePtr& h) {
    string nom = "";
    int num = 0;
    while (true)
    {
        cout << "Enter name, then a number. To quit, enter 0 for the name AND 0 for the number:\n";
        if (!(cin >> nom >> num)) {
            return;
        }
        if (nom == "0" && num == 0) {
            break;
        }
        h_insert(h, nom, num);
    }
}

void printLL(LinkNodePtr h) {
    LinkNodePtr cur = h;
    while (cur != nullptr) {
        cout << cur->name << " " << cur->number << endl;
        cur = cur->link;
    }
}

void insertNodeAfter(LinkNodePtr& h) {
    int pos = 0;
    string nom = "";
    int num = 0;
    cout << "Enter position after which to insert (0 inserts at head): ";
    cin >> pos;
    cout << "Enter name and number to insert:\n";
    cin >> nom >> num;

    LinkNodePtr new_node = new LinkNode;
    new_node->name = nom;
    new_node->number = num;
    new_node->link = nullptr;

    if (h == nullptr || pos <= 0) {
        new_node->link = h;
        h = new_node;
        return;
    }

    LinkNodePtr cur = h;
    int i = 1;
    while (cur->link != nullptr && i < pos) {
        cur = cur->link;
        i++;
    }
    new_node->link = cur->link;
    cur->link = new_node;
}

void findMax(LinkNodePtr h) {
    if (h == nullptr) {
        cout << "Largest number in the list is: 0" << endl;
        return;
    }

    int max = h->number;
    LinkNodePtr cur = h->link;
    while (cur != nullptr) {
        if (cur->number > max) {
            max = cur->number;
        }
        cur = cur->link;
    }
    cout << "Largest number in the list is: " << max << endl;
}

void findMin(LinkNodePtr h) {
    if (h == nullptr) {
        cout << "Smallest number in the list is: 0" << endl;
        return;
    }

    int min = h->number;
    LinkNodePtr cur = h->link;
    while (cur != nullptr) {
        if (cur->number < min) {
            min = cur->number;
        }
        cur = cur->link;
    }
    cout << "Smallest number in the list is: " << min << endl;
}
