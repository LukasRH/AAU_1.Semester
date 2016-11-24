/* 
Fulde navn: Rasmus Egholm Nielsen
Email adresse: reni16@student.aau.dk
Gruppe: B2-1a
Studieretning: Software
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_WEEKDAY_LGT 5
#define MAX_DATE_LGT 15
#define MAX_CLOCK_LGT 10
#define MAX_TEAM_LGT 5

struct game
{
    int round;
    char weekday[MAX_WEEKDAY_LGT];
    char date[MAX_DATE_LGT];
    char clock[MAX_CLOCK_LGT];
    char home_team[MAX_TEAM_LGT];
    char away_team[MAX_TEAM_LGT];
    int home_goal;
    int away_goal;
    int spectators;
};
typedef struct game game;

int number_of_lines(void);
game read_superliga_file(FILE *fp);
void assign_struct_to_array(int number_of_games, game games[number_of_games]);

int main(void)
{
    int number_of_games = number_of_lines();
    game games[number_of_games];

    assign_struct_to_array(number_of_games, &games[number_of_games]);
}

int number_of_lines(void)
{
    /* when 1 match is 1 line in the text file, number of lines must be number of games */
    FILE *fp_line = fopen("superliga-2015-2016", "r");
    int character, count_line = 0;

    do {
        character = fgetc(fp_line);
        if (character == '\n')
            count_line++;
    } while (character != EOF);
        if (character != '\n' && count_line != 0)
        count_line++;

    fclose(fp_line);
    return count_line;
}

void assign_struct_to_array(int number_of_games, game games[number_of_games])
{
    FILE *fp = fopen("superliga-2015-2016", "r");
    for (int i = 0 ; i < number_of_games ; i++)
    {
        games[i] = read_superliga_file(fp);
        printf("R%-5d %-5s %-13s %-5s %5s - %-3s %5d - %-3d Spectators: %-5d\n",
               games[i].round,
               games[i].weekday,
               games[i].date,
               games[i].clock,
               games[i].home_team,
               games[i].away_team,
               games[i].home_goal,
               games[i].away_goal,
               games[i].spectators);
    }
    fclose(fp);
}

game read_superliga_file(FILE *fp)
{
    game game;
    int x = 0, y = 0;
    fscanf(fp, " R%d %s %s %s %s - %s %d - %d %d.%d", 
            &game.round, 
            game.weekday, 
            game.date, 
            game.clock, 
            game.home_team, 
            game.away_team,
            &game.home_goal,
            &game.away_goal,
            &x, &y);

    game.spectators = x * 1000 + y;

    return game;
}
