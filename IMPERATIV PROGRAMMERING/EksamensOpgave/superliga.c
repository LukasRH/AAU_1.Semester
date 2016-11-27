/*
    Exam in Imparative Programming 2016

    Student:    Lukas Rønsholt          Email:          lransh16@student.aau.dk
    Group:      B2-1a                   Field of study: Software

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_NAME_LGT 4
#define MAX_ROUND_LGT 3
#define MAX_DATE_LGT 11
#define MAX_TIME_LGT 6
#define TOTAL_TEAMS 12

/* Structs */

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
    struct goals{
        int goals_for;
        int goals_against;
        int goal_dif;
    }goals;
    int crow_at_home;
};

/* Typedefs */

typedef struct match Match;
typedef struct team Team;

/* Primary Functions Prototypes */

void get_matches(char *file, int total_matches, Match matches[total_matches]);
void get_teams(int total_matches, Match matches[total_matches], Team teams[TOTAL_TEAMS]);
void get_ties_above_four(int total_matches, Match matches[total_matches]);
void find_rounds_under(int total_matches, Match matches[total_matches]);
void away_champions(Team teams[TOTAL_TEAMS]);
void most_unpopular_team_in_15(int total_matches, Match matches[total_matches], Team teams[TOTAL_TEAMS]);
void find_matches_in_period(int total_matches, Match matches[total_matches], char *u, char *k1, char *k2);
void print_league_table(Team teams[TOTAL_TEAMS]);

/* Helper Functions Prototypes */

int get_total_matches(char *file);
Match read_matches(FILE *fp);
void set_teams(int total_matches, Team team[total_matches]);
void find_team_names(int total_matches, Match matches[total_matches], Team teams[TOTAL_TEAMS]);
void find_team_matches(int total_matches, Match matches[total_matches], Team teams[TOTAL_TEAMS]);
void find_team_stats(int total_matches, Match matches[total_matches], Team teams[TOTAL_TEAMS]);
void calculate_position(Team teams[TOTAL_TEAMS]);
int sort_after_points(const void *a, const void *b);
int team_in_match(Team team, Match match);
int home_team(Team team, Match match);
int find_rounds(int total_matches, int goals, int rounds[total_matches][total_matches], Match matches[total_matches]);
void print_matches(char *title, int length, Match match[length]);
void print_teams(char *title, int length, Team teams[TOTAL_TEAMS]);
int wins_more_away(Team team);
int find_matches_in_15(int total_matches, Match matches[total_matches], Match matches_in_15[total_matches]);
void get_crow(int length, Match matches[length], Team teams[TOTAL_TEAMS]);
void find_most_unpopular_team(Team teams[TOTAL_TEAMS], Team *most_unpopular);
int sort_after_crowd(const void *a, const void *b);
int find_matches(int total_matches, Match matches[total_matches], Match matches_in_period[total_matches], char *u, char *k1, char *k2);
int is_between_time(char match_time[MAX_TIME_LGT], char *k1, char *k2);
void clear();

/* Main Function */

int main(int argc, char *argv[]){
    char *file = "superliga-2015-2016";
    int total_matches = get_total_matches(file);
    int quit = 0, key;
    char u[] = "Son", k1[] = "13:15", k2[] = "14:15";

    Match matches[total_matches];
    Team teams[TOTAL_TEAMS];

    get_matches(file, total_matches, matches);
    get_teams(total_matches, matches, teams);

    if (argv[1] != NULL)
    {
        if (!strcmp(argv[1],"--print"))
        {
            get_ties_above_four(total_matches, matches);
            find_rounds_under(total_matches, matches);
            away_champions(teams);
            most_unpopular_team_in_15(total_matches,matches,teams);
            find_matches_in_period(total_matches, matches,"Son", "13:15", "14:15");
            print_league_table(teams);
        }
    } else
    {
        while (!quit)
        {
            printf("Danish Superliga 2015 - 2016\n\n"
                           "Available functions are:\n"
                           "1. Show tie matches with a score above 4.\n"
                           "2. Show rounds which total score is below 10.\n"
                           "3. Show teams who wins more matches away then home.\n"
                           "4. Show the teams who have had in 2015 the least spectators on home matches.\n"
                           "5. Show all matches played on a day between a time period.\n"""
                           "6. Print the league table.\n"""
                           "7. Quit.\n");
            scanf("%d",&key);
            switch(key){
                case 1:
                    clear();
                    get_ties_above_four(total_matches,matches);
                    printf("Press any key to continue");
                    getch();
                    clear();
                    break;
                case 2:
                    clear();
                    find_rounds_under(total_matches,matches);
                    printf("Press any key to continue");
                    getch();
                    clear();
                    break;
                case 3:
                    clear();
                    away_champions(teams);
                    printf("Press any key to continue");
                    getch();
                    clear();
                    break;
                case 4:
                    clear();
                    most_unpopular_team_in_15(total_matches,matches,teams);
                    printf("Press any key to continue");
                    getch();
                    clear();
                    break;
                case 5:
                    clear();
                    printf("Type in the day and time you wish to search for (Son 13:15 14:15): ");
                    fscanf(stdin,"%s %s %s", u, k1, k2);
                    find_matches_in_period(total_matches, matches,u, k1, k2);
                    printf("Press any key to continue");
                    getch();
                    clear();
                    break;
                case 6:
                    clear();
                    print_league_table(teams);
                    printf("Press any key to continue");
                    getch();
                    clear();
                    break;
                case 7:
                    clear();
                    quit = 1;
                    break;
                default:
                    clear();
                    break;
            }
        }
    }

    return 0;
}

/* Primary Functions*/

void get_matches(char *file, int total_matches, Match matches[total_matches]){
    FILE *fp = fopen(file,"r");
    
    for (int i = 0; i < total_matches; i++)
    {
        matches[i] = read_matches(fp);
    }
    fclose(fp);
}

void get_teams(int total_matches, Match matches[total_matches], Team teams[TOTAL_TEAMS]){

    set_teams(total_matches,teams);
    find_team_names(total_matches, matches, teams);
    find_team_matches(total_matches, matches, teams);
    find_team_stats(total_matches, matches, teams);
    calculate_position(teams);
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

void away_champions(Team teams[TOTAL_TEAMS]){
    int j = 0;
    Team away_winners[TOTAL_TEAMS];

    for (int i = 0; i < TOTAL_TEAMS; ++i) {
        if(wins_more_away(teams[i]))
        {
            away_winners[j] = teams[i];
            ++j;
        }
    }

    printf("Teams who have won more matches away then on home field\n\n");
    for (int k = 0; k < j; ++k) {
        printf("Team: %s \t Home wins: %d \t Away wins: %d \t Total wins %d\n",
               away_winners[k].name,
               away_winners[k].wins.at_home,
               away_winners[k].wins.away,
               away_winners[k].wins.total);
    }

}

void most_unpopular_team_in_15(int total_matches, Match matches[total_matches], Team teams[TOTAL_TEAMS]){
    Match matches_in_15[total_matches];
    Team most_unpopular;
    int total_matches_in_15 = find_matches_in_15(total_matches, matches, matches_in_15);

    get_crow(total_matches_in_15,matches_in_15,teams);
    find_most_unpopular_team(teams,&most_unpopular);

    printf("The Team in 2015 with least spectators on home field was %s with %d spectators\n",
          most_unpopular.name,
          most_unpopular.crow_at_home);

}

void find_matches_in_period(int total_matches, Match matches[total_matches], char *u, char *k1, char *k2){
    Match matches_in_period[total_matches];

    int total_matches_in_period = find_matches(total_matches,matches,matches_in_period,u,k1,k2);

    print_matches("Showing matches in given period",total_matches_in_period,matches_in_period);
}

void print_league_table(Team teams[TOTAL_TEAMS]){
    printf("|----------------------------League Table------------------------------|\n");
    printf("| Pos | Team | Matches | Wins | Ties | Lost | GF  | GA  | GD  | Points |\n");
    printf("|-----|------|---------|------|------|------|-----|-----|-----|--------|\n");
    for (int i = 0; i < TOTAL_TEAMS; ++i) {
        printf("| %-3d | %-4s |   %-5d |  %-3d |  %-3d |  %-3d | %-3d | %-3d | %-3d |   %-4d |\n",
               teams[i].position,
               teams[i].name,
               teams[i].matches,
               teams[i].wins.total,
               teams[i].ties,
               teams[i].losses.total,
               teams[i].goals.goals_for,
               teams[i].goals.goals_against,
               teams[i].goals.goal_dif,
               teams[i].points);
    }
}

/* Helper Functions (divide and conquer) */

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

void set_teams(int total_matches, Team team[total_matches]){
    for (int i = 0; i < TOTAL_TEAMS; ++i) {
        team[i].matches = 0;
        team[i].points = 0;
        team[i].position = 0;
        team[i].wins.away = 0;
        team[i].wins.at_home = 0;
        team[i].wins.total = 0;
        team[i].losses.away = 0;
        team[i].losses.at_home = 0;
        team[i].losses.total = 0;
        team[i].ties = 0;
        team[i].goals.goals_against = 0;
        team[i].goals.goals_for = 0;
        team[i].goals.goal_dif = 0;
        team[i].crow_at_home = 0;
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
        for (int j = 0; j < total_matches; j++)
        {
            if (team_in_match(teams[i],matches[j]))
            {
                teams[i].matches += 1;
            }
        }
    }
}

void find_team_stats(int total_matches, Match *matches, Team *teams){
    for (int i = 0; i < TOTAL_TEAMS; i++)
    {
        for (int j = 0; j < total_matches; j++)
        {
            if (team_in_match(teams[i],matches[j]))
            {
                if (home_team(teams[i],matches[j]))
                {

                    teams[i].goals.goals_for += matches[j].homeTeam.goals;
                    teams[i].goals.goals_against += matches[j].awayTeam.goals;

                    if (matches[j].homeTeam.goals > matches[j].awayTeam.goals)
                    {
                        teams[i].wins.at_home += 1;
                        teams[i].points += 3;
                    } else if (matches[j].homeTeam.goals < matches[j].awayTeam.goals)
                    {
                        teams[i].losses.at_home += 1;
                    } else
                    {
                        teams[i].ties += 1;
                        teams[i].points += 1;
                    }
                } else
                {
                    teams[i].goals.goals_for += matches[j].awayTeam.goals;
                    teams[i].goals.goals_against += matches[j].homeTeam.goals;

                    if (matches[j].awayTeam.goals > matches[j].homeTeam.goals)
                    {
                        teams[i].wins.away += 1;
                        teams[i].points += 3;
                    } else if (matches[j].awayTeam.goals < matches[j].homeTeam.goals)
                    {
                        teams[i].losses.away += 1;
                    } else
                    {
                        teams[i].ties += 1;
                        teams[i].points += 1;
                    }
                }
            }
        }
        teams[i].wins.total = teams[i].wins.at_home + teams[i].wins.away;
        teams[i].losses.total = teams[i].losses.at_home + teams[i].losses.away;
        teams[i].goals.goal_dif = teams[i].goals.goals_for - teams[i].goals.goals_against;
    }
}

void calculate_position(Team teams[TOTAL_TEAMS]){
    qsort(teams,TOTAL_TEAMS, sizeof(Team),sort_after_points);

    for (int i = 0; i < TOTAL_TEAMS; ++i) {
        teams[i].position = i + 1;
    }
}

int sort_after_points(const void *a, const void *b){
    Team *pa = (Team*)a;
    Team *pb = (Team*)b;

    if (pb->points == pa->points)
    {
        if (pb->goals.goal_dif == pa->goals.goal_dif)
        {
            return (pb->goals.goals_for - pa->goals.goals_for);
        } else
        {
            return (pb->goals.goal_dif - pa->goals.goal_dif);
        }
    } else
    {
        return (pb->points - pa->points);
    }
}

int team_in_match(Team team, Match match){
    if(!strcmp(team.name,match.homeTeam.name)||!strcmp(team.name,match.awayTeam.name)){
        return 1;
    } else {
        return 0;
    }
}

int home_team(Team team, Match match){
    if (!strcmp(team.name, match.homeTeam.name)){
        return 1;
    } else {
        return 0;
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
        printf("Round: %-5d | Day: %-5s | Time: %-5s | Date: %-15s | Teams: %5s vs %-5s | Score: %d - %d | Crowd: %-7d | \n",
               match[i].round,
               match[i].weekday,
               match[i].time,
               match[i].date,
               match[i].homeTeam.name,
               match[i].awayTeam.name,
               match[i].homeTeam.goals,
               match[i].awayTeam.goals,
               match[i].crowd);
    }
    printf("\n");
}

void print_teams(char *title, int length, Team teams[TOTAL_TEAMS]){
    printf("\n%s\n\n", title);
    for (int i = 0; i < length; i++)
    {
        printf("Position: %-2d | Team: %-5s | Total Matches: %-5d | Wins: %-5d | Losses: %-5d | Ties: %-5d | Goals: %-5d | Points: %-5d | Crowd: %-10d\n",
               teams[i].position,
               teams[i].name,
               teams[i].matches,
               teams[i].wins.total,
               teams[i].losses.total,
               teams[i].ties,
               teams[i].goals.goals_for,
               teams[i].points,
               teams[i].crow_at_home);
    }
    printf("\n");
}

int wins_more_away(Team team){
    if (team.wins.away > team.wins.at_home)
    {
        return 1;
    } else
    {
        return 0;
    }
}

int find_matches_in_15(int total_matches, Match matches[total_matches], Match matches_in_15[total_matches]){
    int j = 0;

    for (int i = 0; i < total_matches; ++i) {
        int match_year;
        sscanf(matches[i].date," %*d/%*d/%d",&match_year);

        if (match_year == 2015)
        {
            matches_in_15[j] = matches[i];
            ++j;
        }
    }

    return j;
}

void get_crow(int length, Match matches[length], Team teams[TOTAL_TEAMS]){

    for (int i = 0; i < TOTAL_TEAMS; ++i) {
        for (int j = 0; j < length; ++j) {
            if (home_team(teams[i],matches[j]))
            {
                teams[i].crow_at_home += matches[j].crowd;
            }
        }
    }
}

void find_most_unpopular_team(Team teams[TOTAL_TEAMS], Team *most_unpopular){
    Team crowd_sorted_teams[TOTAL_TEAMS];

    for (int i = 0; i < TOTAL_TEAMS; ++i) {
        crowd_sorted_teams[i] = teams[i];
    }

    qsort(crowd_sorted_teams,TOTAL_TEAMS, sizeof(Team),sort_after_crowd);

    *most_unpopular = crowd_sorted_teams[0];
}

int sort_after_crowd(const void *a, const void *b){
    Team *pa = (Team*)a;
    Team *pb = (Team*)b;

    return (pa->crow_at_home - pb->crow_at_home);
}

int find_matches(int total_matches, Match matches[total_matches], Match matches_in_period[total_matches], char *u, char *k1, char *k2){
    int j = 0;

    for (int i = 0; i < total_matches; ++i) {
        if (!strcmp(matches[i].weekday,u))
        {
            if (is_between_time(matches[i].time,k1,k2))
            {
                matches_in_period[j] = matches[i];
                ++j;
            }
        }
    }

    return j;
}

int is_between_time(char match_time[MAX_TIME_LGT], char *k1, char *k2){

    if (strcmp(match_time,k1) >= 0 && strcmp(match_time,k2) <= 0)
    {
        return 1;
    } else
    {
        return 0;
    }

}

void clear(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}