#pragma once

// An intrusive singly linked list (next pointer in the element), appended at the tail.
template <class T> struct LIST {
    T* head;
    T* tail;
    LIST() { tail = 0; head = 0; }
    void Append(T* n) {
        if (!tail) { tail = n; head = n; n->next = 0; }
        else { tail->next = n; n->next = 0; tail = n; }
    }
    void Remove(T* p) {
        T* prev;
        if (p == head) { head = p->next; prev = 0; }
        else { prev = head; while (prev->next != p) prev = prev->next; prev->next = p->next; }
        if (p == tail) tail = prev;
        p->next = 0;
    }
};
