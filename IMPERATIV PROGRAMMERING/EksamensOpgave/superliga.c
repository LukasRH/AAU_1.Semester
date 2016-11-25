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
};

typedef struct match Match;
typedef struct team Team;

int get_total_matches(char *file);
void get_matches(char *file, int total_matches, Match matches[total_matches]);
Match read_matches(FILE *fp);
void get_ties_above_four(int total_matches, Match matches[total_matches]);
void find_rounds_under(int total_matches, Match matches[total_matches]);
int find_rounds(int total_matches, int goals, int rounds[total_matches][total_matches], Match matches[total_matches]);
void print_matches(char *title, int length, Match match[length]);
void get_teams(int total_matches, Match matches[total_matches], Team teams[TOTAL_TEAMS]);
void find_team_names(int total_matches, Match matches[total_matches], Team teams[TOTAL_TEAMS]);
void find_team_matches(int total_matches, Match matches[total_matches], Team teams[TOTAL_TEAMS]);


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

    while ((c=fgetc(fp)) != EOF) {
        if (c == '\n')
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
    
    find_team_names(total_matches, matches, teams);
    //find_team_matches(total_matches, matches, teams);

    for (int i = 0; i < TOTAL_TEAMS; i++)
    {
        printf("%s\n",teams[i].name);
        //printf("%s\n",teams[i].wins.at_home);
        //printf("%s\n",teams[i].wins.away);
        //printf("%s\n",teams[i].wins.total);
    }
}

void find_team_names(int total_matches, Match matches[total_matches], Team teams[TOTAL_TEAMS]){
    int j = 0;
    for (int i = 0; i < 6; i++)
    {
        strcpy(teams[j].name, matches[i].homeTeam.name);
        ++j;
        strcpy(teams[j].name, matches[i].awayTeam.name);
        ++j;
    }
}

void find_team_matches(int total_matches, Match matches[total_matches], Team teams[TOTAL_TEAMS]){
    for (int i = 0; i < TOTAL_TEAMS; i++)
    {
        for (int j = 0; j < total_matches; i++)
        
        {
            if (teams[i].name == matches[j].homeTeam.name || matches[j].awayTeam.name)
            {
                teams[i].matches += 1;

                if (teams[i].name == matches[j].homeTeam.name && matches[j].homeTeam.goals > matches[j].awayTeam.goals)
                {
                    teams[i].wins.at_home += 1;
                } else
                {
                    teams[i].losses.at_home += 1;
                }

                if (teams[i].name == matches[j].awayTeam.name && matches[j].homeTeam.goals < matches[j].awayTeam.goals)
                {
                    teams[i].wins.away += 1;
                } else
                {
                    teams[i].losses.away += 1;
                }
            }
        }
       teams[i].wins.total =  teams[i].wins.at_home + teams[i].wins.away;
       teams[i].losses.total =  teams[i].losses.at_home + teams[i].losses.away;
    }
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
    int rounds[total_matches][total_matches];
    int goals = 10;

    int total = find_rounds(total_matches, goals, rounds, matches);

    printf("Found %d rounds whichs total score was below 10:\n\n", total);
    for (int i = 0; i < total; i++)
    {
        printf("Round: %-5d Goals: %-5d\n",rounds[0][i], rounds[1][i]);
    }
}

int find_rounds(int total_matches, int goals, int rounds[total_matches][total_matches], Match matches[total_matches]){
    int j = 0, goals_in_round = 0, number_rounds;
    number_rounds = matches[total_matches-1].round;
    int all_rounds[number_rounds][number_rounds];

    for (int i = 0; i < number_rounds; i++)
    {
        all_rounds[0][i] = i+1;

        for (int k = 0; k < total_matches; k++)
        {
            if (matches[k].round == all_rounds[0][i])
            {
                goals_in_round += matches[k].homeTeam.goals + matches[k].awayTeam.goals;
            }
        }

        all_rounds[1][i] = goals_in_round;
        goals_in_round = 0;
    }

    for (int i = 0; i < number_rounds; i++)
    {
        if (all_rounds[1][i] < goals)
        {
            rounds[0][j] = all_rounds[0][i];
            rounds[1][j] = all_rounds[1][i];
            ++j;
        }
    }


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
