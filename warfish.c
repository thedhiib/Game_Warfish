#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
#include <stdio.h>              // русский язык подключить не получилоьс
#include <stdlib.h>             // не через windows.h , не через locale.h chcp1251 тоже -

void rules()
{
  printf("\n");
  printf("YOU COMMAND AN AMERICAN SUBMARINE THAT BEEN SENT OUT\n");
  printf("TO ATTACK JAPANESE SHIPS AT SEA DURING WORLD WAR TWO\n");
  printf("THE ORDERS THAT CAN BE GIVEN ARE THE FOLLOWING:\n");
  printf("PERISCOPE - TO SEARCH FOR JAPANESE SHIPS\n");
  printf("TORPEDO - TO LAUNCH TORPEDOES AT JAPANESE SHIPS\n");
  printf("DIVE - TO ESCAPE JAPANESE SHIPS THAT ARE ATTACKING\n\n");
}
int Periscope(int tesn)
{
  if (tesn == 0)
  {
  float tes; //Type_enemy_ship Tanker or Destroer for randomize type <75 Tanker; >75 Destroer
  tes=(rand()%100);
  if (tes <= 75) //здесь задаётся процент типа кораблей, чем меньше число в if, тем чаще встретиться эскорт.
  {
    tesn=1;         //Tanker

  }
  else
  {
    tesn=2;        //Destroer
  }
  return (tesn);
  }
  else
  {
    
    printf("Target alredy set: ");

    return (tesn);
  }
  
  
  
}
int Tonnazh(int tonn)
{
  if (tonn == 0)
  {
    return(rand()%10000);
  }
  else
  {
  return(tonn);
  }
}
int Torpedo(int torpedofire)
{
 int itogchet=0; 
 for (int i = 1; i <= torpedofire; i++)
 {
  int percentdetonation=51,random=0; // Здесь задаётся процент детонации торпед, изначально было 70, со ссылкой на историю
  random=(rand()%100);
  if (random < percentdetonation)
  {
    itogchet = itogchet +1;
  }
  
 }
 return(itogchet);
}
int generatedistance(int distd)
{
  if (distd == 0)
  {
    distd=(int)(rand()%10000);
    return distd;
  }
  else
  {
    if (distd >= 500)
    {
     distd = distd - 500;
     return distd;
    }
  }
  return 0;
}
int Dive(int typeship,int distd)
{
  if (typeship == 1)
  {
    return(1);
  }
  else
  {
    if (typeship == 2)
    {
      int b=distd/1000,c; // условно наша лодка успевает погрузиться на 22 метра(см. строка 106), пока корабль подходит к нам 1000 метров.
      int depth=12; //перископная глубина в метрах, раз уж мы всегда смотрим в перископ
      float a;
      for (int i = 1; i <= b; i++)
      {
        printf("DEPTH: [");
        printf("%d",depth);
        printf("] UNDER WATER\n");
        depth = depth + 22;
      }
      printf("\n");
      a=((rand()%100)/2); // Рандомное добавление глубины для успешного скрытия
      c=a;          //преобразуем рандомное флоат "а" в инт "с", чтоб добавить к глубине, когда корабль шёл к нам, а мы погружались
      depth = depth + c; 
      if (depth < 101) // Условие успешного скрытия
      {
        return(3);
      }
      else
      {
        return(2);
      }
      
    }
    
  }
  return 0;
}
int main()
{ 
  int tesn=0,typeship=0,tonn=0,resultshipdestroy=0,resulttonn=0, resultdive=0, distd=0;          // Type_enemy_ship_number return data for function torpedo
  char ruleanswer[3];                                                        //distd=distance for destroyer        
  printf("Before start play the game, please activate button CAPSLOCK\n");
  printf("DO YOU DESIRE THE RULES OF WARFISH?\n\n");
  askagain:
  printf("Enter only [YES or NO]:");
  scanf("%s", &*ruleanswer);
  if (*ruleanswer == 'N')  // я не знаю как в if пройти весь массив символов на соответсвия слова, поэтому 
  {                             // меряем по первому символу ответа и зацикливаем запрос меткой
    printf("\n");
  }
  else
  {
    if (*ruleanswer == 'Y')
    rules();
    else
    goto askagain;
  }       // выход и зацикленно
  
  char boatname[20];            //статический массив символов, НЕ! динамический указатель на адрес стека, в который пишутся данные с data во время инициализации(важно)
  printf("Get name your's boat, Commander![max 20 unit]: "); 
  scanf("%s", &*boatname);     // тут просто смирение с низким уровнем, как точно &* ваще не понятно,
  printf("\n"); 
  int torpedo=26; // из бэйсика у подлодки всегда 26 торпед, причём помним регистр переменной, большая Т это функция, маленькая кол-во терпед
  char orders[9];  // статический массив для записи самой длинной команды перескоп.
  do
  {
   repeatorders: 
   printf("ORDERS, COMMANDER.[PERISCOPE/DIVE/TORPEDO]");
   scanf("%s", &*orders);
   printf("\n");
   if (*orders == 'P')
   {
    typeship=Periscope(tesn);
    tesn=typeship;    //Без этого костыля, цель в перископе меняется, не знаю как точно работает поток/вывод из вызываемой функции.
    tonn=Tonnazh(tonn);
    if (typeship == 1)
    {
      printf("CONTACT: JAPANISE TANKER\n");
      printf("TONNAGE: [");
      printf("%d",tonn);
      printf("]");
      printf("\n\n");
    }
    else
    {
      if (typeship == 2)   //Наблюдаем и принимае действия при виде эскорта
      {
        printf("CONTACT: JAPANISE DESTROYER \n");
        distd=generatedistance(distd);
        printf("TONNAGE: [");
        printf("%d",tonn);
        printf("]   ");
        printf("DISTANCE: [");
        printf("%d",distd);
        printf("] METER\n\n");
        printf("\t");
        printf("WARNING! WARNING! WARNING!\n");
        printf("More torpedoes are needed to guaranteed destroy the destroer ship.\n");
        printf("OR CRASHDIVE!\n");
        printf("If the enemy ship is closer than 500 meter, we will not have time to hide in depth.");
        printf("\n\n");
        if (distd <= 500)
        {
          printf(" Enemy destroer dpor depth bomb and crash you boat, you are dead! \n");
          goto ENDGAME;
        }
        
      }
      
    }
    
   }
   else
   {
    if (*orders == 'T')    //Команда торпедировать цель
    {
      if (typeship == 0)   // Конструкция из 3 Ифов, для определения цели и её отсутствия.
      {                     // 0 Цели нет, значит перископ ещё не подняли ни разу, или после уничтожения цели, не подняли вновь.
       printf("SIR, NO TARGET, NEED UP PERISCOPE.\n\n"); 
      }
      else
      {
          if (typeship == 1)  //Торговое судно
          {
          printf("TARGET IS: JAPANISE TANKER\n");
          printf("TONNAGE: [");
          printf("%d",tonn);
          printf("]\n\n");
          printf("\t");
          printf("%d", torpedo);
          printf(" Torpedos left \n");
          printf("Number of torpedos to fire? ");
          int torpedofire=0;
          scanf("%d", &torpedofire);
          printf("\n");
          torpedo=(torpedo-torpedofire);
          int resultattack=0;
          resultattack=Torpedo(torpedofire);
            if (resultattack >= 1)
            {
            printf("Target Destroy!!! ");
            printf("%d", resultattack);
            printf(" of ");
            printf("%d",torpedofire);
            printf(" torpeds hit the target.\n\n");
            resultshipdestroy = resultshipdestroy + 1;
            resulttonn = resulttonn + tonn;
            typeship=0;
            tesn=0;
            tonn=0;
            }
            else
            {
            printf("Better, attack again, sir!\n\n");
            }
          }
          else
          {
          if (typeship == 2) //Эснимиц, корабль охранения.
          {
            printf("\t");
            printf("%d", torpedo);
            printf(" Torpedos left \n");
            printf("TARGET IS: JAPANISE DESTROYER\n");
            printf("TONNAGE: [");
            printf("%d",tonn);
            printf("]   ");
            distd=generatedistance(distd);
            printf("DISTANCE: [");
            printf("%d",distd);
            printf("] METER\n\n");
            printf("Number of torpedos to fire? ");
            int torpedofire=0;
            scanf("%d", &torpedofire);
            printf("\n");
            torpedo=(torpedo-torpedofire);
            int resultattack=0;
            resultattack=Torpedo(torpedofire);
              if (resultattack >= 1)
              {
              printf("Target Destroy!!! ");
              printf("%d", resultattack);
              printf(" of ");
              printf("%d",torpedofire);
              printf(" torpeds hit the target.\n\n");
              resultshipdestroy = resultshipdestroy + 1;
              resulttonn = resulttonn + tonn;
              typeship=0;
              tesn=0;
              tonn=0;
              distd=0;
              }
              else
              {
                printf("%d",torpedofire);
                printf(" torpedo miss, Sir! \n");
                printf("BETTER, crash dive, sir!\n\n");
                distd=generatedistance(distd);
                printf("TARGET IS: JAPANISE DESTROYER \n");
                printf("TONNAGE: [");
                printf("%d",tonn);
                printf("]   ");
                printf("DISTANCE: [");
                printf("%d",distd);
                printf("] METER\n");
                if (distd <= 500)
                {
                  printf(" Enemy destroer dpor depth bomb and crash you boat, you are dead! \n");
                  goto ENDGAME;
                }
              }
          }
          
        }
      } // Это конец if == 0
      
    } // конец сортировкой if приказа. Это конец приказа T
    else
    {
      if (*orders == 'D')
      {
        if (typeship == 0)
        {
          printf("WE DON'T HAVE TO HIDE. NO ONE CONTACT\n\n");
        }
        else
        {
         resultdive=Dive(typeship,distd);
         if (resultdive == 1)
         {
          printf("WE'VE LOST CONTACT WITH THE TANKER \n\n");
          tesn = 0;
          typeship = 0;
          tonn = 0;
         }
          else
          {
            if (resultdive == 2)
            {
              printf("WE SUCCESSFULLY LEFT THE LINE OF FIRE \n\n");
              tesn = 0;
              typeship = 0;
              tonn = 0;
              distd = 0;
            }
            else
            {
              if (resultdive == 3)
              {
                printf("WE DID NOT HIDE.\n"); 
                printf("BOAT DESTROYED.\n\n");
                tesn = 0;
                typeship = 0;
                tonn = 0;
                distd = 0;
                goto ENDGAME;
              }
              
            }
            
          }
          
        }
        
        

      }
      else
      {
       printf("ORDER NOT UNDERSTOOD, REPEAT:\n\n");
       goto repeatorders; 
      }
      
    }
    
    
   }
    
  } while (torpedo != 0); //спрашиваем приказ, пока есть торпеды
  ENDGAME:
  printf("Game END \n");
  printf("Statistics: ");
  printf("%s", boatname);
  printf(" Sink the ");
  printf("%d", resultshipdestroy);
  printf(" enemy ship\n");
  printf("And all TONNAGE = ");
  printf("%d", resulttonn);
  printf(" TONN");
  getchar(); getchar();
  return 0;
}