/*
** EPITECH PROJECT, 2021
** mylist.h
** File description:
** mylist
*/

#ifndef MYLIST_H_H
    #define MYLIST_H_H

    typedef struct linked_list_s {
        void *data;
        struct linked_list_s *next;
    } linked_list_t;

#endif /* !MYLIST_H_H */
