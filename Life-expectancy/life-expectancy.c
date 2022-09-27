#include <stdio.h>
#include <string.h>

void printSpaces(int amountOfSpaces);
void printNewLines(int amountOfNewLines);
void writeQuestionsWithChoicesTo(char* questionsAndChoices[][2]);
void writePercentageTo(char* percentage[]);
char getFirstCharacterFromStream();

int main() {
   char answerFromUser;
   int  years = 72;
   char availableChoices[15] = "ABCDEMGHIJKLFNO";

   printSpaces(21);
   printf("LIFE EXPECTANCY\n");
   printSpaces(20);
   printf("CREATIVE COMPUTING\n");
   printSpaces(18);
   printf("MORRISTOWN, NEW JERSEY\n");
   printNewLines(6);
   printf("THIS IS A LIFE EXPECTANCY TEST.\n");
   printf("   DO YOU WISH INSTRUCTIONS? ");
   answerFromUser = getFirstCharacterFromStream();
   if (answerFromUser != 'N')
   {
      printNewLines(2);
      printf("   THIS IS A TEST TO PREDICT YOUR LIFE EXPECTANCY.  I\n");
      printf("WILL ASK YOU A SERIES OF SHORT QUESTIONS, WHICH YOU WILL\n");
      printf("REPLY BY TYPING IN THE CORRESPONDING ANSWER TO THE\n");
      printf("QUESTION.\n");
      printNewLines(1);
      printf("        EXAMPLE:  WHAT IS YOUR SEX?\n");
      printf("               M=MALE\n");
      printf("               F=FEMALE\n");
      printf("'M' AND 'F' ARE THE POSSIBLE REPLIES TO THE QUESTION, ANSWER\n");
      printf("LIKE THIS:\n");
      printf("              CHOOSE ONE OF THE LETTERS ABOVE? M\n");
      printf("TYPING AN 'M' SIGNIFIES YOU ARE A MALE.\n");
      printNewLines(3);
   }

   char* questionsAndChoices[21][2];
   writeQuestionsWithChoicesTo(questionsAndChoices);
   
   const int COLUMN_OF_QUESTIONS = 0;
   const int COLUMN_OF_CHOICES = 1;
   const int AMOUNT_OF_QUESTIONS = 21;
   char textOfQuestion[215];
   for (int currentQuestion = 0; currentQuestion < AMOUNT_OF_QUESTIONS; currentQuestion++)
   {
      strcpy(textOfQuestion, questionsAndChoices[currentQuestion][COLUMN_OF_QUESTIONS]); //casting from char* to char[]
      char* sentence = strtok(textOfQuestion, "|");
      while (sentence != NULL)
      {
         if (sentence[0] == ' ')
         {
            printf(" %s\n", sentence);
         }
         else
         {
            printf("  %s\n", sentence);
         }
         sentence = strtok(NULL, "|");
      }
      while (1 == 1)
      {
         printf("CHOOSE ONE OF THE LETTERS ABOVE? ");
         answerFromUser = getFirstCharacterFromStream();
         if (strchr(questionsAndChoices[currentQuestion][COLUMN_OF_CHOICES], (int)answerFromUser) != NULL)
         {
            for (int currentChoice = 0; currentChoice < sizeof(availableChoices); currentChoice++)
            {
               if (availableChoices[currentChoice] == answerFromUser)
               {
                  currentChoice++; //to correspond to original algorithm written in BASIC
                  years = years + (currentChoice - 9);
                  break;
               }
            }
            printNewLines(1);
            break;
         }
      }
   }
   printf("YOU ARE EXPECTED TO LIVE TO THE AGE OF %d YEARS", years);
   if (years >= 60)
   {
      const int AMOUNT_OF_PERCENTAGE = 16;
      char* percentage[AMOUNT_OF_PERCENTAGE];
      char* percentageOfMen;
      char* percentageOfWomen;

      writePercentageTo(percentage);
      int currentPercentage = 0;
      for (int currentYear = 60; currentYear < years; currentYear = currentYear + 5)
      {
         int currentYesrInNextLoopExecution = currentYear + 5;
         if (currentYesrInNextLoopExecution > years)
         {
            break;
         }
         currentPercentage = currentPercentage + 2;
      }
      if (currentPercentage < (AMOUNT_OF_PERCENTAGE - 1))
      {
         percentageOfMen = percentage[currentPercentage];
         currentPercentage++;
         percentageOfWomen = percentage[currentPercentage];
         printf("\nOUT LIVING %s OF THE MEN AND %s OF THE WOMEN.", percentageOfMen, percentageOfWomen);
      }
      else
      {
         printf("\n!OUT OF DATA");
      }
   }

   getchar();
   return 0;
}

void printSpaces(int amountOfSpaces)
{
   for (int space = 0; space < amountOfSpaces; space++)
   {
      printf(" ");
   }
}

void printNewLines(int amountOfNewLines)
{
   for (int newLine = 0; newLine < amountOfNewLines; newLine++)
   {
      printf("\n");
   }
}

void writeQuestionsWithChoicesTo(char* questionsAndChoices[][2])
{
   questionsAndChoices[0][0]  = "+++SEX+++|ARE YOU MALE OR FEMALE?|M= MALE.| F= FEMALE.|";
   questionsAndChoices[0][1]  = "MF";

   questionsAndChoices[1][0]  = "+++LIFE STYLE+++|WHERE DO YOU LIVE?|G= IF YOU LIVE IN AN URBAN AREA WITH A POPULATION OVER 2 MIL.|K= IF YOU LIVE IN A TOWN UNDER 10,000, OR ON A FARM.| I= NEITHER.|";
   questionsAndChoices[1][1]  = "GKI";

   questionsAndChoices[2][0]  = "HOW DO YOU WORK?|M= IF YOU WORK BEHIND A DESK.|L= IF YOUR WORK REQUIRES HEAVY PHYSICAL LABOR.| I= NONE OF THE ABOVE.|";
   questionsAndChoices[2][1]  = "MLI";

   questionsAndChoices[3][0]  = "HOW LONG DO YOU EXERCISE STRENUOUSLY,|(TENNIS, RUNNING, SWIMMING, ETC.)?|F= FIVE TIMES A WEEK FOR AR LEAST A HALF HOUR.|K= JUST TWO OR THREE TIMES A WEEK.| I= DO NOT EXERCISE IN THIS FASHION.|";
   questionsAndChoices[3][1]  = "FKI";
   
   questionsAndChoices[4][0]  = "WHO DO YOU LIVE WITH?|N= IF YOU LIVE WITH A SPOUSE, FRIEND, OR IN A FAMILY.|H= IF YOU'VE LIVED ALONE FOR 1-10 YEARS SINCE AGE 25.|G= FOR 11-20 YEARS.|M= FOR 21-30 YEARS.|E= FOR 31-40 YEARS.| D= MORE THAN 40 YEARS.|";
   questionsAndChoices[4][1]  = "NHGMED";

   questionsAndChoices[5][0]  = "DO YOU SLEEP MORE THAN 10 HOURS A NIGHT?|I= NO.| E= YES.|";
   questionsAndChoices[5][1]  = "IE";

   questionsAndChoices[6][0]  = "+++MENTAL STATE+++|M= IF YOU ARE INTENSE, AGGRESSIVE, OR EASILY ANGERED.|L= IF YOU ARE EASY GOING, RELAXED, OR A FOLLOWER.| I= NEITHER.|";
   questionsAndChoices[6][1]  = "MLI";

   questionsAndChoices[7][0]  = "+++HOW YOU FEEL+++|ARE YOU HAPPY OR UNHAPPY?|J= HAPPY.|G= UNHAPPY.| I= NEITHER.|";
   questionsAndChoices[7][1]  = "JGI";

   questionsAndChoices[8][0]  = "+++FACTORS+++|HAVE YOU HAD A SPEEDING TICKET IN THE LAST YEAR?|H= YES.| I=NO.|";
   questionsAndChoices[8][1]  = "HI";

   questionsAndChoices[9][0]  = "+++INCOME+++|DO YOU EARN MORE THAN $50,000 A YEAR?|G= YES.| I=NO.|";
   questionsAndChoices[9][1]  = "GI";

   questionsAndChoices[10][0] = "+++SCHOOLING+++|J= IF YOU HAVE FINISHED COLLEGE.|L= IF YOU HAVE FINISHED COLLEGE WITH A GRADUATE|OR PROFESSIONAL DEGREE.| I= NOTHING LISTED.|";
   questionsAndChoices[10][1]  = "JLI";

   questionsAndChoices[11][0] = "+++AGE+++|ARE YOU 65 OR OLDER AND STILL WORKING?|L= YES.| I= NO.|";
   questionsAndChoices[11][1]  = "LI";

   questionsAndChoices[12][0] = "+++HEREDITY+++|K= IF ANY GRANDPARENTS LIVED TO 85 YEARS OLD.|O= IF ALL FOUR GRANDPARENTS LIVED TO 80 YEARS OLD.| I= NO GRANDPARENTS QUALIFY IN THE ABOVE.|";
   questionsAndChoices[12][1]  = "KOI";

   questionsAndChoices[13][0] = "HAS ANY PARENT DIED OF A STROKE OR HEART ATTACK|BEFORE THE AGE OF 50?|E= YES.| I= NO.|";
   questionsAndChoices[13][1]  = "EI";

   questionsAndChoices[14][0] = "+++FAMILY DISEASES+++|ANY PARENT, BROTHER, OR SISTER UNDER 50 HAS (OR HAD) |CANCER, A HEART CONDITION, OR DIABETES SINCE CHILDHOOD?|M= YES.| I= NO.|";
   questionsAndChoices[14][1]  = "MI";

   questionsAndChoices[15][0] = "+++HEALTH+++|HOW MUCH DO YOU SMOKE?|A= IF YOU SMOKE MORE THAN TWO PACKS A DAY.|C= ONE TO TWO PACKS A DAY.|M= ONE HALF TO ONE PACK A DAY.| I= DON'T SMOKE.|";
   questionsAndChoices[15][1]  = "ACMI";

   questionsAndChoices[16][0] = "+++DRINK+++|DO YOU DRINK THE EQUIVALENT OF A |QUARTER BOTTLE OF ALCOHOLIC BEVERAGE A DAY?|H= YES.| I= NO.|";
   questionsAndChoices[16][1]  = "HI";

   questionsAndChoices[17][0] = "+++WEIGHT+++|A= IF YOU ARE OVERWEIGHT BY 50 POUNDS OR MORE.|E= OVER BY 30-50 POUNDS.|G= OVER BY 10-30 POUNDS.| I= NOT OVER WEIGHT.|";
   questionsAndChoices[17][1]  = "AEGI";

   questionsAndChoices[18][0] = "+++CHECKUPS+++|DO YOU?  IF YOU ARE A MALE OVER 40 HAVE AN ANNUAL CHECKUP?|K= YES.| I= IF NO OR NOT A MALE OR UNDER 40 YEARS OLD.|";
   questionsAndChoices[18][1]  = "KI";

   questionsAndChoices[19][0] = "DO YOU? IF YOU ARE A WOMAN SEE A GYNECOLOGIST ONCE A YEAR?|K= YES.| I= IF NO OR NOT A WOMAN.|";
   questionsAndChoices[19][1]  = "KI";

   questionsAndChoices[20][0] = "+++CURRENT AGE+++|K= IF YOU ARE BETWEEN 30 AND 40 YEARS OLD.|L= BETWEEN 40 AND 50.|F= BETWEEN 50 AND 70.|N= OVER 70.| I= UNDER 30.|";
   questionsAndChoices[20][1]  = "KLFNI";
}

void writePercentageTo(char* percentage[])
{
   percentage[0]  = "26%";
   percentage[1]  = "15%";
   percentage[2]  = "36%";
   percentage[3]  = "20%";
   percentage[4]  = "48%";
   percentage[5]  = "30%";
   percentage[6]  = "61%";
   percentage[7]  = "39%";
   percentage[8]  = "75%";
   percentage[9]  = "53%";
   percentage[10] = "87%";
   percentage[11] = "70%";
   percentage[12] = "96%";
   percentage[13] = "88%";
   percentage[14] = "99.9%";
   percentage[15] = "99.6%";   
}

char getFirstCharacterFromStream()
{
   int nextCharacter;
   char firstCharacter;
   scanf(" %c", &firstCharacter);
   while((nextCharacter = getchar()) != '\n');
   return firstCharacter;
}