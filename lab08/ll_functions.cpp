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
    if (h == nullptr) {
        cout << "This list is empty." << endl;
        return;
    }

    cout << "Printing the list:" << endl;
    LinkNodePtr cur = h;
    int index = 0;
    while (cur != nullptr) {
        cout << "Node #" << index << ": " << cur->name << ", " << cur->number << endl;
        cur = cur->link;
        index++;
    }
    cout << "--------\n";
}

void insertNodeAfter(LinkNodePtr& h) {
    if (h == nullptr) {
        cout << "Cannot insert in a non-existing link." << endl;
        return;
    }

    int pos = 0;
    string nom = "";
    int num = 0;
    cout << "Enter node position to insert new node after (enter negative number to exit): ";
    cin >> pos;
    if (pos < 0) {
        return;
    }

    int node_count = 0;
    LinkNodePtr count_ptr = h;
    while (count_ptr != nullptr) {
        node_count++;
        count_ptr = count_ptr->link;
    }

    if (pos >= node_count) {
        cout << "Position entered is illegal. Nothing inserted." << endl;
        return;
    }

    cout << "Enter data (name, then number): ";
    cin >> nom >> num;

    LinkNodePtr new_node = new LinkNode;
    new_node->name = nom;
    new_node->number = num;

    LinkNodePtr cur = h;
    for (int i = 0; i < pos; i++) {
        cur = cur->link;
    }

    new_node->link = cur->link;
    cur->link = new_node;
}

void findMax(LinkNodePtr h) {
    if (h == nullptr) {
        cout << "This list is empty." << endl;
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
        cout << "This list is empty." << endl;
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
