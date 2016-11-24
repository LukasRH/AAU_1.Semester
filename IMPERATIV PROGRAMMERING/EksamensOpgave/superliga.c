/*
    Exam in Imparative Programming 2016

    Student:    Lukas Rønsholt          Email:          lransh16@student.aau.dk
    Group:      B2-1a                   Field of study: Software

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NAME_LGT 4
#define MAX_ROUND_LGT 3
#define MAX_DATE_LGT 11
#define MAX_TIME_LGT 6
#define TOTAL_TEAMS 12

int get_total_matches(char *file);
void get_matches(char *file, int total_matches);
struct match read_matches(FILE *fp);
void get_all_teams();

struct team
{
    char name[MAX_NAME_LGT];
    int wins;
    int losses;
    int ties;
    int goals;
    int points;
};

struct match
{
    char round[MAX_ROUND_LGT];
    char weekday[MAX_NAME_LGT];
    char date[MAX_DATE_LGT];
    char time[MAX_TIME_LGT];
    struct homeTeam
    {
        char name[MAX_NAME_LGT];
        int goals;
    }homeTeam;
    struct awayTeam
    {
        char name[MAX_NAME_LGT];
        int goals;
    }awayTeam;
    int crowd;
};

int main(int argc, char *argv[]){
    char *file = "superliga-2015-2016";
    int total_matches = get_total_matches(file);
    struct team teams[TOTAL_TEAMS];

    if (argv[1] == "--print")
    {
        /* Do everything */
    }

    get_matches(file, total_matches);

}

int get_total_matches(char *file){
    FILE *fp = fopen(file,"r");
    int c;
    int newline_count = 0;

    while ( (c=
    fgetc(fp)) != EOF ) {
        if ( c == '\n' )
            ++newline_count;
    }
    /* Since the last line dosnt have a line shift, the loop wont count it up */
    ++newline_count;
    
    fclose(fp);
    
    return newline_count;
}

void get_matches(char *file, int total_matches){
    FILE *fp = fopen(file,"r");
    struct match matches[total_matches];

    for (int i = 0; i <= total_matches-1; i++)
    {
        matches[i] = read_matches(fp);
        printf("Round: %-5d | Day: %-5s | Date: %-15s | Teams: %5s vs %-5s | Score: %d - %d | Crowd: %-7d | \n",
            matches[i].round,
            matches[i].weekday,
            matches[i].date,
            matches[i].homeTeam.name,
            matches[i].awayTeam.name,
            matches[i].homeTeam.goals,
            matches[i].awayTeam.goals,
            matches[i].crowd);
    }
    fclose(fp);
}

struct match read_matches(FILE *fp){
    struct match tmp;
    int t, h;
    fscanf(fp," R%d %s %[0-9/] %[0-9] %s - %s %d - %d %d.%d",
        &tmp.round, 
        tmp.weekday,
        tmp.date,
        tmp.time,
        tmp.homeTeam.name,
        tmp.awayTeam.name,
        &tmp.homeTeam.goals,
        &tmp.awayTeam.goals,
        &t, &h);

    tmp.crowd = t * 1000 + h;

    return tmp;
}

void get_all_teams(){

}
