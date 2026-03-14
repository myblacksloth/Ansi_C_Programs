/* ***************************************************************************
* (C) 2026 Antonio Maulucci
*
* Esempio basilare di pseudo-oggetti in  C
*************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definisco struct di base
typedef struct Object o;

struct Object {
    // attributi
    int counter;
    char* name;
    // pseudo-metodi = puntatori a funzione
    // il puntatore a funzione deve essere speculare alla signature della funzione ---> returnValue, (pointer)(functionArguments)
    void (*increment_counter)(o*);
    void (*print_name)(o*);
    void (*print_counter)(o*);
};

// funzione di incremento del valore
void incrementa(o* obj) {
    if (!obj) return;
    obj->counter++;
}

// funzione di stampa del nome
void printName(o* obj) {
    if (!obj) return;
    printf("%s\n", obj->name);
}

// funzione di stampa del contatore
void printCounter(o* obj) {
    if (!obj) return;
    printf("%d\n", obj->counter);
}

o* create() {
    o* my_object = (o*)malloc(sizeof(o));
    if (!my_object) return NULL;


    // assegno le funzioni
    my_object ->increment_counter = incrementa;
    my_object ->print_name = printName;
    my_object ->print_counter = printCounter;
    /*
     * oppure, assegnazione diretta
     *my_object = (o){
             .increment_counter = incrementa,
             .print_name = printName,
             .print_counter = printCounter,
             .counter = 0,
             .name = NULL
         };
     */


    return my_object;
}

int main()
{
    /*
    // dichiaro l'oggetto
    o* my_object = (o*)malloc(sizeof(o));
    if (!my_object) return 1;

    // assegno le funzioni
    my_object ->increment_counter = incrementa;
    my_object ->print_name = printName;
    my_object ->print_counter = printCounter;
    */


    o* my_object = create();
    if (!my_object) return 1;

    // dichiaro un buffer
    char varc[]  = "ciao";
    // dichiaro campi dell'oggetto
    my_object -> counter = 198;
    my_object -> name = (char*)malloc(sizeof(char) * (strlen(varc) +1));
    if (!my_object -> name) return 1;
    strcpy(my_object -> name, varc);

    // utilizzo le funzioni assegnate come metodi
    printf("PRINT NAME\n");
    my_object -> print_name (my_object);
    printf("PRINT COUNTER\n");
    my_object -> print_counter (my_object);
    printf("INCREMENT COUNTER\n");
    my_object -> increment_counter (my_object);
    my_object -> increment_counter (my_object);
    printf("PRINT COUNTER\n");
    my_object -> print_counter (my_object);


    free(my_object -> name);
    my_object -> name = NULL;
    free(my_object);
    my_object = NULL;

    return 0;
}



/*
 * esempio con costante prototipo === design pseudo-OOP
 */
/*
    static const o object_template = {
        .increment_counter = incrementa,
        .print_name = printName,
        .print_counter = printCounter
    };
    o* create() {
        o* obj = malloc(sizeof(o));
        if (!obj) return NULL;

        *obj = object_template;

        return obj;
    }
 */



/*
 * esempio con vtable
 */
/*
    typedef struct {
        void (*increment_counter)(o*);
        void (*print_name)(o*);
        void (*print_counter)(o*);
    } ObjectMethods;

    struct Object {
        int counter;
        char* name;
        ObjectMethods* methods;
    };
    // metodi globali
    ObjectMethods object_methods = {
        incrementa,
        printName,
        printCounter
    };
    // creazione
    obj->methods = &object_methods;
    // utilizzo
    obj->methods->print_name(obj);
*/





/*
 * OOP FRAMEWORK
 */
/*
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct Object Object;

    struct Object {
        int counter;
        char *name;

        void (*increment_counter)(Object *self);
        void (*print_name)(Object *self);
        void (*print_counter)(Object *self);
    };

    // metodi

    void Object_increment_counter(Object *self) {
        if (!self) return;
        self->counter++;
    }

    void Object_print_name(Object *self) {
        if (!self) return;
        if (self->name)
            printf("%s\n", self->name);
        else
            printf("(null)\n");
    }

    void Object_print_counter(Object *self) {
        if (!self) return;
        printf("%d\n", self->counter);
    }

    // costruttore

    Object *Object_create(const char *name, int counter) {
        Object *obj = malloc(sizeof(Object));
        if (!obj) return NULL;

        obj->counter = counter;
        obj->name = NULL;

        if (name) {
            obj->name = malloc(strlen(name) + 1);
            if (!obj->name) {
                free(obj);
                return NULL;
            }
            strcpy(obj->name, name);
        }

        obj->increment_counter = Object_increment_counter;
        obj->print_name = Object_print_name;
        obj->print_counter = Object_print_counter;

        return obj;
    }

    // distruttore

    void Object_destroy(Object *obj) {
        if (!obj) return;
        free(obj->name);
        obj->name = NULL;
        free(obj);
    }

    // main

    int main(void) {
        Object *obj = Object_create("ciao", 198);
        if (!obj) return 1;

        printf("PRINT NAME\n");
        obj->print_name(obj);

        printf("PRINT COUNTER\n");
        obj->print_counter(obj);

        printf("INCREMENT COUNTER\n");
        obj->increment_counter(obj);
        obj->increment_counter(obj);

        printf("PRINT COUNTER\n");
        obj->print_counter(obj);

        Object_destroy(obj);
        return 0;
    }
*/
