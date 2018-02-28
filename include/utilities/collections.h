//
// Created by temdisponivel on 27/02/2018.
//

#ifndef ENGINE_COLLECTIONS_H
#define ENGINE_COLLECTIONS_H

#include "core/types.h"
#include "math.h"
#include "memory.h"

#define LIST_TEMPLATE template<typename T>

LIST_TEMPLATE
struct list {
    T *items;
    uint length;
    uint capacity;

    allocator allocator;
    deallocator deallocator;
};

LIST_TEMPLATE
list<T> *create_list(uint capacity);

LIST_TEMPLATE
void setup_list(list<T> *list);

LIST_TEMPLATE
void destroy_list(list<T> *list);

LIST_TEMPLATE
void release_list(list<T> *list);

LIST_TEMPLATE
void expand(list<T> *list);

LIST_TEMPLATE
void add(list<T> *list, T item);

LIST_TEMPLATE
void remove_at(list<T> *list, uint index);

LIST_TEMPLATE
int index_of(list<T> *list, T item);

LIST_TEMPLATE
void remove(list<T> *list, T item);

LIST_TEMPLATE
bool null_or_empty(list<T> *list);

LIST_TEMPLATE
void clear(list<T> *list);

// IMPLEMENTATION

LIST_TEMPLATE
list<T> *create_list(uint capacity) {
    list<T> *list = (struct list<T> *) memalloc(sizeof(struct list<T>));
    setup_list(list, capacity);

    return list;
}

LIST_TEMPLATE
void setup_list(list <T> *list, uint capacity) {
    capacity = (uint) fmaxf(capacity, 1);

    list->allocator = __default_allocator;
    list->deallocator = __default_deallocator;

    expand(list, capacity);
    list->length = 0;
}

LIST_TEMPLATE
void destroy_list(list <T> *list) {
    release_list(list);
    memfree(list);
}

LIST_TEMPLATE
void release_list(list <T> *list) {
    ENSURE(list->items != null);

    list->deallocator(list->items);
    list->capacity = 0;
    list->length = 0;
}

LIST_TEMPLATE
void expand(list <T> *list, uint desired_capacity) {
    T *items = (T *) list->allocator(sizeof(T) * desired_capacity);
    if (list->items) {
        memcpy(items, list->items, list->length * sizeof(T));
        list->deallocator(list->items);
    }

    list->items = items;
    list->capacity = desired_capacity;
}

LIST_TEMPLATE
void add(list <T> *list, T item) {
    if (list->length >= list->capacity - 1)
        expand(list, list->capacity * 2);
    list->items[list->length++] = item;
}

LIST_TEMPLATE
void remove_at(list <T> *list, uint index) {
    if (index >= list->length)
        return;

    for (int i = index; i < list->length - 1; ++i) {
        list->items[i] = list->items[i + 1];
    }

    list->length--;
}

LIST_TEMPLATE
int index_of(list <T> *list, T item) {
    for (int i = 0; i < list->length; ++i) {
        T list_item = list->items[i];
        if (list_item == item)
            return i;
    }
    return -1;
}

LIST_TEMPLATE
void remove(list <T> *list, T item) {
    int index = index_of(list, item);
    if (index >= 0)
        remove_at(list, index);
}

LIST_TEMPLATE
bool null_or_empty(list <T> *list) {
    return list == null || list->length == 0;
}

LIST_TEMPLATE
void clear(list <T> *list) {
    if (null_or_empty(list))
        return;

    for (int i = 0; i < list->length; ++i) {
        list->items[i] = null;
    }

    list->length = 0;
}

#endif //ENGINE_COLLECTIONS_H
