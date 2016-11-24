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

struct match
{
    int round;
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

struct team
{
    char name[MAX_NAME_LGT];
    int matches;
    int points;
    int position;
    struct wins
    {
        int at_home;
        int away;
        int total;
    }wins;
    struct losses
    {
        int at_home;
        int away;
        int total;
    }losses;
    int ties;
    struct crowd
    {
        int at_home;
        int away;
        int total;
    }crowd;
};

typedef struct match Match;
typedef struct team Team;

int get_total_matches(char *file);
void get_matches(char *file, int total_matches, Match matches[total_matches]);
Match read_matches(FILE *fp);
void get_ties_above_four(int total_matches, Match matches[total_matches]);
void find_rounds_under(int total_matches, Match matches[total_matches]);
int find_rounds(int total_matches, int goals, int round_numbers[total_matches], int goals_in_round[total_matches], Match matches[total_matches]);
void print_matches(char *title, int length, Match match[length]);
void get_teams(int total_matches, Match matches[total_matches], Team teams[TOTAL_TEAMS]);
void find_team_names(int total_matches, Match matches[total_matches], char team_names[TOTAL_TEAMS][MAX_NAME_LGT]);
int compare (const void *a, const void *b);


int main(int argc, char *argv[]){
    char *file = "superliga-2015-2016";
    int total_matches = get_total_matches(file);
    
    Match matches[total_matches];
    Team teams[TOTAL_TEAMS];

    get_matches(file, total_matches, matches);


    //get_ties_above_four(total_matches, matches);
    //find_rounds_under(total_matches, matches);

    get_teams(total_matches, matches, teams);

}

int get_total_matches(char *file){
    FILE *fp = fopen(file,"r");
    int c;
    int newline_count = 0;

    while ( (c=fgetc(fp)) != EOF ) {
        if ( c == '\n' )
            ++newline_count;
    }
    /* Since the last line dosnt have a line shift, the loop wont count it up */
    ++newline_count;
    
    fclose(fp);
    
    return newline_count;
}

void get_matches(char *file, int total_matches, Match matches[total_matches]){
    FILE *fp = fopen(file,"r");
    
    for (int i = 0; i < total_matches; i++)
    {
        matches[i] = read_matches(fp);
    }
    fclose(fp);
}

Match read_matches(FILE *fp){
    Match tmp;
    int t = 0, h = 0;
    fscanf(fp," R%d %s %s %s %s - %s %d - %d %d.%d",
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

void get_teams(int total_matches, Match matches[total_matches], Team teams[TOTAL_TEAMS]){
    char team_names[TOTAL_TEAMS][MAX_NAME_LGT];

    find_team_names(total_matches, matches, team_names);
}

void find_team_names(int total_matches, Match matches[total_matches], char team_names[TOTAL_TEAMS][MAX_NAME_LGT]){
    char names[total_matches][MAX_NAME_LGT];

    for (int i = 0; i < total_matches; i++)
    {
        strcpy(names[i],matches[i].homeTeam.name);
    }
    
    qsort(names, total_matches, MAX_NAME_LGT, compare);

    int i = 0, j = 0;
    while (j <= TOTAL_TEAMS)
    {
        if (!strcmp(team_names[j],names[i]))
        {
            strcpy(team_names[j],names[i]);
            ++j;
            ++i;
        } else
            ++i;
    }

    for (int i = 0; i < TOTAL_TEAMS; i++)
    {
        printf("%s\n",team_names[i]);
    }
}

int compare(const void *a, const void *b) { 
    return strcmp(a, b); 
}

void get_ties_above_four(int total_matches, Match matches[total_matches]){
    int j = 0;
    Match tie_matches[total_matches];

    for (int i = 0; i < total_matches; i++)
    {
        if ((matches[i].homeTeam.goals == matches[i].awayTeam.goals) && (matches[i].homeTeam.goals + matches[i].awayTeam.goals >= 4))
        {
            tie_matches[j] = matches[i];
            ++j;
        }
    }
    print_matches("Tie Matches With A Score Above Four",j,tie_matches);
}

void find_rounds_under(int total_matches, Match matches[total_matches]){
    int round_numbers[total_matches], goals_in_round[total_matches];
    int goals = 10;

    int total = find_rounds(total_matches, goals, round_numbers, goals_in_round, matches);

    printf("Found %d matches whichs total score was below 10:\n\n", total);
    for (int i = 0; i < total; i++)
    {
        printf("Round: %-5d Goals: %-5d\n",round_numbers[i], goals_in_round[i]);
    }
    free(round_numbers);
    free(goals_in_round);
}

int find_rounds(int total_matches, int goals, int round_numbers[total_matches], int goals_in_round[total_matches], Match matches[total_matches]){
    int j = 0;
    for (int i = 0; i < total_matches; i++)
    {
        if (matches[i].homeTeam.goals + matches[i].awayTeam.goals < goals)
        {
            round_numbers[j] = matches[i].round;
            goals_in_round[j] = matches[i].homeTeam.goals + matches[i].awayTeam.goals;
            ++j;
        }
    }
    round_numbers = (int *) realloc(round_numbers,j);
    goals_in_round = (int *) realloc(goals_in_round,j);
    return j;
}

void print_matches(char *title, int length, Match match[length]){
    printf("\n%s\n\n", title);
    for (int i = 0; i < length; i++)
    {
        printf("Round: %-5d | Day: %-5s | Date: %-15s | Teams: %5s vs %-5s | Score: %d - %d | Crowd: %-7d | \n",
            match[i].round,
            match[i].weekday,
            match[i].date,
            match[i].homeTeam.name,
            match[i].awayTeam.name,
            match[i].homeTeam.goals,
            match[i].awayTeam.goals,
            match[i].crowd);
    }
}

void away_champions(){

}
