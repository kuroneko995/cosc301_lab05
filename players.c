#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <math.h>


struct player {
    char name[8];
    double height;
    struct player *next;
}; 

struct player *make_player_list(int len, char *names[], double heights[]) {
    /*
     * Create a linked list of length len of players given an array of
     * names (C strings) and heights (doubles).  Add new players to the
     * list by inserting ("pushing") onto the front of the list.
     * Note that names[i] corresponds to heights[i].
     * 
     * Return the linked list.
     */

    struct player *list = NULL;

    for (int i = 0; i <= len; i++) {
        char *thisname = strdup(names[i]);
        struct player *new = malloc(sizeof(struct player));
        strcpy(new->name, thisname);
        new->height = heights[i];
        new->next = list;
        list = new;
    }

    return list;
}

void print_players(struct player *players) {
    while (players != NULL) {
        printf("Name: %-30s Height: %d'%01d\"\n", players->name, (int)players->height, (int)(12.0 * (players->height - (int)players->height)));
        players = players->next;
    }
}

void add_player(struct player **p_players, char *name, double height) {
    // append the new player to the end of the list
    struct player *new = malloc(sizeof(struct player));
    strcpy(new->name, name);

    if (*p_players == NULL) {
        *p_players = new;
    } else {
        struct player *tmp = *p_players;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
}

void free_players(struct player *players) {
    while (players != NULL) {
        free(players);
        players = players->next;
    }
}

int main(int argc, char **argv) {

    char *names[] = {
        "Lebron James",
        "Kobe Bryant",
        "Paul Pierce",
        "Zydrunas Ilgauskas"
    };

    double heights[] = { 
        6 + 6.0/12.0,
        6 + 7.0/12.0,
        6 + 8.0/12.0,
        7 + 3.0/12.0,
    };

    struct player *player_list = make_player_list(4, names, heights);
    char *name;
    printf("What is the player's name? ");
    fflush(stdout);
    fgets(name, 32, stdin);

    double height = 0.0;
    printf("What is the player's height? (as a decimal number, e.g., 6.5 is 6'6\")? ");
    fflush(stdout);
    scanf("%lf", &height);

    add_player(&player_list, name, height);

    print_players(player_list);
    free_players(player_list);
    return 0;
}
