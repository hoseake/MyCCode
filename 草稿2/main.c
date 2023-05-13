#include <stdio.h>

struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} /*book = {"C ”Ô—‘", "RUNOOB", "±‡≥Ã”Ô—‘", 123456}*/;

int main()
{
    struct Books;
    printf("title : %s\nauthor: %s\nsubject: %s\nbook_id: %d\n", Books.title, Books.author, Books.subject, Books.book_id);
}
